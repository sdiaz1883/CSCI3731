//
//  pA_3.c
//  pA_3.4
//
//  Created by Sammuel Diaz on 2/2/22.
//

#include "pA_4.h"
#include "math.h"


int main()
{
    // double Distance_traveled
    float angles[5] = {25.0, 30.0, 45.0, 70.0, 75.0};

    printf("(Distance Traveled, Max Height, Angle)\n");

    int i=0;
    while (i<5)
    {
        float* data  = canon_range(angles[i]);
        printf("(%.2f,%.2f,%.2f)\n",data[0],data[1],angles[i]);
        i++;
    } 
}


