//
// Created by jurjen on 13-09-19.
//

#ifndef IMPLEMENTATION_SCANNER__SERVERCONNECT_H
#define IMPLEMENTATION_SCANNER__SERVERCONNECT_H
#include "restclient-cpp/restclient.h"
#include "base64.h"
#include <fstream>
#include <string>
#include <iostream>

class serverConnect
        {
public:
    static void sendFiles();

private:
        int updateConfig();
        static std::vector<BYTE> ReadAllBytes(char const* filename);
};


#endif //IMPLEMENTATION_SCANNER__SERVERCONNECT_H
