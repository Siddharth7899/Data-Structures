#include <stdio.h>
#include <stdlib.h>

struct Node{
  int data;
  struct Node* next;
};

struct Node* deletingHeadNode(struct Node* head){
   struct Node* ptr = head;
   head = head->next;
   free(ptr);
   return head;
}

void deleteNodeatIndex(struct Node* head,int index){
   struct Node* p = head;
   int i=0;
   while(i!=index-1){
       i++;
       p = p->next;
   }
   struct Node* q = p->next;
   p->next = q->next;
   free(q);
}

void deleteLastNode(struct Node* head){
   struct Node* p=head;
   struct Node* q=head->next;
   while(q->next!=NULL){
       q=q->next;
       p=p->next;
   }
   p->next = NULL;
   free(q);
}

struct Node* deletingNodewithgivenValue(struct Node* head,int value){
   struct Node* p = head;
   if(p->data==value){
      p = deletingHeadNode(head);
      return p;
   }
   else{
       struct Node* q=head->next;
       while(q->data!=value && q->next!=NULL){
           q=q->next;
           p=p->next;
       }
       if(q->data==value){
       p->next = q->next;
       free(q);
       }
       return head;
   }
}

void traversal(struct Node* ptr){
  while(ptr!=NULL){
      printf("%d\n",ptr->data);
      ptr = ptr->next;
  }
}

int main(){
    struct Node* head = (struct Node*)malloc(sizeof(struct Node));
    struct Node* second = (struct Node*)malloc(sizeof(struct Node));
    struct Node* third = (struct Node*)malloc(sizeof(struct Node));
    struct Node* fourth = (struct Node*)malloc(sizeof(struct Node));

    head->data = 1;
    head->next = second;
    second->data = 3;
    second->next = third;
    third->data = 5;
    third->next = fourth;
    fourth->data = 7;
    fourth->next = NULL;

    traversal(head);

    //deleting head node T.C O(1)
    // head =  deletingHeadNode(head);
    // traversal(head);

    //deleting node at given index T.C O(n);
    // deleteNodeatIndex(head,2);
    // traversal(head);

    //deleting last Node T.C O(n);
    // deleteLastNode(head);
    // traversal(head);

    //deleting the firstr Node at the given value T.C O(n)
    head = deletingNodewithgivenValue(head,5);
    traversal(head);

    return 0;
}