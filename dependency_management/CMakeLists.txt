include(FetchContent)

FetchContent_Declare(json URL https://github.com/nlohmann/json/releases/download/v3.12.0/json.tar.xz)
FetchContent_MakeAvailable(json)

add_executable(dependency_management src/main.cpp)

target_link_libraries(dependency_management PRIVATE nlohmann_json::nlohmann_json)
target_include_directories(dependency_management PRIVATE src)

add_subdirectory(src)