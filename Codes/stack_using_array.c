#include <stdio.h>
#include <stdlib.h>

struct Stack{
  int size;
  int top;
  int *arr;
};

int isEmpty(struct Stack* stack){
   if(stack->top==-1) return 1;
   else return 0;
}
int isFull(struct Stack* stack){
   if(stack->top==stack->size-1) return 1;
   else return 0;
}

void Push(struct Stack* stack,int val){
   if(isFull(stack)){
       printf("Stack Overflow!!");
   }else{
       stack->top++;
       stack->arr[stack->top] = val;
   }
}
int Pop(struct Stack* stack){
   if(isEmpty(stack)){
       printf("Stack Underflow!!");
       return -1;
   }else{
       int element = stack->arr[stack->top];
       stack->top--;
       return element;
   }
}
int Peak(struct Stack* stack,int index){
   int ind = stack->top-index+1;
   if(ind < 0){
       printf("No element present with the given index!");
       return -1;
   }else{
       return stack->arr[ind];
   }
}

int main(){
  struct Stack *stack = (struct Stack*)malloc(sizeof(struct Stack));
  stack->size = 100;
  stack->top = -1;
  stack->arr = (int*)malloc(stack->size*sizeof(int));
  Push(stack,1);
  Push(stack,2);
  Push(stack,3);
  Push(stack,4);
  Push(stack,5);
  Pop(stack);
  Pop(stack);
  int i=1;
  while(Peak(stack,i)>0){
    printf("%d\n",Peak(stack,i));
    i++;
  }
  return 0;
}