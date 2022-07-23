```{toctree}
:hidden:

building
getting_started
api/index

```
# Clank

Clank is a fully stand-alone C++ front-end based on [LLVM](https://llvm.org/)'s [clang](https://clang.llvm.org/) compiler.

It has been heavily modified and de-coupled from LLVM to be a stand alone library with only the C++ standard libraries as dependencies.

## Planned Support

The [clang](https://clang.llvm.org/) front-end can parse many languages, but clank is mainly focused on C and C++, however work is eventually planned to support most if not all of the languages that clang does as well. The table below shows the status of each language.

There is also the possibility of adding support for [D lang](https://github.com/ldc-developers/ldc) and also possibly [Fortran](https://flang.llvm.org/docs/) but those would be left until after the MVP of supporting C and C++ has been met.

<table>
	<thead>
		<tr>
			<th>Language</th>
			<th>Standard</th>
			<th>Status</th>
	  		<th>Extensions</th>
		</tr>
	</thead>
	<tbody>
	<tr>
	  <td rowspan="6">C++</td>
	  <td>99</td>
	  <td>🚧 In Progress 🚧</td>
	  <td>GNU</td>
	</tr>
	<tr>
	  <td>11</td>
	  <td>🚧 In Progress 🚧</td>
	  <td>GNU</td>
	</tr>
	<tr>
	  <td>14</td>
	  <td>🚧 In Progress 🚧</td>
	  <td>GNU</td>
	</tr>
	<tr>
	  <td>17</td>
	  <td>🚧 In Progress 🚧</td>
	  <td>GNU</td>
	</tr>
	<tr>
	  <td>20</td>
	  <td>🚧 In Progress 🚧</td>
	  <td>GNU</td>
	</tr>
	<tr>
	  <td>2b</td>
	  <td>🚧 In Progress 🚧</td>
	  <td>GNU</td>
	</tr>
	<tr>
	  <td rowspan="5">C</td>
	  <td>99</td>
	  <td>⏳ Planned ⏳</td>
	  <td>GNU</td>
	</tr>
	<tr>
	  <td>11</td>
	  <td>⏳ Planned ⏳</td>
	  <td>GNU</td>
	</tr>
	<tr>
	  <td>14</td>
	  <td>⏳ Planned ⏳</td>
	  <td>GNU</td>
	</tr>
	<tr>
	  <td>17</td>
	  <td>⏳ Planned ⏳</td>
	  <td>GNU</td>
	</tr>
	<tr>
	  <td>2x</td>
	  <td>⏳ Planned ⏳</td>
	  <td>GNU</td>
	</tr>
	<tr>
	  <td rowspan="1">ObjC</td>
	  <td>❔</td>
	  <td>⏳ Planned ⏳</td>
	  <td>None</td>
	</tr>
	<tr>
	  <td rowspan="1">ObjC++</td>
	  <td>❔</td>
	  <td>⏳ Planned ⏳</td>
	  <td>None</td>
	</tr>
	<tr>
	  <td rowspan="1">OpenCL</td>
	  <td>❔</td>
	  <td>⏳ Planned ⏳</td>
	  <td>None</td>
	</tr>
	</tbody>
</table>

## License

Clank is under the [Apache 2.0](https://spdx.org/licenses/Apache-2.0.html) license with LLVM exceptions, just like the original clang. The full text of the license can be found in the [`LICENSE`](https://github.com/lethalbit/clank/blob/main/LICENSE) file.
