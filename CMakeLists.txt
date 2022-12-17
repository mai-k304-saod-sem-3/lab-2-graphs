cmake_minimum_required(VERSION 3.22) # Минимальная версия Cmake

project(lab-2-graphs) # Название проекта

set(CMAKE_CXX_STANDARD 11) # Версия стандарта C++

set(SOURCE_EXE src/main.cpp) # Установка переменной со списком исходников для исполняемого файла

set(SOURCE_LIB src/functions.cpp) # Установка переменной со списком исходников для библиотеки

add_library(functions STATIC ${SOURCE_LIB}) # Создание статической библиотеки

add_executable(lab-2-graphs ${SOURCE_EXE}) # Создаие исполняеого файла

target_link_libraries(lab-2-graphs functions) # Линковка программы с библиотекой