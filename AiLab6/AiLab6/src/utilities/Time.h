#ifndef _UTIL_TIME_H
#define _UTIL_TIME_H

namespace app::time
{
		typedef std::chrono::duration<float> seconds;
		typedef std::chrono::milliseconds milliseconds;
		typedef std::chrono::microseconds microseconds;
		typedef std::chrono::nanoseconds nanoseconds;
		template<typename T>
		constexpr app::time::seconds toSeconds(T const & time) { return std::chrono::duration_cast<app::time::seconds>(time); }
		template<typename T>
		constexpr app::time::milliseconds toMillis(T const & time) { return std::chrono::duration_cast<app::time::milliseconds>(time); }
		template<typename T>
		constexpr app::time::microseconds toMicros(T const & time) { return std::chrono::duration_cast<app::time::microseconds>(time); }
		template<typename T>
		constexpr app::time::nanoseconds toNanos(T const & time) { return std::chrono::duration_cast<app::time::nanoseconds>(time); }

}

#endif // !_UTIL_TIME_H
