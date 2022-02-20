//
//  pA_3.c
//  pA_3.4
//
//  Created by Sammuel Diaz on 2/2/22.
//

#include "pA_4.h"
#include "math.h"
void rotateMatrix(char* mat[][150])
{
    // Consider all squares one by one
    int x=0;
    int N=150;
    while(x<(N/2))
	{
		int y=x;
		while(y < (N-x-1))
		{
			// temp variable
            char *temp = mat[x][y];
 
            // Move values from right to top
            mat[x][y] = mat[y][N - 1 - x];
 
            // Move values from bottom to right
            mat[y][N - 1 - x] = mat[N - 1 - x][N - 1 - y];
 
            // Move values from left to bottom
            mat[N - 1 - x][N - 1 - y]   = mat[N - 1 - y][x];
 
            // Assign temp to left
            mat[N - 1 - y][x] = temp;
			y++;
		}
		x++;
	}
    
}
int main()
{
    // double Distance_traveled
    float angle = 0.0;
    printf("Enter an Angle: ");
    scanf("%f", &angle);

    const int size = 150;
    char *path[size][size];
    
	int i =0;
	int j =0;

	int scale_factor = 35;
	while(i<size)
	 {
	 	while (j<size)
	 	{
	 		path[i][j] = " ";
	 		j=j+1;
		}
		j=0;
	 	i=i+1;
	 }
    canon_range(path,scale_factor,angle);
    rotateMatrix(path);
    i=0;
	 j=0;
	 while(i<size)
	 {
	 	while (j<size)
	 	{
    		printf("%s",path[i][j]);
	 		j=j+1;
		}
		printf("\n");
		j=0;
	 	i=i+1;
	 }
//    printf("(%.2f,%.2f,%.2f)\n",data[0],data[1],angles[i]);
}


