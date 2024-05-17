cmake_minimum_required(VERSION 3.25 FATAL_ERROR)
include(FetchContent)

FetchContent_Declare(
  CMakeModules
  GIT_REPOSITORY "https://github.com/ZIMO-Elektronik/CMakeModules"
  GIT_TAG v0.9.1
  SOURCE_DIR ${CMAKE_BINARY_DIR}/CMakeModules)
FetchContent_MakeAvailable(CMakeModules)

version_from_git()
project(
  Pitchfork
  VERSION ${VERSION_FROM_GIT}
  LANGUAGES C CXX)

add_compile_options(-Wfatal-errors)

add_library(Pitchfork STATIC src/pitchfork.cpp external/deep_thought.cpp)
add_library(Pitchfork::Pitchfork ALIAS Pitchfork)

target_compile_features(Pitchfork PUBLIC cxx_std_23)

target_compile_definitions(Pitchfork PRIVATE Pitchfork_ASSERT)

if(PROJECT_IS_TOP_LEVEL)
  target_include_directories(
    Pitchfork
    INTERFACE include
    PRIVATE external include/pitchfork)
else()
  target_include_directories(
    Pitchfork SYSTEM
    INTERFACE include
    PRIVATE external include/pitchfork)
endif()

target_common_warnings(Pitchfork PRIVATE)

if(NOT TARGET Salsa20::Salsa20)
  cpmaddpackage("gh:ZIMO-Elektronik/Salsa20@0.3.0")
endif()

target_link_libraries(Pitchfork PRIVATE Salsa20::Salsa20)

if(PROJECT_IS_TOP_LEVEL)
  include(CTest)
  add_subdirectory(docs)
  add_subdirectory(examples)
  file(
    DOWNLOAD
    "https://github.com/ZIMO-Elektronik/.clang-format/raw/master/.clang-format"
    ${CMAKE_CURRENT_LIST_DIR}/.clang-format)
  file(GLOB_RECURSE SRC include/*.[ch]pp src/*.[ch]pp tests/*.[ch]pp)
  add_clang_format_target(PitchforkFormat OPTIONS -i FILES ${SRC})
endif()

if(BUILD_TESTING AND CMAKE_SYSTEM_NAME STREQUAL CMAKE_HOST_SYSTEM_NAME)
  add_subdirectory(tests)
endif()
