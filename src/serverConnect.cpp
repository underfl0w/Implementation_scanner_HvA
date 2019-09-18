//
// Created by jurjen on 13-09-19.
//

#include <vector>
#include <iostream>
#include <iterator>

#include "serverConnect.h"

std::string domain = "scanner.underfl0w.nl";


void serverConnect::sendFiles() {
    std::cout << "WOOOOOOO";

    std::vector<BYTE> x = ReadAllBytes("ziptest.zip");

    std::string encodedData = base64_encode(&x[0], x.size());

    RestClient::Response r;
    r = RestClient::post(domain, "application/json", "{\"foo\": \"" + encodedData + "\"}");




}

int serverConnect::updateConfig() {
    return 0;
}

std::vector<BYTE> serverConnect::ReadAllBytes(char const* filename)
{
    std::ifstream file(filename, std::ios::binary);
    file.unsetf(std::ios::skipws);
    std::streampos fileSize;

    file.seekg(0, std::ios::end);
    fileSize = file.tellg();
    file.seekg(0, std::ios::beg);

    // reserve capacity
    std::vector<BYTE> vec;
    vec.reserve(fileSize);

    // read the data:
    vec.insert(vec.begin(),
               std::istream_iterator<BYTE>(file),
               std::istream_iterator<BYTE>());

    return vec;
}
