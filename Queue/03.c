// Circular Queue using array

#include<stdio.h>
#include<stdlib.h>
#define N 5

int queue[N];
int front = -1;
int rear = -1;

void enqueue(int x) {
    if (front == -1 && rear == -1) {
        front = rear = 0;
        queue[rear] = x;
    } 
    else if (((rear + 1) % N) == front) {
        printf("Queue is full\n");
    } else {
        rear = (rear + 1) % N;
        queue[rear] = x;
    }
}

void dequeue() {
    if (front == -1 && rear == -1) {
        printf("Underflow\n");
    } else if (front == rear) {
        front = rear = -1;
    } else {
        printf("%d dequeued\n", queue[front]);
        front = (front + 1) % N;
    }
}

void display() {
    int i = front;
    if (front == -1 && rear == -1) {
        printf("Queue is Empty\n");
    } else {
        printf("Queue is: ");

        while(i != rear) {
            printf("%d ",queue[i]);
            i = (i + 1) % N;
        }
        printf("%d\n", queue[rear]);
    }
}

void peek() {
    printf("%d\n", queue[front]);
}


int main() {
//     int choice;
//     int ele;

//    while(1) {
    
//     printf("\n1.enqueue\n2.dequeue\n3.display\n4.peek\n5.exit\nEnter your choice: ");
//     scanf("%d", &choice);

//      switch (choice)
//     {
//     case 1:
//         printf("enter element: ");
//         scanf("%d",&ele);
//         enqueue(ele);
//         break;

//     case 2:
//         dequeue();
//         break;

//     case 3:
//         display();
//         break;

//     case 4:
//         peek();
//         break;

//     case 5:
//         printf("Exiting...");
//         exit(0);
    
//     default:
//         printf("enter valid choice");
//         break;
//     }
//    }


    enqueue(2);
    enqueue(-1);
    enqueue(5);
    enqueue(6);
    enqueue(7);

    display();
    dequeue();

    display();
    dequeue();
    peek();

    dequeue();
    dequeue();
    display();

    enqueue(1);
    enqueue(2);
    enqueue(11);
    enqueue(13);
    display();
    enqueue(1);

    return 0;

}