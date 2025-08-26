#include "../../include/Commands/Tr.h"


const std::vector<int> Tr::validElements = {true, false, true, true, 2, 3};

void Tr::execute(){
    std:: string what = elements[5].erase(0,1), with = elements.size()==7 ? elements[6].erase(0,1): "";
    what.pop_back();
    with.pop_back();
    if(elements[4][0]!='"')
        elements[4] = getFileContent(elements[4]);
    elements[4] = std::regex_replace(elements[4], std::regex( what), with);
    output(elements[4],elements[3]);
}


Tr::Tr(const std::vector<std::string>& elements){
    this->elements = elements;
    if(elements.size()<6)
        this->elements.insert(this->elements.begin() + 4,InputHandler::awaitArg());
    ErrorHandler::checkCommandElements(this->elements,validElements);
}