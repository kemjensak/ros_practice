#include <string_merger.hpp>

namespace string_merger
{
    StringMerger::StringMerger()
    {
        //todo
        sub_major_msg_ = nh.subscribe("/my_major", 100, &StringMerger::callbackMajor, this);
        sub_subject_msg_ = nh.subscribe("/my_subject", 100, &StringMerger::callbackSubject, this);
        sub_department_number_msg_ = nh.subscribe("/my_department_number", 100, &StringMerger::callbackDepartmentNumber, this);
        sub_name_msg_ = nh.subscribe("/my_name", 100, &StringMerger::callbackName, this);
        
        pub_merged_string_ = nh.advertise<std_msgs::String>("/my_information",100);
        
        major_ok_ = false;
        subject_ok_ = false;
        department_number_ok_ = false;
        name_ok_ = false;
    }

    StringMerger::~StringMerger()
    {   

    }

    void StringMerger::callbackDepartmentNumber(const std_msgs::String::ConstPtr &ptr)
    {
        //todo
        department_number_data_ = ptr-> data;
        department_number_ok_ = true;
    }

    void StringMerger::callbackMajor(const std_msgs::String::ConstPtr &ptr)
    {
        //todo
        major_data_ = ptr-> data;
        major_ok_ = true;
    }

    void StringMerger::callbackName(const std_msgs::String::ConstPtr &ptr)
    {
        //todo
        name_data_ = ptr-> data;
        name_ok_ = true;
    }

    void StringMerger::callbackSubject(const std_msgs::String::ConstPtr &ptr)
    {
        //todo
        subject_data_ = ptr-> data;
        subject_ok_ = true;
    }

    void StringMerger::run()
    {
        if( !(department_number_ok_ && major_ok_ && name_ok_ && subject_ok_) ) return;
        
        merged_data_ = major_data_ +" / "+ subject_data_ +" / "+ department_number_data_ +" / "+ name_data_;
        merged_msg_.data = merged_data_;

        pub_merged_string_.publish(merged_msg_);

        ROS_INFO("Publishing: %s", merged_msg_.data.c_str());

        major_ok_ = false;
        subject_ok_ = false;
        department_number_ok_ = false;
        name_ok_ = false;

        //todo

        
    }
}

int main(int argc, char **argv)
{
    ros::init(argc, argv, "string_merger");

    string_merger::StringMerger SM;

    ros::Rate loop_rate(10);
    while(ros::ok())
    {
        SM.run();

        ros::spinOnce();

        loop_rate.sleep();

        
    }
    //todo
}