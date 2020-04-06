#pragma once

#include <string>
#include <vector>
#include <deque>
#include <sstream>
#include <iomanip>

#define MY_MIN(x,y) ((x)<(y)?(x):(y))
#define MY_MAX(x,y) ((x)>(y)?(x):(y))
#define RANGE_IN(min,max,num) (MY_MAX(MY_MIN((num), (max)), (min)))

using namespace std;
class chess
{
	enum class Mode
	{
		sleep,
		waiting,
		start
	};
	Mode now = Mode::sleep;

	deque<string> msgque;//��Ϣ����
	deque<vector<vector<short>>> history;//��¼
	vector<vector<short>> table;//����
	const int size;
	int role = 0;//�ִ�
	long long playerid[2] = { 0 };//���id

	static chess* running;
	chess(size_t _size = 9);

public:

	long long groupid = 0;//����Ⱥ

public:

	static chess* getinstance()
	{
		if (running)
		{
			return running;
		}
		return new chess;
	}

	size_t msg_size();

	string pop_msg();
	void control(string msg, pair<long long, string> user, long long groupid);

	~chess();

private:
	void init_table();
	bool action(int x, int y);
	void map_to_str();
	bool game_over();
};
