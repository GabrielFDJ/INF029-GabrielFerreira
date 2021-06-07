#include <stdio.h>
#include <stdlib.h>

int multiplic(int k,int max){ 
    if(max==0){        
        return 1;
    }    
    else       
        return k * multiplic(k,max-1);             
    } 

int main(){    

    int k = 0,n = 0;
    int result = 0;
    int sair = 1;

     while(sair){
        
        printf("\nDigite um numero k: ");
        scanf("%d",&k);
        printf("\nDigite um numero n: ");
        scanf("%d",&n);
        if(k>=0){
            sair = 0;
            break;
        }
        else 
            printf("\nErro ... Digite um numero positivo...\n");    
    }
    
    result = multiplic(k,n);
    printf("\nO resultado eh : %d\n",result);

    system("pause");
    return 0;
}

