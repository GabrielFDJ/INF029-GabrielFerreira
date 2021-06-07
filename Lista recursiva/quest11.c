#include <stdio.h>
#include <stdlib.h>

int multip_rec(int n1, int n2,int cont){ 
    if(cont==n2-1){        
        return n1;
    }    
    else       
        return n1 + multip_rec(n1,n2,cont+1);           
    } 

int main(){    

    int a,b;  
    int result = 0;
    int sair = 1;

     while(sair){
        
        printf("\nDigite um numero : ");
        scanf("%d",&a);
        printf("\nDigite um numero : ");
        scanf("%d",&b);
        if(a>=0 && b>=0){
            sair = 0;
            break;
        }
        else 
            printf("\nErro ... Digite um numero positivo...\n");    
    }
    
    result = multip_rec(a,b,0);
    printf("\nO multiplicacao de %d-%d eh : %d\n",a,b,result);

    system("pause");
    return 0;
}

