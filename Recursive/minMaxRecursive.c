#include <stdio.h>
#include <stdlib.h>

// Structure for min and max
typedef struct pair{

	int min;
	int max;

}Pair;


Pair minMax(int arr[], int begin , int end){

	Pair result, one , two;
	// if our current looking array has only one element
	if(begin == end){
		// assign that element to min and max
		result.min = arr[begin];
		result.max = arr[begin];
	}
	else{
		// middle of array
		int mid = begin + (end-begin)/2;
		// apply minMax on both parts of the array
		one = minMax(arr,begin,mid);
		two = minMax(arr,mid+1, end);
		// find min
		if(one.min <= two.min)
			result.min = one.min;
		else
			result.min = two.min;
		// find max
		if(one.max >= two.max)
			result.max = one.max;
		else
			result.max = two.max;
	}

	return result;
}


int main(){
	// read n
	int n; printf("n = "); scanf("%d" , &n);

	Pair result;
	// allocate memory for the array
	int *v = malloc(n*sizeof(int));
	// read elements
	for(int i = 0;i < n;i++)
		scanf("%d", &v[i]);

	result = minMax(v, 0 , n-1);
	// print the result
	printf("min = %d \nmax = %d\n", result.min , result.max );

	return 0;
}