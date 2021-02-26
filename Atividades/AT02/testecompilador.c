/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, PHP, Ruby, 
C#, VB, Perl, Swift, Prolog, Javascript, Pascal, HTML, CSS, JS
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <stdio.h>
/*Atv 2 de laboratório */
int main()
{
    int num1,num2;
    int aux = 0;
    int cont = 0;
    int acao;
    int result;
    
    printf("Digite dois numeros : ");
    scanf("%d %d",&num1,&num2);
    
    while (aux == 0) {
        printf("\nModifique os numeros!!\n'"
        "Digite apenas numeros positivos***\nDigite 0 para Sair do programa"
        "\nDigite 1 para Somar\nDigite 2 para Subtrair\nDigite 3 para multiplicar\n"
        "Digite 4 para dividir\nDigita 5 para alterar os numeros\n");
        scanf("%d",&acao);
        
        if(acao == 0){
            aux = 1;
        }
        else if(acao == 1){
            result = num1 + num2;
        }
        else if(acao == 2){
            result = num1 - num2;
        }
        else if(acao == 3){
            result = num1 * num2;
        }
        else if(acao == 4){
            result = num1 / num2;
        }
        else if(acao == 5){
            printf("Digite dois numeros : ");
            scanf("%d %d",&num1,&num2);
        }
        else
            printf("\nOpcao invalida ... Tente novamente \n");
        
        cont++;
        
        if(aux ==0)
            printf("\nO resultado parcial eh : %d\n",result);
    }
    
    if(cont == 1)
        printf("\nOs numeros nao foram alterados\nFim do programa");
    else
        printf("Os numeros foram alterados\nO resultado final das operacoes foi : %d\nFim do programa",result);
    
    return 0;
}
