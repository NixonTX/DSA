// Pointer & 2D Array
// 2D Array = Array of array
/*   ___________         ___________________
    |          |        |                   |
    | a[i][j]  |        |   *(*(a+i) + j)   |
    |__________|        |___________________|     
                                                 */       

#include<stdio.h>
int main() {
    int a[3][3] = {6, 2, 5, 0, 1, 3, 4, 9, 8};
    int i, j;
/* 
    printf("The 2D Array: \n");
    for(i=0; i<3; i++){
        for(j=0; j<3; j++){
            printf("%d ", a[i][j]);
        }
        printf("\n");
    }
*/
    int *p;
    // p = a;
    /*
    printf("\na+1         : %d", a+1);
    printf("\n*(a+1)      : %d", *(a+1));
    printf("\n*(*(a+1))   : %d", *(*(a+1)));

    printf("\n&a[1][0]    : %d", &a[1][0]);
    printf("\n*(*(a+1)+2) : %d", *(*(a+1)+2));
    printf("\na[1][2]     : %d", a[1][2]);
    printf("\n**a         : %d", **a);
    // printf("\n**p         : %d", **p);
    // printf("\n**p         : %d", *(*p));
    printf("\n*p          : %d", *p);
    printf("\na[1]+1      : %d", a[1]+1);
    printf("\n&a[1]+1     : %d", &a[1]+1);
    */
   printf("\n**a         : %d", **a);
   printf("\n*p          : %d", *p);
    return 0;

}