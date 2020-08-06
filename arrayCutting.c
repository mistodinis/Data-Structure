#include <stdio.h>
#include <stdlib.h>

/* Asupra unui vector cu n elemente se executa succesiv operatii de taiere
astfel: vectorul v se injumatateste, iar daca lungimea lui este un numar impar,
atunci se elimina elementul din mijloc. Acest proces se repeta asupra fiecarei
jumatati pana la obtinerea unui vector cu un singur element. Sa se calculeze
suma tuturor elementelor ce raman in vector dupa aplicarea acestui proces. */

int global = 0;

void editArray(int arr[] , int start , int end);

void print(int *arr , int size);

void cuttingArray(int arr[] , int start, int end){

	int positions = end - start + 1;

	if (positions == 1)
		return;
	if(start <= end){
		if(positions % 2 == 1){

			editArray(arr,start,end);
			//print(arr, end);
			global++;
			end--;
			cuttingArray(arr , start , (start+end)/2 );
			cuttingArray(arr , (start+end)/2 + 1   , end );
		}else{

			cuttingArray(arr , start , (start + end) / 2);
			cuttingArray(arr , (start+end)/2 + 1, end );
		}
	}
}



void editArray(int arr[] , int start , int end){

	int middle = (start + end) / 2;

	for( int i = middle;i < end;i++){
		arr[i] = arr[i + 1];
	}

	//return arr;
} 

void print(int *arr , int size){

	for(int i = 0;i < size;i++){
		printf("%d " , arr[i]);
	}
	printf("\n");
}
int main(){

	int n; printf("n = "); scanf("%d" , &n);
	int *v = malloc(n*sizeof(int));

	for(int i = 0;i < n;i++)
		scanf("%d" , &v[i]);

	cuttingArray(v,0,n-1);
	

	//printf("global = %d " , global);	
	editArray(v,0, n- global);
	print(v,n-global);

	return 0;
}