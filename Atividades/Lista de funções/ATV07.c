//Questão 7 listadefunções
#include <stdio.h>
#include <stdlib.h>
#define TAM 20
void ler3palavras();

 struct lerpl{
    
    char palavra1[TAM];
    char palavra2[TAM];
    char palavra3[TAM];
    
};

int main(){
    
    struct lerpl lp;
    
    ler3palavras(&lp);
    
	printf("\nPalavra 1 = %s",lp.palavra1); 
	printf("\nPalavra 2 = %s",lp.palavra2); 	
	printf("\nPalavra 3 = %s",lp.palavra3); 
	
	system("pause");
	return 0;
}

void ler3palavras(struct lerpl *l){
    
    printf("Digite a palavra 1 : ");
    fgets ((*l).palavra1,TAM,stdin);
    printf("Digite a palavra 2 : ");
    fgets ((*l).palavra2,TAM,stdin);
    printf("Digite a palavra 3 : ");
    fgets ((*l).palavra3,TAM,stdin);
}
	
		







