//
// Created by jurjen de Jonge on 31-5-19.
//

#include "scan.h"
#include <map>
#include <filesystem>
#include <sys/stat.h>

Config conf("config_file.json");

void scan::load_setting() {
     // Read the json file and store the configuration in memory.
     scan_directory();

/*     std::map<std::string, int>::iterator it ;
     it = conf.WhiteListedFiles.find("Notes.txt");
    if (it == conf.WhiteListedFiles.end())
        std::cout << "Key-value pair not present in map";
    else
        std::cout << "Key-value pair present : "
             << it->first << "->" << it->second;

    std::cout << std::endl;*/


}


void scan::scan_directory() {
    std::vector<std::string> dataCollector;

    // Scan all the non Recursive directories first.
    for (int i = 0; i < conf.nonRecursiveDirectories.size(); ++i) {
        for (auto &p: std::filesystem::directory_iterator(conf.nonRecursiveDirectories[i])) {
            if (p.is_regular_file() == 1) {
                if (conf.WhiteListedFiles.count(p.path().filename()) != 0) {
                    // File exists in whitelist.
                    // Lets do nothing.
                } else {
                    //Get the hash from the file
                    std::string path = p.path();
                   dataCollector.push_back(path +","+fileHashing(p.path()));
                }
            }
        }
    }
    // Time to scan the recursive directories.
    for (int i = 0; i < conf.nonRecursiveDirectories.size(); ++i) {

        for (auto &p: std::filesystem::recursive_directory_iterator(conf.recursiveDirectories[i])) {
            if (p.is_regular_file() == 1) {
                if (conf.WhiteListedFiles.count(p.path().filename()) != 0) {
                    // File exists in whitelist.
                    // Lets do nothing.
                } else {
                    //Get the hash from the file
                    std::string path = p.path();
                    dataCollector.push_back(path +","+fileHashing(p.path()));
                }
            }
        }
        compress::compressFile(dataCollector);

    }
}

std::string scan::getFileCreationTime(char *path) {
    struct stat attr;
    stat(path, &attr);
    return (ctime(&attr.st_mtime));
}

std::string scan::fileHashing(std::string p){
        // hashing magic happens here.
        //Get the hash from the file
        std::ifstream f(p, std::ios::binary);
        std::vector<unsigned char> s(picosha2::k_digest_size);
        std::string hexHash;
        picosha2::hash256(f, s.begin(), s.end());
        picosha2::bytes_to_hex_string(s.begin(), s.end(), hexHash);

        // Convert the path to a char array.
        char cstr[std::string(p).size() + 1];
        strcpy(cstr, p.c_str());

        // Combine last modification date and hash into a single hash.
        std::string src_str = hexHash + getFileCreationTime(cstr);
        std::vector<unsigned char> hash(picosha2::k_digest_size);
        picosha2::hash256(src_str.begin(), src_str.end(), hash.begin(), hash.end());
        return picosha2::bytes_to_hex_string(hash.begin(), hash.end());

    }





