#include "ros/ros.h"
#include <iostream>
#include <std_msgs/String.h>

namespace string_merger
{
    class StringMerger
    {
        public:
            StringMerger();
            ~StringMerger();

            void callbackMajor(const std_msgs::String::ConstPtr &ptr);
            void callbackSubject(const std_msgs::String::ConstPtr &ptr);
            void callbackDepartmentNumber(const std_msgs::String::ConstPtr &ptr);
            void callbackName(const std_msgs::String::ConstPtr &ptr);
            
            void run();

        private:

            //todo
            ros::NodeHandle nh;

            ros::Subscriber sub_major_msg_;
            ros::Subscriber sub_subject_msg_;
            ros::Subscriber sub_department_number_msg_;
            ros::Subscriber sub_name_msg_;

            ros::Publisher pub_merged_string_;

            std::string major_data_;
            std::string subject_data_;
            std::string department_number_data_;
            std::string name_data_;
            std::string merged_data_;

            std_msgs::String merged_msg_;



            bool major_ok_;
            bool subject_ok_;
            bool department_number_ok_;
            bool name_ok_;
    };
}