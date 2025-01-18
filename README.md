# Falcon

**Designed and developed by** [Luqman](https://theluqmn.github.io/)

[**Website**](https://theluqmn.github.io/falcon/)

Falcon is a simple bank management system backend written in C++. I am also working on [Moose](https://github.com/theluqmn/moose) which is a more advanced bank management system backend project which I wrote in Rust - but is not planned for High Seas 2024/2025.

This is my first project in C++.

>[!WARNING]
> This project is not memory safe. It is something I will implement in the near future.

## Features

- Create, manage, and view accounts.
- Perform transactions between accounts.
- Detailed records of all transactions.

## How to run

For Linux users, a pre-compiled executable is available. Simply follow the instructions below:

1. Go to the [releases](https://github.com/theluqmn/falcon/releases) and download the latest version.
2. Run the executable file (`./falcon`).

### Compile it yourself

Use the following steps to compile the project yourself, and modify according to your platform:

>[!NOTE]
> The `compile.bash` script only works for **Unix-based** systems (Linux, MacOS).
>
> Compilation may take a while. On my i7-10750H, 16GB laptop:
>
> - ~12s using the package.
> - ~28s if using `crow_all.h`.

1. Clone the repository.
2. Go to [Crow releases](https://github.com/CrowCpp/Crow/releases/latest), download the installer - or `crow_all.h` and move the file to the root directory (you will need to modify some code to use the header file instead of the package).
3. Ensure you have `g++` and`cpprest-devel` installed (Linux).
4. Run `bash compile.bash` - this will compile the project and run the executable.
