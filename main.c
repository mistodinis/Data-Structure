#include <stdio.h>
#include <stdlib.h>
// Tree Structure
typedef struct arbore{
    // Value
    int key;
    // Children  , left and right
    struct arbore *left , *right;
    // Father
    struct arbore *father;
}Tree;
// Tree Initialization
Tree *initTree(int key , Tree *father){
    // Allocate memory for the tree
    Tree *new_tree = malloc(sizeof(struct arbore));
    // Assign values to all fields
    new_tree->key = key;

    new_tree->left = NULL;

    new_tree->right = NULL;

    new_tree->father = father;
    // return the new tree
    return new_tree;
}
// Insert a value into a tree
Tree *insert(Tree *root , int key){
    // If the tree is empty then initialize a tree with "key" value
    if(root == NULL){
        return initTree(key, NULL);
    }
    // A pointer to root
    Tree *tmp = root;
    // I used a loop until i reach the right node , the insert a new node
    while(1){
        // If "key" value is less than tmp->key
        if(tmp->key > key){
            // If tmp does not have a left child then initialize one and exit the loop
            if(!tmp->left){

                tmp->left = initTree(key,tmp);

                break;
            // Else move to the left child
            }else{

                tmp = tmp->left;
            }
        // If "key" value is equal or bigger than tmp->key
        }else{
            // If tmp does not have a right child then initialize one and exit the loop
            if(!tmp->right){

                tmp->right = initTree(key,tmp);

                break;
            // Else move to the right child
            }else{

                tmp = tmp->right;
            }
        }
    }
    // Return the new tree
    return root;
}
// Search "key" into a tree
int search(Tree *root , int key){
    // If the tree is empty return 0(Not found)
    if(root == NULL){

        return 0;
    }
    // A pointer to "root"
    Tree *tmp = root;
    // I user a loop to look after "key"
    while(1){
        // If node's value is equal to "key"
        if(tmp->key == key)
            // return 1 (Found)
                return 1;
        // If key is less than tmp->key try to go into left child
        if(tmp->key > key){
            // If left child is empty return 0(Not found)
            if(!tmp->left){

                return 0;
            // Else move into left child
            }else{

                tmp = tmp->left;
            }
        // If key is equal or bigger than tmp->key try to go into right child
        }else{
            // If right child is empty return 0(Not found)
            if(!tmp->right){

                return 0;
            // Else move into right child
            }else{

            tmp = tmp->right;
            }
        }
    }
}
//Return the node with smallest value
Tree *minValue(Tree *root){
    // A pointer to root
    Tree *tmp = root;
    // If tmp is not NULL and tmp has a left child , move into left child
    while(tmp && tmp->left != NULL)
        tmp = tmp->left;
    // Return tmp  ( at this moment tmp is the most left node in the tree)
    // and has the smallest value
    return tmp;
}
// Delete a node from a tree
Tree *deleteNode(Tree *root , int value){
    // If the tree is empty
    if(root == NULL)
        // return root
        return root;
    // Navigate through the tree until we find the value "value"
    if(value < root->key)

        root->left = deleteNode(root->left , value);

    else if(value > root->key)

        root->right = deleteNode(root->right , value);
    // If value == root->key
    else{
        // If root has one or no child
        if(root->left == NULL){

            Tree *tmp = root->right;

            free(root);

            return tmp;

        }else if(root->right == NULL){

            Tree *tmp = root->left;

            free(root);

            return tmp;
        }
        // If root has two children
        // Find smallest value from root->right
        Tree * tmp = minValue(root->right);
        // Replace root's key  with tmp's key
        root->key = tmp->key;
        // Delete tmp from root->right branch
        root->right = deleteNode(root->right, tmp->key);
    }
    // Return new tree
    return root;
}
// Free the memory
void freeTree(Tree *root){

    if(root != NULL){
        // Call freeTree recursive and free the memory from leafs to root
        freeTree(root->right);

        freeTree(root->right);

        free(root);
    }
}
// Inorder Print
void inorderPrint(Tree *root){

    if(root != NULL)
    {
        inorderPrint(root->left);

        printf("%d " , root->key);

        inorderPrint(root->right);
    }
}
// Post Order Print
void postOrder(Tree *root){

    if(root != NULL){

        postOrder(root->left);

        postOrder(root->right);

        printf("%d " , root->key);
    }
}
// Pre Order Print
void preOrder(Tree *root){

    if(root != NULL){

        printf("%d "  , root->key);

        preOrder(root->left);

        preOrder(root->right);
    }
}
// Return maximum element from two elements
int max(int a  , int b){

    if(a > b)

        return a;

    return b;
}
// Height of the tree
int height(Tree *root){

    if(root == NULL)

        return -1;
    // Go to leafs and come back to root
    int max_L = height(root->left);

    int max_R = height(root->right);
    // Counter every level of the tree , find number of levels
    int max_height = max(max_L , max_R) + 1;
    // return the height
    return max_height;
}

// Search biggest value from the tree smaller than "x"
int searchPrev(Tree *root , int x){

    // base case
    if(root == NULL)
        return -1;
    // if the value exists into the root node return the value
    if(root->key == x)
        return root->key;

    int ans;

    if(root->key < x){
            // Search in root->right
            ans = searchPrev(root->right, x);
            // if ans is -1
            if(ans == -1)
                // return value of root
                return root->key;
            else
                //return ans( because it is the value of "x")
                return ans;
    // If x is lower than root->key
    }else{
        // continue to search into the left branch
        return searchPrev(root->left , x);
    }
}

// Smallest value from tree bigger than "x"
int searchNext(Tree *root , int x){
    // Explanation is like above , everything in the mirror
    if(root == NULL)
        return -1;

    if(root->key == x)
        return root->key;

    int ans;

    if(root->key < x){

        return searchNext(root->right , x);

    }else{

        ans = searchNext(root->left , x);

        if(ans == -1)
            return root->key;
        else
            return ans;
    }
}


int main()
{
    Tree *copac = initTree(5,NULL);

    copac = insert(copac , 2);

    copac = insert(copac , 1);

    copac = insert(copac , 3);

    copac = insert(copac , 12);

    copac = insert(copac , 11);

    copac = insert(copac , 21);

    copac = insert(copac , 19);

    copac = insert(copac , 25);

    inorderPrint(copac); printf("\n");

    printf("Delete node = "); int aux; scanf("%d" , &aux);
    copac = deleteNode(copac , aux);

    inorderPrint(copac); printf("\n");

  //  postOrder(copac); printf("\n");

  //  preOrder(copac); printf("\n");

  //  printf("%d // %d \n"  , copac->right->key , copac->left->key);

  //  printf("%d // %d // %d \n" , search(copac , 39) , search(copac , 1) , search(copac , 22));

  //  printf("%d " , copac->key);

   // printf("\nHeight =  %d \n" , height(copac));

    //printf(" %d "  , copac->key);
    printf("Search value = "); scanf("%d" , &aux);

    printf("Search 1 = %d \n" , searchPrev(copac , aux));

    printf("Search 2 = %d \n" , searchNext(copac , aux));

    return 0;
}
