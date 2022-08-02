// SPDX-License-Identifier: Apache-2.0
#pragma once
#if !defined(libclank_internal_unicode_range_hh)
#define libclank_internal_unicode_range_hh

#include <cstdint>

namespace clank::internal {
	struct UnicodeRange_t final {
	private:
		std::uint32_t _low;
		std::uint32_t _high;
	public:
		// NOLINTNEXTLINE(bugprone-easily-swappable-parameters)
		constexpr UnicodeRange_t(std::uint32_t low, std::uint32_t high) noexcept :
			_low{low}, _high{high} { /* */ }

		inline bool operator<(std::uint32_t val) const noexcept {
			return val < _low;
		}

		inline bool operator>(std::uint32_t val) const noexcept {
			return val > _high;
		}
	};
}

#endif /* libclank_internal_unicode_range_hh */
