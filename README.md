# Pitchfork

[![build](https://github.com/ZIMO-Elektronik/Pitchfork/actions/workflows/build.yml/badge.svg)](https://github.com/ZIMO-Elektronik/Pitchfork/actions/workflows/build.yml) [![tests](https://github.com/ZIMO-Elektronik/Pitchfork/actions/workflows/tests.yml/badge.svg)](https://github.com/ZIMO-Elektronik/Pitchfork/actions/workflows/tests.yml)

<img src="data/images/logo.png" width="25%" align="right"/>

Pitchfork demonstrates how projects should be layed out and structured. This set of conventions is shamelessly copied from the [The Pitchfork Layout](https://api.csswg.org/bikeshed/?force=1&url=https://raw.githubusercontent.com/vector-of-bool/pitchfork/develop/data/spec.bs). The following folders and files should be present in the root of a project:

- `/.github`  
  A special directory for GitHub related stuff, e.g. for running [actions](https://docs.github.com/en/actions/using-workflows/workflow-syntax-for-github-actions).

- `/build`  
  A special directory that should not be considered part of the source of the project. Used for storing ephemeral build results. Must not be checked into source control. If using source control must be ignored using source control ignore-lists.

- `/cmake`  
  CMake utility files (e.g. toolchain or Find\<package>.cmake files)

- `/data`  
  Directory containing non-source code aspects of the project. This might include datasheets, graphics and markup files.

- `/docs`  
  Directory for project documentation

- `/examples`  
  Directory for samples and examples

- `/external`  
  Directory for packages/projects to be used by the project, but not edited as part of the project.

- `/include`  
  Directory for public headers. May be present. May be omitted for projects that do not distinguish between private/public headers. May be omitted for projects that use submodules.

- `/libs`  
  Directory for main project submodules

- `/src`  
  Main compilable source location. Must be present for projects with compiled components that do not use submodules.

- `/tests`  
  Directory for tests

- `/tools`  
  Directory containing development utilities, such as build and refactoring scripts

- `.clang-format`  
  Format template for the [ClangFormat](https://clang.llvm.org/docs/ClangFormat.html) tool

- `.gitignore`  
  Specifies intentionally untracked files that Git should ignore

- `.licenserc.json`  
  A special .json file used by the [kt3k/license_checker](https://github.com/kt3k/license_checker_github_action).

- `CHANGELOG.md`  
  Log or record of all notable changes made to the project

- `CMakeLists.txt`  
  Contains a set of directives and instructions describing the project's source files and targets

- `README.md`  
  Contains a description of the project

- `TODO.md`  
  Can contain a friendly reminder of things to do...

## Style Guide
Furthermore there is a [style guide](STYLE_GUIDE.md) based on best practices and performance considerations.