#include "ros/ros.h"
#include "python_ads/begin_end_point.h"

bool test(python_ads::begin_end_point::Request &req,python_ads::begin_end_point::Response &res)
{
    int flag1=0;
    int flag2=0;
    for(int i=0;i<6;i++)
    {
        if(req.start_pose[i]!=0)
        ++flag1;
    }
    for(int j=0;j<6;j++)
    {
        if(req.end_pose[j]!=0)
        ++flag2;
    }
    ROS_INFO("flag1:%d,flag2:%d",flag1,flag2);
    res.flag=flag1+flag2;
    if((flag1!=0)&&(flag2!=0))
    {
        ROS_INFO("the pose is real,the flag is:%d",res.flag);
        return true;
    }
    else 
    {
        ROS_INFO("the pose is null");
        return false;
    }
    
} 


int main(int argc, char **argv)
{
    /* code for main function */
    ros::init(argc, argv, "python_ads_server");
    ros::NodeHandle nh_;
    ros::ServiceServer service=nh_.advertiseService("python_ads",test);
    ROS_INFO("Ready to test.");
    ros::spin();
    return 0;
}