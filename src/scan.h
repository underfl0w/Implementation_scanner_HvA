
#ifndef IMPLEMENTATION_SCANNER__SCAN_H
#define IMPLEMENTATION_SCANNER__SCAN_H
#include <iostream>
#include <chrono>
#include <string>
#include <iomanip>
#include <fstream>
#include <filesystem>
#include "config.h"
#include "compress.h"
#include "../include/PicoSHA2/picosha2.h"

    class scan
    {
    public:
        void load_setting();

    private:
        void scan_directory();
        std::string getFileCreationTime(char *path);

        std::string fileHashing(std::string path);
    };



#endif //IMPLEMENTATION_SCANNER__SCAN_H
