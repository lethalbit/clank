// SPDX-License-Identifier: Apache-2.0
/* internal/enum.hh - C++ Enum utilities */
#pragma once
#if !defined(CLANK_INTERNAL_ENUM_HH)
#define CLANK_INTERNAL_ENUM_HH

#include <type_traits>

/* This is in it's own sub-namespace because for it to work you need to `using` the namespace. */
namespace clank::internal::enums {

	template<typename T>
	[[nodiscard]]
	constexpr typename std::enable_if_t<std::is_enum_v<T>, T>
	operator|(T lhs, T rhs) noexcept {
		using U = typename std::underlying_type_t<T>;
		return static_cast<T>(
			static_cast<U>(lhs) | static_cast<U>(rhs)
		);
	}

	template<typename T>
	[[nodiscard]]
	constexpr typename std::enable_if_t<std::is_enum_v<T>, T>
	operator|=(T& lhs, T rhs) noexcept {
		using U = typename std::underlying_type_t<T>;
		return lhs = static_cast<T>(
			static_cast<U>(lhs) | static_cast<U>(rhs)
		);
	}

	template<typename T>
	[[nodiscard]]
	constexpr typename std::enable_if_t<std::is_enum_v<T>, T>
	operator&(T lhs, T rhs) noexcept {
		using U = typename std::underlying_type_t<T>;
		return static_cast<T>(
			static_cast<U>(lhs) & static_cast<U>(rhs)
		);
	}

	template<typename T>
	[[nodiscard]]
	constexpr typename std::enable_if_t<std::is_enum_v<T>, T>
	operator&=(T& lhs, T rhs) noexcept {
		using U = typename std::underlying_type_t<T>;
		return lhs = static_cast<T>(
			static_cast<U>(lhs) & static_cast<U>(rhs)
		);
	}

	template<typename T>
	[[nodiscard]]
	constexpr typename std::enable_if_t<std::is_enum_v<T>, T>
	operator^(T lhs, T rhs) noexcept {
		using U = typename std::underlying_type_t<T>;
		return static_cast<T>(
			static_cast<U>(lhs) ^ static_cast<U>(rhs)
		);
	}

	template<typename T>
	[[nodiscard]]
	constexpr typename std::enable_if_t<std::is_enum_v<T>, T>
	operator^=(T& lhs, T rhs) noexcept {
		using U = typename std::underlying_type_t<T>;
		return lhs = static_cast<T>(
			static_cast<U>(lhs) ^ static_cast<U>(rhs)
		);
	}

	template<typename T>
	[[nodiscard]]
	constexpr typename std::enable_if_t<std::is_enum_v<T>, T>
	operator~(T lhs) noexcept {
		using U = typename std::underlying_type_t<T>;
		return lhs = static_cast<T>(
			~static_cast<U>(lhs)
		);
	}

	template<typename T, typename V>
	[[nodiscard]]
	constexpr typename std::enable_if_t<std::is_enum_v<T> && std::is_integral_v<V>, T>
	operator|(T lhs, V rhs) noexcept {
		using U = typename std::underlying_type_t<T>;
		return static_cast<T>(
			static_cast<U>(lhs) | rhs
		);
	}

	template<typename T, typename V>
	[[nodiscard]]
	constexpr typename std::enable_if_t<std::is_enum_v<T> && std::is_integral_v<V>, T>
	operator|=(T& lhs, V rhs) noexcept {
		using U = typename std::underlying_type_t<T>;
		return lhs = static_cast<T>(
			static_cast<U>(lhs) | rhs
		);
	}

	template<typename T, typename V>
	[[nodiscard]]
	constexpr typename std::enable_if_t<std::is_enum_v<T> && std::is_integral_v<V>, T>
	operator&(T lhs, V rhs) noexcept {
		using U = typename std::underlying_type_t<T>;
		return static_cast<T>(
			static_cast<U>(lhs) & rhs
		);
	}

	template<typename T, typename V>
	[[nodiscard]]
	constexpr typename std::enable_if_t<std::is_enum_v<T> && std::is_integral_v<V>, T>
	operator&=(T& lhs, V rhs) noexcept {
		using U = typename std::underlying_type_t<T>;
		return lhs = static_cast<T>(
			static_cast<U>(lhs) & rhs
		);
	}

	template<typename T, typename V>
	[[nodiscard]]
	constexpr typename std::enable_if_t<std::is_enum_v<T> && std::is_integral_v<V>, T>
	operator^(T lhs, V rhs) noexcept {
		using U = typename std::underlying_type_t<T>;
		return static_cast<T>(
			static_cast<U>(lhs) ^ rhs
		);
	}

	template<typename T, typename V>
	[[nodiscard]]
	constexpr typename std::enable_if_t<std::is_enum_v<T> && std::is_integral_v<V>, T>
	operator^=(T& lhs, V rhs) noexcept {
		using U = typename std::underlying_type_t<T>;
		return lhs = static_cast<T>(
			static_cast<U>(lhs) ^ rhs
		);
	}

	template<typename T, typename V>
	[[nodiscard]]
	constexpr typename std::enable_if_t<std::is_integral_v<T> && std::is_enum_v<V>, V>
	operator|(V lhs, T rhs) noexcept {
		using U = typename std::underlying_type_t<V>;
		return static_cast<T>(
			lhs | static_cast<U>(rhs)
		);
	}

	template<typename T, typename V>
	[[nodiscard]]
	constexpr typename std::enable_if_t<std::is_integral_v<T> && std::is_enum_v<V>, V>
	operator|=(V& lhs, T rhs) noexcept {
		using U = typename std::underlying_type_t<V>;
		return lhs = static_cast<T>(
			lhs | static_cast<U>(rhs)
		);
	}

	template<typename T, typename V>
	[[nodiscard]]
	constexpr typename std::enable_if_t<std::is_integral_v<T> && std::is_enum_v<V>, T>
	operator&(V lhs, T rhs) noexcept {
		using U = typename std::underlying_type_t<V>;
		return static_cast<T>(
			lhs & static_cast<U>(rhs)
		);
	}

	template<typename T, typename V>
	[[nodiscard]]
	constexpr typename std::enable_if_t<std::is_integral_v<T> && std::is_enum_v<V>, T>
	operator&=(T& lhs, T rhs) noexcept {
		using U = typename std::underlying_type_t<V>;
		return lhs = static_cast<T>(
			lhs & static_cast<U>(rhs)
		);
	}

	template<typename T, typename V>
	[[nodiscard]]
	constexpr typename std::enable_if_t<std::is_integral_v<T> && std::is_enum_v<V>, T>
	operator^(T lhs, T rhs) noexcept {
		using U = typename std::underlying_type_t<V>;
		return static_cast<T>(
			lhs ^ static_cast<U>(rhs)
		);
	}

	template<typename T, typename V>
	[[nodiscard]]
	constexpr typename std::enable_if_t<std::is_integral_v<T> && std::is_enum_v<V>, T>
	operator^=(T& lhs, T rhs) noexcept {
		using U = typename std::underlying_type_t<V>;
		return lhs = static_cast<T>(
			lhs ^ static_cast<U>(rhs)
		);
	}

}

#endif /* CLANK_INTERNAL_ENUM_HH */
