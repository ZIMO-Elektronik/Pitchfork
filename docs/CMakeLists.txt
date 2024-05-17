find_package(Doxygen QUIET COMPONENTS dot mscgen)

option(
  DOXYGEN_AWESOME_DARKMODE_TOGGLE
  "Adds a button next to the search bar to enable and disable the dark theme variant manually"
  ON)

if(Doxygen_FOUND)
  cpmaddpackage("gh:jothepro/doxygen-awesome-css@2.3.3")

  set(DOXYGEN_PROJECT_LOGO ${CMAKE_SOURCE_DIR}/data/images/logo.png)
  set(DOXYGEN_REPEAT_BRIEF NO)
  set(DOXYGEN_MULTILINE_CPP_IS_BRIEF YES)
  set(DOXYGEN_BUILTIN_STL_SUPPORT YES)
  set(DOXYGEN_NUM_PROC_THREADS 0)
  set(DOXYGEN_EXTRACT_ALL YES)
  set(DOXYGEN_EXTRACT_PRIVATE YES)
  set(DOXYGEN_EXTRACT_STATIC YES)
  set(DOXYGEN_EXTRACT_LOCAL_CLASSES YES)
  set(DOXYGEN_EXTRACT_LOCAL_METHODS YES)
  set(DOXYGEN_EXTRACT_ANON_NSPACES YES)
  set(DOXYGEN_IMAGE_PATH ${CMAKE_SOURCE_DIR}/data/images)
  set(DOXYGEN_HTML_HEADER header.html)
  set(DOXYGEN_HTML_EXTRA_STYLESHEET
      ${doxygen-awesome-css_SOURCE_DIR}/doxygen-awesome.css
      ${doxygen-awesome-css_SOURCE_DIR}/doxygen-awesome-sidebar-only.css
      ${CMAKE_CURRENT_SOURCE_DIR}/custom.css)
  set(DOXYGEN_HTML_EXTRA_FILES
      ${doxygen-awesome-css_SOURCE_DIR}/doxygen-awesome-fragment-copy-button.js
      ${doxygen-awesome-css_SOURCE_DIR}/doxygen-awesome-interactive-toc.js)
  if(DOXYGEN_AWESOME_DARKMODE_TOGGLE)
    set(DOXYGEN_HTML_EXTRA_STYLESHEET
        ${DOXYGEN_HTML_EXTRA_STYLESHEET}
        ${doxygen-awesome-css_SOURCE_DIR}/doxygen-awesome-sidebar-only-darkmode-toggle.css
    )
    set(DOXYGEN_HTML_EXTRA_FILES
        ${DOXYGEN_HTML_EXTRA_FILES}
        ${doxygen-awesome-css_SOURCE_DIR}/doxygen-awesome-darkmode-toggle.js)
  endif()
  set(DOXYGEN_HTML_COLORSTYLE LIGHT)
  set(DOXYGEN_GENERATE_TREEVIEW YES)
  set(DOXYGEN_MACRO_EXPANSION YES)
  set(DOXYGEN_EXPAND_ONLY_PREDEF YES)
  set(DOXYGEN_UML_LOOK YES)
  set(DOXYGEN_DOT_IMAGE_FORMAT svg)

  doxygen_add_docs(
    PitchforkDocs ${CMAKE_SOURCE_DIR}/include ${CMAKE_SOURCE_DIR}/src
    ${CMAKE_SOURCE_DIR}/CHANGELOG.md ${CMAKE_SOURCE_DIR}/TODO.md)
endif()
