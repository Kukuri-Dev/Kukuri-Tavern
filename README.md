# Kukuri Tavern
> A Growtopia Private Server made in C++, well-structured and reliable code.

### Known Issue
> After managing to solve the login issue, I need to make a World Selection before sending the Register Dialog.

### Requirements
- [vcpkg](https://vcpkg.io/en/)
- [CMake](https://cmake.org/download/)

## Setup
To start build the source, first you'll need to follow this step
- Firstly, You need to clone the repository:
```
$ git clone --recurse-submodules https://github.com/Kukuri-Dev/Kukuri-Tavern
```
- Second, You'll need to install the requirements package by using this command below:
```
$ vcpkg install fmt enet cpp-httplib libmariadb magic-enum openssl sigslot spdlog sqlite3
```

## Building
Next step, If you want to build the project, You'll need to run `<any-type>-build.bat` file to build the project
- Dont forgot to switch to the (`Release, x64`)

## Database
Database that we currently use is SQLite3 (With sqlpp11 lib)

## Todo
- [X] Change the Database
- [ ] Login page
- [ ] Caching for holding world offers
- [ ] Fetch some API from my website

## Contributing
Any contributions are welcome.

There's few rules of contributing:
- Code must match the existing code style. Please make sure before submiting.
- The commit must take review first before merging into main branch.

### Credits to this people
- [RebillionXX](https://github.com/RebillionXX) for the source based : [GrowServer](https://github.com/RebillionXX/GrowtopiaServer)
- [YoruAkio](https://github.com/YoruAkio) for helping me about Login System

### Our discord server
[Join our discord](https://discord.gg/pqymdG3pBa)
