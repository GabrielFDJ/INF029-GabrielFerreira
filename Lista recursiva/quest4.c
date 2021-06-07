#include <stdio.h>
#include <stdlib.h>

int soma(int n[], int tam){ 
    if(tam==0){        
        return 0;
    }    
    else       
        return n[tam-1] + soma(n,tam-1);             
    } 

int main(){    

    int num[10]= {10,10,10,10,10,10,10,10,10,10};    
    int result = 0;  
    
    result = soma(num,10);
    printf("\nO numero total do vetor eh : %d\n",result);

    system("pause");
    return 0;
}

