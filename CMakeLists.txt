cmake_minimum_required(VERSION 3.25 FATAL_ERROR)
include(FetchContent)

FetchContent_Declare(
  CMakeModules
  GIT_REPOSITORY https://github.com/ZIMO-Elektronik/CMakeModules
  GIT_TAG v0.2.2)
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

if(CMAKE_PROJECT_NAME STREQUAL PROJECT_NAME)
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

if(CMAKE_PROJECT_NAME STREQUAL PROJECT_NAME)
  add_subdirectory(docs)
  include(CTest)
endif()

if(CMAKE_PROJECT_NAME STREQUAL PROJECT_NAME AND BUILD_TESTING)
  add_subdirectory(examples)
  add_subdirectory(tests)
endif()
