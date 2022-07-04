// SPDX-License-Identifier: Apache-2.0

#include <libclank/config.hh>

#include <pybind11/pybind11.h>

namespace py = pybind11;

PYBIND11_MODULE(libclank, m) {

	m.doc() = "A C++ Front-end based on LLVM's clang";
	m.attr("__version__") = libclank::config::version;

}
