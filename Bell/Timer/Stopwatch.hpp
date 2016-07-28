//=====================================================================
// Copyright (c) 2015-2016 Ryooooooga.
// https://github.com/Ryooooooga
//
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
// http://www.boost.org/LICENSE_1_0.txt)
//=====================================================================

#pragma once

#include <chrono>

namespace Bell::Timer {

	/**
	 * @brief      ストップウォッチ
	 *
	 * @tparam     Clock
	 */
	template <typename Clock>
	class BasicStopwatch
	{
		typename Clock::time_point start_;

	public:
		using clock_type	= Clock;
		using time_point	= typename Clock::time_point;
		using duration		= typename Clock::duration;

		/**
		 * @brief      BasicStopwatch ctor
		 */
		explicit BasicStopwatch() noexcept
			: start_(Clock::now()) {}


		/**
		 * @brief      時間計測の開始時間の再設定
		 *
		 * @return     *this
		 */
		BasicStopwatch& restart() noexcept
		{
			start_ = Clock::now();
			return *this;
		}


		/**
		 * @brief      計測開始からの経過時間を秒単位で取得する
		 *
		 * @return     計測会氏からの経過時間[s]
		 */
		double elapsed() const noexcept
		{
			using std::chrono::duration_cast;
			using std::chrono::nanoseconds;

			return duration_cast<nanoseconds>(Clock::now() - start_).count() * 1e-9;
		}
	};

	using Stopwatch				= BasicStopwatch<std::chrono::system_clock>;
	using HiresolutionStopwatch	= BasicStopwatch<std::chrono::high_resolution_clock>;
	using SteadyStopwatch		= BasicStopwatch<std::chrono::steady_clock>;

}	//	namespace Bell::Timer
