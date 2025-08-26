#include "../include/FileManipulation.h"

#include <filesystem>

bool fileExists(const std::string& filename) {
    return std::filesystem::exists(filename);
}

void createFile(const std::string& filename) {
    if(fileExists(filename))
        throw FileAlreadyExists(filename);
    std::ofstream file(filename);
    if(!fileExists(filename))
        throw FileCreationFailed(filename);
}

void deleteFile(const std::string& filename) {
    if(!fileExists(filename))
        throw FileNotFound(filename);
    if(std::remove(filename.c_str()))
        throw FileDeletionFailed(filename);
}

void truncate(const std::string& filename) {
    std::ofstream file(filename, std::ios::trunc);
}

std::string getFileContent(const std::string& filename) {
    if(!fileExists(filename))
        throw FileNotFound(filename);
    std::ifstream file(filename);
    std::string content;
    std::string line;
    while (std::getline(file, line)) {
            content += line + "\n";
    }
    if(!content.empty())
        content.pop_back();
    return '"' + content + '"';
}

void writeFile(const std::string& filename, const std::string& text){
    std::ofstream file(filename);
    if(!file.is_open()){
        createFile(filename);
    }
    file << text;
    file.close();
}

void appendFile( const std::string& filename, const std::string& text){
    std::ofstream file(filename, std::ios::app);
    if(!file.is_open()){
        createFile(filename);
    }
    file << text;
    file.close();
}
void outputInFile(std::string& filename, const std::string& text){
    std::string temp = filename;
    if(temp[0]=='>'){
        if(temp[1]=='>'){
            temp.erase(0,2);
            appendFile(temp,text);
            return;
        }
        else{
            temp.erase(0,1);
        }
    }
    writeFile(temp,text);
}

