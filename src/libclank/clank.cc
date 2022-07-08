// SPDX-License-Identifier: Apache-2.0
/* clank.cc - Impl for the main parsing endpoints */

#include <libclank/internal/expected.hh>

#include <libclank/clank.hh>

#include <filesystem>
#include <string>
#include <string_view>
#include <cstdint>

namespace clank {
	using clank::internal::expected;

	/* Parse from std::string */
	[[nodiscard]]
	expected<void, std::int16_t> parse(const std::string& src, const clank::core::LanguageStandard_t& lang) {
		return {};
	}

	/* Parse from std::string_view */
	[[nodiscard]]
	expected<void, std::int16_t> parse(const std::string_view& src, const clank::core::LanguageStandard_t& lang) {
		return {};
	}

	/* Parse from a file on disk */
	[[nodiscard]]
	expected<void, std::int16_t> parse(const std::filesystem::path path, const clank::core::LanguageStandard_t& lang) {
		return {};
	}

	/* Parse from an open file descriptor */
	[[nodiscard]]
	expected<void, std::int16_t> parse(const std::int32_t fd, const clank::core::LanguageStandard_t& lang) {
		return {};
	}
}
