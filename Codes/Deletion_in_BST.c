#include <stdio.h>
#include <stdlib.h>

/*
  imp points:-
  1. InorderPredecessor :- it is the rightmost node of the left subtree of the
     given node iff left subtree exist for the given node else the InorderPredessor
     of the node is parent of the node if parent exists.

  2. InorderSuccessor :- it is the leftmost node of the right subtree of the given node
     iff right subtree is exist else there is no InorderSuccessor for the given node.

       ************************** key idea for deletion **************************  
    In deletion we delete the given node and move to its InorderPredessor until we got any
    leaf node. 

    we can also do the same with the help of InorderSuccessor.
*/
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


struct Node* inOrderpredecessor(struct Node* root){
    root = root->left;
    while(root->right!=NULL){
        root = root->right;
    }
    return root;
}

struct Node* deleteNode(struct Node* root,int key){
    struct Node* ipre;
    static struct Node* prev=NULL;
    if(root==NULL) return NULL;
    if(root->left==NULL && root->right==NULL){
        free(root);
        return NULL;
    }
    if(key<root->data){
        prev = root;
        root->left = deleteNode(root->left,key);
    }
    else if(key>root->data){
        prev = root;
        root->right = deleteNode(root->right,key);
    }
    else{
        if(root->left==NULL){
           root->data = prev->data;
           prev = deleteNode(prev,prev->data);
        }
        else{
            ipre = inOrderpredecessor(root);
            root->data = ipre->data;
            root->left = deleteNode(root->left,ipre->data);
        }
    }
    return root;
}

void Inorder(struct Node* root){
    if(root==NULL) return;
    Inorder(root->left);
    printf("%d ",root->data);
    Inorder(root->right);
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
    Inorder(root); 
    printf("\n");
    deleteNode(root,9);
    Inorder(root);
    return 0;
}