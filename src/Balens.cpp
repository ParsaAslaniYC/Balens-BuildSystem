#include <iostream>
#include <filesystem>
#include <vector>
#include <cstdlib>
#include <fstream>
#include <sstream>
#include "args.h"
#include "config.h"
#include "compile.h"
#include "link.h"
#include "BLSRC.h"
#include "DataShop.hpp"

namespace fs = std::filesystem;

// Default build parameters
std::string PROJECT_NAME = "[My Unnamed Project]";
std::string BUILD_DIR = "build";
std::string SRC_DIR = "src";
std::string INCLUDE_DIR = "include";
std::string COMPILER = "g++";
std::string FLAGS = "-Wall -std=c++17";
std::string OUTPUT = "output";
std::string INSTALLATION = "F";
bool USE_BLSRC = false;
std::string RESOURCE_FILE = "";
bool CLEAN_COMMAND = true;
std::string MULTI_TARGET = "F";

void print(const std::string& msg) {
    std::cout << msg << std::endl;
}

int main(int argc, char* argv[]) {
    // Parse command-line arguments
    parseArgs(argc, argv);
    Store ds;

    // Define the buildnumber and save it as a property
    std::string buildnumber = "BLS1-241103";
    ds.save("balens.info.buildnumber", buildnumber);

    std::vector<std::string> configFiles;

    // Search for configuration files with .balens extension
    for (const auto& entry : fs::directory_iterator(".")) {
        if (entry.path().extension() == ".balens") {
            configFiles.push_back(entry.path().string());
        }
    }

    // If there are two or more config files, display a menu. this is multi target project. 
    if (configFiles.size() > 1) {
        std::cout << "Multiple targets found. Please choose one:" << std::endl;
        for (size_t i = 0; i < configFiles.size(); ++i) {
            std::cout << "[" << i + 1 << "] " << configFiles[i] << std::endl;
        }

        int choice;
        std::cout << "Enter your choice: ";
        std::cin >> choice;

        print("\n\n");
        parseConfigFile(configFiles[choice - 1]);   
    } else if (configFiles.size() == 1) {
        parseConfigFile(configFiles[0]);
    } else {    
        // Parse configuration file
        parseConfigFile(configFiles[0]);
    }

    // Check if the configuration file exists
    if (configFiles.empty()) {
        std::cerr << "\033[31mNo configuration file with .balens extension found in the current directory.\033[0m" << std::endl;
        exit(1);
    }

    // Display Flags Table
    print("=============Balens===============");
    print("PROJECT_NAME: " + PROJECT_NAME);
    print("BUILD_DIR: " + BUILD_DIR);
    print("SRC_DIR: " + SRC_DIR);
    print("INCLUDE_DIR: " + INCLUDE_DIR);
    print("COMPILER: " + COMPILER);
    print("COMPILER_FLAGS: " + FLAGS);
    print("OUTPUT_FILE: " + OUTPUT);
    print("INSTALLATION: " + INSTALLATION);
    print("RESOURCES_FILE: " + RESOURCE_FILE);
    print("BALENS_VERSION: " + ds.get("balens.info.buildnumber"));
    print("==================================\n");

    // Check if the source directory exists
    if (!fs::exists(SRC_DIR) || !fs::is_directory(SRC_DIR)) {
        std::cerr << "\033[31mSource directory " << SRC_DIR << " does not exist or is not a directory.\033[0m" << std::endl;
        exit(1);
    }

    // Create build directory if it doesn't exist
    fs::create_directories(BUILD_DIR);
    std::string Wo = "No";
    // Parse BLSRC file if USE_BLSRC is true
    std::vector<std::string> src_files;
    for (const auto& entry : fs::directory_iterator(SRC_DIR)) {
        if (entry.path().extension() == ".cpp" || entry.path().extension() == ".c") {
            src_files.push_back(entry.path().string());
        }
    }
    std::vector<std::string> obj_files;
    for (const auto& src_file : src_files) {
        std::string obj_file = BUILD_DIR + "/" + fs::path(src_file).stem().string() + ".o";
        compile(src_file, obj_file);
        obj_files.push_back(obj_file);
        Wo = "Yes";
    }

    if (USE_BLSRC == true) {
        // Compile resources
        std::string resourceOutput = BUILD_DIR + "/resources.o";
        compileResources(RESOURCE_FILE, resourceOutput);
        obj_files.push_back(resourceOutput);
    }

    // Link object files
    link(obj_files);

    std::cout << "\033[32mBuild successful!\033[0m" << std::endl;

    if (INSTALLATION == "T") {
        std::cout << "\033[33mInstallation is enabled, installing..\033[0m" << std::endl;
        std::string Inst_CMD = "sudo cp " + OUTPUT + " /usr/local/bin/" + OUTPUT;
        if (std::system(Inst_CMD.c_str()) != 0) {
            std::cerr << "\033[31mInstallation failed.\033[0m" << std::endl;
            exit(1);
        }
        std::cout << "\033[32mFinished.\033[0m" << std::endl;
        std::cout << std::endl;
    } else {
        std::cout << "\033[33mInstallation is disabled.\033[0m" << std::endl;       
    }
    return 0;
}
