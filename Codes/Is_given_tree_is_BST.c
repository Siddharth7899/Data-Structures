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

int isBST(struct Node* root){
    static struct Node* prev = NULL;//here we use static so that the value of this variable for the different functions call should not be different.
    if(root==NULL) return 1;
    isBST(root->left);
    if(prev!=NULL && root->data<=prev->data) return 0;
    prev = root;
    isBST(root->right);
}

int main(){
  /*
    Ex-    5
          / \
         3   6
        / \   \
       1   4   8
  */
   struct Node* root = createNode(5);
   struct Node* p1 = createNode(3);
   struct Node* p2 = createNode(6);
   struct Node* p3 = createNode(1);
   struct Node* p4 = createNode(4);
   struct Node* p5 = createNode(2);

   //connecting nodes
   root->left = p1;
   root->right = p2;
   p1->left = p3;
   p1->right = p4;
   p2->right = p5;

   printf("%d\n",isBST(root));
   return 0;
}