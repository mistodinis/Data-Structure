#include <stdio.h>
#include <stdlib.h>


typedef struct node{

    int value;
    struct node* next;
}Node;

typedef struct stack{
    Node *top;
    int size;

}Stack;

Node* initNode(int value){

    Node* newNode = (struct node*)malloc(sizeof(struct node));
    newNode->next = NULL;
    newNode->value = value;

    return newNode;
}

Stack *initStack(int value){

    Stack *newStack = (struct stack*)malloc (sizeof(struct stack));
    newStack->top = initNode(value);
    newStack->size = 1;

    return newStack;
}

int top(Stack *s){
    return s->top->value;
}

Stack *push(Stack *s, int value){

    if(s == NULL)
        return initStack(value);

    Node *newNode = initNode(value);

    newNode->next = s->top;
    s->top = newNode;
    s->size++;

    return s;
}

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

int parantezare(Stack *s , char *str){

   for(int i = 0;i < strlen(str); i++){

        if(str[i] == '('){
            //printf("DA // ");
            if(s == NULL){
                s = initStack(1);
            }else{
                s = push(s,1);
            }
        }

        if(str[i] == ')'){
              //  printf("NU // ");
            if(s == NULL){
                return 0;
                exit(0);
            }else{
                s = pop(s);
            }
        }
   }
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
