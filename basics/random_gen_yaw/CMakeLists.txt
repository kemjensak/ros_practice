cmake_minimum_required(VERSION 3.0.2)
project(random_gen_yaw)


add_compile_options(-O -Wall -std=c++14 -fpermissive)


find_package(catkin REQUIRED)

find_package(catkin REQUIRED COMPONENTS 
    std_msgs
    roscpp
    random_gen_x
)


catkin_package(
    CATKIN_DEPENDS
    roscpp
    random_gen_x
)

###########
## Build ##
###########

include_directories(
    include
    ${catkin_INCLUDE_DIRS}
)


add_executable(random_gen_yaw
    src/random_gen_yaw.cpp)

add_dependencies(random_gen_yaw ${${PROJECT_NAME}_EXPORTED_TARGETS} ${catkin_EXPORTED_TARGETS})
target_link_libraries(random_gen_yaw
    ${catkin_LIBRARIES}
)
