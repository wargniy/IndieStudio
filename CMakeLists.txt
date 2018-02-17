cmake_minimum_required(VERSION 3.5)

find_package(OpenGL)
find_package(X11)
find_package(ZLIB)
find_package(Threads)

set(NAME gods_of_speed)

set(EXECUTABLE_OUTPUT_PATH ${CMAKE_CURRENT_SOURCE_DIR}/build/)

set(CMAKE_SUPPRESS_REGENERATION true)

set(SRC ./src/main.cpp
	./src/Profile.cpp
	./src/Intro.cpp
	./src/LibContainer.cpp
	./src/MyEventListener.cpp
	./src/Event_Game.cpp
	./src/SAppContext.cpp
	./src/Sound.cpp
	./src/Menu.cpp
	./src/AEventListener.cpp
	./src/Distrib.cpp
	./src/MenuEventListener.cpp
	./src/AContext.cpp
	./src/Loading.cpp
	./src/Game.cpp
	./src/CarFactory.cpp
	./src/MapPool.cpp
	)
set(CMAKE_C_FLAGS "-Wall -Wextra -Werror -g3")

include_directories(./irrlicht-1.8.4/include/
/usr/lib64
./irrKlang-64bit-1.5.0/include/)
link_directories(./irrlicht-1.8.4/lib/Linux/)
link_directories(./irrlicht-1.8.4/lib/Win64-visualStudio/)
link_directories(./irrKlang-64bit-1.5.0/lib/Winx64-visualStudio)
link_directories(./irrlicht-1.8.4/bin/Win64-VisualStudio/)
link_directories(./irrKlang-64bit-1.5.0/bin/linux-gcc-64/)
link_directories(./irrKlang-64bit-1.5.0/bin/winx64-visualStudio/)
add_executable(${NAME} ${SRC})
target_link_libraries(
        ${NAME}
	Irrlicht
	IrrKlang
	${CMAKE_THREAD_LIBS_INIT}
	${OPENGL_gl_LIBRARY}
	${X11_LIBRARIES})
if(${UNIX})
	target_link_libraries(${NAME}
	Xxf86vm
	Xext
	ikpMP3
	ikpFlac
	)
endif(${UNIX})

if ( MSVC )
    set_target_properties( ${NAME} PROPERTIES RUNTIME_OUTPUT_DIRECTORY_RELEASE ${EXECUTABLE_OUTPUT_PATH} )
endif ( MSVC )

if(${WIN32})
add_custom_command(TARGET ${NAME} POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E copy_if_different
        "${PROJECT_SOURCE_DIR}/irrlicht-1.8.4/bin/Win64-VisualStudio/Irrlicht.dll"
        $<TARGET_FILE_DIR:${NAME}>)

add_custom_command(TARGET ${NAME} POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E copy_if_different
        "${PROJECT_SOURCE_DIR}/irrKlang-64bit-1.5.0/bin/winx64-visualStudio/IrrKlang.dll"
        $<TARGET_FILE_DIR:${NAME}>)

add_custom_command(TARGET ${NAME} POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E copy_if_different
        "${PROJECT_SOURCE_DIR}/irrKlang-64bit-1.5.0/bin/winx64-visualStudio/ikpMP3.dll"
        $<TARGET_FILE_DIR:${NAME}>)
endif(${WIN32})
