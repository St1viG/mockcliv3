#include "../include/ErrorHandler.h"

ErrorHandler* ErrorHandler::Instance() {
    static ErrorHandler instance;
    return &instance;
}

bool ErrorHandler::getLoop() const{
    return this->loop;
};

void ErrorHandler::switchLoop() {
    this->loop = !this->loop;
}

void ErrorHandler::checkSyntax(const std:: string& line) {
    int size = line.size(),flag = 0, prevc_pos=1;;
    char prevc = line[1];
    std::vector<int>position;
    if(!(isspace(line[0]) || isalpha(line[0])))
        position.push_back(0);
    for(int i=1;i<size-1;i++){
        if(std::isalnum(line[i])){
            prevc = line[i];
            prevc_pos = i;
            continue;
        }else{
            if(line[i] == '"'){
                flag = (flag + 1) % 2;
            }else if(!flag){
                if(!std::isalnum(line[i]) && !isspace(line[i]) && !isValidChar(line[i])){
                    position.push_back(i);
                }else if(aloneDot(line,i)){
                    position.push_back(i);
                }else if(isValidChar(line[i]) && isValidChar(prevc)) {
                    if(line[i]=='>' && line[i-1] == '>' || line[i] == '-' && (prevc == '-' || prevc == '.') || line[i] == '.' && (prevc == '>' || prevc == '<') )
                        continue;
                    if(!position.empty() &&position.back()!=prevc_pos)
                        position.push_back(prevc_pos);
                    position.push_back(i);
                }

            }
        }
        if(line[i]!= '"' && !isspace(line[i])) {
            prevc = line[i];
            prevc_pos = i;
        }
    }
    if(!(isspace(line[size-1]) || std::isalnum(line[size-1]) || line[size-1] == '"'))
        position.push_back(size-1);
    if(!position.empty()) {
        throw LexicalError(line, position);
    }
}

void ErrorHandler::handleError(BaseException& e) {
    std::string x = std::string(e.what());
    output(x,CmdExecutor::Instance()->batchOut);
}


void ErrorHandler::checkCommandElements(std::vector<std::string> elements, std::vector<int> validElements){
    for(int i=0; i< validElements.size()-1;i++)
        if(!validElements[i] && !elements[i].empty()){
            throw InvalidElement(std::to_string(i));
        }
    if(elements.size()-4>validElements[5]){
        throw InvalidArguments(elements[0], validElements[5], ArgLimit::Maximum);
    }else if(elements.size()-4 <validElements[4]){
        throw InvalidArguments(elements[0], validElements[4], ArgLimit::Minimum);
    }
};
