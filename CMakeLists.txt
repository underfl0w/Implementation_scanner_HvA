

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


SET(ZIPPER_INCLUDE_DIR ${EXTERNAL_INSTALL_LOCATION}/3rd_party/src/ForexConnectDownload/include)
SET(ZIPPER_LIB_DIR ${CMAKE_CURRENT_BINARY_DIR}/3rd_party/src/ForexConnectDownload/lib)

ExternalProject_Get_Property(zipper install_dir)
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
)
add_dependencies(Implementation_Scanner_ zipper)
target_link_libraries(Implementation_Scanner_ zip pthread  )
target_link_libraries(Implementation_Scanner_ ${EXTERNAL_INSTALL_LOCATION}/lib/libZipper-static.a)

