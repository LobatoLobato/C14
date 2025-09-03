include(FetchContent)

FetchContent_Declare(json URL https://github.com/nlohmann/json/releases/download/v3.12.0/json.tar.xz)
FetchContent_MakeAvailable(json)

add_library(moviedb INTERFACE)
target_link_libraries(moviedb INTERFACE nlohmann_json::nlohmann_json)
target_include_directories(moviedb INTERFACE src)

add_subdirectory(src)
add_subdirectory(tests)