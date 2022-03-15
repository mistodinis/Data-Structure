#include <stdio.h>


int sum(int n, int acc){
	// base case , n has no more digits
	if(n == 0)
		// return the result
		return acc;
	// last digit
	int lastDigit = n % 10;
	// adjust n , erase last digit 
	n = n / 10;
	// increment acc with lastDigit value
	acc += lastDigit;
	// call function
	sum(n , acc);


}


int main(){
	// read the number
	int n; printf("n = "); scanf("%d" , &n);
	// print the sum of digits from n
	printf("%d \n", sum(n,0));

	return 0;
}