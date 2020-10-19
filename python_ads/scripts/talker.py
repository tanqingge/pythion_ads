#!/usr/bin/env python
 
import rospy
#from后边是自己的包.msg，也就是自己包的msg文件夹下，test是我的msg文件名test.msg
from python_ads.msg import aixs_elongation
 
def talker():
    pub = rospy.Publisher('chatter', aixs_elongation, queue_size=10)
    rospy.init_node('talker', anonymous=True)
    rate = rospy.Rate(10) # 10hz
    k=0
    while not rospy.is_shutdown():
        for i in range(len(axis_length)):
            axis_length[i]=3*i
        k=k+1
        step=k
        pub.publish(aixs_elongation(axis_length))
 
if __name__ == '__main__':
    try:
        talker()
    except rospy.ROSInterruptException:
        pass