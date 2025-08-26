#ifndef MOCKCLIV2_FILEMANIPULATION_H
#define MOCKCLIV2_FILEMANIPULATION_H

#include <iostream>
#include <fstream>
#include <string>
#include "../include/ErrorTypes.h"

[[nodiscard]] bool fileExists(const std::string& filename);

void createFile(const std::string& filename);

void deleteFile(const std::string& filename);

void truncate(const std::string& filename);

void writeFile(const std::string& filename, const std::string& text);

void appendFile(const std::string& filename, const std::string& text);

void outputInFile(std::string&filename, const std::string& text);

std::string getFileContent(const std::string& filename);

#endif //MOCKCLIV2_FILEMANIPULATION_H
