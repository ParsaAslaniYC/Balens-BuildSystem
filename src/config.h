#ifndef CONFIG_H
#define CONFIG_H

#include <string>
#include <map>

extern std::map<std::string, std::string> config;

void loadConfig(const std::string& filename);

#endif // CONFIG_H
