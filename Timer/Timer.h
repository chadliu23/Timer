#pragma once
#include <thread>
class Timer
{
public:
	Timer(void);
	~Timer(void);
	void setup_Timer(int milliseconds);
	static void print_Time();
	static void timerThread(int milliseconds);
	void stop();
	
private:
	int m_milliseconds;
	std::thread* m_thread;

};

