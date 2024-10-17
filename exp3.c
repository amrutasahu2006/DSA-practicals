#include <stdio.h>
#include <stdlib.h>
#define MAX 5

typedef struct Queue {
    int items[MAX];
    int front;
    int rear;
    int size;
} Queue;

Queue* createQueue() {
    Queue* queue = (Queue*)malloc(sizeof(Queue));
    queue->front = 0;
    queue->rear = -1;
    queue->size = 0;
    return queue;
}

int isFull(Queue* queue) {
    return queue->size == MAX;
}

int isEmpty(Queue* queue) {
    return queue->size == 0;
}

void enqueue(Queue* queue, int value) {
    if (isFull(queue)) {
        printf("Queue is full. Cannot enqueue %d.\n", value);
        return;
    }
    queue->rear = (queue->rear + 1) % MAX;
    queue->items[queue->rear] = value;
    queue->size++;
    printf("Enqueued: %d\n", value);
}

int dequeue(Queue* queue) {
    if (isEmpty(queue)) {
        printf("Queue is empty. Cannot dequeue.\n");
        return -1;
    }
    int item = queue->items[queue->front];
    queue->front = (queue->front + 1) % MAX;
    queue->size--;
    printf("Dequeued: %d\n", item);
    return item;
}

int peek(Queue* queue) {
    if (isEmpty(queue)) {
        printf("Queue is empty. Nothing to peek.\n");
        return -1;
    }
    return queue->items[queue->front];
}

int queueSize(Queue* queue) {
    return queue->size;
}

void printQueue(Queue* queue) {
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
    Queue* queue = createQueue();

    enqueue(queue, 10);
    enqueue(queue, 20);
    enqueue(queue, 30);

    printf("Front element is: %d\n", peek(queue));

    dequeue(queue);
    dequeue(queue);
    printf("Front element is: %d\n", peek(queue));

    enqueue(queue, 40);
    enqueue(queue, 50);
    enqueue(queue, 60);
    enqueue(queue, 70);

    printQueue(queue);

    free(queue);
    return 0;
}