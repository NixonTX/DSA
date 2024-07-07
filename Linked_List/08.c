// Pointers & Arrays

/*
 Stores address
 int *p : Pointer to integer. It contains the address of a variable, which datatype is integer. Not an integer pointer.
*/
#include<stdio.h>
int main() {
    int a[5], i;
    int *q = a;

    printf("enter the elements in the Array: ");
    for(i= 0; i< 5; i++){
        scanf("%d", &a[i]);
    }

    printf("\nThe Array: ");
    for(i= 0; i< 5; i++){
        printf("%d ", a[i]);
    }

    printf("\n%p", a+1);
    printf("\n%p", *(a+1));
    
    return 0;
}