// SPDX-License-Identifier: Apache-2.0

#include <clank/config.hh>

#include <pybind11/pybind11.h>

namespace py = pybind11;

PYBIND11_MODULE(clank, m) {

	m.doc() = "A C++ Front-end based on LLVM's clang";
	m.attr("__version__") = clank::config::version;

}
