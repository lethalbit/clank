# SPDX-License-Identifier: Apache-2.0
# FindClank.cmake - Cmake find module for Clank

set(CLANK_SEARCH_PATHS
	~/Library/Frameworks
	/Library/Frameworks
	/usr
	/usr/local
	/opt
	/opt/local

	${CLANK_PATH}
)

find_path(CLANK_INCLUDE_DIR
	clank.hh
	HINTS
	$ENV{CLANKDIR}
	PATH_SUFFIXES include/libclank include
	PATHS ${CLANK_SEARCH_PATHS}
)

find_library(
	CLANK_LIBRARY
	NAME clank
	HINTS
	$ENV{CLANKDIR}
	PATH_SUFFIXES lib64 lib
	PATHS ${SDL2_SEARCH_PATHS}
)
