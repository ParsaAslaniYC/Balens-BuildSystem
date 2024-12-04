#include "compile.h"
#include <cstdlib>
#include <string>

void compileCpp() {
    std::string command = "g++ " + config["SRC_DIR"] + "/*.cpp -I" + config["INCLUDE_DIR"] + " " + config["FLAGS"] + " -o " + config["OUTPUT"];
    system(command.c_str());
}

void compileRust() {
    std::string command = "rustc " + config["SRC_DIR"] + "/*.rs -o " + config["OUTPUT"] + " " + config["FLAGS_RUST"];
    system(command.c_str());
}

void compileCSharp() {
    std::string command = "dotnet build " + config["SRC_DIR"] + " --output " + config["OUTPUT"] + " " + config["FLAGS_CSHARP"];
    system(command.c_str());
}

void compileProject() {
    if (config["COMPILER"] == "g++") {
        compileCpp();
    } else if (config["COMPILER"] == "rustc") {
        compileRust();
    } else if (config["COMPILER"] == "dotnet") {
        compileCSharp();
    }
}
