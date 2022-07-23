# SPDX-License-Identifier: Apache-2.0
message('Building examples')

example_srcs = [
	'simple_parser',
]

foreach ex : example_srcs
	executable(
		ex,
		'@0@.cc'.format(ex),
		dependencies: [
			libclank_dep
		],
		install: false
	)
	if get_option('install_examples')
		install_data(
			'@0@.cc'.format(ex),
			install_mode: 'rw-r--r--',
			install_dir : get_option('datadir') / 'libclank' / 'examples'
		)
	endif
endforeach
