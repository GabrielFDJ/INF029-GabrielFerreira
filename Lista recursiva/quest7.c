#include <stdio.h>
#include <stdlib.h>

int inverter(int vetor[],int posi, int tam){ 
    if(posi<tam){ 
        trocar(vetor,posi,tam);       
        inverter(vetor,posi+1,tam-1);
    }    
}

int trocar(int vetor[],int posi, int tam){
    int aux = vetor[posi];
    vetor[posi] = vetor[tam];
    vetor[tam] = aux;
}

int main(){    

    int result = 0;
    int sair = 1;
    int vetor[100];

    for(int i=0;i<100;i++){
        vetor[i] = i+1;
    }
    
    inverter(vetor,0,99);
    for(int i=0;i<100;i++){
        printf("%d - ",vetor[i]);
    }      

    system("pause");
    return 0;
}

