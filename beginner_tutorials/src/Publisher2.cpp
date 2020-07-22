#include "ros/ros.h"
#include "std_msgs/String.h"
#include "beginner_tutorials/Num.h"

int main(int argc, char **argv)
{
  ros::init(argc, argv, "OddNumberGenerator");
  ros::NodeHandle Node2;
  ros::Publisher pub2 = Node2.advertise<beginner_tutorials::Num>("SecondNumber", 1000);
  ros::Rate loop_rate(1);
  int Iterator = 1;
  beginner_tutorials::Num msg1;
  while (ros::ok())
  {
    msg1.data2 = 2 * Iterator - 1;
    Iterator++;
    ROS_INFO("%ld", msg1.data2);
    pub2.publish(msg1);
    ros::spinOnce();
    loop_rate.sleep();
  }
  return 0;
}