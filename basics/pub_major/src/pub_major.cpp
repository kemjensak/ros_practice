#include "ros/ros.h"
#include <iostream>
#include <std_msgs/String.h>
#include <cstdlib>
#include <ctime>

int main(int argc, char **argv)
{
    ros::init(argc, argv, "pub_major");

    ros::NodeHandle nh;

    ros::Publisher pub_major = nh.advertise<std_msgs::String>("/my_major", 100);
    
    ros::Rate loop_rate(10);

    srand((unsigned int)time(NULL));

    while(ros::ok())
    {
        std_msgs::String major;
         
        std::stringstream ss;
        ss << "School of AI convergence";
        major.data = ss.str();

        pub_major.publish(major);

        ros::spinOnce();
        loop_rate.sleep();
    }

    return 0;
}