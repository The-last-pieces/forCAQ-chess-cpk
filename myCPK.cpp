#include "myCPK.h"

chess* chess::running = nullptr;
chess::chess(size_t _size) :size(RANGE_IN(7, 20, _size))
{
	if (running)
	{
		delete running;
		running = nullptr;
	}

	running = this;
	init_table();
}
chess::~chess()
{
	if (running)
	{
		delete running;
		running = nullptr;
	}
}

void chess::init_table()
{
	for (auto it_i = table.begin(); it_i != table.end(); )
	{
		for (auto it_j = (*it_i).begin(); it_j != (*it_i).end(); )
		{
			it_j = (*it_i).erase(it_j);
		}
		it_i = table.erase(it_i);
	}

	for (int i = 0; i <= size + 1; ++i)
	{
		vector<short >temp;
		for (int j = 0; j <= size + 1; ++j)
		{
			temp.push_back(0);
		}
		table.push_back(temp);
	}
}

size_t chess::msg_size()
{
	return msgque.size();
}
string chess::pop_msg()
{
	if (!msgque.empty())
	{
		string mid = msgque.front();
		msgque.pop_front();
		return mid;
	}
	else
	{
		return "";
	}
}

void chess::control(string msg, pair<long long, string> user, long long group)
{
	if (groupid && groupid != group)
	{
		return;
	}

	switch (now)
	{
	case Mode::sleep:
		if (msg == "chess" && user.first == 2776835685)
		{
			now = Mode::waiting;
			playerid[0] = user.first;
			groupid = group;

			stringstream ss;
			ss << user.second << "������Ϸ";
			init_table();
			msgque.push_back(ss.str());
		}
		break;
	case Mode::waiting:
		if (playerid[0] != user.first)
		{
			if (msg == "chess")
			{
				now = Mode::start;
				playerid[1] = user.first;

				stringstream ss;
				ss << user.second << "������Ϸ";
				msgque.push_back(ss.str());
				map_to_str();
			}
		}
		break;
	case Mode::start:
		if (playerid[role] == user.first)
		{
			if (msg == "back")
			{
				if (history.size() > 2)
				{
					history.pop_back();
					history.pop_back();
					table = history.back();
					map_to_str();
				}
				else
				{
					msgque.push_back("Ŀǰ�޷�����");
				}
				break;
			}
			if (msg == "end")
			{
				now = Mode::sleep;
				this->history.clear();
				playerid[0] = playerid[1] = 0;
				groupid = 0;
				msgque.push_back("��Ϸ��ֹ");
				break;
			}

			stringstream ss(msg);
			int x = 0, y = 0;
			ss >> x >> y;
			if (action(x, y))
			{
				role = !role;
				map_to_str();

				history.push_back(table);
				if (history.size() > 6)
				{
					history.pop_front();
				}
			}
		}
		break;
	default:
		break;
	}
}
bool chess::action(int x, int y)
{
	if (x <= 0 || x > size || y <= 0 || y > size)
	{
		return false;
	}
	else
	{
		if (table[x][y])
		{
			msgque.push_back("�˴���������");
		}
		else
		{
			table[x][y] = role + 1;
			return true;
		}
	}
	return false;
}
void chess::map_to_str()
{
	stringstream rstr;

	if (!game_over())
	{
		rstr << "�ֵ� [CQ:at,qq=" << playerid[role] << "]" << "����" << endl;
	}
	rstr << "x\\y 1 2  3  4 5  6  7 8  9\n";;
	string allstr[] = { " O"," X"," Y" };
	for (int i = 1; i <= size; ++i)
	{
		rstr << ' ' << i << ' ';
		for (int j = 1; j <= size; ++j)
		{
			rstr << allstr[table[i][j]];
		}
		rstr << endl;
	}

	msgque.push_back(rstr.str());
	if (game_over())
	{
		stringstream ss;
		ss << "[CQ:at, qq = " << playerid[role] << "]";
		ss << " ���ʤ��\n";
		msgque.push_back(ss.str());
	}
}
bool chess::game_over()
{
	const int check = !role + 1;

	for (int i = 1; i <= size; ++i)
	{
		for (int j = 1; j <= size; ++j)
		{
			for (int z = 0, count[3] = { 0 }; z + j <= size && z + i <= size && z < 5; ++z)
			{
				if (table[i][z + j] == check)
				{
					count[0]++;//��
				}
				if (table[z + i][j] == check)
				{
					count[1]++;//��
				}
				if (table[z + j][z + j] == check)
				{
					count[2]++;//б
				}

				if (count[0] == 5 || count[1] == 5 || count[2] == 5)
				{
					return true;
				}
			}
		}
	}

	return false;
}