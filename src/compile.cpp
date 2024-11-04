#include "compile.h"
#include <iostream>
#include <filesystem>
#include <cstdlib>

namespace fs = std::filesystem;

extern std::string COMPILER;
extern std::string INCLUDE_DIR;
extern std::string FLAGS;

void compile(const std::string& src_file, const std::string& obj_file) {
    if (!fs::exists(obj_file) || fs::last_write_time(src_file) > fs::last_write_time(obj_file)) {
        std::cout << "\033[32mCompiling " << src_file << "...\033[0m" << std::endl;
        std::string command = COMPILER + " -c " + src_file + " -o " + obj_file + " -I" + INCLUDE_DIR + " " + FLAGS;
        if (std::system(command.c_str()) != 0) {
            std::cerr << "\033[31mCompilation failed for " << src_file << "\033[0m" << std::endl;
            exit(1);
        }
    }
}