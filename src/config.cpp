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
    //TODO: write ALL the things
}

void Config::Reload() {

    std::ifstream fileStream(fileName); // Load the json settings file from disk

    if (fileStream) // Verify that the file was opened successfully
    {
        json j = json::parse(fileStream);
        auto wow = j["directories"]["Folders"]["Recursive"]["Folders"].get<int>();
        std::cout << wow;
        loadFolders(j);

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
    for (int i = 0; i < recursiveFolders; ++i) {
        nonRecursiveDirectories.push_back(j["directories"]["Folders"]["NonRecursive"][std::to_string(i)]["path"].get<std::string>());
    }

}
