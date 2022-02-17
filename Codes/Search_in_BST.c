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

struct Node* Search(struct Node* root,int key){
   if(root==NULL) return NULL;
   if(root->data==key) return root;
   if(key < root->data) return Search(root->left,key);
   else return Search(root->right,key);
}

//T.C of this search algorithm is O(height of tree)
// height of the tree in worst case is n and in best case is log(n) : where n number of    nodes in the tree.

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
   struct Node* p5 = createNode(8);

   //connecting nodes
   root->left = p1;
   root->right = p2;
   p1->left = p3;
   p1->right = p4;
   p2->right = p5;

   int key=8;
   if(Search(root,key)==NULL) printf("Given key is not preset\n");
   else printf("%d\n",Search(root,key)->data);  

   return 0;
}