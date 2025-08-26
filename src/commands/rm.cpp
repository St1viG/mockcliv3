#include "../../include/Commands/Rm.h"

const std::vector<int> Rm::validElements = {true, false, false, false, 1, 1};

void Rm::execute() {
    deleteFile(fileName);
}

Rm::Rm(const std::vector<std::string>& elements) {
    ErrorHandler::checkCommandElements(elements, validElements);
    this->fileName = elements[4];
}
