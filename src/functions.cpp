#include "../include/Functions.h"

void removeQuotationMarks(std::string& s){
    if(s.front()=='"')
        s.erase(0,1);
    if(s.back() == '"')
        s.pop_back();
}

void output(std::string& argument, std::string& filename) {
    std::string batchOutput = CmdExecutor::Instance()->batchOut;
    removeQuotationMarks(argument);
    if(CmdExecutor::Instance()->checkPipe()){
        if(!filename.empty()) {
            throw InvalidPipeUsage("output inside a pipe");
        }
        else
            CmdExecutor::Instance()->setPrevOut(argument);
    }else{
            if (filename.empty()) {
                if(batchOutput.empty()) {
                    argument.append("\n");
                    std::cout << argument;
                }else{
                    outputInFile(batchOutput, argument);
                }
            } else {
                outputInFile(filename, argument);
            }
    }
}

bool isValidChar(char c) {
    return c == '.' || c == '"' || c == '-' || c == '|' || c == '<' || c == '>' || c == '/';
}

bool aloneDot(const std::string& line, const int& pos){
    return line[pos] == '.' && isspace(line[pos - 1]) && isspace(line[pos + 1]);
}
