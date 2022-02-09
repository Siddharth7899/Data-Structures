#include <stdio.h>
#include <stdlib.h>

struct Node {
  int data;
  struct Node* next;
};

struct Node* top;

void traversal(struct Node* ptr){
    while(ptr!=NULL){
        printf("%d\n",ptr->data);
        ptr = ptr->next;
    }
}

int isEmpty(struct Node* top){
    return top==NULL ? 1 : 0;
}

int isFull(struct Node* top){
    struct Node* n = (struct Node*)malloc(sizeof(struct Node));
    return n==NULL ? 1 : 0;
}

struct Node* Push(struct Node* top,int x){
    if(isFull(top)){
      printf("Stack Overflow\n");
    }else{
      struct Node* n = (struct Node*)malloc(sizeof(struct Node));
      n->data = x;
      n->next = top;
      top = n;
      return top;
    }
}
/*Method 1 by making struct Node* top global so we are able to change the value of top
  without passing it by refrence
*/
int Pop(struct Node* tp){
    if(isEmpty(tp)){
      printf("Stack Underflow\n");
    }else{
      struct Node* p = tp;
      int element = p->data;
      top = tp->next;
      free(p);
      return element;
    }
}
/*Method 2 by making struct Node* top local but here we have to pass top by refrence

int Pop(struct Node** top){
    if(isEmpty(*top)){
      printf("Stack Underflow\n");
    }else{
      struct Node* p = *top;
      int element = p->data;
      *top = (*top)->next;
      free(p);
      return element;
    }
}
*/
int Peek(struct Node* top,int pos){
  struct Node* ptr = top;
  for(int i=0 ; i<pos-1 && ptr!=NULL ; i++) ptr = ptr->next;
  return ptr!=NULL ? ptr->data : -1 ;
}

int stackTop(struct Node* top){
  return !isEmpty(top) ? top->data : -1 ;
}

int stackBottom(struct Node* top){
  struct Node* ptr = top;
  while(ptr->next != NULL){
    ptr = ptr->next;
  }
  return ptr!=NULL ? ptr->data : -1 ;
}

int main(){
    // struct Node* top;
    top=NULL;
    top = Push(top,7);
    top = Push(top,9);
    top = Push(top,11);
    traversal(top);
    printf("Element %d is popped\n",Pop(top));
    traversal(top);
    printf("Topmost element of the stack is %d\n",stackTop(top));
    printf("Bottomost element of the stack is %d\n",stackBottom(top));
    for(int i=1;i<=3;i++) printf("Element is %d \n",Peek(top,i));
    return 0;
}