#include <stdio.h>
#define MAX 5

int queue[MAX];
int front = -1, rear = -1;

// Enqueue operation
void enqueue(int x) {
    if (rear == MAX - 1) {
        printf("The Queue is full!!\n");
    } else {
        if (front == -1) front = 0;   // first element
        rear++;
        queue[rear] = x;
        printf("%d has been queued!\n", x);
    }
}

// Dequeue operation
int dequeue() {
    if (front == -1 || front > rear) {
        printf("The Queue is empty!!\n");
        front = rear = -1;   // reset
        return -1;
    } else {
        int x = queue[front];
        printf("%d has been dequeued!\n", x);
        front++;
        return x;
    }
}

// Display queue
void display() {
    if (front == -1 || front > rear) {
        printf("Queue is empty!\n");
    } else {
        int i;  // declare outside loop for C89 compatibility
        printf("Queue elements: ");
        for (i = front; i <= rear; i++) {
            printf("%d ", queue[i]);
        }
        printf("\n");
    }
}

int main() {
    enqueue(10);
    enqueue(20);
    enqueue(30);
    enqueue(40);
    enqueue(50);
    enqueue(60); // full

    display();

    dequeue();
    dequeue();
    dequeue();
    dequeue();
    dequeue();
    dequeue(); // empty

    display();

    return 0;
}
