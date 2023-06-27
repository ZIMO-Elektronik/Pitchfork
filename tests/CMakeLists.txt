include(GoogleTest)

file(GLOB_RECURSE SRC *.cpp)
add_executable(PitchforkTests ${SRC})

FetchContent_Declare(
  googletest
  GIT_REPOSITORY https://github.com/google/googletest.git
  GIT_TAG main
  GIT_PROGRESS TRUE)
FetchContent_MakeAvailable(googletest)

target_link_libraries(PitchforkTests PRIVATE Pitchfork::Pitchfork GTest::gtest)

gtest_discover_tests(PitchforkTests)
