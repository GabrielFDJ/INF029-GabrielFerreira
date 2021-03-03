#include <stdio.h>
/*Atv 2 de laboratório */
int main()
{
    float num1,num2;
    int aux = 0;
    int cont = 0;
    int acao;
    float result = 0;
    
    printf("Digite dois numeros : ");
    scanf("%f %f",&num1,&num2);
    
    printf("\nModifique os numeros!!\n'"
        "Digite apenas numeros positivos***\nDigite 0 para Sair do programa"
        "\nDigite 1 para Somar\nDigite 2 para Subtrair\nDigite 3 para multiplicar\n"
        "Digite 4 para dividir\nDigita 5 para alterar os numeros\n");
        
    while (aux == 0) {
        printf("Opcao : ");
        scanf("%d",&acao);
        
        if(acao == 0){
            aux = 1;
        }
        else if(acao == 1){ /* Soma */
            result = num1 + num2;
        }
        else if(acao == 2){ /* Subtracao */
            result = num1 - num2;
        }
        else if(acao == 3){ /* Multiplicacao */
            result = num1 * num2;
        }
        else if(acao == 4){ /* Divisao */
            result = num1 / num2;
            if (num1 == 0 || num2 == 0)
            	printf("\nNao eh possivel dividir um numero por 0\nTente novamente , digitando 5 numeros para escolher outros numeros\n");            	
        }
        else if(acao == 5){ /* Digitar novamente */
            printf("\nDigite dois numeros : ");
            scanf("%f %f",&num1,&num2);
        }
        else
            printf("\nOpcao invalida ... Tente novamente \n");
        
        cont++;
        
        if(aux ==0)
            printf("\nO resultado parcial eh : %f\n",result);
    }
    
    if(cont == 1)
        printf("\nOs numeros nao foram alterados\nFim do programa");
    else
        printf("Os numeros foram alterados\nO resultado final das operacoes foi : %f\nFim do programa",result);
    
    return 0;
}