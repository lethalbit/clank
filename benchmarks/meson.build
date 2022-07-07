# SPDX-License-Identifier: BSD-3-Clause

message('Building benchmarks')

benchmark = dependency('google-benchmark',  required: false, version: '>=1.6.0-1')
if not benchmark.found()
	message('Did not find local google-benchmark install, bundling')
	benchmark_wrap = subproject('google-benchmark', default_options: [])
	benchmark = benchmark_wrap.get_variable('google_benchmark_dep')
endif
