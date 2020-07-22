#include "ros/ros.h"
#include "std_msgs/String.h"
#include "beginner_tutorials/Num.h"
#include <mutex>

std::mutex callBackMutex;
int64_t sum = 0;
void evencallback(const beginner_tutorials::Num::ConstPtr &msg)
{
  std::lock_guard<std::mutex> guard(callBackMutex);
  if (sum == 0)
  {
    sum = msg->data1;
  }
  else if (sum != 0 && msg->data1 != 0)
  {
    sum = msg->data1; ///////If evencall back is hit consecutive times///////
  }
  else
  {
    sum += msg->data1;
    std::cout << "print sum:" << sum << std::endl;
    sum = 0;
  }
  sum = msg->data1;
}
void oddcallback(const beginner_tutorials::Num::ConstPtr &msg1)
{
  std::lock_guard<std::mutex> guard(callBackMutex);
  if (sum == 0)
  {
    sum = msg1->data2;
  }
  else if (sum != 0 && msg1->data1 != 0)
  {
    sum = msg1->data1; ///////If oddcall back is hit consecutive times///////
  }
  else
  {
    sum += msg1->data2;
    std::cout << "print sum:" << sum << std::endl;
    sum = 0;
  }
}
int main(int argc, char **argv)
{
  ros::init(argc, argv, "DisplayAddition");
  ros::NodeHandle Node3;
  ros::Subscriber sub1 = Node3.subscribe("FirstNumber", 1000, evencallback);
  ros::Subscriber sub2 = Node3.subscribe("SecondNumber", 1000, oddcallback);
  ros::spin();
  return 0;
}