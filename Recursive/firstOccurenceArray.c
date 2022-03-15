#include <stdio.h>
#include <stdlib.h>


int binarySearch(int arr[] , int  left , int right , int key ){
	// We still have elements in our searching range
	if(right >= left){
		// middle of actual searching range  / we use this istead of 
		// (left+right) / 2 to avoid overflow
		int mid = left + (right - left) / 2;
		// mid = 0 means left and right are both 0 or key is the firstOccurence 
		if(mid == 0 || key >  arr[mid-1] && key == arr[mid])
			// return the position , starting from position "1"
			return mid + 1;
		else{
			// If key is bigger than middle of array we call upper array
			if(key > arr[mid])
				return binarySearch(arr,mid + 1 , right , key);
			// If is lower or EQUAL we call lower array 
			else
				return binarySearch(arr, left, mid, key);
		}
	}

	return -1;
}



int main(){
	// read n(size of array) and key(element searched in array)
	int n ; printf("n = "); scanf("%d" , &n);
	int key; printf("key = "); scanf("%d" , &key);
	// allocate memory for the array
	int *v = malloc(n* sizeof(int));
	// read elements
	for(int i = 0;i < n;i++)
		scanf("%d", &v[i]);

	int firstOccurence = binarySearch(v,0,n-1,key);
	// print the result
	printf("%d \n", firstOccurence );

	return 0;
}