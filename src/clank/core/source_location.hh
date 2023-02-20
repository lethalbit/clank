// SPDX-License-Identifier: Apache-2.0
#pragma once
#if !defined(CLANK_CORE_SOURCE_LOCATION_HH)
#define CLANK_CORE_SOURCE_LOCATION_HH

#include <limits>
#include <cstdint>

namespace clank::core {

	struct SourceLocation_t final {
	private:
		std::uint64_t _id{};
		constexpr static auto _macro_bit{decltype(_id)(1ULL << (8 * sizeof(decltype(_id)) - 1))};
	public:
		[[nodiscard]]
		bool is_file() const { return !is_macro(); }
		[[nodiscard]]
		bool is_macro() const { return (_id & SourceLocation_t::_macro_bit) == SourceLocation_t::_macro_bit; }

	};
}

#endif /* CLANK_CORE_SOURCE_LOCATION_HH */
