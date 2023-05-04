#include <iostream>
#include "math.h"

using namespace std;

// TODO
// - change coordinate struct to vector

struct coordinate
{
    float x = 0.0;
    float y = 0.0;
    float z = 0.0;
};

struct camera_properties
{
    float horizontal_angle = 20;  // in degrees
    float vertical_angle   = 20;  // in degress
    float focal_distance   = 2.0; // in cm
};


bool point_inside_camera_fov( 
     coordinate * camera_coordinate, 
     coordinate * end_effector_coordinate,
     camera_properties * endoscope_camera_properties );

int main(){
    
    coordinate * camera_coordinate;
    coordinate * end_effector_coordinate;

    camera_properties * endoscope_camera_properties;

    // set camera coordinate
    camera_coordinate->x = 0.0; // in cm
    camera_coordinate->y = 0.0; // in cm
    camera_coordinate->z = 0.0; // in cm

    // set end effector coordinate
    end_effector_coordinate->x = 10.0; // in cm
    end_effector_coordinate->y = 10.0; // in cm
    end_effector_coordinate->z = 10.0; // in cm

    

    return 0;
}



bool point_inside_camera_fov( 
    coordinate * camera_coordinate, 
    coordinate * end_effector_coordinate,
    camera_properties * endoscope_camera_properties  )
{
    coordinate * relative;
    relative->x = end_effector_coordinate->x - camera_coordinate->x;
    relative->y = end_effector_coordinate->y - camera_coordinate->y;
    relative->z = end_effector_coordinate->z - camera_coordinate->z;

    float dist_from_camera =  sqrt( pow( relative->x, 2 ) + pow( relative->y, 2 ) + pow( relative->z, 2 )  );  

    bool front_of_camera_check = false;
    bool front_of_camera_focus_check = false;

    if( relative->z >= 0){
        front_of_camera_check = true;
    }

    if ( dist_from_camera >= endoscope_camera_properties->focal_distance ){
        front_of_camera_focus_check = true;
    }

    if ( front_of_camera_check && front_of_camera_focus_check ){
        
        // here we check if camera is inside frame or not





    }

}