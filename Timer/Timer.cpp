#include "Timer.h"
#include <iostream>
#include <ctime>
#include <thread>
#include <chrono>
using namespace std;

Timer::Timer(void)
	: m_thread(nullptr)
	, m_stopFlag(-1)
{
}


Timer::~Timer(void)
{
	m_stopFlag = 1;
	if(m_thread != nullptr)
	{
		m_thread->detach();
		delete m_thread;
		m_thread = nullptr;
	}
}

void Timer::timerThread(int& stopFlag)
{
	while(true)
	{
		std::this_thread::sleep_for(std::chrono::milliseconds(100));
		if(stopFlag == 1)
		{
			stopFlag = -1;
			break;
		}
		Timer::print_Time();
	}
}

void Timer::setup_Timer()
{
	//m_milliseconds = milliseconds;
	if(m_thread != nullptr)
	{
		return;
	}
	m_thread = new thread(&Timer::timerThread, std::ref(m_stopFlag));
	

}
void Timer::print_Time()
{

	time_t  timev;
	time(&timev);
	cout <<timev <<endl;
}

void Timer::stop()
{
	if(m_thread != nullptr)
	{
		m_stopFlag = 1;
		m_thread->detach();
		delete m_thread;
		m_thread = nullptr;
	}
}