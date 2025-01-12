# Falcon

**Designed and developed by** [Luqman](https://theluqmn.github.io/)

Falcon is a simple bank management system backend written in C++.

>[!NOTE]
> This project is not memory safe. It is something I will implement in the near future.

## Features

- Create, manage, and view accounts.
- Perform transactions between accounts.
- Detailed records of all transactions.

## How to run

For Linux (Fedora/Debian) users, a pre-compiled executable is available. Simply follow the instructions below:

1. Go to the [releases](https://github.com/theluqmn/falcon/releases) and download the latest version.
2. Run the executable file (`./falcon`).

### Compile it yourself

Use the following steps to compile the project yourself, and modify according to your platform:

1. Clone the repository.
2. Go to [Crow releases](https://github.com/CrowCpp/Crow/releases/latest), download `crow_all.h` and move the file to the root directory.
3. Ensure you have `g++` and`cpprest-devel` installed (Linux).
4. Run `bash compile.bash` - this will compile the project and run the executable.

>[!NOTE]
> Compilation may take a while. ~20 seconds on my machine (i7-10750H, 16GB RAM).
