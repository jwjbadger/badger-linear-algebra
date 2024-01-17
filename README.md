# Badger Linear Algebra

A lightweight linear algebra library which provides basic functionality to be used for machine learning.

## Contents

1. [Introduction](#introduction)
2. [Installation](#installation)
3. [Documentation](#documentation)
4. [Features](#features)

## Introduction

BadLinAlg is a simple header-only library which provides basic requirements for data manipulation with matrices and vectors. It provides simple methods to create, modify, and perform operations with various data structures.

This library is not feature-complete and should not be used for any projects at this point in development.

The intention in creating this library while many other better ones exist is to give a basic understanding of the underworkings of simple machine learning models. This project provides only the minimum features to do this. Ideally the fully completed project will require nothing except the standard C++ library, and everything else will be built from scratch.

## Installation

To install systemwide: clone the repo, `cd` into the directory, and run the following commands:

```bash
mkdir build && cd build
cmake .. -G Ninja
cmake --build . --config Release --target install -- -j $(nproc)
```

Once you've linked the library to your project in your preferred manner, you can include headers in the following manner:

```cpp
#include <BadLinAlg/matrix.h>
```


### CMake

The library should install itself into the proper directories automatically. You can use it either by manually linking the location of the files, placing the folder in your cmake directory and using `add_subdirectory`, or by running the previous commands and including it into your cmake project with the following options:

```cmake
find_package(BadLinAlg REQUIRED CONFIG)
target_link_libraries(my_target BadLinAlg::BadLinAlg)
```

As long as you installed the library in the previously mentioned way, it should install to the default location and be found without any configuration using the command `find_package()`. Note that using CMake is in no way required, and you can simply link the library using any other preferred method.

## Documentation

If the library is built as a standalone project, the documentation should be automatically built with it. The documentation can be found in [`ProjectRootDir/build/docs/html/index.html`](build/docs/html/index.html).

## Features

 - [x] Vector + matrix constructor + storage
 - [x] Simple operations for vectors, matrices, and scalars
 - [x] Simple data modification (e.g. transverse, resize, etc.)
 - [x] Equality operator for vectors & matrices
 - [x] Custom dynamic array
 - [ ] Time everything and minimize wasted time
 - [ ] Allow DArray to be constructed from std::vector
 - [ ] Matrix determinants + inverses

