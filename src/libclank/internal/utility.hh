// SPDX-License-Identifier: Apache-2.0
#pragma once
#if !defined(CLANK_INTERNAL_UTILITY_HH)
#define CLANK_INTERNAL_UTILITY_HH

#include <cstdint>
#include <cstddef>
#include <utility>
#include <array>

namespace clank::internal {
	inline namespace impl {
		template<typename T, std::size_t N, std::size_t... idx>
		// NOLINTNEXTLINE(cppcoreguidelines-avoid-c-arrays,modernize-avoid-c-arrays)
		constexpr std::array<T, N> make_array(T (&&elems)[N], std::index_sequence<idx...>) noexcept {
			return {{elems[idx]...}};
		}
	}
	template<typename T, std::size_t N>
	// NOLINTNEXTLINE(cppcoreguidelines-avoid-c-arrays,modernize-avoid-c-arrays)
	constexpr std::array<T, N> make_array(T (&&elems)[N]) noexcept {
		return impl::make_array(std::move(elems), std::make_index_sequence<N>{});
	}
}

#endif /* CLANK_INTERNAL_UTILITY_HH */
