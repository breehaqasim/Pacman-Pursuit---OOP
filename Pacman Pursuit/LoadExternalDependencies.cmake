include(FetchContent)
Set(FETCHCONTENT_QUIET FALSE)
set(SDL2MIXER_VENDORED ON CACHE BOOL "")

message("Fetching sdl...")
FetchContent_Declare(sdl
	FETCHCONTENT_UPDATES_DISCONNECTED ON
	GIT_REPOSITORY	https://github.com/libsdl-org/SDL.git
	GIT_TAG 	   		release-2.28.2
	GIT_PROGRESS   	ON
)

FetchContent_GetProperties(sdl)
if(NOT sdl_POPULATED)
	FetchContent_Populate(sdl)
	add_subdirectory(${sdl_SOURCE_DIR} ${sdl_BINARY_DIR})
	FetchContent_MakeAvailable(sdl)
endif()

message("Fetching sdl_image...")
FetchContent_Declare(sdl_image
	FETCHCONTENT_UPDATES_DISCONNECTED ON
	GIT_REPOSITORY https://github.com/libsdl-org/SDL_image.git
	GIT_TAG 	   		release-2.6.3
	GIT_PROGRESS   	ON
)

FetchContent_GetProperties(sdl_image)
if(NOT sdl_image_POPULATED)
	set(SDL2IMAGE_INSTALL OFF)
	set(BUILD_SHARED_LIBS FALSE)
	FetchContent_Populate(sdl_image)
	add_subdirectory(${sdl_image_SOURCE_DIR} ${sdl_image_BINARY_DIR})
	FetchContent_MakeAvailable(sdl_image)
endif()

message("Fetching sdl_mixer...")
FetchContent_Declare(sdl_mixer
	FETCHCONTENT_UPDATES_DISCONNECTED ON
	GIT_REPOSITORY https://github.com/libsdl-org/SDL_mixer.git
	GIT_TAG 	   		release-2.6.3
	GIT_PROGRESS   	ON
)

FetchContent_GetProperties(sdl_mixer)
if(NOT sdl_mixer_POPULATED)
	FetchContent_Populate(sdl_mixer)
	add_subdirectory(${sdl_mixer_SOURCE_DIR} ${sdl_mixer_BINARY_DIR})
	FetchContent_MakeAvailable(sdl_mixer)
endif()