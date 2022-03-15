#include <stdio.h>
#include <math.h>

// Check if a number is prime

int prim(int n, int d){
	// base case
	if(n % d == 0)
		return 0;
	// d is going until sqrt(n)
	if(d*d < n)
		// recursive call
		 prim(n,d+1);

	return 1;
}


int main(){
	// read n
	int n; printf("n = "); scanf("%d" , &n);
	// call "prim" function
	int rez = prim(n, 2);
	// print the result
	printf("%d \n" , rez);

	return 0;
}