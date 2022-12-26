#include <stdio.h>
#include "myqueue.h"
#include <stdlib.h>
#include <string.h>
#ifndef ENOUGH20
#define ENOUGH20 10
#endif
int first=-1;
int rear=-1;


NAME_VAL empty_pair = {"empty",-9};

NAME_VAL_QUEUE make_queue(int length){

    NAME_VAL_QUEUE queue={.queue=(NAME_VAL*)malloc(sizeof(NAME_VAL)*length),.first=-1,.rear=-1};
    queue.max=length;
    return queue;
    }


void enqueue(NAME_VAL_QUEUE* queue, NAME_VAL val){
if(queue->rear!=queue->max){
    if(queue->first==-1 && queue->rear==-1){
        queue->first=0;
        queue->rear=0;
        queue->queue[queue->first]=val;
        //printf("rear is %d pushed %d\n",queue->rear, val);
    }else{
    queue->rear++;
    queue->queue[queue->rear]=val;
    //printf("rear is %d pushed %d\n",queue->rear ,val);    
    }
}else{
    printf("QUEUE OVERFLOW\n");
}
};
void enqueue_with_string(NAME_VAL_QUEUE* queue, NAME_VAL val,char* string){
    memcpy(val.name,string,ENOUGH20-1);val.name[ENOUGH20]='\0';
if(queue->rear!=queue->max){
    if(queue->first==-1 && queue->rear==-1){
        queue->first=0;
        queue->rear=0;
        queue->queue[queue->first]=val;
        //printf(" this is you ? queue id %x rear is %d pushed %s\n",&queue,queue->rear, val.name);
    }else{
    queue->rear++;
    queue->queue[queue->rear]=val;
    //printf("rear is %d pushed %s\n",queue->rear ,val.name);    
    }
}else{
    printf("QUEUE OVERFLOW\n");
}
};
NAME_VAL dequeue(NAME_VAL_QUEUE* queue){
if(queue->first!=-1&&queue->first<=queue->rear){
    //printf("\n%d was first POPED %s\n",queue->first,queue->queue[queue->first].name);
    return queue->queue[queue->first++];
}
else{
    //printf("QUEUE IS EMPTY\n");
    queue->first=queue->rear=-1;
    //printf("INITIALIZEED FIRST AND REAR\n");
    return empty_pair;
    
}
};

void display_queue(NAME_VAL_QUEUE queue){
    if(queue.first==queue.rear){
        if(queue.first==-1){
            printf("QUEUE IS EMPTY\n");}
        else{
            //printf("%d. member is %d\n",queue.first,queue.queue[queue.first]);
            }
    }
    else{
        for(int i=queue.first;i<=queue.rear;i++){
        //printf("%d.memeber is %d\n",i,queue.queue[i]);
    }
    }
}
