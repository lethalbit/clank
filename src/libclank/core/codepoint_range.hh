// SPDX-License-Identifier: Apache-2.0
#pragma once
#if !defined(CLANK_CORE_CODEPOINT_RANGE_HH)
#define CLANK_CORE_CODEPOINT_RANGE_HH

#include <cstdint>

namespace clank::core {
	struct CodepointRange_t final {
	private:
		std::uint32_t _lower;
		std::uint32_t _upper;
	public:
		// NOLINTNEXTLINE(bugprone-easily-swappable-parameters)
		constexpr CodepointRange_t(std::uint32_t lower, std::uint32_t upper) noexcept :
			_lower{lower}, _upper{upper} { /* */ }

		inline bool operator<(std::uint32_t value) const noexcept {
			return value < _lower;
		}

		inline bool operator>(std::uint32_t value) const noexcept {
			return value > _upper;
		}
	};
}

#endif /* CLANK_CORE_CODEPOINT_RANGE_HH */
