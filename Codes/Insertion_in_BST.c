#include <stdio.h>
#include <stdlib.h>

struct Node {
  int data;
  struct Node* left;
  struct Node* right;
};

struct Node* createNode(int data){
    struct Node* n = (struct Node*)malloc(sizeof(struct Node));
    n->data = data;
    n->left = NULL;
    n->right = NULL;
    return n;
}

struct Node* insertNode(struct Node* root,int key){
    struct Node* prev = NULL;
    while(root!=NULL){
        if(key==root->data){
          printf("Key is already present!\n");
          return NULL;
        }else if(key<root->data){
          prev=root;
          root = root->left;
        }else{
          prev=root;
          root = root->right;
        }
    }
    struct Node* newNode  = createNode(key);
    if(key<prev->data) prev->left=newNode;
    else prev->right = newNode;
    return newNode;
}

int main(){
    /*
      EX:-   7
            / \
           5   9
          / \   \
         3   6   11
                 / \
                10  15
    */
    struct Node* root = createNode(7);
    struct Node* p1 = createNode(5);
    struct Node* p2 = createNode(3);
    struct Node* p3 = createNode(6);
    struct Node* p4 = createNode(9);
    struct Node* p5 = createNode(11);
    struct Node* p6 = createNode(10);
    struct Node* p7 = createNode(15);

    //connecting nodes
    root->left = p1;
    root->right = p4;
    p1->left = p2;
    p1->right = p3;
    p4->right = p5;
    p5->left = p6;
    p5->right = p7;
    
    struct Node* n = insertNode(root,4);
  return 0;
}