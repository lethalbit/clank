# SPDX-License-Identifier: Apache-2.0

library_hdrs_core = files([
	'lang_standards.hh',
])

library_srcs += files([
	'lang_standards.cc',
])

if not meson.is_subproject()
	install_headers(
		library_hdrs_core,
		subdir: 'libclank' / 'core'
	)
endif
