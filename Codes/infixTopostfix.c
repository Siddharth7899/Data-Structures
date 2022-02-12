#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Stack{
  int top;
  int size;
  char *arr;
};

int isEmpty(struct Stack* stack){
    return stack->top==-1 ? 1 : 0;
}

int isFull(struct Stack* stack){
    return stack->top==stack->size-1 ? 1 : 0;
}

char Stacktop(struct Stack* stack){
    return stack->arr[stack->top];
}

void Push(struct Stack* stack,char c){
    if(isFull(stack)){
        printf("Stack Overflow\n");
    }else{
       stack->top++;
       stack->arr[stack->top]=c;
    }
}

char Pop(struct Stack* stack){
    if(isEmpty(stack)){
        printf("Stack Underflow\n");
        return -1;
    }else{
        char ch = stack->arr[stack->top];
        stack->top--;
        return ch;
    }
}

int isOperator(char ch){
    if(ch=='+' || ch=='-' || ch=='*' || ch=='/' || ch=='^') return 1;
    return 0;
}

int prec(char ch){
    if(ch=='^') return 4;
    if(ch=='*' || ch=='/') return 3;
    if(ch=='+' || ch=='-') return 2;
    else return 0;
}

char* InfixToPostfix(char *exp){
    struct Stack* stack = (struct Stack*)malloc(sizeof(struct Stack));
    stack->top=-1;
    stack->size= strlen(exp)+1;
    stack->arr = (char*)malloc(stack->size*sizeof(char));
    char *postfix = (char*)malloc(stack->size*sizeof(char));
    int i=0,j=0;
    while(exp[i]!='\0'){
      if(!isOperator(exp[i])){
        postfix[j]=exp[i];
        i++;
        j++;
      }else{
        if(isEmpty(stack)){
            Push(stack,exp[i]);
            i++;
        }
        else if(prec(exp[i]) > prec(Stacktop(stack))){
            Push(stack,exp[i]);
            i++;
        }
        else{
            while(prec(exp[i])<=prec(Stacktop(stack)) && !isEmpty(stack)){
                postfix[j]=Pop(stack);
                j++;
            }
            Push(stack,exp[i]);
            i++;
        }
      }
    }
    while(!isEmpty(stack)){
      postfix[j] = Pop(stack);
      j++;
    }
    postfix[j] = '\0';
    return postfix;
}

int main(){
    char *exp = "a+b+c-d*f/g^k";
    printf("Postfix Conversion of the given expression is : %s\n",InfixToPostfix(exp));
    return 0;
}