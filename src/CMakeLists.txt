cmake_minimum_required(VERSION 2.8 FATAL_ERROR)

project(stlvector)

#find_package( Boost REQUIRED)
#if( Boost_FOUND )
 # message( STATUS "Boost found." )
#endif()

#include_directories(${Boost_INCLUDE_DIRS})

#include_directories(/usr/include)
#link_directories(/usr/lib)
#add_executable (exception exceptional.cpp)

#target_link_libraries (multithread -lboost_thread)
#target_link_libraries(multithread ${Boost_LIBRARIES})

add_executable(Btree binarytree.cpp)
#add_executable(Linkedlistimplementation Listimplemtation.cpp)
#add_executable(bisection bisectionmethod.cpp)
#g++ multithreading.cpp  -o threading -I /usr/local/include  -lboost_thread

