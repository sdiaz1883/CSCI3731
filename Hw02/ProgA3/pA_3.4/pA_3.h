//
//  pA_3.h
//  pA_3.4
//
//  Created by Sammuel Diaz on 2/2/22.
//

#ifndef pA_3_h
#define pA_3_h

#include <stdio.h>
#include "math.h"
// Create Variables

double y = 0; // height above ground
double x = 0; // horizontal distance over ground
double dt = 1; //delta t seconds
double v = 0; // velocity
double a = 0; // acceleration
double D = 0; // Drag
int v0 = 250.00; //intial muzzle velocity
double m = 30.00; // mass 30 kg
double cD = 0.45;  // drag coeff
double A = 0.03; // area of object
double p = 1.2; // density of air
double g = 9.81; // gravity

// create variables for velocity and acceleration horizonatl and verticle movement

double Vx = 0; // variable to store Vx result
double Vy = 0; // variable to store Vy result

double Ax = 0; // variable to store accel horizontal movement
double Ay = 0; // variable to store accel verticle movement

float canon_range(float theta)
{
    double x=0, y=0;
    // Starting Velocity
    double Vx = 250 * cos(theta*(M_PI/180));
    double Vy = 250 * sin(theta*(M_PI/180));
    printf("(x,y)\n");

    while (1)
    {
        // components of velocity
        x = (x + Vx * dt);
        y = (y + Vy * dt);
        
        
        // change in velocity
        Vx = Vx + (Ax * dt);
        Vy = Vy + (Ay * dt);
        
        // Velocity
        v = sqrt ((Vx * Vx) + (Vy * Vy));

        // compute drag
        D = 0.5 * cD * A * p * (v * v) /m;
        
        // Acceleration
        Ax = (-D * Vy) /v;
        Ay = -g -(-D * Vy) /v;
        
        printf("(%.2f,%.2f)\n",x,y);
        if(y<=0)
        {
            break;
        } 
    }
    return x; 
}

#endif /* pA_3_h */
