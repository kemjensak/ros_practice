#include "ros/ros.h"
#include <iostream>
#include <geometry_msgs/Twist.h>
#include <turtlesim/Pose.h>






int main(int argc, char **argv)
{


    ros::init(argc, argv, "turtleCtrl");

    ros::NodeHandle nh;

    ros::Publisher pub_control = nh.advertise<geometry_msgs::Twist>("/turtle1/cmd_vel", 10);

    ros::Rate loop_rate(10);

    float turtleVelocity;

    nh.getParam("/turtleVelocity", turtleVelocity);
    std::cout << "==== getParam using nh ====" << std::endl;
    std::cout << turtleVelocity << " , " <<  std::endl;
    std::cout << "==== finish setting parameter ====" << std::endl;

    
    while(ros::ok())
    {
        geometry_msgs::Twist twist;

        nh.getParam("/turtleVelocity", turtleVelocity);

        twist.linear.x = turtleVelocity;
        twist.linear.y = 0.0;
        twist.linear.z = 0.0;
        twist.angular.x = 0.0;
        twist.angular.y = 0.0;
        twist.angular.z = 1.0; //-1.8
        pub_control.publish(twist);
        ros::spinOnce();
        loop_rate.sleep();
    }

    return 0;
}