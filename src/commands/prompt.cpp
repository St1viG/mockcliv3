#include "../../include/Commands/Prompt.h"

const std::vector<int> Prompt::validElements = {true, false, false, false, 1, 1};

void Prompt::execute(){
    InputHandler::Instance()->setCmdPrompt(newCmdPrompt);
}


Prompt::Prompt(const std::vector<std::string>& elements) {
    ErrorHandler::checkCommandElements(elements, validElements);
    this->newCmdPrompt = elements[4];
}
