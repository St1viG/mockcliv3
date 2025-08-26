#include "../../include/Commands/Wc.h"

const std::vector<int> Wc::validElements = {true, true, true, true, 1, 1};

void Wc::execute() {
    removeQuotationMarks(elements[4]);
    int counter = 0;
    if(elements[1] == "-w"){
        std::istringstream stream(elements[4]);
        std::string word;
        while(stream >> word)
            counter++;
    }
    else{
        if(elements[1] == "-c")
            counter = elements[4].length();
        else
            throw UnknownOption(elements[1]);
    }
    std::string cnt = std::to_string(counter);
    output(cnt,elements[3]);
}

Wc::Wc(const std::vector<std::string>& elements){
    this->elements = elements;
    if(elements.size()<5) {
        this->elements.push_back(InputHandler::awaitArg());
    }
    if(this->elements[4][0]!='"')
        this->elements[4] = getFileContent(this->elements[4]);
    ErrorHandler::checkCommandElements(this->elements, validElements);
}
