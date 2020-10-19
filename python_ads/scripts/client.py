import rospy
import sys
from python_ads.srv import *

def python_ads_client(start_pose,end_pose):
    rospy.wait_for_service('python_ads')
    try:
        python_ads_client_test = rospy.ServiceProxy('python_ads', begin_end_point)
        print('i love ros')
        resp1 = python_ads_client_test(start_pose, end_pose)
        print(str(resp1.flag))
        return resp1.flag
    except rospy.ServiceException as e:
            print("Service call failed: %s"%e)

if __name__== '__main__':
    print("Please enter start pose")
    st_x_=input()
    st_y_=input()
    st_z_=input()
    st_roll_=input()
    st_pitch_=input()
    st_yaw_=input()
    print("Please enter end pose")
    ed_x_=input()
    ed_y_=input()
    ed_z_=input()
    ed_roll_=input()
    ed_pitch_=input()
    ed_yaw_=input()
    start_pose=[st_x_,st_y_,st_z_,st_roll_,st_pitch_,st_yaw_]
    end_pose=[ed_x_,ed_y_,ed_z_,ed_roll_,ed_pitch_,ed_yaw_]
    print("the flag is"+str(python_ads_client(start_pose,end_pose)))