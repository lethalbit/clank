# SPDX-License-Identifier: BSD-3-Clause

message('Building tests')

doctest = dependency('doctest',  required: false, version: '>=2.4.8-1')
if not doctest.found()
	message('Did not find local doctest install, bundling')
	doctest_wrap = subproject('doctest', default_options: [])
	doctest = doctest_wrap.get_variable('doctest_dep')
endif
