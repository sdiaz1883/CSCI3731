//
//  PA_2.c
//  PA2.4
//
//  Created by Sammuel Diaz on 2/2/22.
//

#include "PA_2.h"
#include "math.h"
#include <stdio.h>





int main()

{
    
    
    // variables
    double y = 1000.00;
    double v = 0.00;
    double dt = 1.00;
    double a = 0.00;
   

    // variables for a

    double Cd = 1.00;
    double A = 1.00;
    double m = 80.00;
    double p = 1.2;
    double g = 9.81;
    

    
    while (y > 0.00){
        
        
        y = y + v * dt;
       
       //Calculate acceleration
       double Vsqr = pow(v, 2);
       double a = -g + 1.00/2.00 * Cd * A * p * Vsqr / m;
       
       
       //Calculate velocity
        
       v = v + a * dt;
       
       // print v
       
       printf("velocity = %lf\n", v);
       
       
       // print acceleration
       
       printf("acceleration = %lf\n", a);
       //print height at delta
       
       printf("Height at Delta t = %lf\n", y);
        
        
        
    }
    
    
    
    // Calculate height seconds later
 
    
    /*To do
     Orgainze output on sep lines 
     
     Create for while loop? while y is greater than zero repeat,
     for (int y = 1000, y <= 0; y)
    {
        
        
        
    }*/
    

    return 0;

}
