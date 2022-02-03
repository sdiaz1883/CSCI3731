//
//  pA_3.c
//  pA_3.4
//
//  Created by Sammuel Diaz on 2/2/22.
//

#include "pA_3.h"
#include <cmath>


// Create Variables

double y = 0; // height above ground
double x = 0; // horizontal distance over ground
double dt = 0; //delta t seconds
double v = 0; // velocity
double a = 0; // acceleration
double D = 0; // Drag
double v0 = 250.00; //intial muzzle velocity
double m = 30.00; // mass 30 kg
double cD = 0.45;  // drag coeff
double A = 0.03; // area of object
double p = 1.2; // density of air
double g = 9.81; // gravity
double theta = 30.0; // theta


// create variables for velocity and acceleration horizonatl and verticle movement

double Vx = 0; // variable to store Vx result
double Vy = 0; // variable to store Vy result

double Ax = 0; // variable to store accel horizontal movement
double Ay = 0; // variable to store accel verticle movement

double main()
{
    // components of velocity
    double x = (x + Vx * dt);
    double y = (y + Vy * dt);
    
    // change in velocity
    double Vx = Vx + (Ax * dt);
    double vy = Vy + (Ay * dt);
    
    // Velocity
    double v = sqrt ((Vx * Vx) + (Vy * Vy));
    
    // Acceleration
    double Ax = (-D * Vy) /v;
    double Ay = -g -(-D * Vy) /v;
    
    // compute drag
    double D = 0.5 * cD * A * p * (v * v) /m;
    
    printf("At %.2f seconds, your distance is %.2f feet. \n",t,x);
    
    //
    
    }

double range(double theta)
{
    // actively working on this
   
    double Vx = v0 * cos(theta * (M_PI/180.0));
    double Vy = v0 * sin(theta * (M_PI/180.0));
    
    printf("Horizontal distance traveled ");
    
    
    return range;
    
    
    
}

