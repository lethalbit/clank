# SPDX-License-Identifier: Apache-2.0
project(
	'clank',
	'cpp',
	default_options: [
		'cpp_std=c++17',
		'warning_level=3',
		'build.cpp_std=c++17',
		'buildtype=debugoptimized',
		'strip=true',
		'b_ndebug=if-release',
		'b_lto=true'
	],
	subproject_dir: 'deps',
	version: '0.0.1',
	license: [
		'Apache-2.0',
	],
	meson_version: '>=0.63.0',
)

cxx = meson.get_compiler('cpp')

if get_option('cpp_std') not in ['c++17', 'c++20', 'c++23', 'gnu++17', 'gnu++20', 'gnu++23']
	error('Unsupported C++ Version @0@, must be c++17/gnu++17 or newer'.format(get_option('cpp_std')))
endif

extended_warnings = [
	'-Wdouble-promotion',
	'-Wformat=2',
	'-Wformat-overflow=2',
	'-Wformat-signedness',
	'-Wformat-truncation',
	'-Wnull-dereference',
	'-Wmissing-attributes',
	'-Wmissing-braces',
	'-Wsequence-point',
	'-Wreturn-type',
	'-Wunused',
	'-Wunused-local-typedefs',
	'-Wunused-const-variable=2',
	'-Wmaybe-uninitialized',
	'-Wunknown-pragmas',
	'-Wstrict-aliasing',
	'-Wstrict-overflow=3',
	'-Wstring-compare',
	'-Wstringop-overflow',
	'-Warith-conversion',
	'-Wvla-parameter',
	'-Wduplicated-branches',
	'-Wshadow=local',
	'-Wunsafe-loop-optimizations',
	'-Wbad-function-cast',
	'-Wcast-qual',
	'-Wcast-align=strict',
	'-Wcast-function-type',
	'-Wconversion',
	'-Wdangling-else',
	'-Wsign-conversion',
	'-Wfloat-conversion',
	'-Wpacked',
	'-Wpadded',
	'-Wredundant-decls',
	'-Winline',
	'-Wvla',
	'-Wstack-protector',
	'-Wunsuffixed-float-constant',
	'-Wimplicit-fallthrough',
]

add_project_arguments(
	cxx.get_supported_arguments(extended_warnings),
	language: 'cpp'
)

is_clang        = (cxx.get_id() == 'clang')
is_gcc          = (cxx.get_id() == 'gcc')
compiler_verson = cxx.version()


if is_gcc and compiler_verson.version_compare('<11.0.0')
	error('g++ version <= 11.0.0 is required to build Clank')
elif is_clang and compiler_verson.version_compare('<11.0.0')
	error('clang++ version <= 11.0.0 is required to build Clank')
endif


do_fuzzing = get_option('build_fuzzers')

	# we use -fsanitize=fuzzer which is only avaiable in clang
if do_fuzzing
	if is_clang
		if not cxx.has_argument('-fsanitize=address,fuzzer')
			warning('compiler does not support \'-fsanitize=fuzzer\', disabiling fuzzing')
			do_fuzzing = false
		else
			add_project_arguments(
				'-fsanitize=address,fuzzer',
				language: 'cpp'
			)
			add_project_link_arguments(
				'-fsanitize=address,fuzzer',
				language: 'cpp'
			)
		endif
	else
		warning('Skipping building fuzzers, not using clang++ as target compiler')
		do_fuzzing = false
	endif
endif


subdir('contrib')

subdir('src')

if get_option('build_benchmarks')
	subdir('benchmarks')
endif

if do_fuzzing
	subdir('fuzzing')
endif

if get_option('build_tests')
	subdir('tests')
endif

if get_option('build_examples')
	subdir('examples')
endif
