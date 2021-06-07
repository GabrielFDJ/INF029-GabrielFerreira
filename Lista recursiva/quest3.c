#include <stdio.h>
#include <stdlib.h>

int inverter(int n, int total){     
    if(n==0){        
        return total;
    }    
    else       
        return inverter(n / 10 , total * 10 + n % 10);          
    } 

int main(){    
    int num=0;
    int sair = 1;
    int result = 0;    

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
    result = inverter(num,0);
    printf("\nO numero %d invertido eh : %d\n",num,result);

    system("pause");
    return 0;
}

