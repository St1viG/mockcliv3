#ifndef MOCKCLIV2_TIME_H
#define MOCKCLIV2_TIME_H

#include <iomanip>

#include "../ICommand.h"

class Time: public ICommand{
public:
    void execute() override;

    explicit Time(const std::vector<std::string>& elements);

private:
    std::string outputFile;
    static const std::vector<int> validElements;
};
#endif //MOCKCLIV2_TIME_H
