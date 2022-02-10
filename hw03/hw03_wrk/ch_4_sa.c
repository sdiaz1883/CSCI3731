//
//  ch_4_sa.c
//  hw03_wrk
//
//  Created by Sammuel Diaz on 2/7/22.
//




/*
 1. a pointer is a memory address for a variable. The closest thing java has is object variables which hold memory addresses.
 
 9.
 a. int* a; it declares a as a pointer that if dereferenced is an int.
 b. const int b; declares b as a pointer that can't be chnaged
 c const int* c; declares c as constant pointer that if dereferenced is a constant int.
 d int* const d; this declares d as a constant pointer that if dreferenced is non const int.
 e cont int* const e; declares e as a const pointer that if dereferenced points to a const int.
 
 12. I believe the issue is that double x was not initialized so we will not know if something goes wrong with the function
 
 14. I think before the if statement 0 gets assigned to sum, then the if statment assigns the new value. After the intial iteration the new sum is assigned to *out. The second iteration will cause the value of sum to change. I believe this might cause seg fault because the it will attempt to access the *out pointer by attempting to change the value of sum?? .. Was really confused with this one.
 
 15. I believe we would need to add an (&) so that the function can pass the information thats inputted in to the variable.
 
 
 
 
 
 */



#include "ch_4_sa.h"
