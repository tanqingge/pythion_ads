import rospy
from python_ads.srv import *

def test(req):
     flag1=0
     flag2=0
     for i in req.start_pose:
         if i!=0:
             flag1+=1
     for j in req.end_pose:
         if j!=0:
             flag2+=1
     print("flag1"+str(flag1)+"flag2"+str(flag2))
     resp=begin_end_pointResponse(flag1+flag2)
     print('resp'+str(resp))
     return resp


def python_ads_server():
    rospy.init_node('python_ads_server')
    s = rospy.Service('python_ads', begin_end_point, test)
    print('Service advertised.')
    rospy.spin()

if __name__ == "__main__":
    python_ads_server()