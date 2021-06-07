#include <stdio.h>
#include <stdlib.h>

int mdc(int x, int y){ 
    if(y == 0)
        return x;    
    else    
        return mdc(y,x%y);     
        
}

int main(){    

    int x,y;
    int result = 0;
    int sair = 1;
    int vetor[101];

    while(sair){
        
        printf("\nDigite um numero x: ");
        scanf("%d",&x);
        printf("\nDigite um numero y: ");
        scanf("%d",&y);
        if(x>=0 && y>=0){
            sair = 0;
            break;
        }
        else 
            printf("\nErro ... Digite um numero positivo...\n");    
    }
    
    result = mdc(x,y);

    printf("\nMdc de %d-%d eh : %d\n",x,y,result);    

    system("pause");
    return 0;
}

