*/ ATV02 */
#include <stdio.h>
#include <stdlib.h>
#define QUANT 3
int n1,n2,n3;
int subtrai();

int main(){
	
	int n1,n2,n3,subtracao;
	
	printf("Digite 3 numeros para subtrair\n");
	
	printf("Digite o numero 1 :");
	scanf("%d",&n1);
	printf("Digite o numero 2 : ");
	scanf("%d",&n2);
	printf("Digite o numero 3 : ");
	scanf("%d",&n3);

	subtracao = subtrai();

	printf("O resultado da subtracao foi : %d",subtracao);
	system("PAUSE");
	return 0;
	
}

int subtrai(){
	
	float sub;

	sub = (n1 - n2) - n3;

	return sub;	
}

