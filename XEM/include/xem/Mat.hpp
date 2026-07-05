#pragma once

#include <xem/Qualifier.hpp>
#include <xem/Vec.hpp>

namespace xem {
	template <size_t R, size_t C, typename T>
	struct Mat {
	public:
		static_assert(xem_impl::IsValidScalar<T>, "XEM: Mat component type must be an scalar (number)!");
		static_assert(R >= 2, "XEM: Mat rows must be at least 2");
		static_assert(C >= 2, "XEM: Mat columns must be at least 2");
		Vec<C, T> entries[R];


	};
}