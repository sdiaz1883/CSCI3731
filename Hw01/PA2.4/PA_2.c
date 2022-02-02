//
//  PA_2.c
//  PA2.4
//
//  Created by Sammuel Diaz on 2/2/22.
//

#include "PA_2.h"
#include "math.h"
#include "fcntl.h"
#include <stdio.h>


    // variables
int y = 1000;
int v = 0;
int t = 1;
int a = 0;
int hS = 0;
int vS = 0;

// variables for a

int Cd = 1;
int A = 1;
int m = 80;
double p = 1.2;
double g = 9.81;
double Vsqr = 0;



int main()

{
    // Calculate height seconds later
    int hS = y + v * t;
    
    //Calculate acceleration
    double Vsqr = pow(v, 2);
    int a = -g + 1/2 * Cd * A * p * Vsqr / m;
    
    
    //Calculate velocity
     
    int vS = v + a * t;
    
    // print v
    
    printf("velocity = %d", vS);
    
    
    // print acceleration
    
    printf("acceleration = %d", a);
    //print height at delta
    
    printf("Height at Delta t = %d", hS);
    
    /*To do
     Orgainze output on sep lines 
     
     Create for while loop? while y is greater than zero repeat,
     for (int y = 1000, y <= 0; y--)
    {
        
        
        
    }*/
    

    return 0;

}
