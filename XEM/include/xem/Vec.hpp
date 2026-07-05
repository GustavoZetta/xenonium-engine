#pragma once

#include <cmath>
#include <type_traits>
#include <utility>

#include <xem/Qualifier.hpp>

namespace xem {
	template <size_t N, typename T>
	struct Vec {
    public:
		static_assert(xem_impl::IsValidScalar<T>, "XEM: Vec component type must be an scalar (number)!");
        static_assert(N >= 2, "XEM: Vec dimension must be at least 2");
		T components[N];

    public:
        Vec() : components{} {}

        explicit Vec(T scalar) : Vec(scalar, std::make_index_sequence<N>{}) {}

        template <typename... Args, typename = std::enable_if_t<sizeof...(Args) == N>>
        explicit Vec(Args&&... args) : components{ static_cast<T>(std::forward<Args>(args))... } {}

        // Arithmetic operators
        // Vec
        inline Vec<N, T> operator+(const Vec<N, T>& other) const {
            return AdditionImpl(*this, other, std::make_index_sequence<N>{});
        }
        
        inline Vec<N, T> operator-(const Vec<N, T>& other) const {
            return SubtractionImpl(*this, other, std::make_index_sequence<N>{});
        }

        // Scalars
        inline Vec<N, T> operator+(const T& scalar) const {
            return AdditionImpl(*this, scalar, std::make_index_sequence<N>{});
        }

        inline Vec<N, T> operator-(const T& scalar) const {
            return SubtractionImpl(*this, scalar, std::make_index_sequence<N>{});
        }

        inline Vec<N, T> operator*(const T& scalar) const {
            return MultiplicationImpl(*this, scalar, std::make_index_sequence<N>{});
        }

        inline Vec<N, T> operator/(const T& scalar) const {
            return DivisionImpl(*this, scalar, std::make_index_sequence<N>{});
        }

        // Arithmetic Assignment operators
        // Vec
        inline Vec<N, T>& operator+=(const Vec<N, T>& other) {
            AdditionAssignImpl(other, std::make_index_sequence<N>{});
            return *this;
        }

        inline Vec<N, T>& operator-=(const Vec<N, T>& other) {
            SubtractionAssignImpl(other, std::make_index_sequence<N>{});
            return *this;
        }

        // Scalars
        inline Vec<N, T>& operator+=(const T& scalar) {
            AdditionAssignImpl(scalar, std::make_index_sequence<N>{});
            return *this;
        }

        inline Vec<N, T>& operator-=(const T& scalar) {
            SubtractionAssignImpl(scalar, std::make_index_sequence<N>{});
            return *this;
        }

        inline Vec<N, T>& operator*=(const T& scalar) {
            MultiplicationAssignImpl(scalar, std::make_index_sequence<N>{});
            return *this;
        }

        inline Vec<N, T>& operator/=(const T& scalar) {
            DivisionAssignImpl(scalar, std::make_index_sequence<N>{});
            return *this;
        }

        // Component Selection
        inline T& operator[](size_t index) {
            return components[index];
        }

        inline T operator[](size_t index) const {
            return components[index];
        }

        // References to component
        // XYZW
        inline T& X() {
            return components[0];
        }

        inline T& Y() {
            return components[1];
        }

        inline T& Z() {
            static_assert(N >= 3, "XEM: Vec must have at least 3 components to access Z()");
            return components[2];
        }

        inline T& W() {
            static_assert(N >= 4, "XEM: Vec must have at least 4 components to access W()");
            return components[3];
        }

        // RGBA
        inline T& R() {
            static_assert(N >= 3, "XEM: Vec must have at least 3 components to access R()");
            return components[0];
        }

        inline T& G() {
            static_assert(N >= 3, "XEM: Vec must have at least 3 components to access G()");
            return components[1];
        }

        inline T& B() {
            static_assert(N >= 3, "XEM: Vec must have at least 3 components to access B()");
            return components[2];
        }

        inline T& A() {
            static_assert(N >= 4, "XEM: Vec must have at least 4 components to access A()");
            return components[3];
        }

        // Copy component
        // XYZW
        inline T X() const {
            return components[0];
        }

        inline T Y() const {
            return components[1];
        }

        inline T Z() const {
            static_assert(N >= 3, "XEM: Vec must have at least 3 components to access Z()");
            return components[2];
        }

        inline T W() const {
            static_assert(N >= 4, "XEM: Vec must have at least 4 components to access W()");
            return components[3];
        }

        // RGBA
        inline T R() const {
            static_assert(N >= 3, "XEM: Vec must have at least 3 components to access R()");
            return components[0];
        }

        inline T G() const {
            static_assert(N >= 3, "XEM: Vec must have at least 3 components to access G()");
            return components[1];
        }

        inline T B() const {
            static_assert(N >= 3, "XEM: Vec must have at least 3 components to access B()");
            return components[2];
        }

        inline T A() const {
            static_assert(N >= 4, "XEM: Vec must have at least 4 components to access A()");
            return components[3];
        }

        // Math Logic
        inline T Length() const {
            return std::sqrt(SquaredLength());
        }

        inline T SquaredLength() const {
            return SquaredLengthImpl(std::make_index_sequence<N>{});
        }
    private:
        template <size_t... Is>
        constexpr Vec(T scalar, std::index_sequence<Is...>) : components{ ((void)Is, scalar)... } {}

        template <size_t... Is>
        inline T SquaredLengthImpl(std::index_sequence<Is...>) const {
            return (... + (components[Is] * components[Is]));
        }

        // Arithmetic Copy
        // Vec
        template <size_t... Is>
        inline xem::Vec<N, T> AdditionImpl(const xem::Vec<N, T>& vec1, const xem::Vec<N, T>& vec2, std::index_sequence<Is...>) const {
            return xem::Vec<N, T>{ (vec1.components[Is] + vec2.components[Is])... };
        }

        template <size_t... Is>
        inline xem::Vec<N, T> SubtractionImpl(const xem::Vec<N, T>& vec1, const xem::Vec<N, T>& vec2, std::index_sequence<Is...>) const {
            return xem::Vec<N, T>{ (vec1.components[Is] - vec2.components[Is])... };
        }

        // Scalar
        template <size_t... Is>
        inline xem::Vec<N, T> AdditionImpl(const xem::Vec<N, T>& vec, const T& scalar, std::index_sequence<Is...>) const {
            return xem::Vec<N, T>{ (vec.components[Is] + scalar)... };
        }

        template <size_t... Is>
        inline xem::Vec<N, T> SubtractionImpl(const xem::Vec<N, T>& vec, const T& scalar, std::index_sequence<Is...>) const {
            return xem::Vec<N, T>{ (vec.components[Is] - scalar)... };
        }

        template <size_t... Is>
        inline xem::Vec<N, T> MultiplicationImpl(const xem::Vec<N, T>& vec, const T& scalar, std::index_sequence<Is...>) const {
            return xem::Vec<N, T>{ (vec.components[Is] * scalar)... };
        }

        template <size_t... Is>
        inline xem::Vec<N, T> DivisionImpl(const xem::Vec<N, T>& vec, const T& scalar, std::index_sequence<Is...>) const {
            return xem::Vec<N, T>{ (vec.components[Is] / scalar)... };
        }

        // Arithmetic Assignment operators
        // Vec
        template <size_t... Is>
        inline void AdditionAssignImpl(const Vec<N, T>& other, std::index_sequence<Is...>) {
            ((components[Is] += other.components[Is]), ...);
        }

        template <size_t... Is>
        inline void SubtractionAssignImpl(const Vec<N, T>& other, std::index_sequence<Is...>) {
            ((components[Is] -= other.components[Is]), ...);
        }

        // Scalar
        template <size_t... Is>
        inline void AdditionAssignImpl(const T& scalar, std::index_sequence<Is...>) {
            ((components[Is] += scalar), ...);
        }

        template <size_t... Is>
        inline void SubtractionAssignImpl(const T& scalar, std::index_sequence<Is...>) {
            ((components[Is] -= scalar), ...);
        }

        template <size_t... Is>
        inline void MultiplicationAssignImpl(const T& scalar, std::index_sequence<Is...>) {
            ((components[Is] *= scalar), ...);
        }

        template <size_t... Is>
        inline void DivisionAssignImpl(const T& scalar, std::index_sequence<Is...>) {
            ((components[Is] /= scalar), ...);
        }
	};
}
