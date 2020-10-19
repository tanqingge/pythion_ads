#include "ros/ros.h"
#include "python_ads/begin_end_point.h"
#include <cstdlib>

int main(int argc, char **argv)
{
    ros::init(argc, argv,"python_ads_client");
    ros::NodeHandle nh_;
    ros::ServiceClient client=nh_.serviceClient<python_ads::begin_end_point>("python_ads");
    python_ads::begin_end_point srv;
    ROS_INFO("Please enter start pose");
    float st_x_,st_y_,st_z_,st_roll_,st_pitch_,st_yaw_;
    std::cin>>st_x_;
    std::cin>>st_y_;
    std::cin>>st_z_;
    std::cin>>st_roll_;
    std::cin>>st_pitch_;
    std::cin>>st_yaw_;
    srv.request.start_pose={st_x_,st_y_,st_z_,st_roll_,st_pitch_,st_yaw_};
    ROS_INFO("Please enter end pose");
    float ed_x_,ed_y_,ed_z_,ed_roll_,ed_pitch_,ed_yaw_;
    std::cin>>ed_x_;
    std::cin>>ed_y_;
    std::cin>>ed_z_;
    std::cin>>ed_roll_;
    std::cin>>ed_pitch_;
    std::cin>>ed_yaw_;
    srv.request.end_pose={ed_x_,ed_y_,ed_z_,ed_roll_,ed_pitch_,ed_yaw_};
    if(client.call(srv))
    {
        ROS_INFO("The flag of python_ads is %d",srv.response.flag);
    }
    else
    {
    ROS_ERROR("Failed to caculate inverse kinematics");
    return 1;
    }
    return 0;

}