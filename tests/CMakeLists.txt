include(GoogleTest)

file(GLOB_RECURSE SRC *.cpp)
add_executable(PitchforkTests ${SRC})

sanitize(address,undefined)

cpmaddpackage("gh:google/googletest#main")

target_link_libraries(PitchforkTests PRIVATE Pitchfork::Pitchfork
                                             GTest::gtest_main)

gtest_discover_tests(PitchforkTests)
