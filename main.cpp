
#include "myCPK.h"

#include <iostream>
using namespace std;
int main(void)
{
	typeid(int).name();
	chess* test = chess::getinstance();
	string msg;
	int id = 50;
	while (1)
	{
		id = 150 - id;
		getline(cin, msg);
		test->control(msg, {id,"none"}, 100);
		
		while (test->msg_size())
		{
			cout << test->pop_msg() << endl;
		}
	}
}