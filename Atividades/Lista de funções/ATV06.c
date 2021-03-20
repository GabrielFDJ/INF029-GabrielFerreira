//Questão 6 listadefunções
#include <stdio.h>
#include <stdlib.h>

void ler3letras(char *let1, char *let2, char *let3);

int main(){
    char let1,let2,let3;
    ler3letras (&let1,&let2,&let3);
    
	printf("\n Letra 1 = %c \n Letra 2 = %c \n Letra 3 = %c ",let1,let2,let3); 
	
	system("pause");
	return 0;
}

void ler3letras(char *lt1, char *lt2, char *lt3){
    printf("Digite a letra 1 : ");
    scanf(" %c" ,&*lt1);
    printf("Digite a letra 2 : ");
    scanf(" %c" ,&*lt2);
    printf("Digite a letra 3 : ");
    scanf(" %c" ,&*lt3);
    
}
	
		






