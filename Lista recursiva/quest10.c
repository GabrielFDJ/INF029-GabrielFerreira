#include <stdio.h>
#include <stdlib.h>

int calc(int n, int d){     
    if ( n == 0 ) 
        return 0;
    else    
        return calc(n/10,d) + (n%10==d);
}
                

int main(){    

    int num = 0;
    int dig = 0;  
    int result = 0;
    int sair = 1;

     while(sair){
        
        printf("\nDigite um numero positivo: ");
        scanf("%d",&num);
        printf("\nDigite um digito positivo: ");
        scanf("%d",&dig);
        if(num>=0 && dig>=0){
            sair = 0;
            break;
        }
        else 
            printf("\nErro ... Digite um numero positivo...\n");    
    }
    
    result = calc(num,dig);
    printf("\nO quantidade de ocorrencia eh de %d\n",result);

    system("pause");
    return 0;
}

