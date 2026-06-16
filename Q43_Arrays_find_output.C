
int arr[]= {1, 2, 3, 4, 5};
// For the given array, what will be the following outputs?

/*********************************

a) *(arr + 2)

Because we have a stary "value at address" operator *, it will return the value at the address arr + 2, which is 3.

b) *(arr + 5)

Because we have a star "value at address" operator *, it will return the value at the address arr + 5
However, this is out of bounds for the array, so the behavior is undefined. It only goes till arr+4

This can return garbage values or cause a segmentation fault or zero.

************************************/