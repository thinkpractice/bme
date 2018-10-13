cmake_minimum_required(VERSION 3.4)

project(Bme)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_LIBRARY_PATH $(CMAKE_LIBRARY_PATH) /boot/system/lib)

find_package(GTest)

file(GLOB BmeSrc
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

file(GLOB UnitTestsSrc
"UnitTests/Controllers/*.h"
"UnitTests/Controllers/*.cpp"
"UnitTests/Models/*.h"
"UnitTests/Models/*.cpp"
"UnitTests/Models/Protocols/*.h"
"UnitTests/Models/Protocols/*.cpp"
"UnitTests/Models/ChatMessages/*.h"
"UnitTests/Models/ChatMessages/*.cpp"
"UnitTests/Views/*.h"
"UnitTests/Views/*.cpp"
"UnitTests/Views/MessageItemViews/*.h"
"UnitTests/Views/MessageItemViews/*.cpp"
"UnitTests/Utils/*.h"
"UnitTests/Utils/*.cpp"
)

set( ProjectIncludes "." "Controllers" "Models" "Models/Protocols" "Models/ChatMessages" "Views" "Views/MessageItemViews" "Utils")
include_directories(${ProjectIncludes})

link_directories("/boot/system/lib/x86")

set( BmeLibs be bnetapi crypto translation ssl)

add_executable(Bme BmeApp.cpp ${BmeSrc})
target_link_libraries(Bme ${BmeLibs})

#add_executable(BmeTests ${UnitTestsSrc} ${BmeSrc})
#target_link_libraries(BmeTests gtest ${BmeLibs})