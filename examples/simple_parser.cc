// SPDX-License-Identifier: Apache-2.0
/* simple_parser.cc - Simple clank example */

#include <iostream>
#include <string_view>

#include <clank/clank.hh>

using namespace std::literals::string_view_literals;

using clank::core::LanguageID_t;
using clank::core::LanguageStandard_t;

int main(int, char**) {
	/* Some simple C to parse */
	const auto src{"int a = 1;"sv};

	if (auto lang = LanguageStandard_t::get_by_id(LanguageID_t::C11)) {
		clank::parse(src, *lang).map([](const auto& ast){
			std::cout << "Successfully parsed code!\n";
			/* Do AST things */
		}).map_error([](const std::error_code err){
			std::cerr << "Unable to get AST: " << err.message() << "\n";
		});
	} else {
		std::cerr << "Unable to get language standard for 'C11'\n";
		return 1;
	}

	return 0;
}
