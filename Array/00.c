/* Array

Random Access | Continu

*/

#include<stdio.h>
int main() {
    // int arr[5];
    /* int arr[] = {1, 2, 3, 4, 5};

    printf("Ele at index 2 is %d", arr[2]); */

    // Basic Operations
    /*
Operations on Array in DS
    ~ Insertion
    ~ Deletion
    ~ Searching
    ~ Sorting
*/
    // Traversal
    // int arr[5] = {11, 22, 32, 14, 85};
    // for(int i=0; i<5; i++) {
    //     printf("Ele at index %d is %d\n", i, arr[i]);
    // }

    // Insertion
    // int arr[5] ={10, 20, 30, 40, 70};

    // for(int i=0; i<5; i++) {
    //     printf("%d\n", arr[i+1]);
    // }
    // printf("%d", arr[0]);

    // Insert at a given pos
/*    int arr[7] = {11, 22, 33, 44, 55, 66};
    int size = 6;
    int index = 4;
    int val = 100;

    for (int i = size; i > index; i--) {
        arr[i] = arr[i-1];
    }
    arr[index] = val;
    size++;

    for(int i=0; i<size; i++) {
        printf("%d ", arr[i]);
    }   */

   // Deletion
   /* int arr[5] = {1, 2, 3, 4, 5};
   int size = 5;
   int index = 2;

    for(int i=index; i < size - 1; i++) {
        arr[i] = arr[i+1];
    }
    size--;

    for(int i=0; i<size; i++) {
        printf("%d ", arr[i]);
    } */

   // Linear Search
 /*   int arr[5] = {1, 2, 3, 4, 5};
    int size = 5;
    int target = 2;
    int flag = 0;

    for(int i=0; i<size; i++) {
        if(arr[i] == target) {
            printf("Ele %d found at index %d\n", target, i);
        flag = 1;
        return 0;
        }
    }

    printf("Not found"); */

    // Del form the last
    int arr[4] = {4, 3, 5, 7};
    int size = 4;
    int index = size -1;

    if(size > 0) {
        size--;
    }

    for(int i=0; i<size; i++) {
        printf("%d ", arr[i]);
    }


    return 0;
}
