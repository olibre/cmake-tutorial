cmake_minimum_required (VERSION 2.8)
project (TestIDCard)

set(sdk_include "/home/jinwei/image_framework/api_install/include")
set(sdk_lib "/home/jinwei/image_framework/api_install/lib/libidcard.so")

include_directories(${PROJECT_SOURCE_DIR})
include_directories("${PROJECT_SOURCE_DIR}/common")
include_directories("${PROJECT_SOURCE_DIR}/PlistCpp")
include_directories(${sdk_include})

add_subdirectory(common)
add_subdirectory(PlistCpp)

set(Boost_USE_STATIC_LIBS OFF) 
set(Boost_USE_MULTITHREADED OFF)
set(Boost_USE_STATIC_RUNTIME OFF) 
find_package(Boost 1.54.0 COMPONENTS system) 
find_package( OpenCV REQUIRED )

if(Boost_FOUND)
    include_directories(${Boost_INCLUDE_DIRS}) 
    add_executable(basic basic.cpp basic_test.cpp idcard_test.cpp) 
    target_link_libraries(basic common plist ${Boost_LIBRARIES} ${sdk_lib} ${OpenCV_LIBS})
endif()