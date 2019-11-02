#include "ros/ros.h"
#include "std_msgs/String.h"
#include <vector>
#include <iostream>
#include <string>
#include <sstream>

using namespace std;


void chatterCallback(const std_msgs::String::ConstPtr& msg)
{
  //ROS_INFO("I heard: [%s]", msg->data.c_str());

  vector<string> seperated;
  string message = msg->data;
  stringstream ss(message);
  string tok;

  while(getline(ss, tok, ' ')) {
    seperated.push_back(tok);
  }

  int deger = stoi(seperated[4].c_str());
  float sonuc = atof(seperated[6].c_str());

  ROS_INFO("%s %s %s %s %d %s %f", seperated[0].c_str(), seperated[1].c_str(), seperated[2].c_str(), seperated[3].c_str(), deger, seperated[5].c_str(), sonuc);
}

int main(int argc, char **argv)
{
  ros::init(argc, argv, "asma");

  ros::NodeHandle n;
  ros::Subscriber sub = n.subscribe("chatter", 1000, chatterCallback);

  ros::spin();

  return 0;
}
