#include "queue.h"

void initQueue(Queue* q, unsigned int size)
{
    q->data = new unsigned int[size];
    q->size = size;
    q->front = 0;
    q->rear = 0;
    q->count = 0;
}

void cleanQueue(Queue* q)
{
    delete[] q->data; // משחרר את הזיכרון
    q->data = nullptr;
    q->size = 0;
    q->front = 0;
    q->rear = 0;
    q->count = 0;
}

bool isEmpty(Queue* q)
{
    return q->count == 0;
}

bool isFull(Queue* q)
{
    return q->count == q->size;
}

void enqueue(Queue* q, unsigned int newValue)
{
    if (isFull(q))
    {
        cout << "Queue is full! Cannot enqueue " << newValue << endl;
        return;
    }

    q->data[q->rear] = newValue;
    q->rear = (q->rear + 1) % q->size; // תור מעגלי
    q->count++;
}

int dequeue(Queue* q)
{
    if (isEmpty(q))
    {
        cout << "Queue is empty!" << endl;
        return -1;
    }

    int value = q->data[q->front];
    q->front = (q->front + 1) % q->size;
    q->count--;
    return value;
}