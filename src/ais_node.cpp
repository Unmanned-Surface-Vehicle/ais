#include <ros/ros.h>
#include <ais/Ais.h>

int main(int argc, char **argv){

  ros::init(argc, argv, "ais_node");
  ros::NodeHandle n;

  ros::Publisher ais_pub = n.advertise<ais::Ais>("/ais", 10);
  ros::Rate loop_rate(10);

  ais::Ais ais_msg;
  ais_msg.mmsi_num = "0";
  ais_msg.antenna_location.x = 12;

  while (ros::ok()){

    ais_pub.publish(ais_msg);

  }

  ros::spin();

  return 0;
}