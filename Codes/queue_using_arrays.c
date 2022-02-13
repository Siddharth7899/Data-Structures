#include <stdio.h>
#include <stdlib.h>
#define MAX 100000

struct Queue {
   int size;
   int front;
   int reer;
   int *arr;
};

int isEmpty(struct Queue* queue){
    if(queue->front == queue->reer) return 1;
    return 0;
}

int isFull(struct Queue* queue){
    if(queue->reer == queue->size-1) return 1;
    return 0;
}

void Enqueue(struct Queue* queue,int data){
    if(isFull(queue)){
        printf("Queue is Full\n");
    }else{
        queue->reer++;
        queue->arr[queue->reer] = data;
    }
}

int Dequeue(struct Queue* queue){
    if(isEmpty(queue)){
        printf("Queue is Empty\n");
        return -1;
    }else{
       queue->front++;
       return queue->arr[queue->front];
    }
}

int main(){
    struct Queue* queue = (struct Queue*)malloc(sizeof(struct Queue));
    queue->size = MAX;
    queue->front=-1;
    queue->reer=-1;
    queue->arr = (int*)malloc(queue->size*sizeof(int));
    
    //Enqueuing elements into queue
    Enqueue(queue,1);
    Enqueue(queue,5);
    Enqueue(queue,10);
    Enqueue(queue,20);

    int e = Dequeue(queue);
    while(e!=-1){
        printf("Elements are : %d \n",e);
        e = Dequeue(queue);
    }
    return 0;
}