#include <stdio.h>
#include <stdlib.h>

//Struct of a node
typedef struct node{

    int value;
    struct node* next;
}Node;
// Struct of a stack
typedef struct stack{
    Node *top;
    int size;

}Stack;
// Init a node
Node* initNode(int value){

    Node* newNode = (struct node*)malloc(sizeof(struct node));
    newNode->next = NULL;
    newNode->value = value;

    return newNode;
}
// Init a stack
Stack *initStack(int value){

    Stack *newStack = (struct stack*)malloc (sizeof(struct stack));
    newStack->top = initNode(value);
    newStack->size = 1;

    return newStack;
}
// Return value from the top
int top(Stack *s){
    return s->top->value;
}
// Push an element to the top
Stack *push(Stack *s, int value){

    if(s == NULL)
        return initStack(value);

    Node *newNode = initNode(value);

    newNode->next = s->top;
    s->top = newNode;
    s->size++;

    return s;
}
// Delete an element from the top
Stack *pop(Stack *s){

    if(s == NULL)
        return NULL;

    if(s->size == 1){
        free(s);
        return NULL;
    }

    s->top = s->top->next;
    s->size--;

    return s;

}
// Return size of stack
int size(Stack *s){

    return s->size;
}


void printStack(Stack *s){

    if(s == NULL)
        return;

    if(s->size == 1){
        printf("%d " , s->top->value);
        return;
    }

    Node *tmp = s->top;

    while(tmp != NULL){
        printf("%d " , tmp->value);

        if(tmp->next == NULL)
            break;
        tmp = tmp->next;
    }
    printf("\n");
}

int emptyStack(Stack *s){
    if(s == NULL)
        return 1;
    return 0;
}
// Function that has the main objective to see if an string has a good parentheses equitation
//For example : (()) - is a good parentheses equitation , because there are 2 opened and 2 closed
// (()() - is not a good equitation  , there are 3 opened and only 2 closed
int parantezare(Stack *s , char *str){
    // We parse the string
   for(int i = 0;i < strlen(str); i++){
        // if we find an opened parenthesis we push "1" into the stack
        if(str[i] == '('){
            //if the stack is empty we initialize stack
            if(s == NULL){
                s = initStack(1);
            }else{
                s = push(s,1);
            }
        }
        // if we find an closed parenthesis , we have to pop an element from the stack
        if(str[i] == ')'){
              // if there are no element into the stack that means , there are too many ")"
            if(s == NULL){
                // return 0 , means is not a good equitation
                return 0;
                //exit(0);
            }else{
                s = pop(s);
            }
        }
   }
    //After we end the string  , we check if the number of "(" are equal to number of ")"
    // We check that by looking at the stack , if the stack is empty that means all the items pushed were finally poped 
    // and result a good equitation
   if(emptyStack(s) == 1)
    return 1;
   else
    return 0;

}


int main()
{
   Stack *s = initStack(10);
   s = push(s,15);
   s = push(s, 35);
    printf("size = %d \n" , s->size);
   printStack(s);

   s = pop(s);
   printf("size = %d \n" , s->size);
   printStack(s);


   char *str = (char *) malloc(30*sizeof(char));
   str = fgets(str, 30 , stdin);
    Stack *para = NULL;
   // printf("%d " , emptyStack(parantezare));
    if(parantezare(para , str) == 0)
    printf("Fail : Parantezare incorecta" );
    else
    printf("Succes : Parantezare corecta");

    free(str);

    return 0;
}
