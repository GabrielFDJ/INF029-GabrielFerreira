#include <stdio.h>
#include <stdlib.h>
#define TAM 10

#include "EstruturaVetores.h"

struct Estrutura
{
    int tam;
    int cont;
    int *p;
}lista_estrutura[TAM];

/*
Objetivo: criar estrutura auxiliar na posição 'posicao'.
com tamanho 'tamanho'
Rertono (int)
    SUCESSO - criado com sucesso
    JA_TEM_ESTRUTURA_AUXILIAR - já tem estrutura na posição
    POSICAO_INVALIDA - Posição inválida para estrutura auxiliar
    SEM_ESPACO_DE_MEMORIA - Sem espaço de memória
    TAMANHO_INVALIDO - o tamanho tem inteiro maior ou igual a 1
*/
int criarEstruturaAuxiliar(int posicao, int tamanho)
{
    int i;   
    int pos = posicao; 

    if (pos<1 || pos>10)
        return POSICAO_INVALIDA;    
    if(tamanho < 1)
        return TAMANHO_INVALIDO;
    if(NULL==malloc(tamanho*sizeof(int)))    
        return SEM_ESPACO_DE_MEMORIA;
    if(lista_estrutura[pos-1].p!= NULL)
        return JA_TEM_ESTRUTURA_AUXILIAR;
    
    lista_estrutura[pos-1].p = (int *)(malloc(tamanho * sizeof(int)));
    lista_estrutura[pos-1].tam = tamanho;

    return SUCESSO;  
   

}   

/*
Objetivo: inserir número 'valor' em estrutura auxiliar da posição 'posicao'
Retorno (int)
    SUCESSO - inserido com sucesso
    SEM_ESPACO - não tem espaço
    SEM_ESTRUTURA_AUXILIAR - Não tem estrutura auxiliar
    POSICAO_INVALIDA - Posição inválida para estrutura auxiliar
CONSTANTES
*/
int inserirNumeroEmEstrutura(int posicao, int valor)
{
    int i = 0, j = 0;
    int retorno = 0;
    int existeEstruturaAuxiliar = 0;
    int temEspaco = 0;
    int posicao_invalida = 0;
    int pos = posicao;      
    
    if (pos<1 || pos>10)    
        retorno = POSICAO_INVALIDA;      
    else
    {
        // testar se existe a estrutura auxiliar
        if (lista_estrutura[pos-1].p!=NULL)
        {
            
            if(lista_estrutura[pos-1].cont  < lista_estrutura[pos-1].tam)              
                temEspaco = 1;                                                                       
            
            if (temEspaco)
            {
                //insere
                for(j=0;j<lista_estrutura[pos-1].tam;j++)
                {
                    if(lista_estrutura[pos-1].cont == j)
                    {
                        lista_estrutura[pos-1].p[j] = valor;  
                        lista_estrutura[pos-1].cont++;                        
                        return SUCESSO;                              
                    }
                }
                
            }
            else
            {
                retorno = SEM_ESPACO;
            }
        }
        else
        {
            retorno = SEM_ESTRUTURA_AUXILIAR;
        }
    }    
    
    return retorno;
}

/*
Objetivo: excluir o numero 'valor' da estrutura auxiliar no final da estrutura.
ex: suponha os valores [3, 8, 7, 9,  ,  ]. Após excluir, a estrutura deve ficar da seguinte forma [3, 8, 7,  ,  ,  ].
Obs. Esta é uma exclusão lógica
Rertono (int)
    SUCESSO - excluido com sucesso
    ESTRUTURA_AUXILIAR_VAZIA - estrutura vazia
    SEM_ESTRUTURA_AUXILIAR - Não tem estrutura auxiliar
    POSICAO_INVALIDA - Posição inválida para estrutura auxiliar
*/
int excluirNumeroDoFinaldaEstrutura(int posicao)
{
    int pos = posicao;

    if(pos<1 || pos>10)
        return POSICAO_INVALIDA;
    if(lista_estrutura[pos-1].tam == 0)
        return SEM_ESTRUTURA_AUXILIAR;
    if(lista_estrutura[pos-1].cont== 0)
        return ESTRUTURA_AUXILIAR_VAZIA;    
    lista_estrutura[pos-1].cont--;
    
    return SUCESSO;
    
}

/*
Objetivo: excluir o numero 'valor' da estrutura auxiliar da posição 'posicao'.
Caso seja excluido, os números posteriores devem ser movidos para as posições anteriores
ex: suponha os valores [3, 8, 7, 9,  ,  ] onde deve ser excluido o valor 8. A estrutura deve ficar da seguinte forma [3, 7, 9,  ,  ,  ]
Obs. Esta é uma exclusão lógica
Rertono (int)
    SUCESSO - excluido com sucesso 'valor' da estrutura na posição 'posicao'
    ESTRUTURA_AUXILIAR_VAZIA - estrutura vazia
    SEM_ESTRUTURA_AUXILIAR - Não tem estrutura auxiliar
    NUMERO_INEXISTENTE - Número não existe
    POSICAO_INVALIDA - Posição inválida para estrutura auxiliar
*/
int excluirNumeroEspecificoDeEstrutura(int posicao, int valor)
{
    int i;
    int pos = posicao;
    int cont = 0, guardar = 0;
    int aux = 0;

    if(pos<1 || pos>10)
        return POSICAO_INVALIDA;
    if(lista_estrutura[pos-1].tam == 0)
        return SEM_ESTRUTURA_AUXILIAR;
    if(lista_estrutura[pos-1].cont == 0)
        return ESTRUTURA_AUXILIAR_VAZIA;
    for(i=0;i<lista_estrutura[pos-1].cont;i++)
    {
        if(lista_estrutura[pos-1].p[i] == valor)
        {
            cont++;
            guardar = i;
        }    
    }
    if(cont == 0)
        return NUMERO_INEXISTENTE;

    for(i=guardar;i<lista_estrutura[pos-1].cont;i++)
    {
        aux = lista_estrutura[pos-1].p[i];
        lista_estrutura[pos-1].p[i] = lista_estrutura[pos-1].p[i+1];
        lista_estrutura[pos-1].p[i+1] = aux;
    }        

    lista_estrutura[pos-1].cont--;

    return SUCESSO;

    
}

/*
Objetivo: retorna os números da estrutura auxiliar da posição 'posicao (1..10)'.
os números devem ser armazenados em vetorAux
Retorno (int)
    SUCESSO - recuperado com sucesso os valores da estrutura na posição 'posicao'
    SEM_ESTRUTURA_AUXILIAR - Não tem estrutura auxiliar
    POSICAO_INVALIDA - Posição inválida para estrutura auxiliar
*/
int getDadosEstruturaAuxiliar(int posicao, int vetorAux[])
{
    int pos = posicao;

    if(pos<1 || pos>10)
        return POSICAO_INVALIDA;
    if(lista_estrutura[pos-1].tam == 0)
        return SEM_ESTRUTURA_AUXILIAR;     
    
    for(int i = 0; i<lista_estrutura[pos-1].cont;i++)
    {
        vetorAux[i] = lista_estrutura[pos-1].p[i];        
    }    
      
    return SUCESSO;
}

/*
Objetivo: retorna os números ordenados da estrutura auxiliar da posição 'posicao (1..10)'.
os números devem ser armazenados em vetorAux
Rertono (int)
    SUCESSO - recuperado com sucesso os valores da estrutura na posição 'posicao (1..10)'
    SEM_ESTRUTURA_AUXILIAR - Não tem estrutura auxiliar
    POSICAO_INVALIDA - Posição inválida para estrutura auxiliar
*/
int getDadosOrdenadosEstruturaAuxiliar(int posicao, int vetorAux[])
{
    int i,j;
    int aux = 0;
    int pos = posicao;
    int tm = lista_estrutura[pos-1].cont;

    if(pos<1 || pos>10)
        return POSICAO_INVALIDA;
    if(lista_estrutura[pos-1].tam == 0)
        return SEM_ESTRUTURA_AUXILIAR;

    for (j = 1; j < tm; j++) 
    {
        for (i = 0; i < tm - 1; i++) 
        {
            if (vetorAux[i] > vetorAux[i + 1]) 
            {
                aux = vetorAux[i];
                vetorAux[i] = vetorAux[i + 1];
                vetorAux[i + 1] = aux;
            }
        }
    }  
    return SUCESSO;
}

/*
Objetivo: retorna os números de todas as estruturas auxiliares.
os números devem ser armazenados em vetorAux
Rertono (int)
    SUCESSO - recuperado com sucesso os valores da estrutura na posição 'posicao'
    SEM_ESTRUTURA_AUXILIAR - Não tem estrutura auxiliar
*/
int getDadosDeTodasEstruturasAuxiliares(int vetorAux[])
{
    int i,j;
    int contgeral = 0;
    int contam = 0;     
    int aux = 0;

    for(i=0;i<TAM;i++)
    {
        contgeral += lista_estrutura[i].cont;         
    }
    if(contgeral == 0)
    {
        return TODAS_ESTRUTURAS_AUXILIARES_VAZIAS;
    }        
    
    
        for(j=0;j<TAM;j++)
        {
            if(lista_estrutura[j].cont > 0)
            {
                for(i=0;i<lista_estrutura[j].cont;i++)
                {
                    vetorAux[aux] = lista_estrutura[j].p[i];
                    aux++;
                }
                
            }
            if(aux == contgeral) 
                break;
        }    
       
    return SUCESSO;
    
}

/*
Objetivo: retorna os números ordenados de todas as estruturas auxiliares.
os números devem ser armazenados em vetorAux
Rertono (int)
    SUCESSO - recuperado com sucesso os valores da estrutura na posição 'posicao'
    SEM_ESTRUTURA_AUXILIAR - Não tem estrutura auxiliar
*/
int getDadosOrdenadosDeTodasEstruturasAuxiliares(int vetorAux[])
{

    int i,j;
    int aux = 0;
    int contgeral = 0;
    int troca = 0;
    
    for(i=0;i<TAM;i++)
    {
        contgeral += lista_estrutura[i].cont;           
    }
    if(contgeral == 0)
        return TODAS_ESTRUTURAS_AUXILIARES_VAZIAS; 

    for(j=0;j<TAM;j++)
        {
            if(lista_estrutura[j].cont > 0)
            {
                for(i=0;i<lista_estrutura[j].cont;i++)
                {
                    vetorAux[aux] = lista_estrutura[j].p[i];
                    aux++;
                }
                
            }
            if(aux == contgeral) 
                break;
        }        

    for (j = 1; j < aux; j++) 
    {
        for (i = 0; i < aux - 1; i++) 
        {
            if (vetorAux[i] > vetorAux[i + 1]) 
            {
                troca = vetorAux[i];
                vetorAux[i] = vetorAux[i + 1];
                vetorAux[i + 1] = troca;
            }
        }
    }  
    
    return SUCESSO;
}

/*
Objetivo: modificar o tamanho da estrutura auxiliar da posição 'posicao' para o novo tamanho 'novoTamanho' + tamanho atual
Suponha o tamanho inicial = x, e novo tamanho = n. O tamanho resultante deve ser x + n. Sendo que x + n deve ser sempre >= 1
Rertono (int)
    SUCESSO - foi modificado corretamente o tamanho da estrutura auxiliar
    SEM_ESTRUTURA_AUXILIAR - Não tem estrutura auxiliar
    POSICAO_INVALIDA - Posição inválida para estrutura auxiliar
    NOVO_TAMANHO_INVALIDO - novo tamanho não pode ser negativo
    SEM_ESPACO_DE_MEMORIA - erro na alocação do novo valor
*/
int modificarTamanhoEstruturaAuxiliar(int posicao, int novoTamanho)
{
    int i;   
    int pos = posicao;     
    int tamnov = lista_estrutura[pos-1].tam + novoTamanho;

    if (pos<1 || pos>10)
        return POSICAO_INVALIDA;    
    if(tamnov < 1)
        return NOVO_TAMANHO_INVALIDO;
    if(lista_estrutura[pos-1].tam == 0)  
        return SEM_ESTRUTURA_AUXILIAR;
    if(NULL==malloc(tamnov*sizeof(int)))
        return SEM_ESPACO_DE_MEMORIA;  

    int vetaux[tamnov];
    for(i=0;i<lista_estrutura[pos-1].cont;i++)
    {
        vetaux[i] = lista_estrutura[pos-1].p[i];
    }

    lista_estrutura[pos-1].p = (int *)(malloc(tamnov * sizeof(int)));
    lista_estrutura[pos-1].tam = tamnov;

    for(i=0;i<lista_estrutura[pos-1].cont;i++)
    {
        lista_estrutura[pos-1].p[i] = vetaux[i];
    }
    
    return SUCESSO;  
    
}

/*
Objetivo: retorna a quantidade de elementos preenchidos da estrutura auxiliar da posição 'posicao'.
Retorno (int)
    POSICAO_INVALIDA - posição inválida
    SEM_ESTRUTURA_AUXILIAR - sem estrutura auxiliar
    ESTRUTURA_AUXILIAR_VAZIA - estrutura auxiliar vazia
    Um número int > 0 correpondente a quantidade de elementos preenchidos da estrutura
*/
int getQuantidadeElementosEstruturaAuxiliar(int posicao)
{
    int pos = posicao;

    if (pos<1 || pos>10)
        return POSICAO_INVALIDA;
    if(lista_estrutura[pos-1].tam == 0)
        return SEM_ESTRUTURA_AUXILIAR;
    if(lista_estrutura[pos-1].cont == 0)
        return ESTRUTURA_AUXILIAR_VAZIA;

    if( lista_estrutura[pos-1].cont > lista_estrutura[pos-1].tam)
        lista_estrutura[pos-1].cont = lista_estrutura[pos-1].tam;    

    return lista_estrutura[pos-1].cont;    
}

/*
Objetivo: montar a lista encadeada com cabeçote com todos os números presentes em todas as estruturas.
Retorno (No*)
    NULL, caso não tenha nenhum número nas listas
    No*, ponteiro para o início da lista com cabeçote
*/
No *montarListaEncadeadaComCabecote()
{
       
    int i,j;
    int contgeral = 0;
    int contam = 0;     
    int aux = 0;

    for(i=0;i<TAM;i++)   
        contgeral += lista_estrutura[i].cont;           
        
    int vetorAux[contgeral];
    for(j=0;j<TAM;j++)
    {
        if(lista_estrutura[j].cont > 0)
        {
            for(i=0;i<lista_estrutura[j].cont;i++)
            {
                vetorAux[aux] = lista_estrutura[j].p[i];                
                aux++;
            }
            
        }
        if(aux == contgeral) 
            break;
    }
   
    No * ini_ponto;
    No * prox_ponto;

    ini_ponto = (No *)malloc(sizeof(No));
    if(ini_ponto == NULL)
        exit(1);
    prox_ponto = ini_ponto;

    for(i=0;i<contgeral;i++)
    {
        prox_ponto->conteudo = vetorAux[i];
        prox_ponto->prox = (No *)malloc(sizeof(No));
        prox_ponto = prox_ponto->prox;
    }

    return ini_ponto;

}

/*
Objetivo: retorna os números da lista enceada com cabeçote armazenando em vetorAux.
Retorno void
*/
void getDadosListaEncadeadaComCabecote(No *inicio, int vetorAux[])
{
    int i;
    int contgeral = 0;
    No*lista = inicio;
    
    for(i=0;i<TAM;i++)
    {
        contgeral += lista_estrutura[i].cont;           
    }
    
    for(i = 0;i<contgeral;i++)
    {
        vetorAux[i] = lista->conteudo;
        lista=lista->prox;
    }
    
}

/*
Objetivo: Destruir a lista encadeada com cabeçote a partir de início.
O ponteiro inicio deve ficar com NULL.
Retorno 
    void.
*/
void destruirListaEncadeadaComCabecote(No **inicio)
{
    *inicio = NULL;  
}

/*
Objetivo: inicializa o programa. deve ser chamado ao inicio do programa 
*/

void inicializar()
{
    for(int i=0;i<TAM;i++)
    {   
        lista_estrutura[i].cont = 0;
        lista_estrutura[i].tam = 0;
        lista_estrutura[i].p = NULL;    
    }

}

/*
Objetivo: finaliza o programa. deve ser chamado ao final do programa 
para poder liberar todos os espaços de memória das estruturas auxiliares.
*/

void finalizar()
{
    for(int i=0;i<TAM;i++)
    {
        if(lista_estrutura[i].p != NULL)
            free(lista_estrutura[i].p);        
    }

}