

cmake_minimum_required(VERSION 3.13)
project(Implementation_Scanner_)
set(CMAKE_CXX_STANDARD 17)
set(SOURCE_FILES main.cpp)
find_package(ZLIB)

include(ExternalProject)
set(EXTERNAL_INSTALL_LOCATION ${CMAKE_BINARY_DIR}/external)
ExternalProject_Add(zipper
        GIT_REPOSITORY    https://github.com/sebastiandev/zipper
        CMAKE_ARGS -DCMAKE_INSTALL_PREFIX=${EXTERNAL_INSTALL_LOCATION}
        )
ExternalProject_Add(restclient-cpp
        GIT_REPOSITORY https://github.com/mrtazz/restclient-cpp
        CMAKE_ARGS -DCMAKE_INSTALL_PREFIX=${EXTERNAL_INSTALL_LOCATION}
        )

ExternalProject_Get_Property(zipper install_dir)
ExternalProject_Get_Property(restclient-cpp install_dir)

include_directories(include/nlohmann include/PicoSHA2 ${EXTERNAL_INSTALL_LOCATION}/include)
link_directories(${EXTERNAL_INSTALL_LOCATION}/lib)
add_executable(Implementation_Scanner_
        src/main.cpp
        src/main.h
        src/config.cpp
        src/config.h
        src/scan.cpp
        src/scan.h
        src/compress.cpp
        src/compress.h
        src/serverConnect.cpp src/serverConnect.h src/base64.cpp src/base64.h)
add_dependencies(Implementation_Scanner_ zipper restclient-cpp)
target_link_libraries(Implementation_Scanner_ zip pthread z)
target_link_libraries(Implementation_Scanner_ ${EXTERNAL_INSTALL_LOCATION}/lib/libZipper-static.a ${EXTERNAL_INSTALL_LOCATION}/lib/librestclient-cpp.so)

