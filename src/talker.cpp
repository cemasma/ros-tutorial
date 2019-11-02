#include "ros/ros.h"
#include "std_msgs/String.h"
#include <bits/stdc++.h>
#include <sstream>
#include <random>

int main(int argc, char **argv)
{
  ros::init(argc, argv, "cem");
  ros::NodeHandle n;
  
  ros::Publisher chatter_pub = n.advertise<std_msgs::String>("chatter", 1000);

  ros::Rate loop_rate(10);

  std::default_random_engine generator;
  std::uniform_int_distribution<int> distribution(INT_MIN, INT_MAX);
  std::uniform_real_distribution<float> distribution2(-9999.0, 1000.0);
 
  int count = 0;
  int rastgele = 0;
  float toplam = 0.0;
  while (ros::ok())
  {
    std_msgs::String msg;

    std::stringstream ss;

    rastgele = distribution(generator);
    toplam = distribution2(generator);

    ss << "merhaba yapbenzet " << count << " deger " << rastgele << " sonuc " << toplam ;
    msg.data = ss.str();

    ROS_INFO("%s", msg.data.c_str());

    chatter_pub.publish(msg);

    ros::spinOnce();

    loop_rate.sleep();
    ++count;
  }


  return 0;
}
