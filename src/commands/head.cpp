#include "../../include/Commands/Head.h"

const std::vector<int> Head::validElements = {true, true, true, true, 1, 1};

void Head::execute() {
    elements[1].erase(0,1);
    int n = std::stoi(elements[1]);
    std::string final,line;
    std::istringstream stream(elements[4]);
    for(int i=0;i<n;i++){
        if(!std::getline(stream,line))
            break;
        final += "\n" + line;
    }
    final.erase(0,1);
    output(final, elements[3]);
}

Head::Head(const std::vector<std::string>& elements) {
    this->elements = elements;
    if(elements.size()<5)
        this->elements.insert(this->elements.begin() + 4 , InputHandler::awaitArg());
    if(elements[4][0]!='"')
        this->elements[4] = getFileContent(elements[4]);
    ErrorHandler::checkCommandElements(this->elements, validElements);
}

