#include "../include/Parser.h"

void Parser::accept(const std::string& line) {

    int i = 0;
    bool wasQ = false;
    std::vector<std::string> elements(4);
    std::istringstream stream(line);
    std::string word;
    stream >> word;
    elements[0] = word;
    while (stream) {
        stream >> std::ws;
        if (stream.peek() == '"') {
            stream.get();
            std::getline(stream, word, '"');
            word.insert(word.begin(),'"');
            word.push_back('"');
            wasQ = true;
        }
        else {
            if (!(stream >> word))
                break;
        }
        if (!word.empty()) {
            if(word[0]=='>'){
                if(word.length()==1){
                    stream >> word;
                     word.insert(word.begin(),'>');
                }
                else{
                    if(word==">>"){
                        stream >> word;
                        word.insert(word.begin(),'>');
                        word.insert(word.begin(),'>');
                    }
                }
                i = 3;
            }
            else{
                if(wasQ){
                    elements.push_back(word);
                    wasQ=false;
                    continue;
                }
                else{
                    if (word[0] == '-') {
                        i = 1;
                    }else{
                        if(word == "<") {
                            stream >> word;
                            word.insert(word.begin(), '<');
                        }else{
                            if(word[0] == '<'){
                            }else{
                                elements.push_back(word);
                                continue;
                            }
                        }
                        i = 2;
                    }
                }
            }
        }
        if(!elements[i].empty()) {
            throw InvalidElement(elements[i]);
        }
        elements[i] = word;
    }
    CmdExecutor::create(elements);
}