cmake_minimum_required(VERSION 3.4)

project(Bme)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_LIBRARY_PATH $(CMAKE_LIBRARY_PATH) /boot/system/lib)

file(GLOB BmeSrc
"*.h"
"*.cpp"
"Controllers/*.h"
"Controllers/*.cpp"
"Models/*.h"
"Models/*.cpp"
"Models/Protocols/*.h"
"Models/Protocols/*.cpp"
"Models/ChatMessages/*.h"
"Models/ChatMessages/*.cpp"
"Views/*.h"
"Views/*.cpp"
"Views/MessageItemViews/*.h"
"Views/MessageItemViews/*.cpp"
"Utils/*.h"
"Utils/*.cpp"
)

set( ProjectIncludes "." "Controllers" "Models" "Models/Protocols" "Models/ChatMessages" "Views" "Views/MessageItemViews" "Utils")
include_directories(${ProjectIncludes})

link_directories("/boot/system/lib/x86")

add_executable(Bme ${BmeSrc})
target_link_libraries(Bme be bnetapi crypto translation ssl)


