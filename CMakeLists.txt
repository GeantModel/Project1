cmake_minimum_required(VERSION 3.9)

set(NAME project1)
project(project1)

set(CMAKE_CXX_STANDARD 11)
#1 путь к geant4
set(CMAKE_PREFIX_PATH /home/student/geant4/geant4-install)
#2 определить как запускать geant4 с поддержкой визуализации или без
option(WITH_GEANT4_UIVIS "Build example with Geant4 UI and Vis drivers" ON)
if(WITH_GEANT4_UIVIS)
    find_package(Geant4 REQUIRED ui_all vis_all)
else()
    find_package(Geant4 REQUIRED)
endif()

#3 подключение библиотек geat4 к проекту
include(${Geant4_USE_FILE})
include_directories(${PROJECT_SOURCE_DIR}/include)

#4 создание .exe
add_executable(project1 main.cpp)

#5 связывание geant4 с проектом
target_link_libraries(project1 ${Geant4_LIBRARIES})