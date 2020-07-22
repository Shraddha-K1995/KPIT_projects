#include "ros/ros.h"
#include "std_msgs/String.h"
#include "beginner_tutorials/Num.h"

int main(int argc, char **argv)
{
  ros::init(argc, argv, "EvenNumberGenerator");
  ros::NodeHandle Node1;
  ros::Publisher pub1 = Node1.advertise<beginner_tutorials::Num>("FirstNumber", 1000);
  ros::Rate loop_rate(1);
  int Iterator = 0;
  beginner_tutorials::Num msg;
  while (ros::ok())
  {
    msg.data1 = Iterator * 2;
    Iterator++;
    ROS_INFO("%ld", msg.data1);
    pub1.publish(msg);
    ros::spinOnce();
    loop_rate.sleep();
  }
  return 0;
}