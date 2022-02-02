#include <stdio.h>
#include <stdlib.h>

struct Node{
   int data;
   struct Node* next;
};

struct Node* insertAtbegining(struct Node* head,int data){  
   struct Node* ptr = (struct Node*)malloc(sizeof(struct Node)); 
   ptr->data=data;
   ptr->next=head;
   return ptr;
}

struct Node* insertAtindex(struct Node* head,int data,int index){
   struct Node* ptr = (struct Node*)malloc(sizeof(struct Node));
   struct Node* p = head;
   int i=0;
   while(i!=index-1){
       p = p->next;
       i++;
   }
   ptr->next = p->next;
   ptr->data=data;
   p->next = ptr;
   return head;
}

struct Node* insertAtend(struct Node* head,int data){
   struct Node* ptr = (struct Node*)malloc(sizeof(struct Node));
   struct Node* p = head;
   while(p->next!=NULL){
       p = p->next;
   }
   ptr->next = NULL;
   ptr->data=data;
   p->next = ptr;
   return head;
}

void insertAfterNode(struct Node* prevNode,int data){
   struct Node* ptr = (struct Node*)malloc(sizeof(struct Node));
   ptr->data = data;
   ptr->next = prevNode->next;
   prevNode->next=ptr;
}

void traversal(struct Node* ptr){
    while(ptr!=NULL){
        printf("%d\n",ptr->data);
        ptr = ptr->next;
    }
}

int main(){

    /****************************************************/

    // Creation and traversal of linked-list
    struct Node* head;
    struct Node* first;
    struct Node* second;
    
    head = (struct Node*)malloc(sizeof(struct Node));
    first = (struct Node*)malloc(sizeof(struct Node));
    second = (struct Node*)malloc(sizeof(struct Node));

    head->data=7;
    head->next=first;
    first->data=11;
    first->next=second;
    second->data=13;
    second->next=NULL;
    
    //insert at begining T.C O(1)
    head = insertAtbegining(head,1); 

    //insert in between T.C O(N)
    head = insertAtindex(head,30,1);
    
    //insert at end T.C O(n)
    head = insertAtend(head,50);

    //insert after a given Node T.C O(1)
    insertAfterNode(first,30);

    traversal(head);
    /***************************************************/

    /****************************************************/

    //implementation using array 
    /*
    struct Node* a[10];
    for(int i=0 ; i<10 ; i++){
        a[i] = (struct Node*)malloc(sizeof(struct Node));
        // here we can take user input too!!
        a[i]->data=i+1;
        if(i==9) a[i]->next=NULL;
        else a[i]->next=a[i+1];
    }

    for(int i=0 ; i<10 ; i++){
        printf("%d\n",a[i]->data);
    }
    */
    /****************************************************/
    return 0;
}