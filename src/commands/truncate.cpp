#include "../../include/Commands/Truncate.h"

const std::vector<int> Truncate::validElements = {true, false, false, false, 1, 1};

void Truncate::execute() {
    truncate(fileName);
}

Truncate::Truncate(const std::vector<std::string>& elements) {
    ErrorHandler::checkCommandElements(elements, validElements);
    this->fileName = elements[2];
}
