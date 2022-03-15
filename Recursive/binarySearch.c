#include <stdio.h>
#include <stdlib.h>

// binary search in a sorted array and return the position of "key"

int binarySearch(int arr[] , int l , int r , int key){
	// Find the middle point in array
	int m = (l + r) / 2;
	//  Check if arr size , where we are still looking is bigger than 1
	if(l != r){
		// If arr[m] equals key then we return "m+1" because the positions start from "0"
		if(arr[m] == key)
			return m+1;
			// Verify where we should seach forward ( in a left side of the arr or right side)
		else{ if(arr[m] > key){
			return binarySearch(arr, l , m , key);
			}
			else
				return binarySearch(arr , m+1 , r , key);
		}
	}

	return -1;
}

int main(){


	int *v;
	// Read key , and number of element in array "v"
	int key; printf("key = "); scanf("%d" , &key);
	int n; printf("n = "); scanf("%d" , &n);
	// Alocate memory
	v = malloc(n*sizeof(int));
	// Read elements in array
	for(int i = 0;i < n; i++)
		scanf("%d" , &v[i]);	
	// print the result
	printf("%d\n", binarySearch(v,0,n-1,key) );

	return 0;

}