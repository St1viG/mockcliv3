#include "../../include/Commands/Batch.h"

const std::vector<int> Batch::validElements = {true, false, true, true, 1, 1};

void Batch::execute() {
    if(!elements[3].empty())
        CmdExecutor::Instance()->batchOut = elements[3];
    std::string line;
    if(elements.size()<5)
        elements.insert(this->elements.begin() + 4, InputHandler::awaitArg());
    else if(elements[4][0] != '"')
        elements[4] = getFileContent(elements[4]);
    ErrorHandler::checkCommandElements(elements,validElements);
    removeQuotationMarks(elements[4]);
    std::istringstream stream(elements[4]);
    while(std::getline(stream,line)){
        try {
            if(!line.empty())
                InputHandler::forward(line);
        }catch(BaseException& e){
            ErrorHandler::handleError(e);
        }
    }
    CmdExecutor::Instance()->batchOut.clear();
}

Batch::Batch(const std::vector<std::string>& elements) {
    ErrorHandler::checkCommandElements(elements,validElements);
    this->elements = elements;
}
