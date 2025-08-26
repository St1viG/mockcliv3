#ifndef MOCKCLIV3_ECHO_H
#define MOCKCLIV3_ECHO_H

#include "../ICommand.h"

class Echo: public ICommand {
public:
    void execute() override;

    explicit Echo(const std::vector<std::string>& elements);

private:
    std::vector<std::string> elements;
    static const std::vector<int> validElements;
};
#endif //MOCKCLIV3_ECHO_H
