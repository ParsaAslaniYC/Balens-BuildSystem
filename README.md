# Balens Build System

Balens is a simple, one-click build system designed to streamline the compilation process for C++ projects. With Balens, you can configure your project settings in a single configuration file and build your project with a single command.
## Features

    One-Click Build: Simply run ./balens to compile your project.

    Customizable Configuration: Define your project settings in a single configuration file.

    Easy Installation: Optionally install the compiled output with a single flag.

    Resource Management: Include resource files directly in your build process.

## Configuration File

The configuration file (config.ini) for Balens allows you to define various settings for your project. Below is an example configuration:

``` ini
PROJECT_NAME=[Balens Build System]
BUILD_DIR=cache
SRC_DIR=src
INCLUDE_DIR=include
COMPILER=g++
FLAGS= -lstdc++fs -std=c++17 -lstdc++
OUTPUT=balens
INSTALLATION=T
USE_BLSRC=false
RESOURCE_FILE=BLSRC
```

## Configuration Options

    PROJECT_NAME: The name of your project.

    BUILD_DIR: The directory where build artifacts will be stored.

    SRC_DIR: The directory containing your source files.

    INCLUDE_DIR: The directory containing your header files.

    COMPILER: The compiler to use (e.g., g++).

    FLAGS: Additional compiler flags.

    OUTPUT: The name of the output executable.

    INSTALLATION: Whether to install the compiled output (T for true, F for false).

    USE_BLSRC: Whether to use the BLSRC resource file (true or false).

    RESOURCE_FILE: The name of the resource file to include in the build.

## Getting Started
Prerequisites

    g++: Ensure that g++ is installed on your system.

    C++17: The project is configured to use C++17 standard.

## Building the Project

    Clone the Repository:    

``` bash
git clone https://github.com/ParsaAslaniYC/Balens-BuildSystem.git
cd Balens-BuildSystem
```
    Configure the Project:
    Edit the BalensSystem.balens file to match your project settings.

    Build the Project:
    Simply run the following command:

``` bash
./balens
```

    The build process will automatically compile your project based on the settings in config.

    Installation (Optional):
    If INSTALLATION=T is set in the configuration file, the compiled output will be installed to the appropriate location.

## Contributing

Contributions are welcome! Please feel free to submit a pull request or open an issue if you encounter any problems or have suggestions for improvements.
License

This project is licensed under the MIT License. See the LICENSE file for details.

Happy Building! 🚀
