#include "link.h"
#include <iostream>
#include <cstdlib>

extern std::string COMPILER;
extern std::string FLAGS;
extern std::string OUTPUT;

void link(const std::vector<std::string>& obj_files) {
    std::cout << "\033[34mLinking...\033[0m" << std::endl;
    std::string command = COMPILER + " -o " + OUTPUT + " " + FLAGS;
    for (const auto& obj_file : obj_files) {
        command += " " + obj_file;
    }
    if (std::system(command.c_str()) != 0) {
        std::cerr << "\033[31mLinking failed\033[0m" << std::endl;
        exit(1);
    }
}