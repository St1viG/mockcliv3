#ifndef MOCKCLIV2_TOUCH_H
#define MOCKCLIV2_TOUCH_H

#include "../ICommand.h"

class Touch: public ICommand{
public:
    void execute() override;

    explicit Touch(const std::vector<std::string>& elements);

private:
    std::string fileName;
    static const std::vector<int> validElements;
};
#endif //MOCKCLIV2_TOUCH_H
