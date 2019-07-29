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
    for (int i = 0; i < conf.nonRecursiveDirectories.size(); ++i) {
        for(auto& p: std::filesystem::directory_iterator(conf.nonRecursiveDirectories[i])) {
            std::cout << p.path() << '\n';
            std::cout << p.is_regular_file() << '\n';
            if(p.is_directory() == 0){

                std::ifstream f(p.path(), std::ios::binary);
                std::vector<unsigned char> s(picosha2::k_digest_size);
                std::string hexHash;
                picosha2::hash256(f, s.begin(), s.end());
                picosha2::bytes_to_hex_string(s.begin(), s.end(), hexHash);
                std::cout << hexHash;

                // Convert the path to a char array.
                char cstr[std::string(p.path()).size() + 1];
                strcpy(cstr, p.path().c_str());
                getFileCreationTime(cstr);
            }
        }
    }
    //conf.recursiveDirectories
    // Scan the files given in path

    // check config for whitelist

    // calculate hashes

    // last modification time

    // if settings is recursive, scan directories inside current directory

    // return results
}

std::string scan::getFileCreationTime(char *path) {
    struct stat attr;
    stat(path, &attr);
    return (ctime(&attr.st_mtime));
}




