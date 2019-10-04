//
// Created by jurjen on 30-7-19.
//

#include <vector>
#include "compress.h"
using namespace zipper;

void compress::compressFile(std::vector<std::string> collection, Config conf) {
    writeTxt(collection);
    std::ifstream input("collection.txt");
    Zipper zipper("ziptest.zip");
    zipper.add(input, "collection");
    zipper.close();
    serverConnect::sendFiles(conf);
}

void compress::writeTxt(std::vector<std::string> collection){
    std::ofstream outFile("collection.txt");
    for (const auto &e : collection) outFile << e << "\n";
}
