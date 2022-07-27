# SPDX-License-Identifier: Apache-2.0

library_inc  = include_directories('.')


enable_logging = get_option('debug') and not get_option('disable_logging')

if enable_logging

	sawmill = dependency('sawmill',  required: false, version: '>=2.7.0')
	if not sawmill.found()
		message('Did not find local sawmill install, bundling')
		sawmill_wrap = subproject('sawmill', default_options: [])
		sawmill = sawmill_wrap.get_variable('sawmill_dep')
	endif

endif


subdir('libclank')

if get_option('build_bindings')
	subdir('bindings')
endif
