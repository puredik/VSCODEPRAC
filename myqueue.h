#ifndef MYQUEUE_H_INCLUDED
#define MYQUEUE_H_INCLUDED

#define MAX_QUEUE 50

typedef struct NAME_VAL{
    char name[10];
    int val;
    int queue_num_first;
    int queue_num_rear;
}NAME_VAL;

typedef struct NAME_VAL_QUEUE{
    NAME_VAL* queue;
    int first;
    int rear;
    int max;
}NAME_VAL_QUEUE;



NAME_VAL_QUEUE make_queue(int length);
void enqueue(NAME_VAL_QUEUE* queue, NAME_VAL val);
NAME_VAL dequeue(NAME_VAL_QUEUE* queue);
void display_queue(NAME_VAL_QUEUE queue);
void enqueue_with_string(NAME_VAL_QUEUE* queue, NAME_VAL val,char* string);
#endif