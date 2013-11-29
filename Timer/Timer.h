#pragma once
#include <thread>
class Timer
{
public:
	Timer(void);
	~Timer(void);
	void setup_Timer();
	static void print_Time();
	static void timerThread(int& stopFlag);
	void stop();
	
private:
	std::thread* m_thread;
	int m_stopFlag;

};

