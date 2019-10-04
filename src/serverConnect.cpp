//
// Created by jurjen on 13-09-19.
//

#include <vector>
#include <iostream>
#include <iterator>
#include "serverConnect.h"

std::string serverConnect::registerToAPI(Config set, std::string uuid){
    std::string group = "http://" +set.server+ "/group/" +set.group;

    std::string json = "{\"uuid\":" "\"" +  uuid + "\", \"group\":""\"" + group +"/\"}";
    RestClient::Response rest;
    rest = RestClient::post(set.server+"/devices/", "application/json", json );

}

void serverConnect::sendFiles(Config set) {
    std::vector<BYTE> x = ReadAllBytes("ziptest.zip");

    std::string encodedData = base64_encode(&x[0], x.size());
    std::string device = "http://" + set.server + "/devices/" + set.uuid + "/";
    std::string json = "{\"zipfile\": \"" + encodedData + "\", \"device\":""\"" + device +"\"}";
    RestClient::Response r;
    r = RestClient::post(set.server+"/zipfiles/", "application/json", json);

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
