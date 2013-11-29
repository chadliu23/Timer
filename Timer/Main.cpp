#include "Timer.h"
#include <thread>
#include <chrono>
#include <iostream>
using namespace std;



int main()
{
	Timer t;

	cout <<"t.setup_Timer(100);" <<endl;
	t.setup_Timer();
	std::this_thread::sleep_for(std::chrono::milliseconds(1000));
	cout <<"t.stop;" <<endl;
	t.stop();
	std::this_thread::sleep_for(std::chrono::milliseconds(1000));
	return 0;
}