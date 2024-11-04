#include "args.h"
#include <iostream>
#include <cstdlib>

extern std::string OUTPUT;
extern std::string COMPILER;
extern std::string FLAGS;
extern std::string SRC_DIR;
extern std::string INCLUDE_DIR;
extern std::string BUILD_DIR;
extern bool CLEAN_COMMAND;

void parseArgs(int argc, char* argv[]) {
    for (int i = 1; i < argc; ++i) {
        std::string arg = argv[i];
        if (arg == "-o" || arg == "--output") {
            if (i + 1 < argc) {
                OUTPUT = argv[++i];
            }
        } else if (arg == "-c" || arg == "--compiler") {
            if (i + 1 < argc) {
                COMPILER = argv[++i];
            }
        } else if (arg == "-f" || arg == "--flags") {
            if (i + 1 < argc) {
                FLAGS = argv[++i];
            }
        } else if (arg == "-s" || arg == "--src") {
            if (i + 1 < argc) {
                SRC_DIR = argv[++i];
            }
        } else if (arg == "-i" || arg == "--include") {
            if (i + 1 < argc) {
                INCLUDE_DIR = argv[++i];
            }
        } else {
            std::cerr << "\033[31mUnknown parameter passed: " << arg << "\033[0m" << std::endl;
            exit(1);
        }
    }
}