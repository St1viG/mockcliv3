#include "../../include/Commands/Echo.h"


const std::vector<int> Echo::validElements = {true, false, true, true, 1, 1};



void Echo::execute() {
    output(elements[4],elements[3]);
}

Echo::Echo(const std::vector<std::string>& elements) {
    this->elements = elements;
    if(elements.size()<5)
        this->elements.insert(this->elements.begin() + 4 , InputHandler::awaitArg());
    if (this->elements[4][0] != '"') {
        this->elements[4] = getFileContent(elements[4]);
    }
    ErrorHandler::checkCommandElements(this->elements,validElements);
}
