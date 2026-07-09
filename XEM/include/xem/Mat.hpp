#pragma once

#include <xem/Qualifier.hpp>
#include <xem/Vec.hpp>
#include <xem/VecMath.hpp>

namespace xem {
    // M for rows
    // N for columns
    template <size_t M, size_t N, typename T>
    struct Mat {
    public:
        static_assert(xem_impl::IsValidScalar<T>, "XEM: Mat component type must be an scalar (number)!");
        static_assert(M >= 2, "XEM: Mat rows must be at least 2");
        static_assert(N >= 2, "XEM: Mat columns must be at least 2");
        Vec<M, T> entries[N];

        Mat() {}

        // Fill EVERY component (all M*N of them) with the same scalar
        explicit constexpr Mat(T scalar) : Mat(scalar, std::make_index_sequence<N>{}) {}

        // Build from M*N flat scalars, consumed in order: the first M values
        // fill entries[0], the next M fill entries[1], ..., the last M fill entries[N-1].
        // (typename = void at the end for differing from the constructor that takes N vectors)
        template <typename... Args, typename = std::enable_if_t<sizeof...(Args) == (M * N)>, typename = void>
        explicit constexpr Mat(Args&&... args) : Mat(std::array<T, M * N>{ static_cast<T>(std::forward<Args>(args))... }, std::make_index_sequence<N>{}) {}

        // Takes in N vectors (Each one is an column)
        template <typename... Args, typename = std::enable_if_t<sizeof...(Args) == N>>
        explicit constexpr Mat(Args&&... args) : entries{ static_cast<Vec<M, T>>(std::forward<Args>(args))... } {}

        // Mat<M, N, T> * Mat<N, P, T>
        template <size_t P>
        inline Mat<M, P, T> operator*(const Mat<N, P, T>& other) const {
            return MatMultiplicationImpl(*this, other, std::make_index_sequence<P>);
        }

        // Mat<M, N, T> * Vec<M, T>
        inline Vec<M, T> operator*(const Vec<M, T>& vec) const {
            return VecMultiplicationImpl(*this, vec, std::make_index_sequence<M>);
        }

        // Mat<M, N, T> * T
        inline Mat<M, N, T> operator*(const T& scalar) const {
            return ScalarMultiplicationImpl(*this, scalar, std::make_index_sequence<N>);
        }
    private:
        template <size_t... Cs>
        constexpr Mat(T scalar, std::index_sequence<Cs...>) : entries{ ((void)Cs, Vec<M, T>(scalar))... } {}

        // Builds one column (M values starting at flat[C*M]) for the flat constructor
        template <size_t C, size_t... Ns>
        static constexpr Vec<M, T> BuildColumn(const std::array<T, M * N>& flat, std::index_sequence<Ns...>) {
            return Vec<M, T>(flat[C * M + Ns]...);
        }

        // Delegate for the flat M*N-scalar constructor
        template <size_t... Ns>
        constexpr Mat(const std::array<T, M * N>& flat, std::index_sequence<Cs...>) : entries{ BuildColumn<Ns>(flat, std::make_index_sequence<M>{})... } {}

        // Other N sequence
        template <size_t P, size_t... ONs>
        inline Mat<M, P, T> MatMultiplicationImpl(const Mat<M, N, T>& mat1, const Mat<N, P, T>& mat2, std::index_sequence<ONs...>) const {
            return Mat<M, P, T>((mat1 * mat2.entries[ONs])...);
        }

        template <size_t... Ns>
        inline Mat<M, N, T> ScalarMultiplicationImpl(const Mat<M, N, T>& mat, const T scalar, std::index_sequence<Ns...>) const {
            return Mat<M, N, T>(mat.entries[Ns] * scalar...);
        }

        template <size_t... Ns>
        inline Vec<M, T> VecMultiplicationImpl(const Mat<M, N, T>& mat1, const Vec<N, T>& vec, std::index_sequence<Ns...>) const {
            return (... + (mat1.entries[Ns] * vec.components[Ns]));
        }
    };
}
