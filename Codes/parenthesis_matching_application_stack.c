#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
  Parenthesis is of type '(' , '{' , '[' , ')' , '}' , ']' only
  This is code is only ensure that the given expression is balanced parenthesis.
  Does the expression is valid or not is not specified by this code.
*/

struct Stack {
  int size;
  int top;
  char *arr;
};

int isEmpty(struct Stack* stack){
    return stack->top == -1 ? 1 : 0 ;
}

int isFull(struct Stack* stack){
    return stack->top == stack->size -1 ? 1 : 0 ;
}

void Push(struct Stack* stack,char element){
    if(isFull(stack)){
        printf("Stack Overflow\n");
    }else{
        stack->top++;
        stack->arr[stack->top] = element;
    }
}

char Pop(struct Stack* stack){
    if(isEmpty(stack)) return -1;
    char ele = stack->arr[stack->top];
    stack->top--;
    return ele;
}

int isMacth(char a,char b){
    if(a=='(' && b==')' || a=='{' && b=='}' || a=='[' && b==']') return 1;
    return 0;
}

int ParenthesisMatch(char *exp){
   struct Stack *stack = (struct Stack*)malloc(sizeof(struct Stack));
   stack->top = -1;
   stack->size = strlen(exp)+1;
   stack->arr = (char*)malloc(stack->size*sizeof(char));
   for(int i=0 ; exp[i]!='\0' ; i++){
     if(exp[i]=='(' || exp[i]=='{' || exp[i]=='[') Push(stack,exp[i]);
     else if(exp[i]==')' || exp[i]=='}' || exp[i]==']'){
       if(isEmpty(stack)) return 0;
       char popped_char = Pop(stack);
       if(!isMacth(popped_char,exp[i])) return 0;
     }
   }
   return isEmpty(stack)==1 ? 1 : 0;
}

int main(){
  char *exp = "3+2(1{2+5})[7*9]";
  if(ParenthesisMatch(exp)){
      printf("Given Expression is Balanced\n");
  }else{
      printf("Given Expression is not Balanced\n");
  }
  return 0;
}