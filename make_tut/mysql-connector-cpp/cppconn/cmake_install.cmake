# Install script for directory: /home/jinwei/cmake/make_tut/mysql-connector-cpp/cppconn

# Set the install prefix
IF(NOT DEFINED CMAKE_INSTALL_PREFIX)
  SET(CMAKE_INSTALL_PREFIX "/usr/local")
ENDIF(NOT DEFINED CMAKE_INSTALL_PREFIX)
STRING(REGEX REPLACE "/$" "" CMAKE_INSTALL_PREFIX "${CMAKE_INSTALL_PREFIX}")

# Set the install configuration name.
IF(NOT DEFINED CMAKE_INSTALL_CONFIG_NAME)
  IF(BUILD_TYPE)
    STRING(REGEX REPLACE "^[^A-Za-z0-9_]+" ""
           CMAKE_INSTALL_CONFIG_NAME "${BUILD_TYPE}")
  ELSE(BUILD_TYPE)
    SET(CMAKE_INSTALL_CONFIG_NAME "")
  ENDIF(BUILD_TYPE)
  MESSAGE(STATUS "Install configuration: \"${CMAKE_INSTALL_CONFIG_NAME}\"")
ENDIF(NOT DEFINED CMAKE_INSTALL_CONFIG_NAME)

# Set the component getting installed.
IF(NOT CMAKE_INSTALL_COMPONENT)
  IF(COMPONENT)
    MESSAGE(STATUS "Install component: \"${COMPONENT}\"")
    SET(CMAKE_INSTALL_COMPONENT "${COMPONENT}")
  ELSE(COMPONENT)
    SET(CMAKE_INSTALL_COMPONENT)
  ENDIF(COMPONENT)
ENDIF(NOT CMAKE_INSTALL_COMPONENT)

# Install shared libraries without execute permission?
IF(NOT DEFINED CMAKE_INSTALL_SO_NO_EXE)
  SET(CMAKE_INSTALL_SO_NO_EXE "1")
ENDIF(NOT DEFINED CMAKE_INSTALL_SO_NO_EXE)

IF(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  FILE(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/cppconn" TYPE FILE FILES
    "/home/jinwei/cmake/make_tut/mysql-connector-cpp/cppconn/build_config.h"
    "/home/jinwei/cmake/make_tut/mysql-connector-cpp/cppconn/config.h"
    "/home/jinwei/cmake/make_tut/mysql-connector-cpp/cppconn/connection.h"
    "/home/jinwei/cmake/make_tut/mysql-connector-cpp/cppconn/datatype.h"
    "/home/jinwei/cmake/make_tut/mysql-connector-cpp/cppconn/driver.h"
    "/home/jinwei/cmake/make_tut/mysql-connector-cpp/cppconn/exception.h"
    "/home/jinwei/cmake/make_tut/mysql-connector-cpp/cppconn/metadata.h"
    "/home/jinwei/cmake/make_tut/mysql-connector-cpp/cppconn/parameter_metadata.h"
    "/home/jinwei/cmake/make_tut/mysql-connector-cpp/cppconn/prepared_statement.h"
    "/home/jinwei/cmake/make_tut/mysql-connector-cpp/cppconn/resultset.h"
    "/home/jinwei/cmake/make_tut/mysql-connector-cpp/cppconn/resultset_metadata.h"
    "/home/jinwei/cmake/make_tut/mysql-connector-cpp/cppconn/statement.h"
    "/home/jinwei/cmake/make_tut/mysql-connector-cpp/cppconn/sqlstring.h"
    "/home/jinwei/cmake/make_tut/mysql-connector-cpp/cppconn/warning.h"
    "/home/jinwei/cmake/make_tut/mysql-connector-cpp/cppconn/version_info.h"
    "/home/jinwei/cmake/make_tut/mysql-connector-cpp/cppconn/variant.h"
    )
ENDIF(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")

