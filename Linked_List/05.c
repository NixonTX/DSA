// deletion of element in an array

#include<stdio.h>
int main() {
    int a[50], i, size, pos, item;
        
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

        printf("\nfrom which position you wanna delete: ");
        scanf("%d", &pos);

        if(pos <= 0 || pos > size) {
            printf("Invalid position");
        } else {
            item = a[pos -1];
            for(i= pos-1; i < size-1; i++) {
                a[i] = a[i +1];
            }
            size--;
        }
    }

        printf("\nModified Array is: ");
        for(i=0; i<size; i++){
        printf("%d ", a[i]);
        }

        printf("\ndeleted item: %d", item);

        return 0;
    }
    