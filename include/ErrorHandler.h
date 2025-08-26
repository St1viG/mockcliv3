#ifndef MOCKCLIV3_ERRORHANDLER_H
#define MOCKCLIV3_ERRORHANDLER_H

#include <iostream>

#include "Functions.h"
#include "ErrorTypes.h"

class ErrorHandler{
public:
    static ErrorHandler* Instance();

    static void handleError(BaseException& e);

    [[nodiscard]] bool getLoop() const;

    void switchLoop();

    static void checkSyntax(const std:: string& line) ;

    static void checkCommandElements(std::vector<std::string> elements, std::vector<int> validElements);

private:
    bool loop = true;
};

#endif //MOCKCLIV3_ERRORHANDLER_H
