#ifndef MOCKCLIV3_ICOMMAND_H
#define MOCKCLIV3_ICOMMAND_H

#include <iostream>

#include "Functions.h"
#include "ErrorHandler.h"
#include "InputHandler.h"

class ICommand{
public:
    virtual void execute()=0;
};

#endif //MOCKCLIV3_ICOMMAND_H