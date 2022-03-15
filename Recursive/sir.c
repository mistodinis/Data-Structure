#include <stdio.h>
#include <stdlib.h>

// A given recurency  X(n) = 10*X(n-1) - 8*X(n-2) + 5
int recurenta(int n){
	//base cases
	if(n == 0)
		return 0;
	if(n == 1)
		return 1;
	// recursive call
	return (10*recurenta(n-1) - 8*recurenta(n-2) + 5);
}


int main(){
	// read n
	int n; printf("n = "); scanf("%d" , &n);
	// call "recurenta" function
	int rez = recurenta(n);	
	// print the result
	printf("%d \n" , rez);

	return 0;
}