// insert element at the desired position in an easiest way

#include<stdio.h>
int main() {
    int a[50], size, i, num, pos;

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
    printf("enter the position: ");
    scanf("%d", &pos);

    if(pos <= 0 || pos > size+1){
        printf("invalid position.");
    } else {
        a[size] = a[pos -1];
        a[pos -1] = num;
        size ++;

        printf("Modified Array is: ");
        for(i=0; i<size; i++){
        printf("%d ", a[i]);
        }
    }

    printf("\nThe End");
    return 0;
}