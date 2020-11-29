cmake_minimum_required(VERSION 2.8) #Проверка версии CMake.

set(PROJECT_NAME queuelistlib) #Создаем обычную локальную переменную с именем проекта
project(${PROJECT_NAME}) # Название проекта

set(app queuelist) #Переменная с именем приложения
set(lib queuelistlib) #Переменная с именем библиотеки

set(MP2_LIBRARY "${PROJECT_NAME}")
set(MP2_TESTS   "test_${PROJECT_NAME}")

set(CMAKE_CONFIGURATION_TYPES "Debug;Release" CACHE STRING "Configs" FORCE) #Создается переменная CMAKE_CONFIGURATION_TYPES со значением "Debug;Release" и меткой/разделом Configs, переменная сохраниется в специальном файле доступном из всех файлов,
if(NOT CMAKE_BUILD_TYPE) # проверка имеющихся у компилятора вариантов сборки
    set(CMAKE_BUILD_TYPE Release) #Если нет то устанавливаем Release
endif()

include_directories(${CMAKE_CURRENT_SOURCE_DIR}/queuelistlib) #Добавляем директорию "${CMAKE_CURRENT_SOURCE_DIR}/queuelistlib" в дополняемые каталоги включаемых файлов
#${CMAKE_CURRENT_SOURCE_DIR} - стандартная переменная с адресом рабочей директории

add_subdirectory(queuelist)
add_subdirectory(queuelistlib)

add_subdirectory(gtest)
add_subdirectory(test)

