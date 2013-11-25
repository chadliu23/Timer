#include "Timer.h"
#include <iostream>
#include <ctime>
#include <thread>
#include <chrono>
using namespace std;

Timer::Timer(void)
	: m_milliseconds(0)
	, m_thread(nullptr)
{
}


Timer::~Timer(void)
{
	if(m_thread != nullptr)
	{
		m_thread->detach();
		delete m_thread;
		m_thread = nullptr;
	}
}

void Timer::timerThread(int milliseconds)
{
	while(true)
	{
		std::this_thread::sleep_for(std::chrono::milliseconds(milliseconds));
		Timer::print_Time();
	}
}

void Timer::setup_Timer(int milliseconds)
{
	m_milliseconds = milliseconds;
	if(m_thread != nullptr)
	{
		m_thread->detach();
		delete m_thread;
		m_thread = nullptr;
	}
	m_thread = new thread(&Timer::timerThread, milliseconds);
	

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
		m_thread->detach();
		delete m_thread;
		m_thread = nullptr;
	}
}