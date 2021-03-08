#include <stdio.h>
#include <stdlib.h>

float somanum(float,float);

float main(){
	
	float num1,num2,soma;
	
	printf("Digite 2 numeros : ");
	scanf("%f %f",&num1,&num2);

	soma = somanum(num1,num2);

	printf("O resultado da soma eh : %.2f",soma);
	system("PAUSE\n");
	return 0;
	
}

float somanum(float n1,float n2){
	
	float soma;

	soma = n1 + n2;
	return soma;
}

