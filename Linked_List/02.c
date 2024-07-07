// insert element at the beginning of the array

#include<stdio.h>
int main() {
    int a[50], size, i, num;

    printf("enter the size of the array: ");
    scanf("%d", &size);

    printf("enter elements into the array: ");
    for(i=0; i<size; i++){
        scanf("%d", &a[i]);
    }

    printf("Previous Array is: ");
    for(i=0; i<size; i++){
        printf("%d ", a[i]);
    }

    printf("\nEnter the data you want to insert: ");
    scanf("%d", &num);

    
        for (i = size -1; i >= 0 ; i--){
            a[i +1] = a[i];
        }
        a[0] = num;
        size ++;

        printf("Modified Array is: ");
        for(i=0; i<size; i++){
        printf("%d ", a[i]);
        }
        
    printf("\nThe End");
    return 0;
}
