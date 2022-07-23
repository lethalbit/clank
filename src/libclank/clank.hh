// SPDX-License-Identifier: Apache-2.0
/* clank.hh - Root library include */

/*!
	# Clank

	Clank is a C++ front end based on [LLVM](https://llvm.org/)'s
	[clang](https://clang.llvm.org/) compiler.

	It has been heavily modified and de-coupled from LLVM to be a
	stand alone library with only the C++ standard libraries as dependencies.

	## Flow

	```{dot}
	digraph clank_flow {
		fontname="Fira Code"
		bgcolor="#FFFFFF00"

		node [fontname="Fira Code" margin="0.5,0.1"]
		edge [fontname="Fire Code"]
        rankdir=LR;
 		node [shape = none]; SRC
		node [shape = Mrecord];

        SRC -> Lexer
        Lexer -> Tokenizer
        Tokenizer -> Parser
        Parser -> AST
	}
	```

*/

#pragma once
#if !defined(libclank_clank_hh)
#define libclank_clank_hh

#include <libclank/ast.hh>
#include <libclank/core.hh>
#include <libclank/lex.hh>
#include <libclank/parse.hh>

#include <libclank/internal/expected.hh>
#include <libclank/internal/defs.hh>


#include <filesystem>
#include <string>
#include <string_view>
#include <cstdint>
namespace clank {
	using clank::internal::expected;
	/*!
		Attempts to generate an AST from a std::string.
	*/
	[[nodiscard]]
	LIBCLANK_API expected<ast::Node, std::error_code> parse(const std::string& src, const clank::core::LanguageStandard_t& lang);

	/*!
		Attempts to generate an AST from a std::string_view.
	*/
	[[nodiscard]]
	LIBCLANK_API expected<ast::Node, std::error_code> parse(const std::string_view& src, const clank::core::LanguageStandard_t& lang);

	/*!
		Attempts to generate an AST from a file on disk.
	*/
	[[nodiscard]]
	LIBCLANK_API expected<ast::Node, std::error_code> parse(const std::filesystem::path path, const clank::core::LanguageStandard_t& lang);

	/*!
		Attempts to generate an AST from an open file descriptor.
	*/
	[[nodiscard]]
	LIBCLANK_API expected<ast::Node, std::error_code> parse(const std::int32_t fd, std::nullptr_t);

}


#endif /* libclank_clank_hh */
