#include <stdio.h>
#include <stdlib.h>

struct Node {
  int data;
  struct Node* next;
  struct Node* prev;
};

void traversal(struct Node* ptr){
    while(ptr->next!=NULL){
        printf("%d\n",ptr->data);
        ptr=ptr->next;
    }
    printf("%d\n\n",ptr->data);
    while(ptr->prev!=NULL){
        printf("%d\n",ptr->data);
        ptr=ptr->prev;
    }
    printf("%d\n",ptr->data);
}

int main(){
    struct Node* head = (struct Node*)malloc(sizeof(struct Node));
    struct Node* second = (struct Node*)malloc(sizeof(struct Node));
    struct Node* third = (struct Node*)malloc(sizeof(struct Node));
    struct Node* fourth = (struct Node*)malloc(sizeof(struct Node));

    head->data = 1;
    head->prev = NULL;
    head->next = second;

    second->data = 3;
    second->prev = head;
    second->next = third;

    third->data = 5;
    third->prev = second;
    third->next = fourth;

    fourth->data = 7;
    fourth->prev = third;
    fourth->next = NULL;
 
    traversal(head);
    return 0;
}