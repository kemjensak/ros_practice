cmake_minimum_required(VERSION 3.0.2)
project(my_publisher_class)


add_compile_options(-O -Wall -std=c++14 -fpermissive)


find_package(catkin REQUIRED)

find_package(catkin REQUIRED COMPONENTS 
    std_msgs
    roscpp
    message_generation
)

add_message_files(
    DIRECTORY msg
    FILES
    class_msg.msg
)

generate_messages(
    DEPENDENCIES
    std_msgs
)

catkin_package(
    CATKIN_DEPENDS
    roscpp
)

###########
## Build ##
###########

include_directories(
    include
    ${catkin_INCLUDE_DIRS}
)


add_executable(my_publisher_class
    src/my_publisher_class.cpp)

add_dependencies(my_publisher_class ${${PROJECT_NAME}_EXPORTED_TARGETS} ${catkin_EXPORTED_TARGETS})
target_link_libraries(my_publisher_class
    ${catkin_LIBRARIES}
)
