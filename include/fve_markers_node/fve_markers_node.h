#include "ros/ros.h"
#include <visualization_msgs/Marker.h>
#include <string>

class Waypoint
{
public:
	Waypoint()
	{
		visualization_msgs::Marker wp;
		// wp.header.frame_id 			= frameId;
		wp.header.frame_id 			= "/placeholder";
		wp.header.stamp 			= ros::Time::now();
		// wp.ns 						= nameSpace;
		wp.ns 						= "placeholder";
		wp.id 						= 0;
		wp.type 					= 2;
		wp.action 					= visualization_msgs::Marker::ADD;
		wp.pose.position.x 			= 0;
		wp.pose.position.y 			= 0;
		wp.pose.position.z 			= 0;
		wp.pose.orientation.x 		= 0.0;
		wp.pose.orientation.y 		= 0.0;
		wp.pose.orientation.z 		= 0.0;
		wp.pose.orientation.w  		= 1.0;
		wp.scale.x 					= 1.0;
		wp.scale.y 					= 1.0;
		wp.scale.z 					= 1.0;
		wp.color.r 					= 1.0f;
		wp.color.g 					= 1.0f;
		wp.color.b 					= 1.0f;
		wp.color.a 					= 0.5;
		wp.lifetime  				= ros::Duration();
	}

private:

};