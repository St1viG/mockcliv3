#ifndef MOCKCLIV3_PARSER_H
#define MOCKCLIV3_PARSER_H

#include<iostream>
#include<sstream>

#include "CmdExecutor.h"

extern std::string endLine;

class Parser{
public:

    static void accept(const std::string& basicString);

};

#endif //MOCKCLIV3_PARSER_H
