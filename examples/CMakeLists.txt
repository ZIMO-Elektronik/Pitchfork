file(GLOB_RECURSE SRC *.cpp)
add_executable(PitchforkExamples ${SRC})

sanitize("address,undefined")

target_common_warnings(PitchforkExamples PRIVATE)

target_link_libraries(PitchforkExamples PRIVATE Pitchfork::Pitchfork)
