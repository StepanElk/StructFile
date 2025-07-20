project(struct_file_helper LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

include_directories( models actions )

add_executable(struct_file_helper main.cpp actions/devices_file_helper.cpp)