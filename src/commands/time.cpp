#include "../../include/Commands/Time.h"

const std::vector<int> Time::validElements = {true, false, false, true, 0, 0};

void Time::execute() {
    time_t now= time(nullptr);
    tm* localTime = localtime(&now);
    std::ostringstream stream;
    stream << std::put_time(localTime, "%H:%M:%S");
    std::string str = stream.str();
    output(str, outputFile);
}

Time::Time(const std::vector<std::string>& elements) {
    ErrorHandler::checkCommandElements(elements, validElements);
    this->outputFile = elements[3];
}
