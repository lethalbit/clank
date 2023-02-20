# SPDX-License-Identifier: Apache-2.0

library_hdrs_lex = files([
	'codepoints.hh'
])

library_srcs += files([

])

if not meson.is_subproject()
	install_headers(
		library_hdrs_lex,
		subdir: 'libclank' / 'lex'
	)
endif
