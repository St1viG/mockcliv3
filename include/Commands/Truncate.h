#ifndef MOCKCLIV2_TRUNCATE_H
#define MOCKCLIV2_TRUNCATE_H

#include "../ICommand.h"

class Truncate: public ICommand{
public:
    void execute() override;

    explicit Truncate(const std::vector<std::string>& elements);

private:
    std::string fileName;
    static const std::vector<int> validElements;
};
#endif //MOCKCLIV2_TRUNCATE_H
