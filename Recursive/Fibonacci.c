#include <stdio.h>


int Fibonacci(int n){
	//base cases
	if(n == 0)
		return 0;
	if(n == 1)
		return 1;

	return Fibonacci(n-1) + Fibonacci(n-2);

}

int main(){

	int n; printf("n = " ); scanf("%d" , &n);

	printf("%d\n", Fibonacci(n) );

	return 0;
}