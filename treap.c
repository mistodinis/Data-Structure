#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
// Structure of a treap
typedef struct treap{

    int key, priority;
    struct treap *left , *right;

}Treap;
// Initialize a treap
Treap *initTreap(int key){

    Treap *new_treap = malloc(sizeof(struct treap));
   
    new_treap->key = key;
    // randomly pick a priority number
    new_treap->priority = rand()%100;
   
    new_treap->left = NULL;
    
    new_treap->right = NULL;

    return new_treap;
}
/*
                z       right Rotate          w
               / \     ------------->        / \
              w   C                         A   z
             / \       <------------           / \
            A   B        left rotate          B   C


    A , B , C  - branches in our tree
*/
Treap* rightRotate(Treap *y){

    Treap *x = y->left  , *T2 = x->right;

    x->right = y;
   
    y->left = T2;

    return x;
}

Treap* leftRotate(Treap *x){

    Treap *y = x->right , *T2 = y->left;

    y->left = x;
   
    x->right = T2;

    return y;
}
// Insert a node into the treap
Treap *insert(Treap *root, int key){
    // If the tree is empty , then initialize it
    if(root == NULL)
        return initTreap(key);
    // If key is less or equal to root->key
    if(key <= root->key){
        // Go into left branch
        root->left = insert(root->left, key);
        // If the priority of left child is bigger than parents's priority
        if(root->left->priority > root->priority)
            // Rotate to right
            root = rightRotate(root);
    }
    // IF key is bigger than root->key then go to right branch
    else{
        root->right = insert(root->right, key);
        // Same as above  , but now make a left rotate
        if(root->right->priority > root->priority)
            root = leftRotate(root);
    }
    // return the result
    return root;
}
// Delete a node from a treap
Treap *deleteNode(Treap *root , int key){
    // If root is empty then return NULL
    if(root == NULL)
        return NULL;
    // If key is less than root->key , move into left branch
    if(key < root->key)
        root->left = deleteNode(root->left , key);
    
    else{
        // If is bigger move into right branch
        if( key > root->key)
            root->right = deleteNode(root->right , key);
        // If key is equal to root->key
        else{
            // If root has one child or no child
            if(root->left == NULL){
                // Switch right child with root and free root
                Treap *tmp = root->right;
                
                free(root);
               
                root = tmp;
            }else
            {
                if(root->right == NULL){

                    Treap *tmp = root->left;
                   
                    free(root);
                   
                    root = tmp;
                }
                // If root has 2 children
                else {
                    // If left child has smaller priority rotate left
                     if(root->left->priority < root->right->priority){

                    root = leftRotate(root);
                   // then delete from left branch
                    root->left = deleteNode(root->left , key);
                   // Else rotate right and go to the right branch to delete
                    }else{
                    
                     root = rightRotate(root);
                     
                     root->right = deleteNode(root->right , key);
                    }
                }
            }
        }
    }

    return root;
}
// Print inOrder the Treap
void inOrder(Treap *root){

    if(root){

        inOrder(root->left);
        printf("k = %d  , p= %d || "  , root->key , root->priority);
      
        inOrder(root->right);
    }
}
// Verify the functions
int main(){

    Treap *root = NULL;
    root = insert(root , 10);

    inOrder(root); printf("\n");
    root = insert(root, 50); 
    root = insert(root, 30); 
    root = insert(root, 20); 
    root = insert(root, 40); 
    root = insert(root, 70); 
    root = insert(root, 60); 
    root = insert(root, 80); 

    inOrder(root); printf("\n");

    root = deleteNode(root, 30); 
    
    inOrder(root); printf("\n");
    
    root = deleteNode(root, 20); 
    
    inOrder(root); printf("\n");

    return 0;
}
