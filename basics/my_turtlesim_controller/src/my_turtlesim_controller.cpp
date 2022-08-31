#include "ros/ros.h"
#include <iostream>
#include <geometry_msgs/Twist.h>
#include <turtlesim/Pose.h>



int main(int argc, char **argv)
{
    ros::init(argc, argv, "my_turtlesim_controller");

    ros::NodeHandle nh;

    ros::Publisher pub_control = nh.advertise<geometry_msgs::Twist>("/turtle1/cmd_vel", 10);

    ros::Rate loop_rate(10);

    while(ros::ok())
    {
        geometry_msgs::Twist twist;

        twist.linear.x = 3.0;
        twist.linear.y = 0.0;
        twist.linear.z = 0.0;
        twist.angular.x = 0.0;
        twist.angular.y = 0.0;
        twist.angular.z = -1.8; //-1.8
        pub_control.publish(twist);
        // ros::Duration(1.0).sleep();

        // twist.linear.x = 0.0; //2.0
        // twist.linear.y = 0.0;
        // twist.linear.z = 0.0;
        // twist.angular.x = 0.0;
        // twist.angular.y = 0.0;
        // twist.angular.z = -(324-180)*3.141592/180; //-1.8
        // pub_control.publish(twist);
        // ros::Duration(1.0).sleep();

        // twist.linear.x = 0.0; //2.0
        // twist.linear.y = 0.0;
        // twist.linear.z = 0.0;
        // twist.angular.x = 0.0;
        // twist.angular.y = 0.0;
        // twist.angular.z = 0.0; //-1.8
        // pub_control.publish(twist);

        // ros::spinOnce();
        ros::spin();
        loop_rate.sleep();
    }

    return 0;
}