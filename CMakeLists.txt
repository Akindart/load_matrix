cmake_minimum_required(VERSION 2.8)
project(load_matrix)

SET(PROJECT_VERSION 0.1)

set(CMAKE_CXX_STANDARD 14)

find_package(Eigen3 REQUIRED NO_MODULE)

include_directories(
        ${EIGEN3_INCLUDE_DIRS}
)

add_library(load_matrix SHARED load_matrix_file.hpp)

set_target_properties(load_matrix  PROPERTIES LINKER_LANGUAGE CXX)

target_link_libraries(load_matrix
                      ${Eigen_LIBRARIES}
                      )

SET_TARGET_PROPERTIES(load_matrix PROPERTIES SOVERSION 0)
set_target_properties(load_matrix PROPERTIES PUBLIC_HEADER load_matrix_file.hpp)
configure_file(load_matrix.pc.in load_matrix.pc @ONLY)

add_executable(load_test main.cpp)

add_dependencies(load_test load_matrix)

target_link_libraries(load_test
                      load_matrix
                      )

include(GNUInstallDirs)

install(TARGETS load_matrix
        LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
        PUBLIC_HEADER DESTINATION ${CMAKE_INSTALL_INCLUDEDIR})
install(FILES ${CMAKE_BINARY_DIR}/load_matrix.pc
        DESTINATION ${CMAKE_INSTALL_DATAROOTDIR}/pkgconfig)
