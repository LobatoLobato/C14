include(FetchContent)

FetchContent_Declare(
    googletest
    GIT_REPOSITORY https://github.com/google/googletest.git
    GIT_TAG        release-1.11.0 # Or a specific commit hash for more security
)
FetchContent_MakeAvailable(googletest)
