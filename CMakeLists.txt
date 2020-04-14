#CMake最低版本号要求
CMAKE_MINIMUM_REQUIRED(VERSION 2.8)

set(APP_NAME supersocket)

PROJECT(${APP_NAME})

MESSAGE(STATUS "PROJECT_SOURCE_DIR: ${PROJECT_SOURCE_DIR}")
MESSAGE(STATUS "PROJECT_BINARY_DIR: ${PROJECT_BINARY_DIR}")

if(WIN32)
else()
#SET(CMAKE_BUILE_TYPE DEBUG)
#SET(CMAKE_C_FLAGS_DEBUG "-g -Wall")
SET(CMAKE_C_FLAGS "-g -Wall")
endif()

file(COPY "${PROJECT_SOURCE_DIR}/mrtool/mr_buffer.h" DESTINATION  "${PROJECT_SOURCE_DIR}/include")
file(COPY "${PROJECT_SOURCE_DIR}/mrtool/mr_code.h" DESTINATION  "${PROJECT_SOURCE_DIR}/include")

file(COPY "${PROJECT_SOURCE_DIR}/mrsocket/mr_mem.h" DESTINATION  "${PROJECT_SOURCE_DIR}/include")
file(COPY "${PROJECT_SOURCE_DIR}/mrsocket/mr_socket.h" DESTINATION  "${PROJECT_SOURCE_DIR}/include")
file(COPY "${PROJECT_SOURCE_DIR}/mrsocket/socket_info.h" DESTINATION  "${PROJECT_SOURCE_DIR}/include")
file(COPY "${PROJECT_SOURCE_DIR}/mrsocket/mrsocket.h" DESTINATION  "${PROJECT_SOURCE_DIR}/include")

SET(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${PROJECT_SOURCE_DIR}/lib CACHE PATH "Single directory for all static libraries.")
SET(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${PROJECT_SOURCE_DIR}/lib CACHE PATH "Single directory for all dynamic libraries.")
SET(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${PROJECT_SOURCE_DIR}/bin CACHE PATH "Single directory for all executable.")

SET(LIBMRSOCKET mrsocket)
SET(LIBMRTOOL mrtool)

include_directories(${PROJECT_SOURCE_DIR}/${LIBMRSOCKET})
add_subdirectory(${PROJECT_SOURCE_DIR}/${LIBMRSOCKET})

include_directories(${PROJECT_SOURCE_DIR}/${LIBMRTOOL})
add_subdirectory(${PROJECT_SOURCE_DIR}/${LIBMRTOOL})

if(WIN32)
link_libraries(ws2_32)
else()
link_libraries(pthread)
endif()

add_executable(${APP_NAME} main.cpp SuperSocket.h SuperSocket.cpp)
target_link_libraries(${APP_NAME} ${LIBMRSOCKET} ${LIBMRTOOL})

