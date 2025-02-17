#include<stdio.h>
int main() {
    int a[] = {6, 2, 1, 5, 3};
    int *q = a;

    printf("\n*q     : %d", *q);
    printf("\n*q+4   : %d", *q+4);
    printf("\nq+1    : %d", q+1);
    printf("\n&q     : %d", &q);
    printf("\nq      : %d", q);
    printf("\n-(*q)  : %d", -(*q));
    printf("\na      : %d", a);
    printf("\n*a     : %d", *a);
    printf("\na[4]   : %d", a[4]);

    printf("\na+1    : %p", a+1);
    printf("\n*(a+1) : %d", *(a+1));
    
    return 0;
}