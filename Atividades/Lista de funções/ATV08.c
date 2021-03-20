//Questão 8 listadefunções
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void cadastrarCliente();

 struct cadastro{
    
    char nome [50];
    char dataNascimento[11];
    char cpf[12];
    char sexo;
    
};

int main(){
    
    int i;
    struct cadastro cd;
    
    cadastrarCliente(&cd);
    
    printf("\nNome = %s",cd.nome);
	printf("Data de nascimento : %s",cd.dataNascimento);
    printf("\nCpf : %s",cd.cpf);
	printf("\nSexo = %c",cd.sexo); 	
	
	system("pause");
	return 0;
}

void cadastrarCliente(struct cadastro *c){
    int aux=1;
    int i;
    int tamanho;
    
    printf("Digite seu nome : ");
    fgets((*c).nome,50,stdin);
    
    while (aux){
        
        printf("Digite sua data de nascimento ( com barras ou pontos) e ano completo : ");
        scanf(" %s",(*c).dataNascimento);
        tamanho = strlen((*c).dataNascimento);
        
        if(tamanho != 10)
            printf("\nVoce digitou uma data invalida , por favor tente novamente\n\n");
        else
            aux = 0;
    }
    
    aux=1;
    printf("\n");
    while (aux){
        
        printf("Digite os 11 digitos do seu CPF : ");
        scanf(" %s",(*c).cpf);
        tamanho = strlen((*c).cpf);
        
        if(tamanho != 11)
            printf("\nVoce digitou um CPF INVALIDO , por favor tente novamente\n");
        else
            aux = 0;
    }
    
    
        printf("\nDigite M pra masculino e F para feminino : ");
        scanf(" %c",&(*c).sexo);
    
}