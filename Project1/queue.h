#pragma once

#ifndef QUEUE_H
#define QUEUE_H

#include <iostream>
using namespace std;

struct Queue
{
    unsigned int* data;  
    unsigned int size;   
    unsigned int front;  
    unsigned int rear;   
    unsigned int count;  
};

void initQueue(Queue* q, unsigned int size);
void cleanQueue(Queue* q);

void enqueue(Queue* q, unsigned int newValue);
int dequeue(Queue* q); 

bool isEmpty(Queue* q);
bool isFull(Queue* q);

#endif /* QUEUE_H */