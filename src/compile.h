#ifndef COMPILE_H
#define COMPILE_H

#include <string>
#include <map>

extern std::map<std::string, std::string> config;

void compileCpp();
void compileRust();
void compileCSharp();
void compileProject();

#endif // COMPILE_H
