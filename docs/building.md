# Building Clank

```{warning}
The following instructions are a work-in-progress and may not be entirely up to date.
```

```{note}
Currently only instructions for building on Linux and unix-likes is supplied, macOS and Windows build instructions will be added eventually.
```

## System Requirements

To build Clank, ensure you have the following build time dependencies:
 * git
 * meson
 * ninja
 * g++ >= 11 or clang++ >= 11

Optionally, when also building with binding support (which is the default) you also need:
 * python >= 3.9
 * pybind11 >= 2.7.0


## Configuring

You can build libalfheim with the default options, all of which can be found in [`meson_options.txt`](https://github.com/lethalbit/clank/blob/main/meson_options.txt). You can change these by specifying `-D<OPTION_NAME>=<VALUE>` at initial meson invocation time, or with `meson configure` in the build directory post initial configure.

To change the install prefix, which is `/usr/local` by default ensure to pass `--prefix <PREFIX>` when running meson for the first time.

In either case, simply running `meson build` from the root of the repository will be sufficient and place all of the build files in the `build` subdirectory.

## Building

Once you have configured libalfheim appropriately, to simply build and install simply run the following:

```
$ ninja -C build
$ ninja -C build test # Optional: Run Tests
$ ninja -C build install
```

This will build and install Clank into the default prefix which is `/usr/local`, to change that see the configuration steps above.

## Notes to Package Maintainers

If you are building libalfheim for inclusion in a distributions package system then ensure to set `DESTDIR` prior to running meson install.

There is also a `bugreport_url` configuration option that is set to this repositories issues tracker by default, it is recommended to change it to your distributions bug tracking page.
