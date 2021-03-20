//Questão 4 listadefunções
#include <stdio.h>
#include <stdlib.h>

int num[3];
void ler3numeros();

int main(){
	
	int i;
	
	ler3numeros();
	
	for(i=0;i<3;i++){
		printf("\nNum %d : %d",i,num[i]);		
	}
	system("pause");
	return 0;
}

void ler3numeros(){
	int i;
	for(i=0;i<3;i++){
		printf("Digite o num %d : ",i);
		scanf("%d",&num[i]);		
	}
		
}



