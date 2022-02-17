#include <stdio.h>
#include <stdlib.h>

struct Node {
  int data;
  struct Node* left;
  struct Node* right;
};

struct Node* createNode(int data){
    struct Node * n = (struct Node*)malloc(sizeof(struct Node));
    n->data = data;
    n->left=NULL;
    n->right=NULL;
    return n;
}

void PreOrder(struct Node* root){
  if(root==NULL) return;
  printf("%d ",root->data);
  PreOrder(root->left);
  PreOrder(root->right);
}

void PostOrder(struct Node* root){
  if(root==NULL) return;
  PostOrder(root->left);
  PostOrder(root->right);
  printf("%d ",root->data);
}

void InOrder(struct Node* root){
  if(root==NULL) return;
  InOrder(root->left);
  printf("%d ",root->data);
  InOrder(root->right);
}

int main(){
  /*
    Ex-    1
          / \
         2   3
        / \   \
       5   6   4
  */
   struct Node* root = createNode(1);
   struct Node* p1 = createNode(2);
   struct Node* p2 = createNode(3);
   struct Node* p3 = createNode(5);
   struct Node* p4 = createNode(6);
   struct Node* p5 = createNode(4);

   //connecting nodes
   root->left = p1;
   root->right = p2;
   p1->left = p3;
   p1->right = p4;
   p2->right = p5;

   //Traversals
   PreOrder(root);
   printf("\n");
   PostOrder(root);
   printf("\n");
   InOrder(root);
   printf("\n");
   return 0;
}