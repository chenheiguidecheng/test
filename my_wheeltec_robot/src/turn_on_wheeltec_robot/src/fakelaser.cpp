#include <ros/ros.h>
#include <sensor_msgs/LaserScan.h>
#include "fakelaser.h"
/*
int main(int argc, char** argv)
{
    ros::init(argc, argv, "laser_scan_publisher");
    ros::NodeHandle n;

    ros::Publisher scan_pub = n.advertise<sensor_msgs::LaserScan>("scan", 1000);
     std::string frame_id;
     float angle_max,angle_min;
     int num_readings ;
    double laser_frequency ;
    float rangemax,rangemin;
    int count = 0;
    ros::NodeHandle nh_private("~");
    nh_private.param<std::string>("frame_id", frame_id, "fakelaser");
    nh_private.param<float>("angle_min", angle_min, 135.0f);
    nh_private.param<float>("angle_max", angle_max, 225.0f);
    nh_private.param<int>("num_readings", num_readings, 20);
    nh_private.param<double>("laser_frequency", laser_frequency, 10);

    nh_private.param<float>("rangemin", rangemin, 0.15);
    nh_private.param<float>("rangemax", rangemax, 10);
    ros::Rate r(10.0);
    double ranges[num_readings];
    double intensities[num_readings];

    while(n.ok())
    {
        //generate some fake data for our laser scan
       /* for(unsigned int i = 0; i < num_readings; ++i)
        {
            ranges[i] = 1;
            //intensities[i] = 100 + count;
        }*/
     /*   ros::Time scan_time = ros::Time::now();
        ROS_INFO("num_readings: %d\n",num_readings);
        //populate the LaserScan message
        sensor_msgs::LaserScan scan;
        scan.header.stamp = scan_time;
        //scan.header.frame_id = "base_link";
        scan.header.frame_id = frame_id;
        ROS_INFO("angle_min: %.6f\n",angle_min);
        ROS_INFO("angle_max: %.6f\n",angle_max);
        scan.angle_min = angle_min*3.1415926f/180.0f;
        scan.angle_max = angle_max *3.1415926f/180.0f;

        
        scan.angle_increment = (scan.angle_max  -  scan.angle_min) / (double)num_readings;
        scan.time_increment = (1 / laser_frequency) / (num_readings);
        scan.range_min = rangemin;
        scan.range_max = rangemax;
        scan.ranges.resize(num_readings);
        scan.intensities.resize(num_readings);
        for(unsigned int i = 0; i < num_readings; ++i)
        {   
            
                scan.ranges[i] = 0.8;
           
           
            //scan.intensities[i] = intensities[i];
        }

        scan_pub.publish(scan);

        ++count;
        r.sleep();
    }
}*/

ros::Publisher scan_pub ;
void soanrcallback(const sensor_msgs::LaserScan &sonar_laser_data)
{
     ROS_INFO("soanrcallback");
    scan_pub.publish(sonar_laser_data);
}

int main(int argc, char** argv)
{
    ros::init(argc, argv, "sonar_laser__publisher");
    ros::NodeHandle n;
    scan_pub = n.advertise<sensor_msgs::LaserScan>("scan", 1000);
    ros::Subscriber  sonar_sub = n.subscribe("/sonar_scan_data", 100, soanrcallback);
    ros::spin();
}
