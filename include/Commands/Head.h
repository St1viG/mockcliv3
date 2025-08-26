#ifndef MOCKCLIV2_HEAD_H
#define MOCKCLIV2_HEAD_H

#include "../ICommand.h"

class Head: public ICommand{
public:
    void execute() override;

    explicit Head(const std::vector<std::string>& elements);

private:
    std::vector<std::string> elements;
    static const std::vector<int> validElements;
};
#endif //MOCKCLIV2_HEAD_H
