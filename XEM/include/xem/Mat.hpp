#pragma once

#include <xem/Qualifier.hpp>
#include <xem/Vec.hpp>

namespace xem {
	template <size_t M, size_t N, typename T>
	struct Mat {
	public:
		static_assert(xem_impl::IsValidScalar<T>, "XEM: Mat component type must be an scalar (number)!");
		static_assert(M >= 2, "XEM: Mat rows must be at least 2");
		static_assert(N >= 2, "XEM: Mat columns must be at least 2");
		Vec<M, T> entries[N];

		Mat() {}

		template <typename... Args, typename = std::enable_if_t<sizeof...(Args) == (M * N)>>
		explicit Mat(Args&&... args) : entries{ static_cast<T>(std::forward<Args>(args))... } {}

		inline Vec<M, T> operator*(const Vec<M, T>& vec) {
			
		}
	private:
		template<size_t... Is>
		inline Mat<M, N, T> VectorMultiplicationImpl(const Vec<M, T>& vec, std::index_sequence<Is...>) {
			return ()
		}
	};
}