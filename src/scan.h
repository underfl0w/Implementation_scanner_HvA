
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
#include <crossguid/guid.hpp>
#include "serverConnect.h"


    class scan
    {
    public:
       void load_setting();

    private:
       static void scan_directory(Config conf);
       static std::string getFileCreationTime(char *path);

       static std::string fileHashing(std::string path);

       inline static bool exists_test(std::string p);
    };



#endif //IMPLEMENTATION_SCANNER__SCAN_H
