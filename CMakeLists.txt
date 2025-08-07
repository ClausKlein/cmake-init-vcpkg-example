cmake_minimum_required(VERSION 3.21...3.29)

include(cmake/prelude.cmake)

project(
    vcpkg-example
    VERSION 0.1.0
    DESCRIPTION "Short description"
    HOMEPAGE_URL "https://example.com/"
    LANGUAGES CXX
)

include(cmake/variables.cmake)

# ---- Declare library ----

add_library(
    vcpkg-example_lib OBJECT
    source/lib.cpp
    source/lib.hpp
)

target_include_directories(
    vcpkg-example_lib ${warning_guard}
    PUBLIC
    "\$<BUILD_INTERFACE:${PROJECT_SOURCE_DIR}/source>"
)

target_compile_features(vcpkg-example_lib PUBLIC cxx_std_17)

find_package(fmt REQUIRED)
find_package(unofficial-libuuid REQUIRED)
target_link_libraries(vcpkg-example_lib PRIVATE fmt::fmt unofficial::UUID::uuid)

# ---- Declare executable ----

add_executable(vcpkg-example_exe source/main.cpp)
add_executable(vcpkg-example::exe ALIAS vcpkg-example_exe)

set_property(TARGET vcpkg-example_exe PROPERTY OUTPUT_NAME vcpkg-example)

target_compile_features(vcpkg-example_exe PRIVATE cxx_std_17)

target_link_libraries(vcpkg-example_exe PRIVATE vcpkg-example_lib)

# ---- Install rules ----

if(NOT CMAKE_SKIP_INSTALL_RULES)
  include(cmake/install-rules.cmake)
endif()

# ---- Developer mode ----

if(NOT vcpkg-example_DEVELOPER_MODE)
  return()
elseif(NOT PROJECT_IS_TOP_LEVEL)
  message(
      AUTHOR_WARNING
      "Developer mode is intended for developers of vcpkg-example"
  )
endif()

include(cmake/dev-mode.cmake)
