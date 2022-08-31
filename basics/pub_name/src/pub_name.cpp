#include "ros/ros.h"
#include <iostream>
#include <std_msgs/String.h>
#include <cstdlib>
#include <ctime>

int main(int argc, char **argv)
{
    ros::init(argc, argv, "pub_name");

    ros::NodeHandle nh;

    ros::Publisher pub_name = nh.advertise<std_msgs::String>("/my_name", 100);
    
    ros::Rate loop_rate(10);

    srand((unsigned int)time(NULL));

    while(ros::ok())
    {
        std_msgs::String name;
         
        std::stringstream ss;
        ss << "Kim Jin Seok";
        name.data = ss.str();

        pub_name.publish(name);

        ros::spinOnce();
        loop_rate.sleep();
    }

    return 0;
}