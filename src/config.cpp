#include "config.h"
#include <fstream>

using namespace std;

Config::Config(std::string fileName)
        :fileName(fileName)
{
    Reload();
}

Config::~Config()
{
}

void Config::Reload() {

    std::ifstream fileStream(fileName); // Load the json settings file from disk

    if (fileStream) // Verify that the file was opened successfully
    {
        json j = json::parse(fileStream);
        server = j["Server"].get<string>();
        group = j["Group"].get<string>();
        Microseconds = j["Microseconds"].get<int>();
        loadFolders(j);
        if (j["uuid"].is_null())
        {
            j["uuid"] = "empty";
            std::ofstream o("config_file.json");
            o << std::setw(4) << j << std::endl;
            Reload();
        }
        else
        {
            uuid = j["uuid"].get<string>();

        }
        fileStream.close();
    }
    else
    {
        cerr << "File could not be opened!\n"; // Report error
        cerr << "Error code: " << strerror(errno); // Get some info as to why
    }

}


// store the data and return the settings
void Config::loadFolders(json j) {

    auto recursiveFolders = j["directories"]["Folders"]["Recursive"]["Folders"].get<int>();
    auto nonRecursiveFolders = j["directories"]["Folders"]["NonRecursive"]["Folders"].get<int>();

    for (int i = 0; i < recursiveFolders; ++i) {
        recursiveDirectories.push_back(j["directories"]["Folders"]["Recursive"][std::to_string(i)]["path"].get<std::string>());
    }
    for (int i = 0; i < nonRecursiveFolders; ++i) {
        nonRecursiveDirectories.push_back(j["directories"]["Folders"]["NonRecursive"][std::to_string(i)]["path"].get<std::string>());
    }
    loadWhiteList(j);
}

void Config::loadWhiteList(json j) {
    auto whitelist = j["Whitelist"]["Files"]["Files"].get<int>();
    for (int i = 0; i < whitelist; ++i) {
        WhiteListedFiles[
        (j["Whitelist"]["Files"][std::to_string(i)]["fileName"].get<std::string>())] = 10
        ;
    }

}
