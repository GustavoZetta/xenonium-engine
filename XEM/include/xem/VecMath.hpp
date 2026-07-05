#pragma once

#include <xem/General.hpp>

#include <xem/Vec.hpp>

namespace xem_impl {
    template <size_t N, typename T, size_t... Is>
    inline xem::Vec<N, T> NormalizeImpl(const xem::Vec<N, T>& vec, T len, std::index_sequence<Is...>) {
        return xem::Vec<N, T>{ (vec.components[Is] / len)... };
    }

    template <size_t N, typename T, size_t... Is>
    inline T DotProductImpl(const xem::Vec<N, T>& vec1, const xem::Vec<N, T>& vec2, std::index_sequence<Is...>) {
        return (... + (vec1.components[Is] * vec2.components[Is]));
    }
}

namespace xem {
    template <size_t N, typename T>
    inline Vec<N, T> Normalize(const Vec<N, T>& vec) {
        T len = vec.Length();
        return len == 0.0 ? Vec<N, T>(0.0) : xem_impl::NormalizeImpl(vec, len, std::make_index_sequence<N>{});
    }

    template <size_t N, typename T>
    inline T DotProduct(const Vec<N, T>& vec1, const Vec<N, T>& vec2) {
        return xem_impl::DotProductImpl(vec1, vec2, std::make_index_sequence<N>{});
    }

    template <typename T>
    inline Vec<3, T> CrossProduct(const Vec<3, T>& vec1, const Vec<3, T>& vec2) {
        return Vec<3, T>(
            vec1.Y() * vec2.Z() - vec1.Z() * vec2.Y(),
            vec1.Z() * vec2.X() - vec1.X() * vec2.Z(),
            vec1.X() * vec2.Y() - vec1.Y() * vec2.X()
        );
    }

    template <size_t N, typename T>
    inline Vec<N, T> Lerp(const Vec<N, T>& a, const Vec<N, T>& b, const T& t) {
        return a + (b - a) * t;
    }

    template <size_t N, typename T>
    inline Vec<N, T> PreciseLerp(const Vec<N, T>& a, const Vec<N, T>& b, const T& t) {
        return a * (T(1) - t) + b * t;
    }
}