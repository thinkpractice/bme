cmake_minimum_required(VERSION 3.4)
project(Bme)

set(CMAKE_LIBRARY_PATH $(CMAKE_LIBRARY_PATH) /boot/system/lib)

file(GLOB BmeSrc 
"*.h"
"*.cpp"
)

add_executable(Bme ${BmeSrc})

find_package(LibXml2 REQUIRED)

include_directories(${LIBXML2_INCLUDE_DIR})
target_link_libraries(Bme ${LIBXML2_LIBRARIES})
