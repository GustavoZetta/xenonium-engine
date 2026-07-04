#pragma once

#include <cmath>
#include <type_traits>
#include <utility>

#include "Qualifier.hpp"

namespace XEM {
	template <size_t N, typename T>
	struct Vec {
    public:
		static_assert(IsValidScalar<T>);
		T components[N];

        inline T length() const {
            return std::sqrt(squaredLength());
        }

        inline T squaredLength() const {
            return squaredLengthImpl(std::make_index_sequence<N>{});
        }
    private:
        template <size_t... Is>
        inline T squaredLengthImpl(std::index_sequence<Is...>) const {
            return (... + (components[Is] * components[Is]));
        }
	};
}
