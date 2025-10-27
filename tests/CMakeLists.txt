include(GoogleTest)

file(GLOB_RECURSE SRC *.cpp)
add_executable(PitchforkTests ${SRC})

sanitize(address,undefined)

target_common_warnings(PitchforkTests PRIVATE)
target_common_errors(PitchforkTests PRIVATE -Werror)

cpmaddpackage(URI "gh:google/googletest#main" OPTIONS "INSTALL_GTEST OFF")

target_link_libraries(PitchforkTests PRIVATE Pitchfork::Pitchfork
                                             GTest::gtest_main)

gtest_discover_tests(PitchforkTests)
