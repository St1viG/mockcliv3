#include "../../include/Commands/Date.h"


const std::vector<int> Date::validElements = {true, false, false, true, 0, 0};

void Date::execute() {
    auto now = std::chrono::system_clock::now();
    std::time_t now_c = std::chrono::system_clock::to_time_t(now);
    std::tm localTime = *std::localtime(&now_c);
    std::ostringstream stream;
    stream << std::put_time(&localTime, "%Y-%m-%d");
    std::string str = stream.str();
    output(str,outputFile);
}

Date::Date(const std::vector<std::string>& elements) {
    ErrorHandler::checkCommandElements(elements, validElements);
    this->outputFile = elements[3];
}