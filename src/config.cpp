#include "config.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <cstdlib>

extern std::string PROJECT_NAME;
extern std::string BUILD_DIR;
extern std::string SRC_DIR;
extern std::string INCLUDE_DIR;
extern std::string COMPILER;
extern std::string FLAGS;
extern std::string OUTPUT;
extern std::string INSTALLATION;
extern bool USE_BLSRC;
extern std::string RESOURCE_FILE;

void parseConfigFile(const std::string& configFile) {
    std::ifstream file(configFile);
    if (!file.is_open()) {
        std::cerr << "\033[31mFailed to open configuration file: " << configFile << "\033[0m" << std::endl;
        exit(1);
    }

    std::string line;
    while (std::getline(file, line)) {
        std::istringstream iss(line);
        std::string key, value;
        if (std::getline(iss, key, '=') && std::getline(iss, value)) {
            if (key == "BUILD_DIR") {
                BUILD_DIR = value;
            } else if (key == "PROJECT_NAME") {
                PROJECT_NAME = value;
            } else if (key == "SRC_DIR") {
                SRC_DIR = value;
            } else if (key == "INCLUDE_DIR") {
                INCLUDE_DIR = value;
            } else if (key == "COMPILER") {
                COMPILER = value;
            } else if (key == "FLAGS") {
                FLAGS = value;
            } else if (key == "OUTPUT") {
                OUTPUT = value;
            } else if (key == "INSTALLATION") {
                INSTALLATION = value;
            } else if (key == "USE_BLSRC") {
                USE_BLSRC = (value == "true");
            } else if (key == "RESOURCE_FILE") {
                RESOURCE_FILE = value;
            }
        }
    }
}