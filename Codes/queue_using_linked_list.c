#include <stdio.h>
#include <stdlib.h>

struct Node* front;
struct Node* reer;

struct Node {
   int data;
   struct Node* next;
};

void traversal(){
    struct Node* ptr = front;
    while(ptr!=NULL){
        printf("%d ",ptr->data);
        ptr = ptr->next;
    }
    printf("\n");
}

int isEmpty(){
  return front==NULL ? 1 : 0;
}

int isFull(){
  struct Node* n = (struct Node*)malloc(sizeof(struct Node));
  return n==NULL ? 1 : 0;
}

void Enqueue(int data){
  if(isFull()){
      printf("Queue is Full\n");
  }else{
      struct Node* n = (struct Node*)malloc(sizeof(struct Node));
      n->data = data;
      n->next = NULL;
      if(front==NULL){
        front=n;
        reer=n;
      }else{
        reer->next = n;
        reer=n;
      }
  }
}

int Dequeue(){
    int a = -1;
    if(isEmpty()){
        printf("Queue is Empty\n");
    }else{
        struct Node* ptr = front;
        front = front->next;
        a = ptr->data;
        free(ptr);
    }
    return a;
}

int main(){
  front=NULL;
  reer = NULL;
  Enqueue(1);
  Enqueue(5);
  Enqueue(7);
  traversal();
  printf("Element %d is dequeued\n",Dequeue());
  traversal();
  return 0;
}