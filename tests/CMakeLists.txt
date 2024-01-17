include(GoogleTest)

include(${CMAKE_CURRENT_LIST_DIR}/../cmake/pitch_sanitize.cmake)

file(GLOB_RECURSE SRC *.cpp)
add_executable(PitchforkTests ${SRC})

pitch_sanitize("address,undefined")

cpmaddpackage("gh:google/googletest#main")

target_link_libraries(PitchforkTests PRIVATE Pitchfork::Pitchfork
                                             GTest::gtest_main)

gtest_discover_tests(PitchforkTests)
