#ifndef MOCKCLIV3_IHANDLER_H
#define MOCKCLIV3_IHANDLER_H

#include<iostream>
#include<string>

#include "Functions.h"
#include "Parser.h"
#include "CmdExecutor.h"

class InputHandler{
public:
    static InputHandler* Instance();

    void listen();

    static std::string awaitArg();

    void setCmdPrompt(std::string& value);

    static void forward(const std::string& input_str) ;

private:
    std::string cmdPrompt = "$";
};

#endif //MOCKCLIV2_IHANDLER_H