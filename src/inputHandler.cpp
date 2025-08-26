#include "../include/InputHandler.h"

InputHandler* InputHandler::Instance(){
    static InputHandler instance;
    return &instance;
}
void InputHandler::listen() {
    std::cout<<cmdPrompt<<" ";
    std::string input_str;
    getline(std::cin,input_str);
    if (input_str.length() > 512) {
        input_str.resize(512);
    }else{
        if(!input_str.empty()) {
            ErrorHandler::checkSyntax(input_str);
            InputHandler::forward(input_str);
        }
    }
}

void InputHandler::forward(const std::string& input_str) {
    int len = input_str.length(), prev = -1;
    bool in = false;

    for(int i=0;i<len;i++){
        if(input_str[i] == '"')
            in = !in;
        else if(input_str[i] == '|' && !in){
            if(!CmdExecutor::Instance()->checkPipe()){
                CmdExecutor::Instance()->setPipe(true);
            }
            Parser::accept(input_str.substr(prev + 1,i-1 - prev));
            //dodati error za situaciju $ | .... i $ ..... |
            prev= i;
        }
    }
    CmdExecutor::Instance()->setPipe(false);
    Parser::accept(input_str.substr((prev + 1)));
}

std::string InputHandler::awaitArg() {
    std::string argument, line;
    while(std::getline(std::cin,line)){
        if (std::cin.eof()) {
            std::cin.clear();
            break;
        }
        argument.append("\n" + line);
    }
    argument.erase(0,1);
    return '"' + argument + '"';
}

void InputHandler::setCmdPrompt(std::string& value) {
    removeQuotationMarks(value);
    cmdPrompt= value;
}




