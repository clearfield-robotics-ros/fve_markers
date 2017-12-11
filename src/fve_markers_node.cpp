#include <ros/ros.h>
//#include "fve_markers_node/fve_markers_node.h"
#include <visualization_msgs/MarkerArray.h>
#include <visualization_msgs/Marker.h>
#include <string>

using namespace std;

// string wp1Frame, wp1Ns, wp2Frame, wp2Ns, wp3Frame, wp3Ns, wp4Frame, wp4Ns;

int main(int argc, char** argv)
{
	ros::init(argc, argv, "fve_markers_node");
	ros::NodeHandle n;
	// ros::Publisher marker1Pub = n.advertise<visualization_msgs::Marker>("visualization_marker",0);
	// ros::Publisher marker2Pub = n.advertise<visualization_msgs::Marker>("visualization_marker",0);
	// ros::Publisher marker3Pub = n.advertise<visualization_msgs::Marker>("visualization_marker",0);
	// ros::Publisher marker4Pub = n.advertise<visualization_msgs::Marker>("visualization_marker",0);
	ros::Publisher markersPub = n.advertise<visualization_msgs::MarkerArray>("visualization_marker_array",0);
	ros::Rate loop_rate(1);

	//point 1 : 40 yard near (origin)
	visualization_msgs::Marker wp1;
	wp1.header.frame_id 		= "/wp1";
	wp1.ns 						= "wp1";
	wp1.id 						= 1;
	//point 2 : 40 yard away
	visualization_msgs::Marker wp2;
	wp2.header.frame_id  		= "/wp2";
	wp2.ns 						= "wp2";
	wp2.id 						= 2;
	//point 3 : 50 yard away
	visualization_msgs::Marker wp3;
	wp3.header.frame_id 	 	= "/wp3";
	wp3.ns 						= "wp3";
	wp3.id 						= 3;
	//point 4 : -40 yard away
	visualization_msgs::Marker wp4;
	wp4.header.frame_id  		= "/wp4";
	wp4.ns 						= "wp4";
	wp4.id 						= 4;
	//point 4 : -40 yard near
	visualization_msgs::Marker wp5;
	wp5.header.frame_id  		= "/wp5";
	wp5.ns 						= "wp5";
	wp5.id 						= 5;
	//point 4 : 50 yard near
	visualization_msgs::Marker wp6;
	wp6.header.frame_id  		= "/wp6";
	wp6.ns 						= "wp6";
	wp6.id 						= 6;


	//common attributes
	uint32_t shape 																							= 2; //sphere
	wp1.header.stamp = wp2.header.stamp = wp3.header.stamp = wp4.header.stamp = wp5.header.stamp = wp6.header.stamp								= ros::Time();
	wp1.type = wp2.type = wp3.type = wp4.type = wp5.type = wp6.type																= shape;
	wp1.action = wp2.action = wp3.action = wp4.action = wp5.action = wp6.action														= visualization_msgs::Marker::ADD;
	wp1.pose.position.x = wp2.pose.position.x = wp3.pose.position.x = wp4.pose.position.x = wp5.pose.position.x = wp6.pose.position.x 					= 0;
	wp1.pose.position.y = wp2.pose.position.y = wp3.pose.position.y = wp4.pose.position.y = wp5.pose.position.y = wp6.pose.position.y					= 0;
	wp1.pose.position.z = wp2.pose.position.z = wp3.pose.position.z = wp4.pose.position.z = wp5.pose.position.z = wp6.pose.position.z		 			= 0;
	wp1.pose.orientation.x = wp2.pose.orientation.x = wp3.pose.orientation.x = wp4.pose.orientation.x = wp5.pose.orientation.x = wp6.pose.orientation.x		= 0.0;
	wp1.pose.orientation.y = wp2.pose.orientation.y = wp3.pose.orientation.y = wp4.pose.orientation.y = wp5.pose.orientation.y = wp6.pose.orientation.y		= 0.0;
	wp1.pose.orientation.z = wp2.pose.orientation.z = wp3.pose.orientation.z = wp4.pose.orientation.z = wp5.pose.orientation.z = wp6.pose.orientation.z		= 0.0;
	wp1.pose.orientation.w = wp2.pose.orientation.w = wp3.pose.orientation.w = wp4.pose.orientation.w = wp5.pose.orientation.w = wp6.pose.orientation.w	 	= 1.0;
	wp1.scale.x = wp2.scale.x = wp3.scale.x = wp4.scale.x = wp5.scale.x = wp6.scale.x													= 1.0;
	wp1.scale.y = wp2.scale.y = wp3.scale.y = wp4.scale.y = wp5.scale.y = wp6.scale.y 													= 1.0;
	wp1.scale.z = wp2.scale.z = wp3.scale.z = wp4.scale.z = wp5.scale.z = wp6.scale.z													= 1.0;
	wp1.color.r = wp2.color.r = wp3.color.r = wp4.color.r = wp5.color.r = wp6.color.r													= 1.0f;
	wp1.color.g = wp2.color.g = wp3.color.g = wp4.color.g = wp5.color.g = wp6.color.g													= 1.0f;
	wp1.color.b = wp2.color.b = wp3.color.b = wp4.color.b = wp5.color.b = wp6.color.b													= 1.0f;
	wp1.color.a = wp2.color.a = wp3.color.a = wp4.color.a = wp5.color.a = wp6.color.a													= 0.5;
	wp1.lifetime = wp2.lifetime = wp3.lifetime = wp4.lifetime = wp5.lifetime = wp6.lifetime 				 								= ros::Duration(); //while ros is open
	wp1.frame_locked = wp2.frame_locked = wp3.frame_locked = wp4.frame_locked = wp5.frame_locked = wp6.frame_locked 								= 1;
	

	//initialize array
	visualization_msgs::MarkerArray markerArray;
	markerArray.markers.push_back(wp1);
	markerArray.markers.push_back(wp2);
	markerArray.markers.push_back(wp3);
	markerArray.markers.push_back(wp4);
	markerArray.markers.push_back(wp5);
	markerArray.markers.push_back(wp6);

	while (ros::ok())
	{
		// while (marker1Pub.getNumSubscribers() < 1 || marker2Pub.getNumSubscribers() < 1 || marker3Pub.getNumSubscribers() < 1 || marker4Pub.getNumSubscribers() < 1)
		while (markersPub.getNumSubscribers() < 1)
		{
			if (!ros::ok()){return 0;}
			ROS_WARN_ONCE("Please remember to subscribe to markers");
			sleep(1);
		}
		// marker1Pub.publish(wp1);
		// marker2Pub.publish(wp2);
		// marker3Pub.publish(wp3);
		// marker4Pub.publish(wp4);
		markersPub.publish(markerArray);
		ros::spinOnce(); 
      	loop_rate.sleep();
	}
	return 0;
}