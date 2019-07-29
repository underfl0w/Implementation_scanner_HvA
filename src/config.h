#ifndef IMPLEMENTATION_SCANNER__CONFIG_H
#define IMPLEMENTATION_SCANNER__CONFIG_H

#include <iostream>
#include <iomanip>
#include <map>
#include <cstdlib>
#include <map>
#include "../include/nlohmann/json.hpp"
using json = nlohmann::json;

    class Config
    {
    public:
        Config(std::string fileName);
        ~Config();

        void Reload();

        int Microseconds;
        std::vector<std::string> recursiveDirectories;
        std::vector<std::string> nonRecursiveDirectories;
        std::map<std::string,int> WhiteListedFiles;
        std::vector<std::string> whiteListedFile;
        std::vector<std::string> whiteListedFolder;


    private:
        void loadFolders(json j);
        void loadWhiteList(json j);

        std::string fileName;
        std::vector<std::string> w;
        std::map<std::string, std::string> stringContents;
        std::map<std::string, int> intBoolContents;
        std::map<std::string, double> doubleContents;
    };




#endif //IMPLEMENTATION_SCANNER__CONFIG_H
