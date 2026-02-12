#include <time.h>
#include <cassert>

template <clockid_t clock_type = CLOCK_MONOTONIC>
class Timer
{
	bool m_started = false;
	bool m_stopped = false;
	timespec m_start_time = {};
	timespec m_stop_time = {};
public:
	Timer(bool autostart = true)
	{
		if (autostart)
			start();
	}

	void start()
	{
		assert(!m_started);
		m_started = true;
		int result = clock_gettime(clock_type, &m_start_time);
		assert(result == 0);
	}

	void stop()
	{
		assert(m_started && !m_stopped);
		int result = clock_gettime(clock_type, &m_stop_time);
		assert(result == 0);
		m_stopped = true;
	}

	double microseconds() const 
	{
		assert(m_started && m_stopped);
		long long seconds_taken = m_stop_time.tv_sec  - m_start_time.tv_sec;
		long long nanoseconds   = m_stop_time.tv_nsec - m_start_time.tv_nsec;
		
		return seconds_taken*1.0e6 + nanoseconds*1.0e-3;
	}
};

