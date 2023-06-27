file(GLOB_RECURSE SRC *.cpp)
add_executable(PitchforkExamples ${SRC})

sanatize("address,undefined")

target_common_warnings(PitchforkExamples)

target_link_libraries(PitchforkExamples PRIVATE Pitchfork::Pitchfork)
