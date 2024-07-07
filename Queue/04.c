// Circular Queue using LL
#include<stdio.h>
#include<stdlib.h>

struct node {
    int data;
    struct node* next;
};
struct node* front = NULL;
struct node* rear = NULL;

void enqueue(int x) {
    struct node* newnode;
    newnode = (struct node*)malloc(sizeof(struct node));
    newnode->data = x;
    newnode->next = NULL;

    if(rear == NULL) {
        front = rear = newnode;
        rear->next = front;
    } else {
        rear->next = newnode;
        rear = newnode;
        rear->next = front;
    }
}

void dequeue() {
    struct node* temp = front;

    if (front == NULL && rear == NULL) {
        printf("Underflow\n");
    } else if (front == rear) {
        printf("\ndeleting/dequeuing %d", front->data);
        front = rear = NULL;
        free(temp);
    } else {
        printf("\ndeleting/dequeuing %d", front->data);
        front = front->next;
        rear->next = front;
        free(temp);
    }
}

void peek() {
    if (front == NULL && rear == NULL) {
        printf("Queue is Empty\n");
    } else {
        printf("\npeeking ele %d\n", front->data);
    }
}

void display() {
    struct node* temp = front;
    if (front == NULL && rear == NULL) {
        printf("Queue is Empty\n");
    } else {
        printf("\nElements are: ");
        while(temp->next != front) {
            printf("%d ", temp->data);
            temp = temp->next;
        }
        printf("%d", temp->data);
    }
}

int main() {
    enqueue(3);
    enqueue(-1);
    enqueue(0);
    display();

    dequeue();
    peek();

    display();
    enqueue(1);
    enqueue(10);
    display();

    return 0;
}