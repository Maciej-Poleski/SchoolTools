project(Schedule)
cmake_minimum_required(VERSION 2.6)
find_package(Qt4 REQUIRED)

include_directories(${QT_INCLUDES} ${CMAKE_CURRENT_BINARY_DIR} include)

set(Schedule_SRCS src/markevaluator.cpp src/deletable.cpp src/initializable.cpp src/mark.cpp src/type.cpp src/subjects.cpp src/generatoridgenerator.cpp src/idgenerator.cpp main.cpp src/subject.cpp src/events.cpp src/event.cpp src/term.cpp src/complist.cpp )
qt4_automoc(${Schedule_SRCS})
add_executable(Schedule ${Schedule_SRCS})
target_link_libraries(Schedule ${QT_QTCORE_LIBRARY} ${QT_QTGUI_LIBRARY})
