add_library(${PROJECT_NAME} INTERFACE)

message(STATUS "CMake install directory: " ${CMAKE_INSTALL_INCLUDEDIR})

target_include_directories(
  ${PROJECT_NAME}
  INTERFACE $<BUILD_INTERFACE:${${PROJECT_NAME}_SOURCE_DIR}/lib>
            $<INSTALL_INTERFACE:${CMAKE_INSTALL_INCLUDEDIR}>)