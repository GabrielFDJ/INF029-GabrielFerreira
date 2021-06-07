#include <stdio.h>
#include <stdlib.h>

void imprime(int cont,int n){

    if(cont!=n)  
       imprime(cont+1,n);
    printf("%d-",cont);
       
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
    
    imprime(0,num);    

    system("pause");
    return 0;
}

