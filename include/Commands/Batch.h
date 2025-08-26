#ifndef MOCKCLIV2_BATCH_H
#define MOCKCLIV2_BATCH_H

#include "../ICommand.h"

class Batch: public ICommand{
public:
    void execute() override;

    explicit Batch(const std::vector<std::string>& elements);

private:
    std::vector<std::string> elements;
    static const std::vector<int> validElements;
};
#endif //MOCKCLIV2_BATCH_H
