// SPDX-License-Identifier: Apache-2.0

#include <string_view>
#include <algorithm>
#include <optional>

#include <libclank/core/lang_standards.hh>

#include <libclank/internal/utility.hh>
#include <libclank/internal/enum.hh>

namespace libclank::core {
	using namespace std::literals::string_view_literals;
	using namespace libclank::internal::enums;

	/* This array contains instances of all supported languages and their configuration */
	const static auto Languages{
		libclank::internal::make_array<LanguageStandard_t>({
			/* C Language Definitions */
			{
				LanguageID_t::C89, Language_t::C,
				"c89"sv, "ISO C 1990"sv,
				LanguageFeatures_t::None
			},
			{
				LanguageID_t::GNU89, Language_t::C,
				"gnu89"sv, "ISO C 1990 w/ GNU extensions"sv,
				LanguageFeatures_t::LineComment |
				LanguageFeatures_t::Digraphs    |
				LanguageFeatures_t::GNU
			},
			{
				LanguageID_t::C94, Language_t::C,
				"c94"sv, "ISO C 1990 w/ amendment 1"sv,
				LanguageFeatures_t::Digraphs
			},
			{
				LanguageID_t::C99, Language_t::C,
				"c99"sv, "ISO C 1999"sv,
				LanguageFeatures_t::LineComment |
				LanguageFeatures_t::C99         |
				LanguageFeatures_t::Digraphs    |
				LanguageFeatures_t::HexFloats
			},
			{
				LanguageID_t::GNU99, Language_t::C,
				"gnu99"sv, "ISO C 1999 w/ GNU extensions"sv,
				LanguageFeatures_t::LineComment |
				LanguageFeatures_t::C99         |
				LanguageFeatures_t::Digraphs    |
				LanguageFeatures_t::HexFloats   |
				LanguageFeatures_t::GNU
			},
			{
				LanguageID_t::C11, Language_t::C,
				"c11"sv, "ISO C 2011"sv,
				LanguageFeatures_t::LineComment |
				LanguageFeatures_t::C99         |
				LanguageFeatures_t::C11         |
				LanguageFeatures_t::Digraphs    |
				LanguageFeatures_t::HexFloats
			},
			{
				LanguageID_t::GNU11, Language_t::C,
				"gnu11"sv, "ISO C 2011 w/ GNU extensions"sv,
				LanguageFeatures_t::LineComment |
				LanguageFeatures_t::C99         |
				LanguageFeatures_t::C11         |
				LanguageFeatures_t::Digraphs    |
				LanguageFeatures_t::HexFloats   |
				LanguageFeatures_t::GNU
			},
			{
				LanguageID_t::C17, Language_t::C,
				"c17"sv, "ISO C 2017"sv,
				LanguageFeatures_t::LineComment |
				LanguageFeatures_t::C99         |
				LanguageFeatures_t::C11         |
				LanguageFeatures_t::C17         |
				LanguageFeatures_t::Digraphs    |
				LanguageFeatures_t::HexFloats
			},
			{
				LanguageID_t::GNU17, Language_t::C,
				"gnu17"sv, "ISO C 2017 w/ GNU extensions"sv,
				LanguageFeatures_t::LineComment |
				LanguageFeatures_t::C99         |
				LanguageFeatures_t::C11         |
				LanguageFeatures_t::C17         |
				LanguageFeatures_t::Digraphs    |
				LanguageFeatures_t::HexFloats   |
				LanguageFeatures_t::GNU
			},
			{
				LanguageID_t::C2X, Language_t::C,
				"c2x"sv, "Working Draft for ISO C2X"sv,
				LanguageFeatures_t::LineComment |
				LanguageFeatures_t::C99         |
				LanguageFeatures_t::C11         |
				LanguageFeatures_t::C17         |
				LanguageFeatures_t::C2X         |
				LanguageFeatures_t::Digraphs    |
				LanguageFeatures_t::HexFloats
			},
			{
				LanguageID_t::GNU2X, Language_t::C,
				"gnu2x"sv, "Working Draft for ISO C2x w/ GNU extensions"sv,
				LanguageFeatures_t::LineComment |
				LanguageFeatures_t::C99         |
				LanguageFeatures_t::C11         |
				LanguageFeatures_t::C17         |
				LanguageFeatures_t::C2X         |
				LanguageFeatures_t::Digraphs    |
				LanguageFeatures_t::HexFloats   |
				LanguageFeatures_t::GNU
			},
			/* C++ Language Definitions */
			{
				LanguageID_t::CXX98, Language_t::CXX,
				"c++98"sv, "ISO C++ 1998 w/ amendments"sv,
				LanguageFeatures_t::LineComment |
				LanguageFeatures_t::CXX         |
				LanguageFeatures_t::Digraphs
			},
			{
				LanguageID_t::GNUXX98, Language_t::CXX,
				"gnu++98"sv, "ISO C++ 1998 w/ amendments and GNU extensions"sv,
				LanguageFeatures_t::LineComment |
				LanguageFeatures_t::CXX         |
				LanguageFeatures_t::Digraphs    |
				LanguageFeatures_t::GNU
			},
			{
				LanguageID_t::CXX11, Language_t::CXX,
				"c++11"sv, "ISO C++ 2011 w/ amendments"sv,
				LanguageFeatures_t::LineComment |
				LanguageFeatures_t::CXX         |
				LanguageFeatures_t::CXX11       |
				LanguageFeatures_t::Digraphs
			},
			{
				LanguageID_t::GNUXX11, Language_t::CXX,
				"gnu++11"sv, "ISO C++ 2011 w/ amendments and GNU extensions"sv,
				LanguageFeatures_t::LineComment |
				LanguageFeatures_t::CXX         |
				LanguageFeatures_t::CXX11       |
				LanguageFeatures_t::Digraphs    |
				LanguageFeatures_t::GNU
			},
			{
				LanguageID_t::CXX14, Language_t::CXX,
				"c++14"sv, "ISO C++ 2014 w/ amendments"sv,
				LanguageFeatures_t::LineComment |
				LanguageFeatures_t::CXX         |
				LanguageFeatures_t::CXX11       |
				LanguageFeatures_t::CXX14       |
				LanguageFeatures_t::Digraphs
			},
			{
				LanguageID_t::GNUXX14, Language_t::CXX,
				"gnu++14"sv, "ISO C++ 2014 w/ amendments and GNU extensions"sv,
				LanguageFeatures_t::LineComment |
				LanguageFeatures_t::CXX         |
				LanguageFeatures_t::CXX11       |
				LanguageFeatures_t::CXX14       |
				LanguageFeatures_t::Digraphs    |
				LanguageFeatures_t::GNU
			},
			{
				LanguageID_t::CXX17, Language_t::CXX,
				"c++17"sv, "ISO C++ 2017 w/ amendments"sv,
				LanguageFeatures_t::LineComment |
				LanguageFeatures_t::CXX         |
				LanguageFeatures_t::CXX11       |
				LanguageFeatures_t::CXX14       |
				LanguageFeatures_t::CXX17       |
				LanguageFeatures_t::Digraphs    |
				LanguageFeatures_t::HexFloats
			},
			{
				LanguageID_t::GNUXX17, Language_t::CXX,
				"gnu++17"sv, "ISO C++ 2017 w/ amendments and GNU extensions"sv,
				LanguageFeatures_t::LineComment |
				LanguageFeatures_t::CXX         |
				LanguageFeatures_t::CXX11       |
				LanguageFeatures_t::CXX14       |
				LanguageFeatures_t::CXX17       |
				LanguageFeatures_t::Digraphs    |
				LanguageFeatures_t::HexFloats   |
				LanguageFeatures_t::GNU
			},
			{
				LanguageID_t::CXX20, Language_t::CXX,
				"c++20"sv, "ISO C++ 2020 DIS"sv,
				LanguageFeatures_t::LineComment |
				LanguageFeatures_t::CXX         |
				LanguageFeatures_t::CXX11       |
				LanguageFeatures_t::CXX14       |
				LanguageFeatures_t::CXX17       |
				LanguageFeatures_t::CXX20       |
				LanguageFeatures_t::Digraphs    |
				LanguageFeatures_t::HexFloats
			},
			{
				LanguageID_t::GNUXX20, Language_t::CXX,
				"gnu++20"sv, "ISO C++ 2020 DIS w/ GNU extensions"sv,
				LanguageFeatures_t::LineComment |
				LanguageFeatures_t::CXX         |
				LanguageFeatures_t::CXX11       |
				LanguageFeatures_t::CXX14       |
				LanguageFeatures_t::CXX17       |
				LanguageFeatures_t::CXX20       |
				LanguageFeatures_t::Digraphs    |
				LanguageFeatures_t::HexFloats   |
				LanguageFeatures_t::GNU
			},
			{
				LanguageID_t::CXX2B, Language_t::CXX,
				"c++2b"sv, "Working draft for ISO C++ 2023 DIS"sv,
				LanguageFeatures_t::LineComment |
				LanguageFeatures_t::CXX         |
				LanguageFeatures_t::CXX11       |
				LanguageFeatures_t::CXX14       |
				LanguageFeatures_t::CXX17       |
				LanguageFeatures_t::CXX20       |
				LanguageFeatures_t::CXX2B       |
				LanguageFeatures_t::Digraphs    |
				LanguageFeatures_t::HexFloats
			},
			{
				LanguageID_t::GNUXX2B, Language_t::CXX,
				"gnu++2b"sv, "Working draft for ISO C++ 2023 DIS w/ GNU extensions"sv,
				LanguageFeatures_t::LineComment |
				LanguageFeatures_t::CXX         |
				LanguageFeatures_t::CXX11       |
				LanguageFeatures_t::CXX14       |
				LanguageFeatures_t::CXX17       |
				LanguageFeatures_t::CXX20       |
				LanguageFeatures_t::CXX2B       |
				LanguageFeatures_t::Digraphs    |
				LanguageFeatures_t::HexFloats   |
				LanguageFeatures_t::GNU
			},
			/* OpenCL Language Definitions */
			{
				LanguageID_t::OpenCL10, Language_t::OpenCL,
				"cl1.0"sv, "OpenCL 1.0"sv,
				LanguageFeatures_t::LineComment |
				LanguageFeatures_t::C99         |
				LanguageFeatures_t::Digraphs    |
				LanguageFeatures_t::HexFloats   |
				LanguageFeatures_t::OpenCL
			},
			{
				LanguageID_t::OpenCL11, Language_t::OpenCL,
				"cl1.1"sv, "OpenCL 1.1"sv,
				LanguageFeatures_t::LineComment |
				LanguageFeatures_t::C99         |
				LanguageFeatures_t::Digraphs    |
				LanguageFeatures_t::HexFloats   |
				LanguageFeatures_t::OpenCL
			},
			{
				LanguageID_t::OpenCL12, Language_t::OpenCL,
				"cl1.2"sv, "OpenCL 1.2"sv,
				LanguageFeatures_t::LineComment |
				LanguageFeatures_t::C99         |
				LanguageFeatures_t::Digraphs    |
				LanguageFeatures_t::HexFloats   |
				LanguageFeatures_t::OpenCL
			},
			{
				LanguageID_t::OpenCL20, Language_t::OpenCL,
				"cl2.0"sv, "OpenCL 2.0"sv,
				LanguageFeatures_t::LineComment |
				LanguageFeatures_t::C99         |
				LanguageFeatures_t::Digraphs    |
				LanguageFeatures_t::HexFloats   |
				LanguageFeatures_t::OpenCL
			},
			{
				LanguageID_t::OpenCL30, Language_t::OpenCL,
				"cl3.0"sv, "OpenCL 3.0"sv,
				LanguageFeatures_t::LineComment |
				LanguageFeatures_t::C99         |
				LanguageFeatures_t::Digraphs    |
				LanguageFeatures_t::HexFloats   |
				LanguageFeatures_t::OpenCL
			},
			/* OpenCL++ Language Definitions */
			{
				LanguageID_t::OpenCLXX10, Language_t::OpenCL,
				"clc++1.0"sv, "C++ for OpenCL 1.0"sv,
				LanguageFeatures_t::LineComment |
				LanguageFeatures_t::CXX         |
				LanguageFeatures_t::CXX11       |
				LanguageFeatures_t::CXX14       |
				LanguageFeatures_t::CXX17       |
				LanguageFeatures_t::Digraphs    |
				LanguageFeatures_t::HexFloats   |
				LanguageFeatures_t::OpenCL
			},
			{
				LanguageID_t::OpenCLXX2021, Language_t::OpenCL,
				"clc++2021"sv, "C++ for OpenCL 2021"sv,
				LanguageFeatures_t::LineComment |
				LanguageFeatures_t::CXX         |
				LanguageFeatures_t::CXX11       |
				LanguageFeatures_t::CXX14       |
				LanguageFeatures_t::CXX17       |
				LanguageFeatures_t::Digraphs    |
				LanguageFeatures_t::HexFloats   |
				LanguageFeatures_t::OpenCL
			}
		})
	};

	[[nodiscard]]
	std::optional<LanguageStandard_t> LanguageStandard_t::get_by_name(const std::string_view name) noexcept {
		auto res = std::find_if(Languages.begin(), Languages.end(), [&name](const LanguageStandard_t lang) {
			return lang.name() == name;
		});

		if (res != Languages.end()) {
			return std::make_optional(*res);
		}
		return std::nullopt;
	}

}
