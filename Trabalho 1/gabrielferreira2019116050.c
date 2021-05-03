// #################################################
//  Instituto Federal da Bahia
//  Salvador - BA
//  Curso de Análise e Desenvolvimento de Sistemas http://ads.ifba.edu.br
//  Disciplina: INF029 - Laboratório de Programação
//  Professor: Renato Novais - renato@ifba.edu.br

//  ----- Orientações gerais -----
//  Descrição: esse arquivo deve conter as questões do trabalho do aluno.
//  Cada aluno deve renomear esse arquivo para Aluno<MATRICULA>.c
//  O aluno deve preencher seus dados abaixo, e implementar as questões do trabalho

//  ----- Dados do Aluno -----
//  Nome: Gabriel Ferreira de Jesus
//  email: gabrielfereiradj2014@gmail.com
//  Matrícula: 2019116050
//  Semestre: 1

//  Copyright © 2016 Renato Novais. All rights reserved.
// Última atualização: 20/06/2018 - 19/08/2016

// #################################################

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "gabrielferreira2019116050.h"
/*
## função utilizada para testes  ##
 somar = somar dois valores
@objetivo
    Somar dois valores x e y e retonar o resultado da soma
@entrada
    dois inteiros x e y
@saida
    resultado da soma (x + y)
 */
int somar(int x, int y){
  int soma = 0;
  soma = x + y;
  return soma;
}

/*
## função utilizada para testes  ##
 fatorial = fatorial de um número
@objetivo
    calcular o fatorial de um número
@entrada
    um inteiro x
@saida
    fatorial de x -> x!
 */
int fatorial(int x){ //função utilizada para testes
  int fat = 1;
  return fat;
}

/*
 Q1 = validar data
@objetivo
    Validar uma data
@entrada
    uma string data. Formatos que devem ser aceitos: dd/mm/aaaa, onde dd = dia, mm = mês, e aaaa, igual ao ano. dd em mm podem ter apenas um digito, e aaaa podem ter apenas dois digitos.
@saida
    0 -> se data inválida
    1 -> se data válida
 */
 
    //verificar se a string está vazia logo de cara
    //usar atoi
    //se for data com dois digitos no ano somar com 2000
    
int q1(char *data){
    
    int datavalida = 1;
    char sDia[3], sMes[3], sAno[5];
    int iDia, iMes, iAno;
    int tamanho, cont = 0, i = 0, j = 0, x = 0;
    int bissexto = 0;
    tamanho = strlen(data);
    
    for (i=0; i<tamanho;i++)
    {
        if(cont == 0) // pegando o dia 
        {
            if (data[i] != '/' ) 
                sDia[i] = data[i];
                
            if (data[i] == '/')
            {
                sDia[i] = '\0';
                cont++;
                i++;
            }
        }
        if(cont == 1) // pegando o mes
        {
            if (data[i] != '/')
                sMes[j] = data[i];
        
            if (data[i] == '/')
            {
                sMes[j] = '\0';
                cont++;
                i++;
            }
            j++;
        }    
        if(cont == 2) // pegando o ano
        { 
            if (data[i] != '/')
                sAno[x] = data[i];
                
            if(i+1 == tamanho)
                sAno[x+1] = '\0';
            x++;    
        }    
    }
    
    tamanho = strlen(sDia);
    if(tamanho == 0 || tamanho > 2)
        return 0;
    
    tamanho = strlen(sMes);
    if(tamanho == 0 || tamanho > 2)
        return 0;
        
    tamanho = strlen(sAno);
    if(tamanho == 0 || tamanho == 1 || tamanho > 4)
        return 0;
    
    iDia = atoi(sDia);
    iMes = atoi(sMes);
    iAno = atoi(sAno);
    
    if(iAno > 99 && iAno < 1000 )
        return 0;
        
    if(iAno > 9999)    
        return 0;
        
    if(iAno < 100)
        iAno += 2000;
    
    // verifica se o dia é entre 1 e 31.
    if(iDia < 1  || iDia > 31)
        datavalida = 0;
    
    // verifica se o mês é entre 1 e 12    
    if(iMes < 1 || iMes > 12)
        datavalida = 0;
    
    // verifica se mês for 04, 06, 09 ou 11, dia pode ser no máximo 30;
    if(iMes == 4 || iMes == 6 || iMes == 9 || iMes == 11)
        if(iDia > 30)
            datavalida = 0;
    
    //calculo do ano bissexto
    if(iAno % 4 == 0 && iAno % 100 != 0)
        bissexto = 1;
    if(iAno % 4 == 0 && iAno % 400 == 0 && iAno % 100 == 0)
        bissexto = 1;   
    
    if(bissexto) { // verifica se ano for bissexto e mês for 02, dia pode ser no máximo 29.
        if(iMes == 2)
            if(iDia > 29)
                datavalida = 0;
            }
    
    else { // verifica se mês for 02, dia pode ser no máximo 28;
        if(iMes == 2)
            if(iDia > 28)
                datavalida = 0;
        }
    
    if (datavalida)
        return 1;
    else
        return 0;

}

/*
 Q2 = diferença entre duas datas
 @objetivo
    Calcular a diferença em anos, meses e dias entre duas datas
 @entrada
    uma string datainicial, uma string datafinal. Além disso, a função tem três parâmetros qtdDias, qtdMeses e qtdAnos. Esses três parâmetros devem ser utilizados para guardar os resultados dos cálculos. Na chamada da função deve passar o valor -1 para os três
 @saida
    1 -> cálculo de diferença realizado com sucesso
    2 -> datainicial inválida
    3 -> datafinal inválida
    4 -> datainicial > datafinal
 */
int q2(char *datainicial, char *datafinal, int *qtdDias, int *qtdMeses, int *qtdAnos){
    
    int datavalida = 1, contdata = 0;
    char sDia[3], sMes[3], sAno[5] , sFDia[3], sFMes[3], sFAno[5];
    int iDia, iMes, iAno, iFDia, iFMes, iFAno;
    int nDias,nMeses,nAnos;
    int tamanho, cont = 0, i = 0, j = 0, x = 0;
    int ibissexto = 0, fbissexto = 0;
    
    //validando datainicial e datafinal
    
    if(q1(datainicial)==0)
        return 2;
    if(q1(datafinal)==0)
        return 3;
        
    tamanho = strlen(datainicial);
    for (i=0; i<tamanho;i++)
    {
        if(cont == 0) // pegando o dia 
        {
            if (datainicial[i] != '/' ) 
                sDia[i] = datainicial[i];
                
            if (datainicial[i] == '/')
            {
                sDia[i] = '\0';
                cont++;
                i++;
            }
        }
        if(cont == 1) // pegando o mes
        {
            if (datainicial[i] != '/')
                sMes[j] = datainicial[i];
        
            if (datainicial[i] == '/')
            {
                sMes[j] = '\0';
                cont++;
                i++;
            }
            j++;
        }    
        if(cont == 2) // pegando o ano
        { 
            if (datainicial[i] != '/')
                sAno[x] = datainicial[i];
                
            if(i+1 == tamanho)
                sAno[x+1] = '\0';
            x++;    
        }    
    }
    
    iDia = atoi(sDia);
    iMes = atoi(sMes);
    iAno = atoi(sAno);
    
    //calculo do ano bissexto
    if(iAno % 4 == 0 && iAno % 100 != 0)
        ibissexto = 1;
    if(iAno % 4 == 0 && iAno % 400 == 0 && iAno % 100 == 0)
        ibissexto = 1;
   
    contdata++;
    cont = 0;
    j = 0;
    x = 0;
    i = 0;
     
    //fim validação datainicial
    
    //printf("\ndia : %d, mes : %d , ano : %d",iDia,iMes,iAno);
    
    //validando datafinal
    
    tamanho = strlen(datafinal);
    for (i=0; i<tamanho;i++)
    {
        if(cont == 0) // pegando o dia 
        {
            if (datafinal[i] != '/' ) 
                sFDia[i] = datafinal[i];
                
            if (datafinal[i] == '/')
            {
                sFDia[i] = '\0';
                cont++;
                i++;
            }
        }
        if(cont == 1) // pegando o mes
        {
            if (datafinal[i] != '/')
                sFMes[j] = datafinal[i];
        
            if (datafinal[i] == '/')
            {
                sFMes[j] = '\0';
                cont++;
                i++;
            }
            j++;
        }    
        if(cont == 2) // pegando o ano
        { 
            if (datafinal[i] != '/')
                sFAno[x] = datafinal[i];
                
            if(i+1 == tamanho)
                sFAno[x+1] = '\0';
            x++;    
        }    
    }
    
    iFDia = atoi(sFDia);
    iFMes = atoi(sFMes);
    iFAno = atoi(sFAno);
    
    if(iFAno < 100)
        iAno += 2000;
    
    //calculo do ano bissexto
    if(iFAno % 4 == 0 && iFAno % 100 != 0)
        fbissexto = 1;
    if(iFAno % 4 == 0 && iFAno % 400 == 0 && iFAno % 100 == 0)
        fbissexto = 1;   
    
    //termino validação datafinal
    // printf("\ndia : %d, mes : %d , ano : %d",iFDia,iFMes,iFAno);
    
    //verifica se a datainicial é maior que a final
    if(iAno > iFAno)
        return 4;
    if(iAno == iFAno && iMes > iFMes)
        return 4;
    if(iAno == iFAno && iMes == iFMes && iDia > iFDia)
        return 4;
      
    //calculo do diferença das datas    
    
    //anos
    if(iFMes > iMes)
    {
        nAnos = iFAno - iAno;
    }
    if(iFMes < iMes)
    {
        nAnos = (iFAno - iAno) - 1;
    }
    if(iFMes == iMes)
    {
        if(iDia > iFDia)
            nAnos = nAnos = (iFAno - iAno) - 1;
        else
            nAnos = iFAno - iAno;
    }
    
    //meses
    
    if(iMes < iFMes)
    {
        
        if(iFDia >= iDia)
        {
            nMeses = iFMes - iMes;
           
        }
    }
    if(iMes > iFMes)
    {
        if(iDia == iFDia)
            nMeses = (iMes - iFMes) - 12;
        else    
            if(iDia >= iFDia)
                nMeses = 12 - (iMes - iFMes);
            else
                nMeses = 11 - (iMes - iFMes);
    }
    if(iMes == iFMes)
    {
        if(iDia > iFDia)
            nMeses = 11;
        else
            nMeses = 0;
    }
    
    //dias
    if(iDia == iFDia)
	    nDias = 0;
    if(iDia > iFDia)
    {
        if(iMes == 2 && ibissexto && fbissexto)
        	nDias = (29 - iDia) + iFDia;
        if(iMes == 2 && ibissexto && !fbissexto)
            nDias = (29 - iDia) + iFDia;
    	else if (iMes == 2 && !ibissexto)
    		nDias = (28 - iDia) - iFDia;	
    	else if(iMes == 4 || iMes == 6 || iMes == 9 || iMes == 11)
    		nDias = (30 - iDia) + iFDia;
    	else	
    		nDias = (31 - iDia) + iFDia;
    }		
    if(iDia < iFDia)
    	nDias = iFDia - iDia;
    
    *qtdDias = nDias;
    *qtdAnos = nAnos;
    *qtdMeses = nMeses;
    
    return 1;
}


/*
 Q3 = encontrar caracter em texto
 @objetivo
    Pesquisar quantas vezes um determinado caracter ocorre em um texto
 @entrada
    uma string texto, um caracter c e um inteiro que informa se é uma pesquisa Case Sensitive ou não. Se isCaseSensitive = 1, a pesquisa deve considerar diferenças entre maiúsculos e minúsculos.
        Se isCaseSensitive != 1, a pesquisa não deve  considerar diferenças entre maiúsculos e minúsculos.
 @saida
    Um número n >= 0.
 */
int q3(char *texto, char c, int isCaseSensitive){
    int i = 0,j = 0, k = 0, aux = 0, cont = 0;
    int qtdOcorrencias = 0;
    char copia;
    int tamanho;
    tamanho = strlen(texto);
    char copiatexto[250];
    int texto_int[250];
    int texto_int2[250];
    
    for(i=0;i<=tamanho;i++)
    {
        if(i<tamanho)
            copiatexto[i] = texto[i];
        else 
            copiatexto[i] = '\0';
    }
    
    for (i = 0; copiatexto[i] != '\0'; i+=2){
        texto_int[i] = copiatexto[i]; 
        texto_int[i+1] = copiatexto[i+1]; 
    }
    
    
    
    for (j = 0; j < tamanho; j++)
    {
        if (texto_int[j] != -61)
        {
            texto_int2[k] = texto_int[j];
            k++;
        }    
    }
   
    for (j = 0; j < tamanho-1; j++)
    {
        if(texto_int2[j] < 0)
        {
            //minisculas especias
            if(texto_int2[j] > -72 && texto_int2[j] < -68)
                texto_int2[j] = 117;
            if(texto_int2[j] > -79 && texto_int2[j] < -71)
                texto_int2[j] = 111;
            if(texto_int2[j] > -85 && texto_int2[j] < -80)
                texto_int2[j] = 105;
            if(texto_int2[j] > -89 && texto_int2[j] < -84)
                texto_int2[j] = 101;
            if(texto_int2[j] > -97 && texto_int2[j] < -89)
                texto_int2[j] = 97;
            //maisculas especiais
            if(texto_int2[j] > -104 && texto_int2[j] < -99)
                texto_int2[j] = 85;
            if(texto_int2[j] > -111 && texto_int2[j] < -103)
                texto_int2[j] = 79;
            if(texto_int2[j] > -117 && texto_int2[j] < -112)
                texto_int2[j] = 73;
            if(texto_int2[j] > -121 && texto_int2[j] < -116)
                texto_int2[j] = 69;
            if(texto_int2[j] > -129 && texto_int2[j] < -121)
                texto_int2[j] = 65;
        }
        
    }
    
    for(i=0;i<k;i++)
        copiatexto[i] = texto_int2[i];
    copiatexto[i] = '\0'; 
    
    tamanho=strlen(copiatexto);
    
    aux = c;
    if(aux < 0)
    {
        //minisculas especias
        if(c > -72 && c < -68)
            c = 117;
        if(c > -79 && c < -71)
            c = 111;
        if(c > -85 && c < -80)
            c = 105;
        if(c > -89 && c < -84)
            c = 101;
        if(c > -97 && c < -89)
            c = 97;
        //maisculas especiais
        if(c > -104 && c < -99)
            c = 85;
        if(c > -111 && c < -103)
            c = 79;
        if(c > -117 && c < -112)
            c = 73;
        if(c > -121 && c < -116)
            c = 69;
        if(c > -129 && c < -121)
            c = 65;    
    }
       
    for(i=0;i<tamanho;i++)
    {
        if(isCaseSensitive)
        {
            if(c == copiatexto[i])
                qtdOcorrencias++;
        }
        else
        {   
            aux = c;
            cont = 0;
            if(aux > 96 && aux < 123)
            {
                aux-=32;
                cont++;
            }
            
            if(aux > 64 && aux < 91 && cont == 0)   
                aux+=32;
            
            copia = aux;
            
            if(c == copiatexto[i] || copia == copiatexto[i])
                qtdOcorrencias++; 
        }
        
    }
    
    return qtdOcorrencias;
    
}

/*
 Q4 = encontrar palavra em texto
 @objetivo
    Pesquisar todas as ocorrências de uma palavra em um texto
 @entrada
    uma string texto base (strTexto), uma string strBusca e um vetor de inteiros (posicoes) que irá guardar as posições de início e fim de cada ocorrência da palavra (strBusca) no texto base (texto).
 @saida
    Um número n >= 0 correspondente a quantidade de ocorrências encontradas.
    O vetor posicoes deve ser preenchido com cada entrada e saída correspondente. Por exemplo, se tiver uma única ocorrência, a posição 0 do vetor deve ser preenchido com o índice de início do texto, e na posição 1, deve ser preenchido com o índice de fim da ocorrencias. Se tiver duas ocorrências, a segunda ocorrência será amazenado nas posições 2 e 3, e assim consecutivamente. Suponha a string "Instituto Federal da Bahia", e palavra de busca "dera". Como há uma ocorrência da palavra de busca no texto, deve-se armazenar no vetor, da seguinte forma:
        posicoes[0] = 13;
        posicoes[1] = 16;
        Observe que o índice da posição no texto deve começar ser contado a partir de 1.
        O retorno da função, n, nesse caso seria 1;
 */
int q4(char *strTexto, char *strBusca, int posicoes[30]){
    int i,j = 0,n = 0, k = 0,z,x;
    int inicio = 0, fim = 0;
    int cont = 0;
    int qtdOcorrencias = 0;
    
    char str_cpTexto[250];
    int tam = strlen(strTexto);
    int tamanho = strlen(strBusca);
    
   // printf("\ntam : %d,tamanho : %d",tam,tamanho);
    char copiatexto[250];
    int texto_int[250];
    int texto_int2[250];
    
    char copiabusca[50];
    int busca_int[50];
    int busca_int2[50];
    
    for(i=0;i<=tam;i++)
    {
        if(i<tam)
            copiatexto[i] = strTexto[i];
        else 
            copiatexto[i] = '\0';
    }
    
    for (i = 0; copiatexto[i] != '\0'; i+=2){
        texto_int[i] = copiatexto[i]; 
        texto_int[i+1] = copiatexto[i+1]; 
    }
    
    for (j = 0; j < tam; j++)
    {
        if (texto_int[j] != -61)
        {
            texto_int2[k] = texto_int[j];
            k++;
        }    
    }
   
    for (j = 0; j < tam-1; j++)
    {
        if(texto_int2[j] < 0)
        {
            //minisculas especias
            if(texto_int2[j] > -72 && texto_int2[j] < -68)
                texto_int2[j] = 117;
            if(texto_int2[j] > -79 && texto_int2[j] < -71)
                texto_int2[j] = 111;
            if(texto_int2[j] > -85 && texto_int2[j] < -80)
                texto_int2[j] = 105;
            if(texto_int2[j] > -89 && texto_int2[j] < -84)
                texto_int2[j] = 101;
            if(texto_int2[j] > -97 && texto_int2[j] < -89)
                texto_int2[j] = 97;
            if(texto_int2[j] == -89)
                texto_int2[j] = 99;    
            //maisculas especiais
            if(texto_int2[j] > -104 && texto_int2[j] < -99)
                texto_int2[j] = 85;
            if(texto_int2[j] > -111 && texto_int2[j] < -103)
                texto_int2[j] = 79;
            if(texto_int2[j] > -117 && texto_int2[j] < -112)
                texto_int2[j] = 73;
            if(texto_int2[j] > -121 && texto_int2[j] < -116)
                texto_int2[j] = 69;
            if(texto_int2[j] > -129 && texto_int2[j] < -121)
                texto_int2[j] = 65;
            if(texto_int2[j] == -121)
                texto_int2[j] = 67;    
        }
        
    }
    
    for(i=0;i<k;i++)
        copiatexto[i] = texto_int2[i];
    copiatexto[i] = '\0'; 
    
    //printf("\n%s",copiatexto);
    
    k=0;
    for(i=0;i<=tamanho;i++)
    {
        if(i<tamanho)
            copiabusca[i] = strBusca[i];
        else 
            copiabusca[i] = '\0';
    }
    
    for (i = 0; copiabusca[i] != '\0'; i+=2){
        busca_int[i] = copiabusca[i]; 
        busca_int[i+1] = copiabusca[i+1]; 
    }
    
    for (j = 0; j < tamanho; j++)
    {
        if (busca_int[j] != -61)
        {
            busca_int2[k] = busca_int[j];
            k++;
        }    
    }
   
    for (j = 0; j < tamanho-1; j++)
    {
        if(busca_int2[j] < 0)
        {
            //minisculas especias
            if(busca_int2[j] > -72 && busca_int2[j] < -68)
                busca_int2[j] = 117;
            if(busca_int2[j] > -79 && busca_int2[j] < -71)
                busca_int2[j] = 111;
            if(busca_int2[j] > -85 && busca_int2[j] < -80)
                busca_int2[j] = 105;
            if(busca_int2[j] > -89 && busca_int2[j] < -84)
                busca_int2[j] = 101;
            if(busca_int2[j] > -97 && busca_int2[j] < -89)
                busca_int2[j] = 97;
            if(busca_int2[j] == -89)
                busca_int2[j] = 99;
            //maisculas especiais
            if(busca_int2[j] > -104 && busca_int2[j] < -99)
                busca_int2[j] = 85;
            if(busca_int2[j] > -111 && busca_int2[j] < -103)
                busca_int2[j] = 79;
            if(busca_int2[j] > -117 && busca_int2[j] < -112)
                busca_int2[j] = 73;
            if(busca_int2[j] > -121 && busca_int2[j] < -116)
                busca_int2[j] = 69;
            if(busca_int2[j] > -129 && busca_int2[j] < -121)
                busca_int2[j] = 65;
            if(busca_int2[j] == -121)
                busca_int2[j] = 67;
        }
        
    }
    
    for(i=0;i<k;i++)
        copiabusca[i] = busca_int2[i];
    copiabusca[i] = '\0';
    
    //printf("\nbusca : %s\n",copiabusca);
    
    tam = strlen(copiatexto);
    tamanho = strlen(copiabusca);
    //printf("\ntam : %d,tamanho : %d\n",tam,tamanho);
    
    for(i = 0; i<tam; i++)
    {
        if(tamanho == 1)
        {
            if(copiabusca[0] == copiatexto[i]){
                qtdOcorrencias++;
                j = 0; 
                while(j!=2)
                {
                    posicoes[n] = i;
                    posicoes[n+1] = i; 
                    n++;
                    j++;
                }
            }
        }
        else 
        {
            x = i;
            for(z=0;z<=tamanho;z++)
            {
                
                if(z==0)
                    inicio = x+1;
                if(z == tamanho - 1)
                    fim = x+1;
                    
                if(z<tamanho)
                {
                    str_cpTexto[z] = copiatexto[x];
                }
                else
                    str_cpTexto[z] = '\0';
                x++;
                
            }
            //printf("\ninicio : %d, fim : %d\n",inicio,fim);
            cont = 0; 
            for(z=0;z<tamanho;z++)
            {
                if(str_cpTexto[z] == copiabusca[z])
                {
                    cont++;
                } 
            }
            
            
            if(cont == tamanho)
            {
                qtdOcorrencias++;
                posicoes[n] = inicio;
                posicoes[n+1] = fim; 
                n=n+2;
                    
                }
                
        }
    }  
    return qtdOcorrencias;

}

/*
 Q5 = inverte número
 @objetivo
    Inverter número inteiro
 @entrada
    uma int num.
 @saida
    Número invertido
 */
int q5(int num){
    
    int i;
    int cont = 0;
    int invertido = 0;
    int pot = 0, result = 0, guardar = 0;
    int aux = 0;
    
    aux = num;
    
    while (aux != 0){
    
        aux = aux / 10;
        cont++;
    }
    
    while (num != 0)
    {
        pot = cont - 1;
        for(i=0; i<cont; i++){
            if(i == 0)
                result = 1;
            else
                result *= 10;
            if(pot == i)                
                guardar = result;
    }
        
        invertido += (num % 10) * guardar;
        num = num / 10;
        cont--;
    }
    
    return invertido;
}


/*
 Q5 = ocorrência de um número em outro
 @objetivo
    Verificar quantidade de vezes da ocorrência de um número em outro
 @entrada
    Um número base (numerobase) e um número de busca (numerobusca).
 @saida
    Quantidade de vezes que número de busca ocorre em número base
 */

int q6(int numerobase, int numerobusca){
    int qtdOcorrencias = 0;
    int i, j, x, fim = 1, comparado = 0;
    int icont = 0, jcont = 0,xcont = 0, pot = 0;
    int base_aux = 0, busca_aux = 0, aux = 0;
    int guardar = 0;
    
    base_aux = numerobase;
    busca_aux = numerobusca;
    guardar = numerobase;
    
    while (base_aux != 0){
    
        base_aux = base_aux / 10;
        icont++;
    }
    
    while (busca_aux != 0){
    
        busca_aux = busca_aux / 10;
        jcont++;
    }
   
    
    for(i=0;i<icont;i++)
    {
        if(jcont == 1){
            if( numerobase % 10  == numerobusca){
                qtdOcorrencias++;
                numerobase = numerobase / 10;
            }
            else 
                numerobase = numerobase / 10;
        }
        else{
            for(j=0; j<jcont; j++){
                    if(j == 0)
                        pot = 1;
                    else
                        pot *= 10;
                
                aux = numerobase % 10;
                comparado += aux * pot;
                numerobase /= 10;
            }
            
            
            if(comparado == numerobusca){
                qtdOcorrencias++;
                guardar = guardar / (10 * pot);
                numerobase = guardar;
                
            }
            else{
                guardar /= 10;
                numerobase = guardar;
                
            }    
            comparado = 0;
            pot = 0;
        }
            
    }
    
    return qtdOcorrencias;
}
