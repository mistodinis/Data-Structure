#include <stdio.h>
#include <stdlib.h>
// Node of List
typedef struct node{
	int data;
	struct node *next;
	struct node *prev;
}Node;
// Struct for Double Linked List
typedef struct TDoubleLinkedList{
	Node *head;
	Node *tail;
	int len;
}TDoubleLinkedList;

//Initialize a node
Node * initNode(int value){
	// Allocate memory for the node
	Node *new_node = (struct node*) malloc(sizeof(struct node));
	new_node->next = NULL;
	new_node->prev = NULL;
	new_node->data = value;

	return new_node;
}
// Initialize a list
TDoubleLinkedList* initList(int value){
	// Allocate memory for the list
	TDoubleLinkedList *new_list = (struct TDoubleLinkedList*) malloc (sizeof(struct TDoubleLinkedList));
	
	Node * new_node = initNode(value);

	new_list->head = new_node;
	new_list->tail = new_node;
	new_list->len = 1;

	return new_list;
}
// Add at the end of list
TDoubleLinkedList* addLast(TDoubleLinkedList *list , int value){
	// If list is empty then initialize a list and return it
	if(list == NULL || list->tail == NULL)
		return initList(value);
	// Else move the tail node
	Node *new_node = initNode(value);
	list->tail->next = new_node;
	new_node->prev = list->tail;
	list->tail = list->tail->next;
	list->len++;
	return list;
}
//Add at the beginning of list
TDoubleLinkedList *addFirst(TDoubleLinkedList *list , int value){
	// If list is empty then initialize a list and return it
	if(list == NULL || list->head == NULL){
		return initList(value);
	}
	// Else change the head node
	Node* new_node = initNode(value);
	new_node->next = list->head;
	list->head->prev = new_node;
	list->head = list->head->prev;
	list->len++;

	return list;	
}
// Insert on a specific position , the value "value"
TDoubleLinkedList* addAtPosition(TDoubleLinkedList *list , int position , int value){
	// Base case , list is empty , initialize one and return it
	if(list == NULL || list->head == NULL){
		list = initList(value);
		//printf("The list was empty , the value was inserted at first position \n");
		return list;
	}
	// Create a temporary pointer to list( not the best option -> i  realize after i wrote the program)
	TDoubleLinkedList *temp = list;
	// The node to be added
	Node *new_node = initNode(value);
	// Save address for head and tail
	Node *first = list->head;
	Node *last = list->tail;
	// If the element has to be inserted at the beginning , addFirst is called
	if(position == 1){
		return addFirst(list,value);
	}
	// If the item has to be inserted at the end , addLast is called
	if(position > list->len){
		return addLast(list,value);
	}
	// If the item has to be inserted in the first half of the list
	if(position <= (list->len)/2){
		// reach node before position
		int counter = 1;
		while(temp->head != NULL && counter != position-1){
			
			if(temp->head->next != NULL){
				temp->head = temp->head->next;
			}else
				break;
			counter++;
		}
		// insert the node into the list
		new_node->next = temp->head->next;
		temp->head->next = new_node;
		new_node->prev = temp->head;
		
		if(new_node->next != NULL){
			new_node->next->prev = new_node;
		}
		// Assign head back to where it was at the beginning
		temp->head = first;
		list->len++;

		return list;
		// If position is in the second half
	}else{
		// Number of moves until we can insert the item at position "position"
		int moves = list->len - position + 1;
		// Reach the node before position
		while(temp->tail != NULL && moves != 0){
			temp->tail = temp->tail->prev;
			moves--;
		}
		// Add the item into the list (using new_node)
		new_node->next = temp->tail->next;
		temp->tail->next = new_node;
		new_node->prev = temp->tail;
		temp->tail = last;
		
		if(new_node->next != NULL)
			new_node->next->prev = new_node;
		
		list->len++;

		return list;
	}
}

// Delete an item , i think it can be improved 
TDoubleLinkedList *deleteElem(TDoubleLinkedList *list , int value){
	// If list is empty , return list(NULL)
	if(list == NULL || list->head == NULL)
		return list;
	// If the first item matches 
	if(list->head->data == value){
		// If the list has more than only one element(node)
		if(list->head->next != NULL){
			
			Node *tmp = list->head;
			// move head pointer to the next node
			list->head = list->head->next;
			// free first node
			free(tmp);
			list->len--;
			return list;
			// If the list has only one element(node) , return NULL
		}else{
			free(list->head);
			return NULL;
		}
	}
	
	TDoubleLinkedList *tmp = list;
	// Keep the head in "first" 
	Node *prev = list->head;
	Node *first = list->head;
	
	tmp->head = tmp->head->next;
	// Move through the list while the node exists and the data is different to "value"
	while(tmp->head != NULL && tmp->head->data != value){
		
		if(tmp->head->next == NULL)
			break;
		
		tmp->head = tmp->head->next;
		prev = prev->next;
	}
	// If the item was found
	if(tmp->head->data == value){
		// if is the last node
		if(tmp->head->next == NULL){
			
			prev->next = NULL;
			// release last elem
			free(tmp->head);
			list->len--;
			// Assign head with first (which is initial head)
			tmp->head = first;
			return list;
			// If it is not last node
		}else{
			// Delete the node tmp->head
			prev->next = tmp->head->next;
			prev->next->prev = prev;
			// Release tmp->head
			free(tmp->head);
			
			list->len--;
			tmp->head = first;
			
			return list;
		}
	}
	// If the item(value) does not exist in "list"
	// Assign list->head with initial head and return the list
	list->head = first;
	return list;
}
// Delete entire list , recursive , using "deleteItem" function
TDoubleLinkedList *deleteList(TDoubleLinkedList *list){
	// base case , if the list is empty the return NULL
	if(list == NULL)
		return list;
	// Delete first node
	list = deleteElem(list,list->head->data);
	// Call "deleteList" on the new list ( with 1 node in minus)
	return deleteList(list);
}

// Print list
void printList(TDoubleLinkedList *list){

	if( list == NULL || list->head == NULL){
		printf("The list is empty \n");
		return;
	}

	if(list->head->next == NULL){
		printf("%d \n" , list->head->data);
		return;
	}
	
	TDoubleLinkedList *temp = list;
	Node *tmp = list->head;
	
	while(temp->head->next != NULL){

		printf("%d ", temp->head->data );
		temp->head = temp->head->next;
	}

	printf("%d " , temp->head->data);
	temp->head = tmp;

	printf("\n");
}
// Print list from tail to head
void printReversed(TDoubleLinkedList *list){

	if(list == NULL || list->head == NULL || list->tail == NULL){
		printf("The list is empty\n");
		return;
	}

	if(list->tail->prev == NULL){
		printf("%d \n" , list->tail->data );
		return;
	}

	TDoubleLinkedList *temp = list;
	Node *last = list->tail;

	while(temp->tail != NULL){

		printf("%d ", temp->tail->data);

		if(temp->tail->prev == NULL)
			break;

		temp->tail = temp->tail->prev;
	}

	temp->tail = last;
	printf("\n");
}

// Add "value" into an ordered list
TDoubleLinkedList *add_in_order(TDoubleLinkedList *list , int value){

	//base case 
	if(list == NULL){
		return initList(value);
	}

	Node *new_node = initNode(value);
	Node *first = list->head;
	TDoubleLinkedList *temp = list;
	// If "value" is smaller than first node's value of the list , insert "value" at the beginning
	if(list->head != NULL){
		if(list->head->data > value)
			return addFirst(list,value);
	}
	// while next node exists
	while(temp->head->next != NULL ){
		// If "value" is bigger than current node's value and smaller or equal than next one
		if(value > temp->head->data && value <= temp->head->next->data){
			// Insert the node (with "value" ) between the other two
			new_node->next = temp->head->next;
			new_node->prev = temp->head;
			temp->head->next = new_node;
			new_node->next->prev = new_node;
			// Assing head with the initial head
			temp->head = first;
			list->len++;
			
			return list;
		}
		// if there is no more nodes after the next one , break
		if(temp->head->next->next == NULL)
			break;
		temp->head = temp->head->next;
	}
	// If the function gets here , then "value" is bigger than all elements from "list"
	// and we add "value" at the end
	temp->head = first;
	return addLast(list,value);
}


int main(){

	TDoubleLinkedList *list = initList(10);
	printList(list);

	list = addFirst(list , 3);
	list = addFirst(list , 4);
	list = addFirst(list , 7);
	list = addFirst(list , 9);

	list = addLast(list,7);
	list = addLast(list,69);
	list = addLast(list,35);
	
	printList(list);
	printf("len = %d \n" , list->len);

	int position; printf("position = " ); scanf("%d" , &position); printf("\n");

	list = addAtPosition(list , position , -222);
	printList(list);

	int del; printf("DelElem = "); scanf("%d" , &del); printf("\n");
	list = deleteElem(list, del);
	printList(list); printf("\n");
	
	//printReversed(list);

	//list = deleteList(list);
	//printList(list);

	TDoubleLinkedList *ord_list = initList(1);
	ord_list = addLast(ord_list , 2);
	ord_list = addLast(ord_list , 3);
	ord_list = addLast(ord_list , 5);
	ord_list = addLast(ord_list , 7);
	ord_list = addLast(ord_list , 9);
	ord_list = addLast(ord_list , 12);

	printList(ord_list);

	int ordItem; printf("Elem to ord list = "); scanf("%d" , &ordItem);
	ord_list = add_in_order(ord_list, ordItem);

	printList(ord_list);

	return 0;

}
