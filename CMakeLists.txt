cmake_minimum_required(VERSION 3.13)

set(CMAKE_CXX_STANDARD 20)

set(CMAKE_USE_RELATIVE_PATHS TRUE)
project("ninjaPatchScanner")
set(PROJECT_VERSION "0.0.1")
set("PROJECT_DESCRIPTION" "A tool generating \"dyndep\" files for ninja build system from patch files.")
set("PROJECT_HOMEPAGE_URL" "https://codeberg.org/KOLANICH-tools/ninjaPatchScanner")
set(CPACK_PACKAGE_VENDOR "KOLANICH")

set(CPACK_PACKAGE_VERSION "${PROJECT_VERSION}")

find_package(ParsePatch)
add_executable("${PROJECT_NAME}" "./NinjaPatchScanner.cpp")
target_link_libraries("${PROJECT_NAME}" PRIVATE ParsePatch::libParsePatch)
#harden("${PROJECT_NAME}")

set(CPACK_PACKAGE_MAINTAINER "${CPACK_PACKAGE_VENDOR}")
set(CPACK_DEBIAN_PACKAGE_NAME "${CPACK_PACKAGE_NAME}")
set(CPACK_RPM_PACKAGE_NAME "${CPACK_PACKAGE_NAME}")

set(CPACK_DEB_COMPONENT_INSTALL ON)
set(CPACK_RPM_COMPONENT_INSTALL ON)
set(CPACK_NSIS_COMPONENT_INSTALL ON)
#set(CPACK_DEBIAN_ENABLE_COMPONENT_DEPENDS ON)
set(CPACK_RPM_ENABLE_COMPONENT_DEPENDS ON)
set(CPACK_DEBIAN_COMPRESSION_TYPE "xz")

include(CPack)
