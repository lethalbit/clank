# SPDX-License-Identifier: Apache-2.0

library_hdrs_internal = files([
	'defs.hh',
	'enum.hh',
	'utility.hh',
])

library_srcs += files([

])

if not meson.is_subproject()
	install_headers(
		library_hdrs_internal,
		subdir: 'libclank' / 'internal'
	)
endif
