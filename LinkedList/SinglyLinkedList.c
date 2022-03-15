#include <stdio.h>
#include <stdlib.h>
    // List structure
typedef struct list{
    int value;
    struct list *next;
}List;
    // List Initialization
List* initList(int value) {
	// Allocate memory for a new list
	List *new_list = (struct list*) malloc( sizeof(struct list));
	//Assign value and pointer to NULL
	new_list->next = NULL;
	new_list->value = value;
    //return the new list
	return new_list;
}
    // Print List
void printList(List* l) {
    // base case
    if (l == NULL)
        return;
    // if the list has only one element
    if( l->next == NULL){
        printf("%d " , l->value);
        return;
    }
    // Parsing the list and print the nodes value
    while(l != NULL){
        printf("%d " , l->value);
        l = l->next;
    }
}
    // Add element at the beginning of list
List* addFirst(List* l, int value) {
	// Initialize a new node
	List *new_node = initList(value);
    // If our given list is empty , return new node
    if(l == NULL)
        return new_node;
    // Bind new node to "L"
	new_node->next = l;
	// return the new head
	return new_node;
}
    // Add at the end
List* addLast(List* l, int value) {

	List *new_node = initList(value);
    // base cases
	if(l == NULL)
        return new_node;

    if(l->next == NULL){
        l->next = new_node;
        return l;
    }
    // Take a pointer to our list
    List *temp = l;
    // Parse till we reach last element
    while(temp->next != NULL){
        temp = temp->next;
    }
    // Bind last element to new node
    temp->next = new_node;
    // Return head of the list
	return l;
}
    // Add a node after first occurence of "x" in List
List* addItem(List* l, int x, int value) {

	List *new_node = initList(value);
	List *temp = l;
    // Parse till we find the right node
	while(temp != NULL && temp->value != x){
        temp = temp->next;
	}
    // Bind new node inside the list
	new_node->next = temp->next;
	temp->next = new_node;
	// Return the head
	return l;
}
    // Delete the node with value "value"
List* deleteItem(List* l, int value) {
    // If "l" is empty return NULL or "l"
    if(l == NULL)
        return l;
    // If value is in head "l"
    if(l->value == value){
            // If we have an following node
        if(l->next != NULL){
            // Move forward and return the new head
            l = l->next;
            return l;
        }else{
            // Otherwise return NULL
            return NULL;
        }
    }
    // Take two pointers
    List *temp = l;
    List *prev = l;

    if(l->next != NULL)
        temp = temp->next;
    // Parse till the right item is found or the list ends
    while(temp != NULL && temp->value != value){
        if(temp->next == NULL)
            break;
        temp = temp->next;
        prev = prev->next;
    }
    // If the right item was found then delete it
    if(temp->value == value){
            // If temp is not last element
        if(temp->next != NULL){
            prev->next = temp->next;
            free(temp);
            return l;
            // If temp is last element
        }else{
            prev->next = NULL;
            free(temp);
            return l;
        }
    }

	return l;
}
    // Delete all element from a list
    // It can be done using previous function
List* deleteList(List* l) {

    if(l == NULL)
        return l;
    if(l ->next == NULL){
        free(l);
        return NULL;
    }

     List *temp;
     // Parsing "l"
    while(l != NULL){

        if(l->next == NULL)
            break;
        // Erase nodes using temp
        temp = l;
        l = l->next;
        free(temp);
    }
    //Erase last element
    free(l);

	return NULL;
}

// Merge 2 ordered lists
List* reunion(List* list1, List* list2) {
    // If one of the given lists is empty
    // We return the other one
	if(list1 == NULL )
        return list2;
    if(list2 == NULL)
        return list1;

    List *temp = NULL ;
    // Parsing both lists
    while(list1 != NULL && list2 != NULL){
        // If lower value is in list1
        if(list1->value < list2->value){
            // Add value from list1 to temp
            temp = addLast(temp,list1->value);
            // Move to the next node
            list1 = list1->next;
        }else{

            temp = addLast(temp,list2->value);

            list2 = list2->next;
        }
    }
    // If there are any nodes left in list1 we
    // Add them at the end of temp
    while(list1 != NULL){
        temp = addLast(temp,list1->value);

        if(list1->next != NULL)
            list1 = list1->next;
        else
            break;
    }
    // Same as above
    while(list2 != NULL){
        temp = addLast(temp,list2->value);

        if(list2->next != NULL)
            list2 = list2->next;
        else
            break;
    }

	return temp;
}
    // Find middle of a list without a counter
    // Or knowing the size
int middle(List* head) {
    // If the head is empty return -1
	if(head == NULL)
        return -1;
    // If the list has only one element return 1
    if(head->next == NULL)
        return 1;
    // Take 2 pointers
    List *one = head;
    List *two = head;
    // Parsing with those 2 pointers (one , two)
    while(one != NULL && two != NULL){
        // Check if it is still room to move on
        if(one->next != NULL && two->next != NULL){
            one = one->next;
            two = two->next;
        }else
            break;
        // Second move of "two" pointer
        if(two->next != NULL)
            two = two->next;
        else
            break;
            // The main explanation is that when pointer
            //"two" reaches the end , pointer "one" reaches
            // the middle
    }
        return one->value;
}


int main()
{
    List *l = initList(10);
    printList(l);
      printf("\n");

    l = addFirst(l,15);
    printList(l);
      printf("\n");


    l = addLast(l , -3);
    printList(l);
    printf("\n");

    l = addItem(l,15,-69);
    printList(l);
    printf("\n");
    printf("Item to delete = "); int cc; scanf("%d" , &cc);
    l = deleteItem(l , cc);
    printList(l);
    printf("\n");

   // l = deleteList(l);
    l = addFirst(l,10);
    printList(l);
    printf("\n");

    List *l2 = initList(-20);
    l2 = addFirst(l2,69);

    List *l4 = initList(1);
    l4 = addLast(l4,2);
    l4 = addLast(l4,3);
    l4 = addLast(l4,23);
    l4 = addLast(l4,233);

    List *l5 = initList(5);
    l5 = addLast(l5 , 52);
    l5 = addLast(l5 , 53);
    l5 = addLast(l5 , 2222);
    List *l3 = reunion(l4 , l5);

    printList(l3);
    printf("\n");

    printf("%d " , middle(l));

    return 0;
}


