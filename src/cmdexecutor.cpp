#include "../include/CmdExecutor.h"
#include "../include/AllCommands.h"

CmdExecutor* CmdExecutor::Instance() {
    static CmdExecutor instance;
    return &instance;
}

void CmdExecutor::create(std::vector<std::string>& elements) {
    std::unique_ptr<ICommand> cmd;
    std::vector<std::string> cmdNames = {"echo", "prompt", "time", "date", "touch", "truncate", "rm", "wc", "tr",
                                         "head", "batch"};
    static std::unordered_map<std::string, int> mapCmd;
    for (int i = 0; i < cmdNames.size(); i++)
        mapCmd[cmdNames[i]] = i + 1;
    std::string prevOut = CmdExecutor::Instance()->getPrevOut();
    std::vector<std::string>arguments;
    if (!prevOut.empty()) {
        elements.insert(elements.begin() + 4,'"' + prevOut + '"');
    }
    if(!elements[2].empty()) {
        elements.insert(elements.begin() + 4, getFileContent(elements[2].erase(0,1)));
    }
    switch (mapCmd[elements[0]]) {
        case 1: {
            cmd = std::make_unique<Echo>(elements);
            break;
        }
        case 2: {
            cmd = std::make_unique<Prompt>(elements);
            break;
        }
        case 3: {
            cmd = std::make_unique<Time>(elements);
            break;
        }
        case 4: {
            cmd = std::make_unique<Date>(elements);
            break;
        }
        case 5: {
            cmd = std::make_unique<Touch>(elements);
            break;
        }
        case 6: {
            cmd = std::make_unique<Truncate>(elements);
            break;
        }
        case 7: {
            cmd = std::make_unique<Rm>(elements);
            break;
        }
        case 8: {
            cmd = std::make_unique<Wc>(elements);
            break;
        }
        case 9: {
            cmd = std::make_unique<Tr>(elements);
            break;
        }
        case 10: {
            cmd = std::make_unique<Head>(elements);
            break;
        }
        case 11: {
            cmd =std::make_unique<Batch>(elements);
            break;
        }
        default:
            throw CommandNotFound(elements[0]);
    }
    cmd->execute();
    clearerr(stdin);
    std::cin.clear();
}

void CmdExecutor::setPrevOut(const std::string& value) {
    this->pipeInOut= value;
}


std::string CmdExecutor::getPrevOut(){
    std::string _pipeInOut = this->pipeInOut;
    this->pipeInOut.clear();
    return _pipeInOut;
}

bool CmdExecutor::checkPipe() const{
    return pipe;
}

void CmdExecutor::setPipe(bool value) {
    this->pipe = value;
}
