cmake_minimum_required(VERSION 3.0.2)
project(turtleCtrl)


add_compile_options(-O -Wall -std=c++14 -fpermissive)


find_package(catkin REQUIRED)

find_package(catkin REQUIRED COMPONENTS 
    message_generation
    geometry_msgs
    std_msgs
    roscpp
    turtlesim
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



add_executable(turtleCtrl
    src/publishvel.cpp)

add_dependencies(turtleCtrl ${${PROJECT_NAME}_EXPORTED_TARGETS} ${catkin_EXPORTED_TARGETS})
target_link_libraries(turtleCtrl
  ${catkin_LIBRARIES}
)
