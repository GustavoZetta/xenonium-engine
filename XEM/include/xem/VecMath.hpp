#pragma once

#include <xem/Vec.hpp>

#include <cassert>

namespace xem_impl {
    template <size_t N, typename T, size_t... Is>
    inline xem::Vec<N, T> NormalizeImpl(const xem::Vec<N, T>& vec, T len, std::index_sequence<Is...>) {
        return xem::Vec<N, T>{ (vec.components[Is] / len)... };
    }
}

namespace xem {
    template <size_t N, typename T>
    inline Vec<N, T> Normalize(const Vec<N, T>& vec) {
        T len = vec.Length();
        assert(len != 0.0 && "XEM: Cannot normalize a zero-length vector");
        return xem_impl::NormalizeImpl(vec, len, std::make_index_sequence<N>{});
    }
}