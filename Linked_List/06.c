// deletion of element in an array from the end

#include<stdio.h>
int main() {
    int a[50], i, size, item;
        
    printf("enter the size of the array: ");
    scanf("%d", &size);

    if(size > 50) {
        printf("Out of band");
    } else {
        printf("enter elements into the array: ");
        for(i=0; i<size; i++){
        scanf("%d", &a[i]);
        }

        printf("Previous Array is: ");
        for(i=0; i<size; i++){
            printf("%d ", a[i]);
        }
            size--;
    }
        printf("\nModified Array is: ");
        for(i=0; i<size; i++){
        printf("%d ", a[i]);
        }
        return 0;
    }
