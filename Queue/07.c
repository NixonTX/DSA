// Implementation of DEQUE using Circular Array

#include<stdio.h>
#include<stdlib.h>
#define N 5

int deque[N];
int F = -1, R = -1;     // front and rear respectivily

void enqueueFront(int x) {
    if ((F == 0 && R == N-1) || (F == R+1)) {
        printf("Queue is Full\n");
    } 
    else if ( F == -1 && R == -1) {
        F = R = 0;
        deque[F] = x;
    } 
    else if (F == 0) {
        F = N-1;
        deque[F] = x;
    } else {
        F--;
        deque[F] = x;
    }
}

void enqueueRear(int x) {
    if ((F == 0 && R == N-1) || (F == R+1)) {
        printf("Queue is Full\n");
    } 
    else if ( F == -1 && R == -1) {
        F = R = 0;
        deque[R] = x;
    } 
    else if (R == N-1) {
        R = 0;
        deque[R] = x;
    } else {
        R++;
        deque[R] = x;
    }
}

void display() {
    int i = F;

    printf("Elements are: ");
    while(i != R) {
        printf("%d ", deque[i]);
        i = (i+1) % N;
    }

    printf("%d ", deque[R]);
    printf("\n");
}

void getFront() {
    if (F == -1 && R == -1) {
        printf("Queue is Empty\n");
    } else {
        printf("%d ", deque[F]);
    }

    printf("\n");
}

void getRear() {
    if (F == -1 && R == -1) {
        printf("Queue is Empty\n");
    } else {
        printf("%d ", deque[R]);
    }

    printf("\n");
}

void dequeueFront() {
    if (F == -1 && R == -1) {
        printf("Queue is Empty\n");
    } 
    else if (F == R) {
        printf("%d is dequeued\n", deque[F]);
        F = R = -1;
    }
    else if(F == N-1) {
        printf("%d is dequeued\n", deque[F]);
        F = 0;
    } else {
        printf("%d is dequeued\n", deque[F]);
        F++;
    }
}

void dequeueRear() {
    if (F == -1 && R == -1) {
        printf("Queue is Empty\n");
    } 
    else if (F == R) {
        printf("%d is dequeued\n", deque[R]);
        F = R = -1;
    }
    else if(R == 0) {
        printf("%d is dequeued\n", deque[R]);
        R = N-1;
    } else {
        printf("%d is dequeued\n", deque[R]);
        R--;
    }
}

/*  in most cases, using NULL is preferred for indicating a null pointer or absence of value, as it's a convention in C. But functionally, using 0 instead of NULL in non-pointer contexts wouldn't make a significant difference. */

int main() {
    printf("ef 2 : ");
    enqueueFront(2);
    printf("eF 5 : ");
    enqueueFront(5);
    printf("e R -1 : ");
    enqueueRear(-1);
    printf("e R 0 : ");
    enqueueRear(0);
    printf("eF 7 : ");
    enqueueFront(7);
    printf("ef 4: ");
    enqueueFront(4);

    display();

    printf("dF :");
    dequeueFront();
    display();

    printf("dR :");
    dequeueRear();
    display();

    printf("dF :");
    dequeueFront();
    display();

    return 0;
}