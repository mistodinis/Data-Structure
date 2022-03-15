#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// "a" times "b" recursive 

int produs(int a , int b){
	// base case
	if(b == 1)
		return a;
	// recursive case
	return a + produs(a,b-1);
}


int main(){
	// read m, n
	int m , n; 
	printf("n = "); scanf("%d" , &n);

	printf("m = "); scanf("%d" , &m);
	// call "produs" function
	int prod = produs(m,n);
	// print result
	printf("%d \n" , prod);

	return 0;
}