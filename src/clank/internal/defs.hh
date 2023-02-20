// SPDX-License-Identifier: Apache-2.0
#pragma once
#if !defined(CLANK_INTERNAL_DEFS_HH)
#define CLANK_INTERNAL_DEFS_HH

#if defined(_MSC_VER) && !defined(_WINDOWS)
#	define _WINDOWS 1
#endif

#ifdef _WINDOWS
#	ifdef CLANK_BUILD_INTERNAL
		// NOLINTNEXTLINE
#		define CLANK_CLS_API __declspec(dllexport)
#	else
		// NOLINTNEXTLINE
#		define CLANK_CLS_API __declspec(dllimport)
#	endif
	// NOLINTNEXTLINE
#	define CLANK_API extern CLANK_CLS_API
	// NOLINTNEXTLINE
#	define CLANK_CLS_MAYBE_API
#else
	// NOLINTNEXTLINE
#	define CLANK_CLS_API __attribute__ ((visibility("default")))
	// NOLINTNEXTLINE
#	define CLANK_CLS_MAYBE_API CLANK_CLS_API
	// NOLINTNEXTLINE
#	define CLANK_API extern CLANK_CLS_API
#endif

#if defined(__has_include)
// NOLINTNEXTLINE(cppcoreguidelines-macro-usage)
#define CLANK_HAS_INCLUDE(inc) __has_include(inc)
#else
// NOLINTNEXTLINE(cppcoreguidelines-macro-usage)
#define CLANK_HAS_INCLUDE(inc) 0
#endif

#endif /* CLANK_INTERNAL_DEFS_HH */
