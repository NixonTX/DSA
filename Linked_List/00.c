/*
Array: fixed size, same datatype, Continueous memory Address, Random Access.
*/
/*
Operations on Array in DS
    ~ Traversal
    ~ Insertion
    ~ Deletion
    ~ Searching
    ~ Sorting
*/

// Traversal: Visiting every element of an array exactly the same time.

#include<stdio.h>
int main() {
    int a[50], size, i;

    printf("enter the size of the array: ");
    scanf("%d", &size);

    printf("enter elements into the array: ");
    for(i=0; i<size; i++){
        scanf("%d", &a[i]);
    }

    printf("The Array is: ");
    for(i=0; i<size; i++){
        printf("%d ", a[i]);
    }
    
    printf("\nThe End");
    return 0;
}