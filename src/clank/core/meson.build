# SPDX-License-Identifier: Apache-2.0

library_hdrs_core = files([
	'codepoint_range.hh',
	'lang_standards.hh',
	'source_location.hh',
])

library_srcs += files([
	'lang_standards.cc',
])

if not meson.is_subproject()
	install_headers(
		library_hdrs_core,
		subdir: 'clank' / 'core'
	)
endif
