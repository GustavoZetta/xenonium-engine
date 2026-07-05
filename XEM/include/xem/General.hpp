#pragma once

#include <xem/Qualifier.hpp>

namespace xem {
	// Linear Interpolation
	template<typename T>
	inline T Lerp(const T& a, const T& b, const T& t) {
		static_assert(xem_impl::IsValidScalar<T>, "XEM: cannot lerp a non scalar (number) value");
		return a + (b - a) * t;
	}

	// 1 more multiplication than normal lerp (so its a little bit slower), 
	// but guarantees that when t = 1, result = B
	template<typename T>
	inline T PreciseLerp(const T& a, const T& b, const T& t) {
		static_assert(xem_impl::IsValidScalar<T>, "XEM: cannot lerp a non scalar (number) value");
		return a * (T(1) - t) + b * t;
	}
}