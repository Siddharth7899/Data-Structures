#include <stdio.h>
#include <stdlib.h>
#define MAX 5

struct CircularQueue {
   int size;
   int front;
   int reer;
   int *arr;
};

int isEmpty(struct CircularQueue* queue){
    if(queue->front == queue->reer) return 1;
    return 0;
}

int isFull(struct CircularQueue* queue){
    if((queue->reer+1)%queue->size == queue->front) return 1;
    return 0;
}

void Enqueue(struct CircularQueue* queue,int data){
    if(isFull(queue)){
        printf("Queue is Full\n");
    }else{
        queue->reer = (queue->reer+1)%queue->size;
        queue->arr[queue->reer] = data;
    }
}

int Dequeue(struct CircularQueue* queue){
    if(isEmpty(queue)){
        printf("Queue is Empty\n");
        return -1;
    }else{
       queue->front = (queue->front+1)%queue->size;
       return queue->arr[queue->front];
    }
}

int main(){
    struct CircularQueue* queue = (struct CircularQueue*)malloc(sizeof(struct CircularQueue));
    queue->size = MAX;
    /*we initialize front and reer is equal to 0 because here we use concept of
    circular increment*/
    queue->front=0;
    queue->reer=0;
    queue->arr = (int*)malloc(queue->size*sizeof(int));
    
    //Enqueuing elements into queue
    Enqueue(queue,1);
    Enqueue(queue,5);
    Enqueue(queue,10);
    Enqueue(queue,20);

    Dequeue(queue);
    Dequeue(queue);
    Dequeue(queue);
    Dequeue(queue);
    //This enqueuing did'nt show queue is full is size is 5
    Enqueue(queue,20);
    return 0;
}