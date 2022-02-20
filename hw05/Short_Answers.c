/*
Chapter 6 short answers - Sammuel Diaz

1. The issue with two dimesional arrays in C/C++ is that they are used for stornig tables and images. Since C/C++ are primarly used for OS
development, they are bad at handling MD arrays. The issue arises when a 2D array is passed to a function. It will require you to specify the
data at compile time.

2. The most commmon would be the flat array, in this case you create a one dimensional array and store your data. To access an element in the array
you have to compute the offset into the array its self. The second is called the numerical recipes trick. In this case you would create two
arrays. A flat array and array of pointers. It simply allows you to use the pointers to access elements in the array.

3. int *b;

b = getArray();




*/