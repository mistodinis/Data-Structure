#include <stdio.h>
#include <stdlib.h>


// cmmdc recursive
int r;

int cmmdc(int a , int b){
	// assign a value to r
	r = a % b;
	// check the base case
	if(r == 0)
		return b;
	// recursive call
	return cmmdc(b,r);
}


int main(){
	// read m , n
	int m, n; 
	printf("m = "); scanf("%d" , &m);
	printf("n = "); scanf("%d" , &n);
	// print the cmmdc between m and n
	printf("%d " , cmmdc(m, n));

	return 0;
}