//Questão 5 listadefunções
#include <stdio.h>
#include <stdlib.h>

void ler4numeros();

struct num4 {
		int n[4];
};

int main(){

    int i;
	struct num4 n4;
	
	ler4numeros (&n4);

	for(i=0;i<4;i++){
	    printf("\nNum %d = %d",i,n4.n[i]);
	}
	
	system("pause");
	return 0;
}

void ler4numeros(struct num4 *n){
    
    int i;
    
    for(i=0;i<4;i++){
	    printf("Num %d : ",i);
	    scanf("%d",&(*n).n[i]);
	}

}
	
		





