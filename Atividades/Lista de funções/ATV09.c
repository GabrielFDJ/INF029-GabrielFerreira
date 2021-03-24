//Questão 9 listadefunções
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int validarNome(),validarNascimento(),validarCpf(),validarSexo();
int contN = 0, contDT = 0, contCP = 0 , contS = 0;
 
struct cadastro{
    
    char nome [50];
    char dataNascimento[15];
    char cpf[15];
    char sexo;
    
}cd;

struct cadastro cadastrarCliente(char nome[], char dataNascimento[], char cpf[], char sexo );

int main(){
    
    int i;
   
    cadastrarCliente(cd.nome, cd.dataNascimento, cd.cpf, cd.sexo);
    
    printf("\n***************************************\n");
    
    if(contN == 0)
        printf("\nNome = %s",cd.nome);
    else 
        printf("\nErro de validacao no NOME\n");
	
	if(contDT == 0)
	    printf("Data de nascimento : %s",cd.dataNascimento);
	else
	    printf("Erro de validacao na DATA\n");
	
	if(contCP == 0)
        printf("Cpf : %s",cd.cpf);
    else
        printf("Erro de validacao no CPF");
	
	if(contS == 0)
	   printf("\nSexo = %c",cd.sexo); 
	else 
	    printf("\nErro de validacao no SEXO");
	
	system("pause");
	return 0;
}

struct cadastro cadastrarCliente(char nome[], char dataNascimento[], char cpf[], char sexo){
    
    printf("Digite o nome : ");
    fgets(cd.nome,50,stdin);
    validarNome();
    
    printf("Digite a data de nascimento : ");
    fgets(cd.dataNascimento,15,stdin);
    validarNascimento();
    
    printf("Digite o cpf : ");
    fgets(cd.cpf,15,stdin);
    validarCpf();
    
    printf("Digite o sexo : ");
    scanf(" %c",&cd.sexo);
    validarSexo();
    
    return cd;
    
}
	
int validarNome(){
    int i;
    int tamanho;
    tamanho = strlen(cd.nome);
    if(tamanho > 50)
        contN = 1;
    for(i=0;cd.nome[i] != '\0';i++){
        if(cd.nome[i]-'0' >= 0 && cd.nome[i]-'0' < 10)
            contN = 1;
    }    
    return 0;
}

int validarNascimento(){
    int i;
    int tamanho;
    int dia,mes,ano,bissexto = 0;
    tamanho = strlen(cd.dataNascimento);
    if((tamanho - 1) != 10){ // se o tamanho do nome esta correto
        contDT = 1;
        return 0;}   
    else{
        for(i=0;i<10;i++){
            if(i == 2 || i == 5){ 
                if(cd.dataNascimento[2] != '/' || cd.dataNascimento[5] != '/') // verifica se a posicao das barras tem realmente barras
                    contDT = 1;}
            else {
                if((cd.dataNascimento[i]-'0') < 0) // verifica se contem algo que não seja numeros nas outras posicoes
                    contDT = 1;}
        }
    }
    //calculo do dia
    dia = (cd.dataNascimento[0]-'0') * 10;
    dia += cd.dataNascimento[1]-'0';
    //calculo do mes
    mes = (cd.dataNascimento[3]-'0') * 10;
    mes += cd.dataNascimento[4]-'0';
    //calculo do ano 
    ano = (cd.dataNascimento[6]-'0') * 1000;
    ano += (cd.dataNascimento[7]-'0') * 100;
    ano += (cd.dataNascimento[8]-'0') * 10;
    ano += cd.dataNascimento[9]-'0';
    
    // verifica se o dia é entre 1 e 31.
    if(dia < 1  || dia > 31)
        contDT = 1;
    
    // verifica se o mês é entre 1 e 12    
    if(mes < 1 || mes > 12)
        contDT = 1;
    
    // verifica se o ano esta no intervalo entre 1900 e 2100
    if(ano < 1900 || ano > 2100)
        contDT = 1;
    
    // verifica se mês for 04, 06, 09 ou 11, dia pode ser no máximo 30;
    if(mes == 4 || mes == 6 || mes == 9 || mes == 11)
        if(dia > 30)
            contDT = 1;
    
    //calculo do ano bissexto
    if(ano % 4 == 0 && ano % 100 != 0)
        bissexto = 1;
    if(ano % 4 == 0 && ano % 400 == 0 && ano % 100 == 0)
        bissexto = 1;   
    
    if(bissexto) { // verifica se ano for bissexto e mês for 02, dia pode ser no máximo 29.
        if(mes == 2)
            if(dia > 29)
                contDT = 1;
            }
    
    else { // verifica se mês for 02, dia pode ser no máximo 28;
        if(mes == 2)
            if(dia > 28)
                contDT = 1;
        }
    
    return 0;
}
        
int validarCpf(){
    int i;
    int tamanho;
    int valid1, soma1 = 0, aux1 = 10;
    int valid2, soma2 = 0, aux2 = 11;
    char dg1,dg2;
    
    tamanho = strlen(cd.cpf);
    if(tamanho != 14){ // verifica se o tamanho do cpf esta correto
        contCP = 1;
        return 0;}
    else{
        for(i=0;i<14;i++){
           if (i == 3 || i == 7 ||i == 11){ 
                if(cd.cpf[3] != '.' || cd.cpf[7] != '.')
                    contCP = 1;
                if(cd.cpf[11] != '-')
                    contCP = 1;}
            else{
                if ((cd.cpf[i]-'0') < 0 )
                    contCP = 1;}
                    
        }}
      
    for(i=0;i<11;i++){ // validação do primeiro digito
            if((cd.cpf [i]) != '.'){
                soma1 += (cd.cpf[i]-'0') * aux1;
                aux1 = aux1 - 1;}
    }  
    
    dg1 = cd.cpf[12]-'0'; // capturando o primero digito verificador
    valid1 = (soma1 * 10) % 11;
    
    if(valid1 == 10) // se o resto da divisão for igual a 10 só capturamos o 0 
        valid1 = 0;
    
    if(valid1 != dg1) // verificando se o primeiro digito verificador é igual ao valid1 , primeira etapa de verificação concluida
        contCP = 1;
        
    for(i=0;i<13;i++){ // validação do segundo digito
            if(cd.cpf [i] != '.' || cd.cpf [i] != '-')
                soma2 += (cd.cpf[i]-'0') * aux2;
            aux2 = aux2 - 1; 
    }   
    
    dg2 = cd.cpf[13]-'0'; // capturando o segundo digito verificador
    valid2 = (soma2 * 10) % 11;
    
    if(valid2 == 10) // se o resto da divisão for igual a 10 só capturamos o 0 
        valid2 = 0;
        
    if(valid2 != dg2) // verificando se o segundo digito verificador é igual ao valid2 , segunda etapa de verificação concluida
        contCP = 1;
    
}


int validarSexo(){
    
    if(cd.sexo == 'M' || cd.sexo == 'F' || cd.sexo == 'm' || cd.sexo == 'f' || cd.sexo == 'o' || cd.sexo == 'O')
        contS = 0;
    else
        contS = 1;
    return 0 ;
    
}










