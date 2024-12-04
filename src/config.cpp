#include "config.h"
#include <fstream>
#include <sstream>
#include <iostream>

std::map<std::string, std::string> config;

void loadConfig(const std::string& filename) {
    std::ifstream file(filename);
    std::string line;
    while (std::getline(file, line)) {
        std::istringstream is_line(line);
        std::string key;
        if (std::getline(is_line, key, '=')) {
            std::string value;
            if (std::getline(is_line, value)) {
                config[key] = value;
            }
        }
    }
}
