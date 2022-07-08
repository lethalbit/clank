// SPDX-License-Identifier: Apache-2.0
#pragma once
#if !defined(libclank_core_lang_standards_hh)
#define libclank_core_lang_standards_hh

#include <cstdint>
#include <string_view>
#include <array>
#include <optional>


#include <libclank/internal/defs.hh>
#include <libclank/internal/enum.hh>

namespace clank::core {
	using namespace std::literals::string_view_literals;

	enum struct Language_t : std::uint8_t {
		Unkown = 0x00U,
		/* C-Like Languages */
		C         = 0x03U,
		CXX       = 0x04U,
		ObjC      = 0x05U,
		ObjCXX    = 0x06U,
		OpenCL    = 0x07U,
		OpenCLCXX = 0x08U,
	};

	enum struct LanguageFeatures_t : std::uint16_t {
		None        = 0b0000'0000'0000'0000U,
		LineComment = 0b0000'0000'0000'0010U,
		C99         = 0b0000'0000'0000'0100U,
		C11         = 0b0000'0000'0000'1000U,
		C17         = 0b0000'0000'0001'0000U,
		C2X         = 0b0000'0000'0010'0000U,
		CXX         = 0b0000'0000'0100'0000U,
		CXX11       = 0b0000'0000'1000'0000U,
		CXX14       = 0b0000'0001'0000'0000U,
		CXX17       = 0b0000'0010'0000'0000U,
		CXX20       = 0b0000'0100'0000'0000U,
		CXX2B       = 0b0000'1000'0000'0000U,
		Digraphs    = 0b0001'0000'0000'0000U,
		GNU         = 0b0010'0000'0000'0000U,
		HexFloats   = 0b0100'0000'0000'0000U,
		OpenCL      = 0b1000'0000'0000'0000U,
	};

	enum struct LanguageID_t : std::uint8_t {
		Unknown      = 0x00U,
		/* C language IDs */
		C89          = 0x01U,
		GNU89        = 0x02U,
		C94          = 0x03U,
		C99          = 0x04U,
		GNU99        = 0x05U,
		C11          = 0x06U,
		GNU11        = 0x07U,
		C17          = 0x08U,
		GNU17        = 0x09U,
		C2X          = 0x0AU,
		GNU2X        = 0x0BU,
		/* C++ Language IDs */
		CXX98        = 0x0CU,
		GNUXX98      = 0x0DU,
		CXX11        = 0x0EU,
		GNUXX11      = 0x0FU,
		CXX14        = 0x10U,
		GNUXX14      = 0x11U,
		CXX17        = 0x12U,
		GNUXX17      = 0x13U,
		CXX20        = 0x14U,
		GNUXX20      = 0x15U,
		CXX2B        = 0x16U,
		GNUXX2B      = 0x17U,
		/* OpenCL Language IDs */
		OpenCL10     = 0x18U,
		OpenCL11     = 0x19U,
		OpenCL12     = 0x1AU,
		OpenCL20     = 0x1BU,
		OpenCL30     = 0x1CU,
		/* OpenCL++ Language IDs */
		OpenCLXX10   = 0x1DU,
		OpenCLXX2021 = 0x1EU,
		/* C Aliased Language IDs */
		C90          = C89,
		GNU90        = GNU89,
		C9X          = C99,
		GNU9x        = GNU99,
		C1X          = C11,
		GNU1X        = GNU11,
		C18          = C17,
		GNU18        = GNU17,
		/* C++ Aliased Language IDs */
		CXX03        = CXX98,
		GNUXX03      = GNUXX98,
		CXX0X        = CXX11,
		GNUXX0X      = GNUXX11,
		CXX1Y        = CXX14,
		GNUXX1Y      = GNUXX14,
		CXX1Z        = CXX17,
		GNUXX1Z      = GNUXX17,
		CXX2A        = CXX20,
		GNUXX2A      = GNUXX20,
		/* OpenCL Aliased Language IDs */
		CL           = OpenCL10,
		CL11         = OpenCL11,
		CL12         = OpenCL12,
		CL20         = OpenCL20,
		CL30         = OpenCL30,
		/* OpenCL++ Aliased Language IDs */
		CLCXX       = OpenCLXX10,
		CLCXX10     = OpenCLXX10,
		CLCXX2021   = OpenCLXX2021,
	};

	using namespace clank::internal::enums;

	struct LIBCLANK_CLS_API LanguageStandard_t final {
	private:
		LanguageID_t _id;
		Language_t _lang;
		std::string_view _name;
		std::string_view _desc;
		LanguageFeatures_t _flags;

		[[nodiscard]]
		inline bool _has_flag(LanguageFeatures_t feature) const noexcept {
			return (_flags & feature) == feature;
		}

	public:
		[[nodiscard]]
		LanguageStandard_t(LanguageID_t id, Language_t lang, std::string_view name, std::string_view desc, LanguageFeatures_t flags) noexcept :
			_id{id}, _lang{lang}, _name{name}, _desc{desc}, _flags{flags} { /* NOP */ }

		[[nodiscard]]
		static std::optional<LanguageStandard_t> get_by_name(const std::string_view name) noexcept;
		[[nodiscard]]
		static std::optional<LanguageStandard_t> get_by_id(const LanguageID_t id) noexcept;

		[[nodiscard]]
		const std::string_view& name() const noexcept { return _name; }
		[[nodiscard]]
		const std::string_view& desc() const noexcept { return _desc; }
		[[nodiscard]]
		Language_t lang() const noexcept { return _lang; }
		[[nodiscard]]
		LanguageID_t id() const noexcept { return _id; }


		/* Quick checks for languages */
		[[nodiscard]]
		bool is_c() const noexcept { return _lang == Language_t::C; }
		[[nodiscard]]
		bool is_cxx() const noexcept { return _lang == Language_t::CXX; }
		[[nodiscard]]
		bool is_objc() const noexcept { return _lang == Language_t::ObjC; }
		[[nodiscard]]
		bool is_objcxx() const noexcept { return _lang == Language_t::ObjCXX; }
		[[nodiscard]]
		bool is_opencl() const noexcept { return _lang == Language_t::OpenCL; }
		[[nodiscard]]
		bool is_openclxx() const noexcept { return _lang == Language_t::OpenCLCXX; }


		/* Various checks for feature flags */
		[[nodiscard]]
		bool has_line_comments() const noexcept { return _has_flag(LanguageFeatures_t::LineComment); }
		[[nodiscard]]
		bool has_digraphs() const noexcept { return _has_flag(LanguageFeatures_t::Digraphs); }
		[[nodiscard]]
		bool has_hex_floats() const noexcept { return _has_flag(LanguageFeatures_t::HexFloats); }
		[[nodiscard]]
		bool has_gnu_extensions() const noexcept { return _has_flag(LanguageFeatures_t::GNU); }

		/* Standards checks */
		[[nodiscard]]
		bool is_c99() const noexcept { return _has_flag(LanguageFeatures_t::C99); }
		[[nodiscard]]
		bool is_c11() const noexcept { return _has_flag(LanguageFeatures_t::C11); }
		[[nodiscard]]
		bool is_c17() const noexcept { return _has_flag(LanguageFeatures_t::C17); }
		[[nodiscard]]
		bool is_c2x() const noexcept { return _has_flag(LanguageFeatures_t::C2X); }

		[[nodiscard]]
		bool is_cxx11() const noexcept { return _has_flag(LanguageFeatures_t::CXX11); }
		[[nodiscard]]
		bool is_cxx14() const noexcept { return _has_flag(LanguageFeatures_t::CXX14); }
		[[nodiscard]]
		bool is_cxx17() const noexcept { return _has_flag(LanguageFeatures_t::CXX17); }
		[[nodiscard]]
		bool is_cxx20() const noexcept { return _has_flag(LanguageFeatures_t::CXX20); }
		[[nodiscard]]
		bool is_cxx2b() const noexcept { return _has_flag(LanguageFeatures_t::CXX2B); }

	};
}

#endif /* libclank_core_lang_standards_hh */
