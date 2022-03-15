#include <stdio.h>
#include <stdlib.h>


int partition(int arr[],int start, int end);

void quickSort(int arr[], int start , int end){
	//If we still have elements in our current array 
	if(start < end){
		// We find out the pivot using partition function , the pisition to be more acurate
		int pivot = partition(arr,start,end);
		// 2 recursive calls in the left and right of pivot
		quickSort(arr,start,pivot-1);
		quickSort(arr,pivot+1 , end);
	}
}

int partition(int arr[],int start , int end){

	int pivot = start;
	int index = start , aux;
	// If the pivot has the first position we have to check from the next one till the end
	for(int i = start + 1;i <= end;i++){
		// if following element after arr[pivot] are lower then arr[pivot] then
		// increase index to know how many swaps we did
		if (arr[i] < arr[pivot]){
			
			index++;
			
			aux = arr[i];
			arr[i] = arr[index];
			arr[index] = aux;
		}
	}
	// place arr[pivot] where it should be , 
	// all lower element on his left and all bigger on his right
	aux = arr[start];
	arr[start] = arr[index];
	arr[index] = aux;
	//return position of the pivot
	return index;
}

// print function
void print(int arr[], int size){

	for(int i = 0;i < size;i++)
		printf("%d " , arr[i]);
}

int main(){
	//read n (number of elements)
	int n; printf("n = "); scanf("%d", &n);
	// allocate memory for the array
	int *v = malloc(n*sizeof(int));
	// read elements
	for(int i = 0;i < n;i++)
		scanf("%d" , &v[i]);

	quickSort(v,0,n-1);

	print(v,n);

	return 0;
}