cmake_minimum_required(VERSION 3.0.2)
project(my_subscriber)


add_compile_options(-O -Wall -std=c++14 -fpermissive)


find_package(catkin REQUIRED)

find_package(catkin REQUIRED COMPONENTS 
    std_msgs
    roscpp
    my_publisher
)

catkin_package(
    CATKIN_DEPENDS
    roscpp
    my_publisher
)

###########
## Build ##
###########

include_directories(
    include
    ${catkin_INCLUDE_DIRS}
)


add_executable(my_subscriber
    src/my_subscriber.cpp)

add_dependencies(my_subscriber ${${PROJECT_NAME}_EXPORTED_TARGETS} ${catkin_EXPORTED_TARGETS})
target_link_libraries(my_subscriber
    ${catkin_LIBRARIES}
)
