include(FetchContent)

FetchContent_Declare(json URL https://github.com/nlohmann/json/releases/download/v3.12.0/json.tar.xz)
FetchContent_MakeAvailable(json)

add_executable(moviedb src/main.cpp)


target_link_libraries(moviedb PRIVATE nlohmann_json::nlohmann_json moviedb)
target_include_directories(moviedb PRIVATE src)

add_subdirectory(src)