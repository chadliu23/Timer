#include "Timer.h"
#include <thread>
#include <chrono>
#include <iostream>
using namespace std;



int main()
{
	Timer t;

	t.setup_Timer(100);
	std::this_thread::sleep_for(std::chrono::milliseconds(1000));
	t.stop();
	std::this_thread::sleep_for(std::chrono::milliseconds(1000));
	return 0;
}