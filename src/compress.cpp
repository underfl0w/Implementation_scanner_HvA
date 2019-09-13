//
// Created by jurjen on 30-7-19.
//

#include <vector>
#include "compress.h"
using namespace zipper;

void compress::compressFile(std::vector<std::string> collection) {
    writeTxt(collection);
    zipper::Zipper zipper("ziptest.zip");
    //std::ifstream input("collection.txt");
    //zipper.add(input, "collection");
    std::ofstream test1("test1.txt");
    test1 << "test file compression";
    test1.flush();
    test1.close();

    std::ifstream test1stream("test1.txt");

    zipper.add(test1stream, "test1.txt");

    test1stream.close();
    zipper.close();

    std::remove("test1.txt");
    zipper.close();

}

void compress::writeTxt(std::vector<std::string> collection){
    std::ofstream outFile("collection.txt");
    for (const auto &e : collection) outFile << e << "\n";
}
