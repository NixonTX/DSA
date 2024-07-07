// 2D Array
// int a[row][column];

#include<stdio.h>
int main() {
    int a[2][3], i, j;

    printf("enter the elements into the 2D Array: ");
    for(i=0; i<2; i++){
        for(j=0; j<3; j++){
            scanf("%d", &a[i][j]);
        }
    }
    printf("The 2D Array: \n");
    for(i=0; i<2; i++){
        for(j=0; j<3; j++){
            printf("%d ", a[i][j]);
        }
        printf("\n");
    }
    return 0;
}