#include "ros/ros.h"
#include <iostream>
#include <std_msgs/String.h>
#include <cstdlib>
#include <ctime>

int main(int argc, char **argv)
{
    ros::init(argc, argv, "pub_subject");

    ros::NodeHandle nh;

    ros::Publisher pub_subject = nh.advertise<std_msgs::String>("/my_subject", 100);
    
    ros::Rate loop_rate(10);

    srand((unsigned int)time(NULL));

    while(ros::ok())
    {
        std_msgs::String subject;
         
        std::stringstream ss;
        ss << "Sensor motion robot engineering";
        subject.data = ss.str();

        pub_subject.publish(subject);

        ros::spinOnce();
        loop_rate.sleep();
    }

    return 0;
}