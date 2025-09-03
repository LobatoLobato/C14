include(FetchContent)

FetchContent_Declare(
    googletest
    GIT_REPOSITORY https://github.com/google/googletest.git
    GIT_TAG        release-1.11.0 # Or a specific commit hash for more security
)
FetchContent_MakeAvailable(googletest)

add_executable(movie_service_tests movie_service_tests.cpp)
target_link_libraries(movie_service_tests PRIVATE gtest_main moviedb)