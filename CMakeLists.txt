cmake_minimum_required(VERSION 3.17)

set(CMAKE_CXX_STANDARD 17)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++17")

project(game)

set (SOURCE_FILES
        Character.cpp
        Character.h
        Game.cpp
        Game.h
        Leaf.cpp
        Leaf.h
        main.cpp
        Object.cpp
        Object.h
        Player.cpp
        Player.h)

add_executable(game ${SOURCE_FILES})
target_link_libraries(game sfml-graphics sfml-window sfml-system)


#[[
cmake_minimum_required(VERSION 3.17)
project(game)

set(CMAKE_CXX_STANDARD 17)
#På skolans Linux-system finns det två versionerav SFML. Se efter vilken somanvänds:
if (DEFINED ENV{LOADEDMODULES} AND ("$ENV{LOADEDMODULES}" MATCHES ".prog/gcc/6.1.0."))
    set(CMAKE_CXX_COMPILER /sw/gcc-6.1.0/bin/g++)
if (DEFINED ENV{SFML_ROOT})
    list(APPEND CMAKE_MODULE_PATH "$ENV{SFML_ROOT}/share/SFML/cmake/Modules")
endif()
endif()
#Välj vilka moduler i SFML som ska användas.
set(SFML_MODULES network graphics window system)
#Försökatt hitta SFML genom att anropa 'FindSFML.cmake'(om det finns).
find_package(SFML 2 COMPONENTS ${SFML_MODULES})
include_directories(${SFML_INCLUDE_DIR})
#Om det inte finns hoppas vi på att SFML finns installerat ändå.
if (NOT (${SFML_FOUND} STREQUAL "TRUE"))
    set(SFML_LIBRARIES "")
foreach(i ${SFML_MODULES})
    list(APPEND SFML_LIBRARIES "sfml-${i}")
endforeach(i)
endif()
set (SOURCE_FILES
        Character.cpp
        Character.h
        Game.cpp
        Game.h
        Leaf.cpp
        Leaf.h
        main.cpp
        Object.cpp
        Object.h
        Player.cpp
        Player.h)
add_executable(game main.cpp)
target_link_libraries(game ${SFML_LIBRARIES} ${SFML_DEPENDENCIES})]]
