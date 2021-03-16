#include <stdio.h>
#include <stdlib.h>

int num;
int fatorial(int n);

int main(){
	
	int num,fat;
	
	printf("Digite 1 um numero para saber seu fatorial :");
	scanf("%d",&num);	

	printf("O fatorial de %d eh : %d",num,fat = fatorial(num));
	system("PAUSE");
	return 0;
	
}

int fatorial(int n){
	
	if(n == 0 || n == 1)
		return 1;
	else
		return n * fatorial(n - 1);	
}


