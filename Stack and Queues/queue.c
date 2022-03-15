#include <stdio.h>
#include <stdlib.h>

typedef struct node{
    int value;
    struct node* next;
}Node;

typedef struct queue{
    Node *head;
    Node *tail;
    int size;
}Queue;
// Node initialization
Node* initNode(int value){
    Node *new_node = (struct node*) malloc(sizeof(struct node));
    new_node->next = NULL;
    new_node->value = value;

    return new_node;
}
// Queue initialization
Queue *init_queue(int value){

    Queue *new_queue = (struct queue*) malloc(sizeof(struct queue));
    Node *new_node = initNode(value);
    new_queue->head = new_node;
    new_queue->tail = new_node;
    new_queue->size = 1;

    return new_queue;
}
// Return head value
int peek(Queue *q){

    return q->head->value;
}
// add "value" in queue "q"
Queue* enQueue(Queue *q , int value){

    if(q == NULL)
        return init_queue(value);

    Node *new_node = initNode(value);

    q->tail->next = new_node;
    q->tail = q->tail->next;
    q->size++;

    return q;
}

// delete first element from queue "q"
Queue* deQueue(Queue *q){

    if(q == NULL)
        return NULL;

    if(q->size == 1){
        free(q);
        return NULL;
    }
    Node *tmp = q->head;
    q->head = q->head->next;
    free(tmp);
    q->size--;

    return q;
}
// return size of "q"
int size(Queue *q){
    return q->size;
}

void printQueue(Queue *q){

    if(q == NULL)
        return;
    Node *tmp = q->head;
    while(tmp != NULL){
        printf("%d " , tmp->value);
        if(tmp->next != NULL)
            tmp = tmp->next;
        else
            break;
    }
    printf("\n");
}

int main()
{
    Queue *test = init_queue(10);
    //printf("%d " , test->head->value);

    test = enQueue(test,33);
    test = enQueue(test, 44);
   // printf("%d " , test->head->value);
    //test->head = test->head->next;
   // printf("%d " , test->head->value);
    printQueue(test);

    test = deQueue(test);
    printf(" size = %d \n"  , test->size);
    printQueue(test);
    return 0;
}
