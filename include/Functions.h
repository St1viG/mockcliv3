#ifndef MOCKCLIV3_FUNCTIONS_H
#define MOCKCLIV3_FUNCTIONS_H

#include <iostream>

#include "Parser.h"
#include "FileManipulation.h"

void output(std::string& argument, std::string& filename);

[[nodiscard]] bool isValidChar( char c);

void removeQuotationMarks(std::string& s);

[[nodiscard]] bool aloneDot(const std::string& line, const int& pos);

#endif //MOCKCLIV3_FUNCTIONS_H