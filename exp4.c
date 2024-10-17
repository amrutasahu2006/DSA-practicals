#include <stdio.h>
#include <stdlib.h>

#define MAX 5

typedef struct CircularQueue {
    int items[MAX];
    int front;
    int rear;
    int size;
} CircularQueue;

CircularQueue* createQueue() {
    CircularQueue* queue = (CircularQueue*)malloc(sizeof(CircularQueue));
    queue->front = -1;
    queue->rear = -1;
    queue->size = 0;
    return queue;
}

int isFull(CircularQueue* queue) {
    return queue->size == MAX;
}

int isEmpty(CircularQueue* queue) {
    return queue->size == 0;
}

void enqueue(CircularQueue* queue, int value) {
    if (isFull(queue)) {
        printf("Queue is full. Cannot enqueue %d.\n", value);
        return;
    }

    if (queue->front == -1) {
        queue->front = 0;
    }

    queue->rear = (queue->rear + 1) % MAX;
    queue->items[queue->rear] = value;
    queue->size++;
    printf("Enqueued: %d\n", value);
}

int dequeue(CircularQueue* queue) {
    if (isEmpty(queue)) {
        printf("Queue is empty. Cannot dequeue.\n");
        return -1;
    }

    int item = queue->items[queue->front];
    queue->front = (queue->front + 1) % MAX;
    queue->size--;

    if (queue->size == 0) {
        queue->front = -1;
        queue->rear = -1;
    }

    printf("Dequeued: %d\n", item);
    return item;
}

int peek(CircularQueue* queue) {
    if (isEmpty(queue)) {
        printf("Queue is empty. Nothing to peek.\n");
        return -1;
    }
    return queue->items[queue->front];
}

void printQueue(CircularQueue* queue) {
    if (isEmpty(queue)) {
        printf("Queue is empty.\n");
        return;
    }

    printf("Queue contents: ");
    int i = queue->front;
    for (int count = 0; count < queue->size; count++) {
        printf("%d ", queue->items[i]);
        i = (i + 1) % MAX;
    }
    printf("\n");
}

int main() {
    CircularQueue* queue = createQueue();

    enqueue(queue, 10);
    enqueue(queue, 20);
    enqueue(queue, 30);
    enqueue(queue, 40);
    enqueue(queue, 50);

    printQueue(queue);

    dequeue(queue);
    dequeue(queue);

    enqueue(queue, 60);

    printQueue(queue);

    printf("Front element is: %d\n", peek(queue));

    free(queue);
    return 0;
}
