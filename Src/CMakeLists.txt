cmake_minimum_required(VERSION 3.4)

#set compiler and linker to gcc 5.0
set(CMAKE_CXX_COMPILER "/boot/system/bin/g++-x86")

project(Bme)

set(CMAKE_LIBRARY_PATH $(CMAKE_LIBRARY_PATH) /boot/system/lib)

file(GLOB BmeSrc 
"*.h"
"*.cpp"
"Controllers/*.h" 
"Controllers/*.cpp"
"Models/*.h" 
"Models/*.cpp"
"Views/*.h" 
"Views/*.cpp"
)

set( ProjectIncludes "." "Controllers" "Models" "Views")

#find_package(LibXml2 REQUIRED)
include_directories(${ProjectIncludes})

link_directories("/boot/system/lib/x86")

#link_directories("/boot/system/lib")


add_executable(Bme ${BmeSrc})
target_link_libraries(Bme be bnetapi crypto translation ssl)


