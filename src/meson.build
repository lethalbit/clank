# SPDX-License-Identifier: Apache-2.0

library_inc  = include_directories('.')


enable_logging = get_option('debug') and not get_option('disable_logging')

cxx_extra_args = []

if enable_logging and not is_windows

	sawmill = dependency('sawmill',  required: false, version: '>=2.7.0')
	if not sawmill.found()
		message('Did not find local sawmill install, bundling')
		sawmill_wrap = subproject('sawmill', default_options: [
			'b_sanitize=none',
			'build_compiler_plugins=false',
			'build_examples=false',
			'build_tests=false',
			# 'plugin_clang=@0@'.format(is_clang),
			# 'plugin_gcc=@0@'.format(is_gcc),
		])
		sawmill = sawmill_wrap.get_variable('sawmill_dep')

		# if is_clang
		# 	compiler_plugin = sawmill_wrap.get_variable('clang_plugin')
		# elif is_gcc
		# 	compiler_plugin = sawmill_wrap.get_variable('gcc_plugin')
		# endif
	endif

	# cxx_extra_args + [
	# 	'-fplugin=@0@'.format(compiler_plugin.full_path())
	# ]

endif


subdir('libclank')

if get_option('build_bindings')
	subdir('bindings')
endif
