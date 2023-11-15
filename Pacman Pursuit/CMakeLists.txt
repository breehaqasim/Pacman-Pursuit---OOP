cmake_minimum_required(VERSION 3.20)
SET(CMAKE_CXX_STANDARD 14)
SET(CMAKE_CXX_STANDARD_REQUIRED ON)
SET(CMAKE_CXX_EXTENSIONS OFF)

set(STACK_PROTECTOR_SUPPORTED 0 CACHE BOOL "")
set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -fstack-protector")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -fstack-protector")

include("${PROJECT_SOURCE_DIR}/LoadExternalDependencies.cmake")

file(GLOB CODE_FILES *.h *.hpp *.cpp)
SET(APP_NAME main)
SET(APP_FILES ${CODE_FILES} )

add_executable(${APP_NAME} ${APP_FILES})
target_include_directories(${APP_NAME} PUBLIC ${sdl_SOURCE_DIR}/include ${sdl_mixer_SOURCE_DIR}/include ${sdl_image_SOURCE_DIR})
target_link_libraries(${APP_NAME} SDL2::SDL2main SDL2::SDL2-static SDL2_image::SDL2_image-static SDL2_mixer::SDL2_mixer-static)

file(COPY ${PROJECT_SOURCE_DIR}/assets.png DESTINATION ${PROJECT_BINARY_DIR})
file(COPY ${PROJECT_SOURCE_DIR}/assets.svg DESTINATION ${PROJECT_BINARY_DIR})
file(COPY ${PROJECT_SOURCE_DIR}/hu.png DESTINATION ${PROJECT_BINARY_DIR})
file(COPY ${PROJECT_SOURCE_DIR}/pigeon.mp3 DESTINATION ${PROJECT_BINARY_DIR})
