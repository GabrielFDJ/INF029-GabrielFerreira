#include <stdio.h>
#include <stdlib.h>

int fatorial(int v){      
    if(v == 0)
        return 1;
    else    
        return v*fatorial(v-1);
}

int main(){

    int valor=0;
    int sair = 1;
    int result = 0; 

    while(sair){
        
        printf("\nDigite o valor do fatorial que deseja calcular : ");
        scanf("%d",&valor);
        if(valor>0){
            sair = 0;
            break;
        }
        else 
            printf("\nErro ... Digite um valor positivo...\n");
    }
    result = fatorial(valor);
    printf("\nFatorial de %d eh : %d\n",valor,result);

    system("pause");
    return 0;
}
