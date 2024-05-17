include(GoogleTest)

file(GLOB_RECURSE SRC *.cpp)
add_executable(PitchforkTests ${SRC})

sanitize(address,undefined)

cpmaddpackage(
  NAME
  googletest
  GITHUB_REPOSITORY
  "google/googletest"
  GIT_TAG
  main
  SYSTEM
  YES
  OPTIONS
  "INSTALL_GTEST OFF")

target_link_libraries(PitchforkTests PRIVATE Pitchfork::Pitchfork
                                             GTest::gtest_main)

gtest_discover_tests(PitchforkTests)
