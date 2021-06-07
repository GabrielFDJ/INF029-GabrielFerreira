#include <stdio.h>
#include <stdlib.h>

int fibonacci(int f){     
    if(f == 1 || f == 0){        
        return 1;
    }    
    else       
        return fibonacci(f-1) + fibonacci(f-2);             
    } 

int main(){    
    int valor=0;
    int sair = 1;
    int result = 0;    

    while(sair){
        
        printf("\nDigite o tamanho da sequencia fibbo : ");
        scanf("%d",&valor);
        if(valor>=0){
            sair = 0;
            break;
        }
        else 
            printf("\nErro ... Digite um valor positivo...\n");    
    }
    result = fibonacci(valor-1);
    printf("\nO n-%d termo da Fibonacci eh : %d\n",valor,result);

    system("pause");
    return 0;
}

