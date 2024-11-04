#include "BLSRC.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <cstdlib>
#include <filesystem>

namespace fs = std::filesystem;

extern bool USE_BLSRC;

void parseBLSRCFile(const std::string& blsrcFile, std::vector<std::string>& src_files) {
    std::ifstream file(blsrcFile);
    if (!file.is_open()) {
        std::cerr << "\033[31mFailed to open BLSRC file: " << blsrcFile << "\033[0m" << std::endl;
        exit(1);
    }

    std::string line;
    while (std::getline(file, line)) {
        if (!line.empty()) {
            src_files.push_back(line);
        }
    }
}

void compileResources(const std::string& resourceFile, const std::string& outputFile) {
    if (USE_BLSRC == true) {
        // Check if rcc is available
        if (std::system("command -v rcc > /dev/null 2>&1") != 0) {
            std::cerr << "\033[31mrcc command not found. Please install Qt tools.\033[0m" << std::endl;
            exit(1);
        }

        std::string command = "rcc --binary " + resourceFile + " -o " + outputFile;
        if (std::system(command.c_str()) != 0) {
            std::cerr << "\033[31mFailed to compile resources.\033[0m" << std::endl;
            exit(1);
        }
    }
}