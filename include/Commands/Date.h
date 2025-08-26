#ifndef MOCKCLIV2_DATE_H
#define MOCKCLIV2_DATE_H

#include <iomanip>

#include "../ICommand.h"

class Date: public ICommand{
public:
    void execute() override;

    explicit Date(const std::vector<std::string> &elements);

private:
    std::string outputFile;
    static const std::vector<int> validElements;
};
#endif //MOCKCLIV2_DATE_H
