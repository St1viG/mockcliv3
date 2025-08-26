#ifndef MOCKCLIV3_ERRORTYPES_H
#define MOCKCLIV3_ERRORTYPES_H

#include <exception>
#include <string>

class BaseException : public std::exception {
    std::string message;
public:
    explicit BaseException(const std::string& msg) : message("Error - " + msg) {}

    [[nodiscard]] const char* what() const noexcept override {
        return message.c_str();
    }
};

class InvalidElement: public BaseException{
public:
    explicit InvalidElement(const std::string& details) : BaseException("Invalid argument at position:" + details){}

};

enum class ArgLimit { Minimum, Maximum };

class InvalidArguments : public BaseException {
public:
    InvalidArguments(const std::string& command, int details, ArgLimit limit)
            : BaseException("Command " + command + " accepts " +
                            (limit == ArgLimit::Maximum ? "maximum " : "minimum ") +
                            std::to_string(details) + " argument(s)") {}
};


class UnknownOption: public BaseException{
public:
    explicit UnknownOption(const std::string& option) : BaseException("Unknown option:" + option){}

};

class CommandNotFound: public BaseException{
public:
    explicit CommandNotFound(const std::string& command) : BaseException("Command not found:" + command){}

};

class InvalidPipeUsage: public BaseException{
public:
    explicit InvalidPipeUsage(const std::string& details) : BaseException("Invalid Pipe Handling:" + details){}

};

class OutputInPipe: public InvalidPipeUsage{
public:
    explicit OutputInPipe() : InvalidPipeUsage("Output redirection inside a pipe"){}

};
class InputInPipe: public InvalidPipeUsage{
public:
    explicit InputInPipe() : InvalidPipeUsage("Input redirection inside a pipe"){}

};

class FileException : public BaseException {
    std::string path;
public:
    explicit FileException(const std::string& filePath, const std::string& msg = "")
            : BaseException("Error manipulating file =>" + msg + filePath) {}

};

class FileNotFound : public FileException {
    std::string path;
public:
    explicit FileNotFound(const std::string& filePath)
            : FileException(filePath,"File doesnt exist:" ) {}

};

class FileAlreadyExists : public FileException {
    std::string path;
public:
    explicit FileAlreadyExists(const std::string& filePath)
            : FileException(filePath,"File already exists." ) {}

};

class FileCreationFailed : public FileException {
    std::string path;
public:
    explicit FileCreationFailed(const std::string& filePath)
            : FileException(filePath,"File creation failed" ) {}

};

class FileDeletionFailed : public FileException {
    std::string path;
public:
    explicit FileDeletionFailed(const std::string& filePath)
            : FileException(filePath,"File deletion failed" ) {}

};


class LexicalError: public BaseException{
    std::string commandLine;
    std::vector<int> positions;
public:
    explicit LexicalError(const std::string& cmdLine, const std::vector<int>& pos)
            : BaseException(formatMessage(cmdLine, pos)),
              commandLine(cmdLine),
              positions(pos)
    {}
private:
    static std::string formatMessage(const std::string& commandLine, const std::vector<int>&pos){
        std::string message = "Lexical error:\n" + commandLine + "\n";
        int j=0;
        for (int i = 0; i <= pos.back(); i++) {
            if (i == pos[j]) {
                j++;
                message.push_back('^');
            } else {
                message.push_back(' ');
            }
        }
        return message;
    };

};

#endif //MOCKCLIV3_ERRORTYPES_H
