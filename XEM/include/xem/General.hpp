#pragma once

#include <xem/Qualifier.hpp>

namespace xem {
	template<typename T>
	inline T Lerp(const T& a, const T& b, const T& t) {
		static_assert(xem_impl::IsValidScalar<T>, "XEM: cannot lerp a non scalar (number) value")
		return a + (b - a) * t;
	}
}