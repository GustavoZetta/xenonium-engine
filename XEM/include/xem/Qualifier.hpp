#pragma once

#include <cmath>
#include <type_traits>

namespace xem {
    template <typename T, typename = void>
    struct ValidScalar : std::false_type {};

    // Specialization: only matches if ALL expressions below are well-formed
    template <typename T>
    struct ValidScalar < T, std::void_t<
        // basic arithmetic
        decltype(std::declval<T>() + std::declval<T>()),
        decltype(std::declval<T>() - std::declval<T>()),
        decltype(std::declval<T>() * std::declval<T>()),
        decltype(std::declval<T>() / std::declval<T>()),
        decltype(-std::declval<T>()), 

        // compound assignment (needs an lvalue, hence declval<T&>)
        decltype(std::declval<T&>() += std::declval<T>()),
        decltype(std::declval<T&>() -= std::declval<T>()),
        decltype(std::declval<T&>() *= std::declval<T>()),
        decltype(std::declval<T&>() /= std::declval<T>()),

        // comparisons
        decltype(std::declval<T>() == std::declval<T>()),
        decltype(std::declval<T>() != std::declval<T>()),
        decltype(std::declval<T>() < std::declval<T>()),
        decltype(std::declval<T>() > std::declval<T>()),
        decltype(std::declval<T>() <= std::declval<T>()),
        decltype(std::declval<T>() >= std::declval<T>()),

        // math functions used by Vec (length, normalize, etc.)
        decltype(std::sqrt(std::declval<T>())),

        // basic object semantics needed to store T inside Vec<T>
        std::enable_if_t<std::is_default_constructible_v<T>>,
        std::enable_if_t<std::is_copy_constructible_v<T>>
    >> : std::true_type{};

    template <typename T>
    inline constexpr bool IsValidScalar = ValidScalar<T>::value;
}