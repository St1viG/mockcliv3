#ifndef MOCKCLIV2_WC_H
#define MOCKCLIV2_WC_H

#include "../ICommand.h"

class Wc: public ICommand{
public:
    void execute() override;

    explicit Wc(const std::vector<std::string>& elements);

private:
    std::vector<std::string> elements;
    static const std::vector<int> validElements;
};
#endif //MOCKCLIV2_WC_H
