#include "../../include/Commands/Touch.h"

const std::vector<int> Touch::validElements = {true, false, false, false, 1, 1};

void Touch::execute() {
    createFile(fileName);
}
Touch::Touch(const std::vector<std::string>& elements) {
    ErrorHandler::checkCommandElements(elements, validElements);
    this->fileName = elements[4];
}
