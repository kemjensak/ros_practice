#include "ros/ros.h"
#include <iostream>
#include <std_msgs/String.h>
#include <cstdlib>
#include <ctime>

int main(int argc, char **argv)
{
    ros::init(argc, argv, "pub_department_number");

    ros::NodeHandle nh;

    ros::Publisher pub_department_number = nh.advertise<std_msgs::String>("/my_department_number", 100);
    
    ros::Rate loop_rate(10);

    srand((unsigned int)time(NULL));

    while(ros::ok())
    {
        std_msgs::String department_number;
         
        std::stringstream ss;
        ss << "20162138";
        department_number.data = ss.str();

        pub_department_number.publish(department_number);

        ros::spinOnce();
        loop_rate.sleep();
    }

    return 0;
}