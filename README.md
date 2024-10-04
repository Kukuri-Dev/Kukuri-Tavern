# Kukuri Tavern
> A Growtopia Private Server made in C++, well-structured and reliable code.

# Requirements
- [vcpkg](https://vcpkg.io/en/)
- [CMake](https://cmake.org/download/)

# Setup
To start build the source, first you'll need to follow this step
- Firstly, You need to clone [enet](https://github.com/lsalzman/enet/tree/be7cefa39cd23dfc5919b20a12d8e25a9f3a2419), [sqlpp11](https://github.com/rbock/sqlpp11/tree/9412851408e7bc290732b56d7a5e76c6942d49d8), [sigslot](https://github.com/palacaze/sigslot/tree/33802bb3e94c4dfe07bd41b537b36806f94c3e3a) into the libraries partition
- Second, You'll need to install the requirements package by using this command below:
```
$ vcpkg install fmt enet cpp-httplib libmariadb magic-enum openssl sigslot spdlog sqlite3
```
- Go to build partition then run this command
  - replace `<your vcpkg path>` to your vcpkg `installed directory`
```
cmake -DCMAKE_TOOLCHAIN_FILE=<your vcpkg path>/scripts/buildsystems/vcpkg.cmake -DCMAKE_PREFIX_PATH=<your vcpkg path>/installed/x64-windows ..
```

# Building
Next step, If you want to build the project, You'll need to run `<any-type>-build.bat` file to build the project
- Dont forgot to switch to the (`Release, x64`)

# Contributing
Any contributions are welcome.

There's few rules of contributing:
- Code must match the existing code style. Please make sure before submiting.
- The commit must take review first before merging into main branch.
=======

>>>>>>> e9c6b01e06a3302bbe8a8f96301ced25a2e6aa39
