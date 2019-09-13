//
// Created by jurjen on 30-7-19.
//

#ifndef IMPLEMENTATION_SCANNER__COMPRESS_H
#define IMPLEMENTATION_SCANNER__COMPRESS_H
#include <stdlib.h>
#include <fstream>
#include <zipper/zipper.h>
#include <zip.h>
#include <zipper/unzipper.h>
#include <zipper/tools.h>
class compress {
public:
    static void compressFile(std::vector<std::string> collection);
private:

    static void writeTxt(std::vector<std::string> collection);
};


#endif //IMPLEMENTATION_SCANNER__COMPRESS_H
