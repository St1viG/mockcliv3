#ifndef MOCKCLIV2_RM_H
#define MOCKCLIV2_RM_H

#include "../ICommand.h"

class Rm: public ICommand{
public:
    void execute() override;

    explicit Rm(const std::vector<std::string>& elements);

private:
    std::string fileName;
    static const std::vector<int> validElements;
};
#endif //MOCKCLIV2_RM_H
