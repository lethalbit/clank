# Contribution Guidelines

## Contributing

Contributions to this project are released under the [project's open source license](LICENSE).

Please note that this project is released with a [Contributor Code of Conduct](CODE_OF_CONDUCT.md).
By participating in this project you agree to abide by its terms.

## Development and Testing

As noted in the README, this project requires [Meson](https://meson.build/) to build.
For a development setup, we recommend running `meson build --buildtype=debug` rather than just `meson build`.
We also recommend the use of the 'build' directory name as this works with the existing .gitignore rules
and keeps a nice commonality between all developer setups.

## Common tasks

These are intended to be run from inside your build directory

 * Building the library component and tests: `ninja` (`meson compile`)
 * Running tests: `ninja test` (`meson test`), or to view the raw output `meson test -v`
 * Debugging tests: `meson test --gdb`

## Submitting a Pull Request

 1. [Fork](https://github.com/lethalbit/clank/fork) and clone the repository
 2. Create a new branch: `git switch -c branch-name` (`git checkout -b branch-name` in the old syntax)
 3. Make your change, create unit tests and sure all tests new and old pass
 4. Push to your fork and submit a [pull request](https://github.com/lethalbit/clank/compare)

Before your pull request will be accepted, please keep in mind that unless your change is a bugfix, writing unit tests to proove your new code is mandatory.

Additionally, please write good and descriptive commit messages that both summarize the change and,
if necessary, expand on the summary using description lines.
"Patched the utility header" is, while terse and correct, an example of a bad commit message.
"Fixed a bug in core/lang_standards.cc causing issues in C++ handling" is an example of a better commit message.

We would like to be able to look back through the commit history and tell what happened, when, and why without having
to dip into the commit descriptions as this improves the `git bisect` experience and improves everyone's lives.

We use rebasing to merge pull requests, so please keep this in mind and aim to keep a linear history.
