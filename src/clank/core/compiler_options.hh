// SPDX-License-Identifier: Apache-2.0
#pragma once
#if !defined(CLANK_CORE_COMPILER_OPTIONS_HH)
#define CLANK_CORE_COMPILER_OPTIONS_HH

#include <optional>

#include <clank/internal/defs.hh>
#include <clank/internal/enum.hh>

namespace clank::core {
	/*
		- `-CC` - Include comments from within macros in preprocessed output
		- `-cxx-isystem <directory>` Add directory to the C++ SYSTEM include search path
		- `-C` Include comments in preprocessed output
		- `-dependency-dot <value>` Filename to write DOT-formatted header dependencies to
		- `-dD`                     Print macro definitions in -E mode in addition to normal output
		- `-dI`                     Print include directives in -E mode in addition to normal output
		- `-D <macro>=<value>`      Define <macro> to <value> (or 1 if <value> omitted)
		- `-E`                      Only run the preprocessor
		- `-fallow-editor-placeholders` Treat editor placeholders as valid source code
		- `-fansi-escape-codes`     Use ANSI escape codes for diagnostics
		- `-fborland-extensions`    Accept non-standard constructs supported by the Borland compiler
		- `-fchar8_t`               Enable C++ builtin type char8_t
		- `-fcolor-diagnostics`     Enable colors in diagnostics
		- `-fcomment-block-commands=<arg>` Treat each comma separated argument in <arg> as a documentation comment block command
		- `-fcoroutines-ts`         Enable support for the C++ Coroutines TS
		- `-fcxx-modules`           Enable modules for C++
		- `-fdeclspec`              Allow __declspec as a keyword
		- `-fdelayed-template-parsing` Parse templated function definitions at the end of the translation unit
		- `-fdiagnostics-absolute-paths` Print absolute paths in diagnostics
		- `-fdiagnostics-parseable-fixits` Print fix-its in machine parseable form
  		- `-fdiagnostics-print-source-range-info` Print source range spans in numeric form
  		- `-fdiagnostics-show-note-include-stack` Display include stacks for diagnostic notes
  		- `-fdiagnostics-show-option` Print option name with mappable diagnostics
  		- `-fdiagnostics-show-template-tree` Print a template comparison tree for differing templates
  		- `-fdigraphs`              Enable alternative token representations '<:', ':>', '<%', '%>', '%:', '%:%:' (default)
  		- `-fdollars-in-identifiers` Allow '$' in identifiers
  		- `-fdouble-square-bracket-attributes` Enable '[[]]' attributes in all C and C++ language modes
		- `-femit-all-decls`        Emit all declarations, even if unused
		- `-fenable-matrix`         Enable matrix data type and related builtin functions
		- `-fexperimental-new-constant-interpreter`  Enable the experimental new constant interpreter
		- `-ffile-prefix-map=<value>` remap file source paths in debug info, predefined preprocessor macros and __builtin_FILE()
		- `-ffixed-point`           Enable fixed point types
		- `-fforce-enable-int128`   Enable support for int128_t type
		- `-fgnu-keywords`          Allow GNU-extension keywords regardless of language standard
  		- `-fgnuc-version=<value>`  Sets various macros to claim compatibility with the given GCC version (default is 4.2.1)
		// Do we keep this? Or just force UTF-8 unilaterally?
		- `-finput-charset=<value>` Specify the default character set for source files
		- `-fkeep-static-consts`    Keep static const variables if unused
		- `-flax-vector-conversions=<value>` Enable implicit vector bit-casts
		- `-fmacro-prefix-map=<value>` remap file source paths in predefined preprocessor macros and __builtin_FILE()
		- `-fmax-tokens=<value>`    Max total number of preprocessed tokens for -Wmax-tokens.
		- `-fminimize-whitespace`   Minimize whitespace when emitting preprocessor output
  -fms-compatibility-version=<value>
                          Dot-separated value representing the Microsoft compiler version number to report in _MSC_VER (0 = don't define it (default))
  -fms-compatibility      Enable full Microsoft Visual C++ compatibility
  -fms-extensions         Accept some non-standard constructs supported by the Microsoft compiler
  -fmsc-version=<value>   Microsoft compiler version number to report in _MSC_VER (0 = don't define it (default))

  -fno-builtin-<value>    Disable implicit builtin knowledge of a specific function
  -fno-builtin            Disable implicit builtin knowledge of functions
  -fno-complete-member-pointers
                          Do not require member pointer base types to be complete if they would be significant under the Microsoft ABI

  -fno-c++-static-destructors
                          Disable C++ static destructor registration
  -fno-char8_t            Disable C++ builtin type char8_t
  -fno-color-diagnostics  Disable colors in diagnostics
  -fno-debug-macro        Do not emit macro debug information
  -fno-declspec           Disallow __declspec as a keyword

  -fno-elide-type         Do not elide types when printing diagnostics
  -fno-gnu-inline-asm     Disable GNU style inline asm
  -fno-openmp-extensions  Disable all Clang extensions for OpenMP directives and clauses
  -fno-operator-names     Do not treat C++ operator name keywords as synonyms for operators
  -fno-short-wchar        Force wchar_t to be an unsigned int
  -fno-show-column        Do not include column number on diagnostics
  -fno-show-source-location
                          Do not include source location information with diagnostics
  -fno-signed-char        char is unsigned
  -fno-signed-zeros       Allow optimizations that ignore the sign of floating point zeros
  -fno-spell-checking     Disable spell-checking

  -fno-strict-float-cast-overflow
                          Relax language rules and try to match the behavior of the target's native float-to-int conversion instructions

-fno-double-square-bracket-attributes
                          Disable '[[]]' attributes in all C and C++ language modes
  -fno-strict-return      Don't treat control flow paths that fall off the end of a non-void function as unreachable

  -fno-trigraphs          Do not process trigraph sequences
  -frelaxed-template-template-args
                          Enable C++17 relaxed template template argument matching

  -fshort-wchar           Force wchar_t to be a short unsigned int

  -fshow-overloads=<value>
                          Which overload candidates to show when overload resolution fails: best|all; defaults to all
  -fshow-skipped-includes Show skipped includes in -H output.
  -fsigned-char           char is signed
  -fsized-deallocation    Enable C++14 sized global deallocation functions
  -ftrigraphs             Process trigraph sequences
  -fuse-line-directives   Use #line in preprocessed output
  -fxl-pragma-pack        Enable IBM XL #pragma pack handling
  -fzvector               Enable System z vector language extension
  -H                      Show header includes and nesting depth
  -I-                     Restrict all prior -I flags to double-quoted inclusion and remove current directory from include path
  -ibuiltininc            Enable builtin #include directories even when -nostdinc is used before or after -ibuiltininc. Using -nobuiltininc after the option disables it
  -idirafter <value>      Add directory to AFTER include search path
  -iframeworkwithsysroot <directory>
                          Add directory to SYSTEM framework search path, absolute paths are relative to -isysroot
  -iframework <value>     Add directory to SYSTEM framework search path
  -imacros <file>         Include macros from file before parsing
  -include <file>         Include file before parsing
  -iprefix <dir>          Set the -iwithprefix/-iwithprefixbefore prefix
  -iquote <directory>     Add directory to QUOTE include search path
  -isysroot <dir>         Set the system root directory (usually /)
  -isystem-after <directory>
                          Add directory to end of the SYSTEM include search path
  -isystem <directory>    Add directory to SYSTEM include search path
  -iwithprefixbefore <dir>
                          Set directory to include search path with prefix
  -iwithprefix <dir>      Set directory to SYSTEM include search path with prefix
  -iwithsysroot <directory>
                          Add directory to SYSTEM include search path, absolute paths are relative to -isysroot
  -I <dir>                Add directory to the end of the list of include search paths
  -mcmse                  Allow use of CMSE (Armv8-M Security Extensions)
  -MD                     Write a depfile containing user and system headers
  -MF <file>              Write depfile output from -MMD, -MD, -MM, or -M to <file>
  -MG                     Add missing headers to depfile
  -MJ <value>             Write a compilation database entry per input
  -MMD                    Write a depfile containing user headers
  -MM                     Like -MMD, but also implies -E and writes to stdout by default






	*/
}

#endif /* CLANK_CORE_COMPILER_OPTIONS_HH */
