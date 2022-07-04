// SPDX-License-Identifier: Apache-2.0
#pragma once
#if !defined(libclank_internal_utility_hh)
#define libclank_internal_utility_hh

#include <cstdint>
#include <cstddef>
#include <utility>
#include <array>

namespace libclank::internal {
	namespace {
		template<typename T, std::size_t N, std::size_t... idx>
		constexpr std::array<T, N> make_array(T (&&elems)[N], std::index_sequence<idx...>) {
			return {{elems[idx]...}};
		}
	}
	template<typename T, std::size_t N>
	constexpr std::array<T, N> make_array(T (&&elems)[N]) {
		return make_array(std::move(elems), std::make_index_sequence<N>{});
	}
}

#endif /* libclank_internal_utility_hh */
