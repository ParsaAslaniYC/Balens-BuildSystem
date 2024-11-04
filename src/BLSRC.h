#ifndef BLSRC_H
#define BLSRC_H

#include <vector>
#include <string>

void parseBLSRCFile(const std::string& blsrcFile, std::vector<std::string>& src_files);
void compileResources(const std::string& resourceFile, const std::string& outputFile);

#endif // BLSRC_H