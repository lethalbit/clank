// SPDX-License-Identifier: Apache-2.0
#pragma once
#if !defined(libclank_internal_defs_hh)
#define libclank_internal_defs_hh

#if defined(_MSC_VER) && !defined(_WINDOWS)
#	define _WINDOWS 1
#endif

#ifdef _WINDOWS
#	ifdef LIBCLANK_BUILD_INTERNAL
		// NOLINTNEXTLINE
#		define LIBCLANK_CLS_API __declspec(dllexport)
#	else
		// NOLINTNEXTLINE
#		define LIBCLANK_CLS_API __declspec(dllimport)
#	endif
	// NOLINTNEXTLINE
#	define LIBCLANK_API extern LIBCLANK_CLS_API
	// NOLINTNEXTLINE
#	define LIBCLANK_CLS_MAYBE_API
#else
	// NOLINTNEXTLINE
#	define LIBCLANK_CLS_API __attribute__ ((visibility("default")))
	// NOLINTNEXTLINE
#	define LIBCLANK_CLS_MAYBE_API LIBCLANK_CLS_API
	// NOLINTNEXTLINE
#	define LIBCLANK_API extern LIBCLANK_CLS_API
#endif

#if defined(__has_include)
#define LIBCLANK_HAS_INCLUDE(inc) __has_include(inc)
#else
#define LIBCLANK_HAS_INCLUDE(inc) 0
#endif

#endif /* libclank_internal_defs_hh */
