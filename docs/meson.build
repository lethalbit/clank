# SPDX-License-Identifier: Apache-2.0

sphinx = find_program(
	'sphinx-build',
	required: false
)

if sphinx.found()
	message('sphinx-build found, adding docs target')
	run_target(
		'docs',
		command: [
			sphinx,
			'-b', 'html',
			'-a',
			'@0@'.format(meson.current_source_dir()),
			'@0@'.format(meson.current_build_dir())
		]
	)
else
	warning('sphinx-build not found, skipping doc target')
endif
