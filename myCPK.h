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
	int size;
	bool isend = false;
	int role = 0;//�ִ�
	string errlog;
	long long playerid[2] = { 0 };//���id

	static chess* running;
public:
	size_t msg_size();

	string pop_msg();
	void control(string msg, long long userid);

	chess(size_t _size = 10);
	~chess() {}

private:
	void init_table();
	bool action(int x, int y);
	string map_to_str();
	bool game_over();
};
