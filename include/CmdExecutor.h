#ifndef MOCKCLIV3_CMDEXECUTOR_H
#define MOCKCLIV3_CMDEXECUTOR_H

#include <iostream>

#include "ICommand.h"

extern std::string endLine;

class CmdExecutor{
public:
    static CmdExecutor* Instance();

    static void create(std::vector<std::string>& elements);

    std::string getPrevOut();

    void setPrevOut(const std::string& value);

    [[nodiscard]] bool checkPipe() const;

    void setPipe(bool value);

    std::string batchOut;

private:
    bool pipe = false;
    std::string pipeInOut;
};

#endif //MOCKCLIV3_CMDEXECUTOR_H
