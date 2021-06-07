#include <stdio.h>
#include <stdlib.h>

int soma(int n){ 
    if(n==0){        
        return 0;
    }    
    else       
        return n + soma(n-1);             
    } 

int main(){    

    int num = 0;  
    int result = 0;
    int sair = 1;

     while(sair){
        
        printf("\nDigite um numero : ");
        scanf("%d",&num);
        if(num>=0){
            sair = 0;
            break;
        }
        else 
            printf("\nErro ... Digite um numero positivo...\n");    
    }
    
    result = soma(num);
    printf("\nO somatorio de %d de 1 a N eh : %d\n",num,result);

    system("pause");
    return 0;
}

