#ifndef MYQUEUE_H_INCLUDED
#define MYQUEUE_H_INCLUDED

typedef struct NAME_VAL{
    char name[10];
    int val;
}NAME_VAL;

void enqueue(NAME_VAL * queue, NAME_VAL val);
NAME_VAL dequeue(NAME_VAL* queue);
void display_queue(NAME_VAL* queue);
#endif