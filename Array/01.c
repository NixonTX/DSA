// del from beg & Pointer
#include<stdio.h>
int main() {
    /* int arr[10] = {10, 20, 30, 40, 55};
    int size = 5;

    for(int i=0; i<size-1; i++) {
        arr[i] = arr[i+1];
    }
    size--;

    for(int i=0; i<size; i++){
        printf("%d ", arr[i]);
    } */

   int arr[] = {6, 2, 1, 5, 3};
   int *q = arr;

    printf("\n*q     : %d", *q);
    printf("\n*q+4   : %d", *q+4);
    printf("\nq : %d", q[1]);
    printf("\na[0] : %d", &arr[0]);
    printf("\nq+1    : %d", q+1);
    printf("\nq[1]    : %d", q[1]);
    printf("\na[1] : %d", &arr[1]);

    printf("\nq+2    : %d", q+2);
    printf("\n&q     : %d", &q);
    printf("\nq      : %d", q);

    printf("\n-(*q)  : %d", -(*q));
    printf("\na      : %d", arr);
    printf("\n*a      : %d", *arr);
    printf("\na[4]   : %d", arr[4]);


    return 0;
}