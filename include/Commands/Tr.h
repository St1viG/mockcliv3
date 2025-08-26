#ifndef MOCKCLIV3_TR_H
#define MOCKCLIV3_TR_H

#include <regex>

#include "../ICommand.h"

class Tr: public ICommand {
public:
    void execute() override;

    explicit Tr(const std::vector<std::string>& elements);

private:
    std::vector<std::string> elements;
    static const std::vector<int> validElements;
};
#endif //MOCKCLIV3_ECHO_H
