#ifndef MOCKCLIV2_PROMPT_H
#define MOCKCLIV2_PROMPT_H

#include "../ICommand.h"

class Prompt: public ICommand{
public:
    void execute() override;

    explicit Prompt(const std::vector<std::string>& elements);

private:
    std::string newCmdPrompt;
    static const std::vector<int> validElements;
};
#endif //MOCKCLIV2_PROMPT_H
