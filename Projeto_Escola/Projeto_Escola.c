// Projeto escola
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>
#define TAM 5
#include "relatorio.h"
#define ERRO_VALID_NOME 4
#define ERRO_VALID_DATA 5
#define ERRO_VALID_SEXO 6
#define ERRO_VALID_CPF 7
#define ERRO_VALID_SEMESTRE 8
#define ERRO_VALID_CODPROF 10

//int contAL = 0, contN = 0, contDT = 0, contCP = 0 , contS = 0, contSM = 0, ContMatAlun = 1000,ContMatProf = 1000, ContCodDisciplina = 10000;//contadores globais
//int Verific = 0; // auxiliar para verificar as validações
//int escolha;// armazena a opcao escolhida no menu

/*typedef struct cadastroAluno{
    
    int matricula;
    char nome [50];
    char dataNascimento [15];
    char cpf [15];
    char sexo;
    
}Aluno;

typedef struct cadastroProfessor{
    
    int matricula;
    char nome [50];
    char dataNascimento [15];
    char cpf [15];
    char sexo;
    
}Professor;

typedef struct cadastroDisciplinas{
    
    char nome [50];
    int codigodisc;
    int semestre;
    int codigoprof;
    char nomeprofdisc[50];
    char nomealundisc[50];
    int codalun;
    int codalundisc;
    
}Disciplina;*/

/*//funcoes de validação de aluno e prof 
int validarNome(Aluno lista_aluno[], int qtd_alunos, Professor lista_professor[], int qtd_professores);
int validarNascimento(Aluno lista_aluno[], int qtd_alunos, Professor lista_professor[], int qtd_professores);
int validarCpf(Aluno lista_aluno[], int qtd_alunos, Professor lista_professor[], int qtd_professores);
int validarSexo(Aluno lista_aluno[], int qtd_alunos,Professor lista_professor[],int qtd_professores);
int geradorMatricula(Aluno lista_aluno[], int qtd_alunos, Professor lista_professor[], int qtd_professores); 
//funcoes de validação de disciplina
int validarNomeDisc(Disciplina lista_disciplina[], int qtd_disciplinas);
int validarSemestre(Disciplina lista_disciplina[], int qtd_disciplinas);
int validarCodProf (Professor lista_professor[], int qtd_professores, Disciplina lista_disciplina[], int qtd_disciplinas);
int geradorCodDisc(Disciplina lista_disciplina[], int qtd_disciplinas);

int Menudeopcoes();

//funcoes aluno/professor
int cadastroalunos_professores (Aluno lista_aluno[], int qtd_alunos, Professor lista_professor[], int qtd_professores);
void listaralunos_professores (Aluno lista_aluno[], int qtd_alunos,Professor lista_professor[], int qtd_professores);
//funcoes aluno/disciplina/professor 
int inseriralundisc(Aluno lista_aluno[], int qtd_alunos, Disciplina lista_disciplina[], int qtd_disciplinas, Disciplina lista_alundisc[], int qtd_alundisc);
int cadastrodisciplinas (Professor lista_professor[], int qtd_professores, Disciplina lista_disciplina[], int qtd_disciplinas);
void listardisciplinas (Disciplina lista_disciplina[], int qtd_disciplinas);
int listardiscalun (Aluno lista_aluno[], int qtd_alunos, Disciplina lista_disciplina[], int qtd_disciplinas, Disciplina lista_alundisc[], int qtd_alundisc);
int excluir_alundisc(Aluno lista_aluno[], int qtd_alunos, Disciplina lista_disciplina[], int qtd_disciplinas,Disciplina lista_alundisc[], int qtd_alundisc);
int ordenar_alunprof_SND(Aluno lista_aluno[], int qtd_alunos, Professor lista_professor[], int qtd_professores);//função que lista aluno/prof por sexo,data de nascimento e nome
void aniversarianteMes(Aluno lista_aluno[], int qtd_alunos, Professor lista_professor[], int qtd_professores);
void listar_alunosmat(Aluno lista_aluno[], int qtd_alunos, Disciplina lista_alundisc[], int qtd_alundisc);
void stringbusca(Aluno lista_aluno[], int qtd_alunos,Professor lista_professor[], int qtd_professores);*/

int main(void)
{
    
    setlocale(LC_ALL, "portuguese");
    int opcao,retorno;
    int fim = 0;
    Aluno lista_aluno[TAM];
    int qtd_alunos = 0;
    Professor lista_professor[TAM];
    int qtd_professores = 0;
    Disciplina lista_disciplina[TAM];
    int qtd_disciplinas = 0;
    Disciplina lista_alundisc[TAM];
    int qtd_alundisc = 0;
    
    
    
    while (!fim){
        
        opcao = Menudeopcoes();
        
        switch (opcao){
            case 0:{ //programa encerrado
                printf("Programa encerrado");
                fim = 1; break;}
            case 1: { //cadastrar alunos
                retorno = cadastroalunos_professores(lista_aluno, qtd_alunos,lista_professor, qtd_professores);
                if (retorno == 2){
                    printf("\nDigite novamente os dados de aluno");
                    retorno = cadastroalunos_professores(lista_aluno, qtd_alunos,lista_professor, qtd_professores);
                }
                if (retorno == 0){
                    printf("Cadastro realizado com sucesso\n");
                    qtd_alunos++;} 
                else {
                    printf("\nERRRO AO REALIZAR CADASTRO PELOS SEGUINTES MOTIVOS : ");
                     if(retorno == ERRO_VALID_NOME)
                        printf("\nErro de validacao no NOME");
                    if(retorno == ERRO_VALID_DATA)
        	            printf("\nErro de validacao na DATA");
        	        if(retorno == ERRO_VALID_CPF) 
        	            printf("\nErro de validacao no CPF");
        	        if(retorno == ERRO_VALID_SEXO)
        	            printf("\nErro de validacao no SEXO");
                    }break;}
            case 2: { // listar alunos
                if(qtd_alunos > 0)
                    listaralunos_professores(lista_aluno, qtd_alunos,lista_professor, qtd_professores);
                else
                    printf("Não existem alunos cadastrados\n");
                break;    
            }
            case 3: { // inserir aluno em uma disciplina
                if(qtd_alunos > 0 && qtd_disciplinas > 0){
                    retorno = inseriralundisc(lista_aluno, qtd_alunos, lista_disciplina, qtd_disciplinas, lista_alundisc, qtd_alundisc);
                    if(retorno == 3){
                        printf("\nSucesso ao inserir aluno ");
                        qtd_alundisc++;break;}
                    else
                        printf("\nErro ao inserir aluno");
                    break;
                }
                else{
                    printf("Não existem alunos ou disciplinas suficientes cadastrados\n");
                    break;} 
                
            }
            case 4: { // cadastrar professores
                retorno = cadastroalunos_professores(lista_aluno, qtd_alunos,lista_professor, qtd_professores);
                if (retorno == 0){
                    printf("Cadastro realizado com sucesso\n");
                    qtd_professores++;} 
                else {
                    printf("\nERRRO AO REALIZAR CADASTRO PELOS SEGUINTES MOTIVOS : ");
                     if(retorno == ERRO_VALID_NOME)
                        printf("\nErro de validacao no NOME");
                    if(retorno == ERRO_VALID_DATA)
        	            printf("\nErro de validacao na DATA");
        	        if(retorno == ERRO_VALID_CPF) 
        	            printf("\nErro de validacao no CPF");
        	        if(retorno == ERRO_VALID_SEXO)
        	            printf("\nErro de validacao no SEXO");
                    }break;}
            case 5: { // listar alunos 
                if(qtd_professores > 0)
                    listaralunos_professores(lista_aluno, qtd_alunos,lista_professor, qtd_professores);
                else
                    printf("Não existem professores cadastrados\n");
                break;  
            }
            case 6: { // cadastrar disciplinas / inserir prof em disciplina
                retorno = cadastrodisciplinas (lista_professor,qtd_professores,lista_disciplina, qtd_disciplinas);
                if (retorno == 0){
                    printf("Cadastro realizado com sucesso\n");
                    qtd_disciplinas++;}
                else {
                    printf("\nERRRO AO REALIZAR CADASTRO PELOS SEGUINTES MOTIVOS : ");
                    if(retorno == ERRO_VALID_NOME)
                        printf("\nErro de validacao no NOME");
                    if(retorno == ERRO_VALID_SEMESTRE)
        	            printf("\nErro de validacao no SEMESTRE");
        	        if(retorno = ERRO_VALID_CODPROF ) 
        	            printf("\nErro de validacao no CODIGO DO PROFESSOR");
        	        }
        	       break;}
            case 7: { // listar disciplinas
                if(qtd_disciplinas > 0)
                    listardisciplinas (lista_disciplina, qtd_disciplinas);
                else
                    printf("Não existem professores cadastrados\n");
                break;}    
            case 8: { // listar alunos cadastrados em uma disciplina
                if(qtd_alunos > 0 && qtd_disciplinas > 0){
                    retorno = listardiscalun (lista_aluno, qtd_alunos, lista_disciplina, qtd_disciplinas, lista_alundisc, qtd_alundisc);
                    if(retorno == 1)
                        printf("\nSucesso ao mostrar alunos cadastrados disciplina");
                    else
                        printf("\nErro ao listar alunos cadastrados em disciplina");
                    break;}
                else{
                    printf("Não existem alunos, disciplinas suficientes cadastrados\n");
                    break;}    
            }
            case 9: {
                if(qtd_alundisc > 0){
                retorno = excluir_alundisc(lista_aluno, qtd_alunos, lista_disciplina, qtd_disciplinas, lista_alundisc, qtd_alundisc);
                if(retorno == 1)
                    printf("\nExclusão realizado com sucesso");
                else
                    printf("\nFalha na exclusão");
                break;}
                else
                    printf("\nNão existem alunos cadastrados em disciplinas");
            }
            case 10: {
                if(qtd_alunos > 0 || qtd_professores > 0){
                     retorno = ordenar_alunprof_SND(lista_aluno, qtd_alunos, lista_professor, qtd_professores);
                    if(retorno = 1)
                        printf("\nListagem feita com sucesso");
                    else
                        printf("\nErro ao listagem de alunos/professores");
                }
                else
                    printf("\nNão existem alunos cadastrados");
                break;    
            }
            case 11:{
                if(qtd_alunos > 0 || qtd_professores > 0)
                    aniversarianteMes(lista_aluno, qtd_alunos, lista_professor, qtd_professores);
                else 
                    printf("\nNão existem Alunos/Professores cadastrados");
                break;    
            }
            case 12: {
                if(qtd_alunos > 0 && qtd_disciplinas > 0)
                    listar_alunosmat(lista_aluno, qtd_alunos, lista_alundisc, qtd_alundisc);
                else 
                    printf("\nNão existem alunos/disciplinas cadastradas");
                break;    
            }
            case 13: {
                if(qtd_alunos > 0 || qtd_professores > 0)
                    stringbusca(lista_aluno, qtd_alunos, lista_professor, qtd_professores);
                else
                    printf("\nNão existem alunos/professores cadastrados");
                break;    
            }
            default: {
                printf("\nOpção Inválida\n");
            }
        }
}
    return 0;
}

/*int Menudeopcoes(){
    printf("\n\nOpcoes disponiveis");
    printf("\n0 - Sair");
    printf("\n1 - Cadastrar Aluno");
    printf("\n2 - Listar Alunos");
    printf("\n3 - Inserir aluno disciplina");
    printf("\n4 - Cadastrar Professor");
    printf("\n5 - Listar Professores");
    printf("\n6 - Cadastrar Disciplina / Inserir prof disciplina");
    printf("\n7 - Listar Disiplinas sem alunos");
    printf("\n8 - Listar Disiplina e alunos cadastrados");
    printf("\n9 - Excluir aluno de uma disciplina");
    printf("\n10 - Listar alunos  / Listar professores por sexo/data/nome");
    printf("\n11 - Listar aniversariantes do mês aluno/professor");
    printf("\n12 - Listar alunos matriculados em menos de 3 disciplinas");
    printf("\n13 - Lista de alunos/professor a partir de uma string de busca");
    printf("\nDigite uma opcao : ");
    scanf(" %d",&escolha);
    getchar();
    
    return escolha;
}

int cadastroalunos_professores(Aluno lista_aluno[], int qtd_alunos, Professor lista_professor[], int qtd_professores){ // funcao que recebe o cadastro de alunos e professores
    //variaveis para modificar o aluno atual;
    int aux = 0, fim = 0, opcao = 0, ant = 0, i;
    //cadastro alunos
    Verific = 0;
    if(escolha == 1){
        
        printf("\n******* Bem vindo a central de cadastro de alunos *******\n");
        printf("Matricula sera gerada automaticamente caso os dados estiverem corretos\n");
        
        printf("Digite o nome: ");
        fgets(lista_aluno[qtd_alunos].nome, 50, stdin);
        validarNome(lista_aluno, qtd_alunos, lista_professor, qtd_professores);
        
        printf("Digite o sexo: ");
        scanf(" %c",&lista_aluno[qtd_alunos].sexo);
        getchar();
        validarSexo(lista_aluno, qtd_alunos, lista_professor,  qtd_professores);
        
        printf("Digite a data de nascimento no formato ' 08/06/2001 ' : ");
        fgets(lista_aluno[qtd_alunos].dataNascimento, 15,stdin);
        size_t ln = strlen(lista_aluno[qtd_alunos].dataNascimento) - 1; 
        if (lista_aluno[qtd_alunos].dataNascimento[ln] == '\n')
            lista_aluno[qtd_alunos].dataNascimento[ln] = '\0';
        validarNascimento(lista_aluno, qtd_alunos, lista_professor,  qtd_professores);
        
        printf("Digite o CPF: ");
        fgets(lista_aluno[qtd_alunos].cpf, 15,stdin);
        validarCpf(lista_aluno, qtd_alunos, lista_professor,  qtd_professores);
        
        if(Verific == 0){
            geradorMatricula(lista_aluno, qtd_alunos, lista_professor,  qtd_professores);
            
            
            printf("\n Digite 1 se deseja acessar o menu de modificação do aluno , caso contrario digite outro numero : ");
            scanf("%d",&aux);
            getchar();
            
            if(aux == 1){
                while(!fim){
                
                    printf("\n*******Menu de modificação principal*******");
                    printf("\n Digite 0 para sair do menu de modificação");
                    printf("\n Digite 1 se deseja excluir o aluno atual");
                    printf("\n Digite 2 se deseja alterar o cadastro do aluno");
                    printf("\n Escolha uma opcao : ");
                    scanf("%d",&opcao);
                    getchar();
            
                    switch (opcao){
                            case 0: {
                                printf("\nSaida do menu modificação retornando ao menu de opções\n");
                                return 0;fim = 1; break;}
                            case 1: {
                                for(i=0;i<50;i++)
                                    lista_aluno[qtd_alunos].nome[i] = -1;
                                for(i=0;i<15;i++){
                                    lista_aluno[qtd_alunos].dataNascimento[i] = -1;
                                    lista_aluno[qtd_alunos].cpf[i] = -1;}
                                lista_aluno[qtd_alunos].sexo = -1;      
                                    return 2;}
                                
                            case 2: {
                                printf("\nAltere o cadastro do aluno atual\n");
                                return 2;
                            }    
                        }    
                        
                    }}
            else
                return 0;}
        else 
            return 1;
        
    }
    //inserir professores    
    else {
        
        printf("\n******* Bem vindo a central de cadastro de professores *******\n");
        printf("Matricula sera gerada automaticamente caso os dados estiverem corretos\n");
        
        printf("Digite o nome: ");
        fgets(lista_professor[qtd_professores].nome, 50, stdin);
        validarNome(lista_aluno, qtd_alunos,lista_professor, qtd_professores);
        
        printf("Digite o sexo: ");
        scanf(" %c",&lista_professor[qtd_professores].sexo);
        getchar();
        validarSexo(lista_aluno, qtd_alunos,lista_professor, qtd_professores);
        
        printf("Digite a data de nascimento no formato ' 08/06/2000 ' : ");
        fgets(lista_professor[qtd_professores].dataNascimento, 15,stdin);
        size_t ln = strlen(lista_professor[qtd_professores].dataNascimento) - 1; 
        if (lista_professor[qtd_professores].dataNascimento[ln] == '\n')
            lista_professor[qtd_professores].dataNascimento[ln] = '\0';
        validarNascimento(lista_aluno, qtd_alunos,lista_professor, qtd_professores);
        
        printf("Digite o CPF: ");
        fgets(lista_professor[qtd_professores].cpf, 15,stdin);
        validarCpf(lista_aluno, qtd_alunos,lista_professor, qtd_professores);
        
        if(Verific == 0){
            geradorMatricula(lista_aluno, qtd_alunos,lista_professor, qtd_professores);
            return 0;}
        else 
            return 1;
        
    }
}

int cadastrodisciplinas(Professor lista_professor [], int qtd_professores , Disciplina lista_disciplina[], int qtd_disciplinas){
        Verific = 0;
        int i;
    
        printf("\n******* Bem vindo a central de cadastro de disciplinas *******\n");
        printf("O codigo da disciplina sera gerado automaticamente caso os dados estiverem corretos\n");
        
        printf("Digite o nome: ");
        fgets(lista_disciplina[qtd_disciplinas].nome, 50, stdin);
        validarNomeDisc(lista_disciplina, qtd_disciplinas);
        
        printf("Digite o semestre no formato de um dígito '1': ");
        scanf("%d",&lista_disciplina[qtd_disciplinas].semestre);
        getchar();
        validarSemestre(lista_disciplina, qtd_disciplinas);
        
        printf("Digite o codigo do professor da disciplina no formato '1000': ");
        scanf("%d",&lista_disciplina[qtd_disciplinas].codigoprof);
        getchar();
        validarCodProf(lista_professor, qtd_professores, lista_disciplina, qtd_disciplinas);
        
        if(Verific == 0){
            geradorCodDisc(lista_disciplina, qtd_disciplinas);
            return 0;}
        else 
            return 1;
}

int inseriralundisc(Aluno lista_aluno[], int qtd_alunos, Disciplina lista_disciplina[], int qtd_disciplinas, Disciplina lista_alundisc[], int qtd_alundisc){
        Verific = 0;
        int i, cont = 0;
        
        if(qtd_alundisc == 0){
        int x;
        for(x = 0; x < TAM; x++)
            lista_alundisc[x].codalundisc = -1;} //inicializando o vetor
            
        printf("\n Digite a matricula do aluno que deseja inserir na disciplina : ");
        scanf("%d", &lista_alundisc[qtd_alundisc].codalun);
        
        printf("\n Digite o codigo da disciplina : ");
        scanf("%d", &lista_alundisc[qtd_alundisc].codalundisc);
        
        for(i=0;i<qtd_alunos;i++){
            if(lista_aluno[i].matricula == lista_alundisc[qtd_alundisc].codalun){
                strcpy(lista_alundisc[qtd_alundisc].nomealundisc,lista_aluno[i].nome);
                cont++;}    
        }
        
        for(i=0;i<qtd_disciplinas;i++){
            if(lista_disciplina[i].codigodisc == lista_alundisc[qtd_alundisc].codalundisc)
                cont++;} 
                
        if(cont == 2)
            return 3;
        return 0;       
}

void listar_alunosmat(Aluno lista_aluno[], int qtd_alunos, Disciplina lista_alundisc[], int qtd_alundisc){
    int i,j,x;
    int codalun;
    int cont = 0;
    
    for(i = 0; i < qtd_alundisc; i++){
        cont = 0;
        codalun = lista_alundisc[i].codalun; 
        for(j = 0; j < qtd_alundisc; i++){
            if(codalun = lista_alundisc[j].codalun)
                cont++;
        }
        if(cont < 3)
            printf("\nAluno %d : %s",i,lista_alundisc[j].nomealundisc);
    }
}

int excluir_alundisc(Aluno lista_aluno[], int qtd_alunos, Disciplina lista_disciplina[], int qtd_disciplinas, Disciplina lista_alundisc[], int qtd_alundisc){
    int i, j, x, y,k;
    int matalunex;
    int coddiscex;
    int cont = 0;
    
    printf("\nDigite a matricula do aluno que deseja excluir ");
    scanf("%d", &matalunex);
    
    printf("\nDigite o codigo da disciplina ");
    scanf("%d", &coddiscex);
    
    for(i = 0 ; i < qtd_disciplinas; i++){
        for(j = 0 ; j < qtd_alundisc; j++){
            if (lista_disciplina[i].codigodisc == coddiscex){
                if(lista_alundisc[j].codalun == matalunex){
                    if(qtd_alundisc == 1){
                        for(x = 0 ; x < 50; x++)
                            lista_alundisc[j].nomealundisc[x] = 0; // zerando nome de aluno guardado na disciplina
                        lista_alundisc[j].codalundisc = -1; // zerando codigo do aluno cadastrado na discipllina
                        qtd_alundisc--; // decrementando contador de quantidade de alunos cadastrados em uma disciplina
                        return 1;
                    }
                    else{
                        for(y = j; y < TAM ;y++){
                            if(lista_alundisc[y+1].codalundisc == -1){
                                for(x = 0 ; x < 50; x++)
                                    lista_alundisc[y].nomealundisc[x] = lista_alundisc[y+1].nomealundisc[x];
                                lista_alundisc[y].codalundisc = lista_alundisc[y+1].codalundisc;
                                qtd_alundisc--;
                                return 1;}
                            for(x = 0 ; x < 50; x++)
                                    lista_alundisc[y].nomealundisc[x] = lista_alundisc[y+1].nomealundisc[x];
                                lista_alundisc[y].codalundisc = lista_alundisc[y+1].codalundisc;
                        }    
                    }        
                }
        }}
    }
    return 0;
}

int validarSemestre(Disciplina lista_disciplina[], int qtd_disciplinas){
    contSM = 0;
    
    if(lista_disciplina[qtd_disciplinas].semestre <= 0  || lista_disciplina[qtd_disciplinas].semestre > 2){
        contSM = 1;
        return Verific++;}
    
    return 0;

}

int validarCodProf(Professor lista_professor[], int qtd_professores, Disciplina lista_disciplina[], int qtd_disciplinas){
    contCP = 0;
    int i, cont = 0;
    
    if(lista_disciplina[qtd_disciplinas].codigoprof <= 1000 || lista_disciplina[qtd_disciplinas].codigoprof > 1999){
        contCP++;
        return Verific++;}
    
    for(i=0;i<qtd_professores;i++){
        if(lista_professor[i].matricula == lista_disciplina[qtd_disciplinas].codigoprof){
            strcpy(lista_disciplina[qtd_disciplinas].nomeprofdisc,lista_professor[i].nome);
            cont++;}
    }
    
    if(cont == 0){
        contCP++;
        return Verific++;}
    return 0;    
}

int validarNome(Aluno lista_aluno[], int qtd_alunos, Professor lista_professor[], int qtd_professores){
    contN = 0;
    if(escolha == 1){
        int i;
        int tamanho;
        tamanho = strlen(lista_aluno[qtd_alunos].nome);
        if(tamanho > 50){
            contN = 1;
            return Verific++;}
        return 0;
    }
    else{
        int i;
        int tamanho;
        tamanho = strlen(lista_professor[qtd_professores].nome);
        if(tamanho > 50){
            contN = 1;
            return Verific++;}
        return 0;
    }
}

int validarNomeDisc(Disciplina lista_disciplina[], int qtd_disciplinas){
        int i;
        int tamanho;
        tamanho = strlen(lista_disciplina[qtd_disciplinas].nome);
        if(tamanho > 50){
            contN = 1;
            return Verific++;}
        return 0;
}

int validarNascimento(Aluno lista_aluno[], int qtd_alunos, Professor lista_professor[], int qtd_professores){
    int ContDT = 0;
    if(escolha == 1){
        int i;
        int dia,mes,ano,bissexto = 0;
        int tamanho;
        tamanho = strlen(lista_aluno[qtd_alunos].dataNascimento);
        if(tamanho != 10){ // se o tamanho do nome esta correto
            contDT = 1;
            return Verific++;
        }   
        else{
            for(i=0;i<10;i++){
                if(i == 2 || i == 5){ 
                    if(lista_aluno[qtd_alunos].dataNascimento[2] != '/' || lista_aluno[qtd_alunos].dataNascimento[5] != '/') // verifica se a posicao das barras tem realmente barras
                        contDT = 1;}
                else {
                    if((lista_aluno[qtd_alunos].dataNascimento[i]-'0') < 0) // verifica se contem algo que não seja numeros nas outras posicoes
                        contDT = 1;}
            }
        }
        //calculo do dia
        dia = (lista_aluno[qtd_alunos].dataNascimento[0]-'0') * 10;
        dia += lista_aluno[qtd_alunos].dataNascimento[1]-'0';
        //calculo do mes
        mes = (lista_aluno[qtd_alunos].dataNascimento[3]-'0') * 10;
        mes += lista_aluno[qtd_alunos].dataNascimento[4]-'0';
        //calculo do ano 
        ano = (lista_aluno[qtd_alunos].dataNascimento[6]-'0') * 1000;
        ano += (lista_aluno[qtd_alunos].dataNascimento[7]-'0') * 100;
        ano += (lista_aluno[qtd_alunos].dataNascimento[8]-'0') * 10;
        ano += lista_aluno[qtd_alunos].dataNascimento[9]-'0';
        
        // verifica se o dia é entre 1 e 31.
        if(dia < 1  || dia > 31)
            contDT = 1;
        
        // verifica se o mês é entre 1 e 12    
        if(mes < 1 || mes > 12)
            contDT = 1;
        
        // verifica se o ano esta no intervalo entre 1900 e 2100
        if(ano < 1900 || ano > 2100)
            contDT = 1;
        
        // verifica se mês for 04, 06, 09 ou 11, dia pode ser no máximo 30;
        if(mes == 4 || mes == 6 || mes == 9 || mes == 11)
            if(dia > 30)
                contDT = 1;
        
        //calculo do ano bissexto
        if(ano % 4 == 0 && ano % 100 != 0)
            bissexto = 1;
        if(ano % 4 == 0 && ano % 400 == 0 && ano % 100 == 0)
            bissexto = 1;   
        
        if(bissexto) { // verifica se ano for bissexto e mês for 02, dia pode ser no máximo 29.
            if(mes == 2)
                if(dia > 29)
                    contDT = 1;
                }
        
        else { // verifica se mês for 02, dia pode ser no máximo 28;
            if(mes == 2)
                if(dia > 28)
                    contDT = 1;
            }
        if(contDT == 1)
            return Verific++;
        return 0;
    }
    else{
        int i;
        int tamanho;
        int dia,mes,ano,bissexto = 0;
        tamanho = strlen(lista_professor[qtd_professores].dataNascimento);
        if(tamanho != 10){ // se o tamanho do nome esta correto
            contDT = 1;
            return Verific++;
        }
        else{
            for(i=0;i<10;i++){
                if(i == 2 || i == 5){ 
                    if(lista_professor[qtd_professores].dataNascimento[2] != '/' || lista_professor[qtd_professores].dataNascimento[5] != '/') // verifica se a posicao das barras tem realmente barras
                        contDT = 1;}
                else {
                    if((lista_professor[qtd_professores].dataNascimento[i]-'0') < 0) // verifica se contem algo que não seja numeros nas outras posicoes
                        contDT = 1;}
            }
        }
        
        //calculo do dia
        dia = (lista_professor[qtd_professores].dataNascimento[0]-'0') * 10;
        dia += lista_professor[qtd_professores].dataNascimento[1]-'0';
        //calculo do mes
        mes = (lista_professor[qtd_professores].dataNascimento[3]-'0') * 10;
        mes += lista_professor[qtd_professores].dataNascimento[4]-'0';
        //calculo do ano 
        ano = (lista_professor[qtd_professores].dataNascimento[6]-'0') * 1000;
        ano += (lista_professor[qtd_professores].dataNascimento[7]-'0') * 100;
        ano += (lista_professor[qtd_professores].dataNascimento[8]-'0') * 10;
        ano += lista_professor[qtd_professores].dataNascimento[9]-'0';
        
        // verifica se o dia é entre 1 e 31.
        if(dia < 1  || dia > 31)
            contDT = 1;
        
        // verifica se o mês é entre 1 e 12    
        if(mes < 1 || mes > 12)
            contDT = 1;
        
        // verifica se o ano esta no intervalo entre 1900 e 2100
        if(ano < 1900 || ano > 2100)
            contDT = 1;
        
        // verifica se mês for 04, 06, 09 ou 11, dia pode ser no máximo 30;
        if(mes == 4 || mes == 6 || mes == 9 || mes == 11)
            if(dia > 30)
                contDT = 1;
        
        //calculo do ano bissexto
        if(ano % 4 == 0 && ano % 100 != 0)
            bissexto = 1;
        if(ano % 4 == 0 && ano % 400 == 0 && ano % 100 == 0)
            bissexto = 1;   
        
        if(bissexto) { // verifica se ano for bissexto e mês for 02, dia pode ser no máximo 29.
            if(mes == 2)
                if(dia > 29)
                    contDT = 1;
                }
        
        else { // verifica se mês for 02, dia pode ser no máximo 28;
            if(mes == 2)
                if(dia > 28)
                    contDT = 1;
            }
            
        if(contDT == 1)
            return Verific++;
        return 0;
    }
}

int validarCpf(Aluno lista_aluno[], int qtd_alunos, Professor lista_professor[], int qtd_professores){
    contCP = 0;
    if(escolha == 1 ){
        int i;
        int tamanho;
        int valid1, soma1 = 0, aux1 = 10;
        int valid2, soma2 = 0, aux2 = 11;
        char dg1,dg2;
        
        tamanho = strlen(lista_aluno[qtd_alunos].cpf);
        if(tamanho != 14){ // verifica se o tamanho do cpf esta correto
            contCP = 1;
            return Verific++;
        }
        else{
            for(i=0;i<14;i++){
               if (i == 3 || i == 7 ||i == 11){ 
                    if(lista_aluno[qtd_alunos].cpf[3] != '.' || lista_aluno[qtd_alunos].cpf[7] != '.')
                        contCP = 1;
                    if(lista_aluno[qtd_alunos].cpf[11] != '-')
                        contCP = 1;}
                else{
                    if ((lista_aluno[qtd_alunos].cpf[i]-'0') < 0 )
                        contCP = 1;}
                        
            }}
          
        for(i=0;i<11;i++){ // validação do primeiro digito
                if((lista_aluno[qtd_alunos].cpf [i]) != '.'){
                    soma1 += (lista_aluno[qtd_alunos].cpf[i]-'0') * aux1;
                    aux1 = aux1 - 1;}
        }  
        
        dg1 = lista_aluno[qtd_alunos].cpf[12]-'0'; // capturando o primero digito verificador
        valid1 = (soma1 * 10) % 11;
        
        if(valid1 == 10) // se o resto da divisão for igual a 10 só capturamos o 0 
            valid1 = 0;
        
        if(valid1 != dg1) // verificando se o primeiro digito verificador é igual ao valid1 , primeira etapa de verificação concluida
            contCP = 1;
            
        for(i=0;i<13;i++){ // validação do segundo digito
                if(lista_aluno[qtd_alunos].cpf [i] != '.' || lista_aluno[qtd_alunos].cpf [i] != '-')
                    soma2 += (lista_aluno[qtd_alunos].cpf[i]-'0') * aux2;
                aux2 = aux2 - 1; 
        }   
        
        dg2 = lista_aluno[qtd_alunos].cpf[13]-'0'; // capturando o segundo digito verificador
        valid2 = (soma2 * 10) % 11;
        
        if(valid2 == 10) // se o resto da divisão for igual a 10 só capturamos o 0 
            valid2 = 0;
            
        if(valid2 != dg2) // verificando se o segundo digito verificador é igual ao valid2 , segunda etapa de verificação concluida
            contCP = 1;
        
        if(contCP == 1)
            return Verific++;
        return 0;
    }
    else {
        int i;
        int tamanho;
        int valid1, soma1 = 0, aux1 = 10;
        int valid2, soma2 = 0, aux2 = 11;
        char dg1,dg2;
        
        tamanho = strlen(lista_professor[qtd_professores].cpf);
        if(tamanho != 14){ // verifica se o tamanho do cpf esta correto
            contCP = 1;
            return Verific++;
        }
        else{
            for(i=0;i<14;i++){
               if (i == 3 || i == 7 ||i == 11){ 
                    if(lista_professor[qtd_professores].cpf[3] != '.' || lista_professor[qtd_professores].cpf[7] != '.')
                        contCP = 1;
                    if(lista_professor[qtd_professores].cpf[11] != '-')
                        contCP = 1;}
                else{
                    if ((lista_professor[qtd_professores].cpf[i]-'0') < 0 )
                        contCP = 1;}
                        
            }}
          
        for(i=0;i<11;i++){ // validação do primeiro digito
                if((lista_professor[qtd_professores].cpf [i]) != '.'){
                    soma1 += (lista_professor[qtd_professores].cpf[i]-'0') * aux1;
                    aux1 = aux1 - 1;}
        }  
        
        dg1 = lista_professor[qtd_professores].cpf[12]-'0'; // capturando o primero digito verificador
        valid1 = (soma1 * 10) % 11;
        
        if(valid1 == 10) // se o resto da divisão for igual a 10 só capturamos o 0 
            valid1 = 0;
        
        if(valid1 != dg1) // verificando se o primeiro digito verificador é igual ao valid1 , primeira etapa de verificação concluida
            contCP = 1;
            
        for(i=0;i<13;i++){ // validação do segundo digito
                if(lista_professor[qtd_professores].cpf [i] != '.' || lista_professor[qtd_professores].cpf [i] != '-')
                    soma2 += (lista_professor[qtd_professores].cpf[i]-'0') * aux2;
                aux2 = aux2 - 1; 
        }   
        
        dg2 = lista_professor[qtd_professores].cpf[13]-'0'; // capturando o segundo digito verificador
        valid2 = (soma2 * 10) % 11;
        
        if(valid2 == 10) // se o resto da divisão for igual a 10 só capturamos o 0 
            valid2 = 0;
            
        if(valid2 != dg2) // verificando se o segundo digito verificador é igual ao valid2 , segunda etapa de verificação concluida
            contCP = 1;
        
        if(contCP == 1)
            return Verific++;
        return 0;
    }
}

int validarSexo(Aluno lista_aluno[], int qtd_alunos, Professor lista_professor[], int qtd_professores){
    contS = 0 ;
    if(escolha == 1){
        
        if(lista_aluno[qtd_alunos].sexo == 'M' || lista_aluno[qtd_alunos].sexo == 'F' || lista_aluno[qtd_alunos].sexo == 'm' || lista_aluno[qtd_alunos].sexo == 'f' || lista_aluno[qtd_alunos].sexo == 'o' || lista_aluno[qtd_alunos].sexo == 'O')
            contS = 0;
        else
            contS = 1;
        
        if(contS == 1)
            return Verific++;
        return 0;  
    }
    else {
        if(lista_professor[qtd_professores].sexo == 'M' || lista_professor[qtd_professores].sexo == 'F' || lista_professor[qtd_professores].sexo == 'm' || lista_professor[qtd_professores].sexo == 'f' || lista_professor[qtd_professores].sexo == 'o' || lista_professor[qtd_professores].sexo == 'O')
            contS = 0;
        else
            contS = 1;
        
        if(contS == 1)
            return Verific++;
        return 0;  
    }
}

int geradorMatricula(Aluno lista_aluno[], int qtd_alunos, Professor lista_professor[], int qtd_professores){
    int i;
    if(escolha == 1){
        ContMatAlun++;
        lista_aluno[qtd_alunos].matricula = ContMatAlun;
        getchar();
    }
    else{
        ContMatProf++;
        lista_professor[qtd_professores].matricula = ContMatProf;
        getchar();
    }    
        
    return 0;    
}

int geradorCodDisc(Disciplina lista_disciplina[], int qtd_disciplinas){
    ContCodDisciplina++;
    lista_disciplina[qtd_disciplinas].codigodisc = ContCodDisciplina;
    return 0;
}

void listaralunos_professores(Aluno lista_aluno[], int qtd_alunos, Professor lista_professor[], int qtd_professores){
        if(escolha == 2){
            printf("\n****** Alunos Cadastrados ******#\n");
            int i;
        for (i = 0; i < qtd_alunos; i++){
            printf("-----\n");
            printf("Matrícula: %d\n", lista_aluno[i].matricula);
            printf("Nome: %s", lista_aluno[i].nome);
            printf("Sexo: %c\n", lista_aluno[i].sexo);
            printf("Data Nascimento: %s\n", lista_aluno[i].dataNascimento);
            printf("CPF: %s\n", lista_aluno[i].cpf);
        }
        printf("-----\n\n");
        }
        else{
            printf("\n****** Professores Cadastrados ******#\n");
            int i;
            for (i = 0; i < qtd_professores; i++){
                printf("-----\n");
                printf("Matrícula: %d\n", lista_professor[i].matricula);
                printf("Nome: %s", lista_professor[i].nome);
                printf("Sexo: %c\n", lista_professor[i].sexo);
                printf("Data Nascimento: %s\n", lista_professor[i].dataNascimento);
                printf("CPF: %s\n", lista_professor[i].cpf);
            }
            printf("-----\n\n");
            }
    }
    
void stringbusca(Aluno lista_aluno[], int qtd_alunos,Professor lista_professor[], int qtd_professores){
    int op;
    int i,j,x;
    char busca[10];
    int mesal[qtd_alunos];
    int mespr[qtd_alunos];
    int cont = 0 , contl = 0, aux = 0;
    int tamanho;
    
    printf("\nDigite 1 se deseja consultar os Alunos e 2 para os Professores : ");
    scanf("%d",&op);
    getchar();
    
    if(op == 1 && qtd_alunos > 0){
        
        printf("\nDigite ao menos 3 caracteres para buscar Aluno(s) : ");
        scanf("%s",busca);
        
        tamanho = strlen(busca);
        printf("\ntamanho : %d",tamanho);
        cont++;
        
            if(tamanho >= 3){
                for(i = 0; i < tamanho; i++){
                    if(i == 0)
                        j = 0;
                    else
                        j = i + 1;
                    for(; j < qtd_alunos; j++){
                        contl = 0;
                        for(x = 0 ; x < qtd_alunos; x++){
                            if(busca[i] == lista_aluno[j].nome[x] && contl == 0){
                                printf("\nAluno : %s",lista_aluno[j].nome);
                                contl++;}
                        }
                    }
                }
            }
    }
    if(op == 2 && qtd_professores > 0){
        
        printf("\nDigite ao menos 3 caracteres para buscar Professor(es) : ");
        scanf("%s",busca);
        
        tamanho = strlen(busca);
        cont++;
        
        printf("\n*******Busca Professor*********\n");
            if(tamanho >= 3){
                for(i = 0; i < tamanho; i++){
                    if(i == 0)
                        j = 0;
                    else
                        j = i + 1;
                    for(; j < qtd_professores; j++){
                        contl = 0;
                        for(x = 0 ; x < qtd_professores; x++){
                            if(busca[i] == lista_professor[j].nome[x] && contl == 0){
                                printf("\nProfessor : %s",lista_professor[j].nome);
                                printf("-----");
                                contl++;}
                        }
                    }
                }
            }
    }
    
    if(cont == 0)
        printf("\nOpção inválida");
    
}

int ordenar_alunprof_SND(Aluno lista_aluno[], int qtd_alunos, Professor lista_professor[], int qtd_professores){
    int op = 0, fim = 0, opcao = 0;
    int i, j, x, z,y, menor,cont = 0;
    char copianomes[qtd_alunos][50];
    char aux[qtd_alunos];
    char copiadatas[qtd_alunos][15];
    char auxCP[qtd_alunos][15];
    int dia[qtd_alunos], mes[qtd_alunos], ano[qtd_alunos];
    int auxdata, contA = 0,contM = 0,contD = 0;
    
    
    printf("\nDigite 1 para acessar o menu de listagem de Aluno");
    printf("\nDigite 2 para acessar o menu de listagem de Professor\n");
    scanf("%d",&op);
    getchar();
    
    if(op == 1 && qtd_alunos > 0){
        while(!fim){
            
            printf("\n*******Menu de Listagem de aluno*******");
            printf("\n Digite 0 para sair do menu de listagem");
            printf("\n Digite 1 para ordenar alunos pelo sexo");
            printf("\n Digite 2 para ordenar alunos pelo nome");
            printf("\n Digite 3 para ordenar alunos pela data de nascimento");
            printf("\n Escolha uma opcao : ");
            scanf("%d",&opcao);
            getchar(); 
            
            switch(opcao){
            case 0:{ 
                printf("\nSaindo do menu de listagem voltando para o Menu Principal");
                return 0; break;}
            case 1: { 
                printf("\n****** Aluno(s) do sexo Masculino ******");
                for(i=0;i<qtd_alunos;i++){
                    if(lista_aluno[i].sexo == 'M' || lista_aluno[i].sexo == 'm'){
                        printf("\nNome do aluno : %s",lista_aluno[i].nome);
                        printf("-----\n");}
                }
                printf("\n****** Aluno(s) do sexo Feminino ******");
                for(i=0;i<qtd_alunos;i++){
                    if(lista_aluno[i].sexo == 'F' || lista_aluno[i].sexo == 'f'){
                        printf("\nNome do aluno : %s",lista_aluno[i].nome);
                        printf("-----\n");}
                }
                fim = 1; return 1; break;
                }
            case 2: {
                for(j = 0; j < qtd_alunos;j++)
                    for(i = 0; i<50;i++)
                        copianomes[j][i] =  lista_aluno[j].nome[i];
                
                for(i = 0; i < qtd_alunos - 1; i++){
                    
                x = 0;
                menor = i;
                for(j = i + 1; j < qtd_alunos; j++)
                {
                    x = 0;
                    while(copianomes[menor][x] == copianomes[j][x])
                    {
                            x++;
                    } 
                    if(copianomes[menor][x] > copianomes[j][x])
                        menor = j;
                    
                }
                if(menor != i){
                    strcpy(aux, copianomes[menor]);
                    strcpy(copianomes[menor], copianomes[i]);
                    strcpy(copianomes[i], aux);
                }
            }
                printf("\n****** Aluno(s) Ordenados por nome ******\n");
                for(i = 0; i < qtd_alunos; i++){
                    printf("Nome do aluno %d: %s%c", i + 1,copianomes[i], TAM);
                    printf("-----\n");}
                fim = 1 ; return 1; break;   
            }
            
            case 3: {
                for(j = 0; j < qtd_alunos;j++)
                    for(i = 0; i<15;i++)
                        copiadatas[j][i] =  lista_aluno[j].dataNascimento[i];
                
                if(qtd_alunos == 1){
                    for(i = 0; i<15;i++){
                        printf("\nAluno %d = %s%c", i + 1, copiadatas[i], 15);
                        return 1;break;} 
                }
                
                for(i = 0; i < qtd_alunos; i++){
                    //calculo do dia
                    dia[i] = (copiadatas[i][0]-'0') * 10;
                    dia[i]+= copiadatas[i][1]-'0';
                    //calculo do mes
                    mes[i] = (copiadatas[i][3]-'0') * 10;
                    mes[i] += copiadatas[i][4]-'0';
                    //calculo do ano 
                    ano[i] = (copiadatas[i][6]-'0') * 1000;
                    ano[i] += (copiadatas[i][7]-'0') * 100;
                    ano[i] += (copiadatas[i][8]-'0') * 10;
                    ano[i] += copiadatas[i][9]-'0';
                    
                }
                
                for(j = 0; j < qtd_alunos; j++){
                    cont = 0,contA = 0,contM = 0, contD = 0;
                    for(i = 0; i < qtd_alunos - 1; i++){
                        if((ano[i] > ano[i + 1]) && cont == 0){
                            contA++;
                            for(x = 0; x < 15; x++){
                                auxCP[i][x] = copiadatas[i][x];
                                copiadatas[i][x] = copiadatas[i + 1][x];
                                copiadatas[i + 1][x] = auxCP[i][x];
                                cont++;
                            }
                        }
                        if(ano[i] == ano[i + 1]){
                            if(mes[i] > mes[i + 1] && cont == 0){
                                contD++;
                                for(x = 0; x < 15; x++){
                                    auxCP[i][x] = copiadatas[i][x];
                                    copiadatas[i][x] = copiadatas[i + 1][x];
                                    copiadatas[i + 1][x] = auxCP[i][x];
                                    cont++;
                                }
                            }
                            if(mes[i] == mes[i + 1]){
                                if(dia[i] > dia[i + 1] && cont == 0){
                                    contD++;
                                    for(x = 0; x < 15; x++){
                                    auxCP[i][x] = copiadatas[i][x];
                                    copiadatas[i][x] = copiadatas[i + 1][x];
                                    copiadatas[i + 1][x] = auxCP[i][x];
                                    cont++;
                                    }
                                }    
                            }
                        }   
                
                    if(cont != 0){
                        if(contA == 1 || contM == 1 || contD == 1){
                        for(z = 0; z != 1; z++){
                            auxdata = ano[z];
                            ano[z] = ano[z + 1];
                            ano[z + 1] = auxdata;
                            auxdata = mes[z];
                            mes[z] = ano[z + 1];
                            mes[z + 1] = auxdata;
                            auxdata = dia[z];
                            dia[z] = dia[z + 1];
                            dia[z + 1] = auxdata;
                        }}
                    }
                    }
                }
                printf("\n****** Aluno(s) Ordenados por data de nascimento ******\n"); 
                for(i = 0;i<qtd_alunos;i++){
                    printf("\nAluno %d = %s%c",i, copiadatas[i], 15);
                    printf("-----\n");
                }
                fim = 1; return 1; break; 
            }
            default: {
                printf("\nOpcao inválida retornando ao menu de listagem");}
            }
        } 
                    
    }
    
		fim = 0;
		if(op == 2 && qtd_professores > 0){
			while(!fim){
            
            printf("\n*******Menu de Listagem de professores*******");
            printf("\n Digite 0 para sair do menu de listagem");
            printf("\n Digite 1 para ordenar alunos pelo sexo");
            printf("\n Digite 2 para ordenar alunos pelo nome");
            printf("\n Digite 3 para ordenar alunos pela data de nascimento");
            printf("\n Escolha uma opcao : ");
            scanf("%d",&opcao);
            getchar(); 
            
            switch(opcao){
            case 0:{ 
                printf("\nSaindo do menu de listagem voltando para o Menu Principal");
                return 0; break;}
            case 1: { 
                printf("\n****** Professor(es) do sexo Masculino ******");
                for(i=0;i<qtd_professores;i++){
                    if(lista_professor[i].sexo == 'M' || lista_professor[i].sexo == 'm'){
                        printf("\nNome do professor : %s",lista_professor[i].nome);
                        printf("-----\n");}
                }
                printf("\n****** Professor(es) do sexo Feminino ******");
                for(i=0;i<qtd_professores;i++){
                    if(lista_professor[i].sexo == 'F' || lista_professor[i].sexo == 'f'){
                        printf("\nNome do professor : %s",lista_professor[i].nome);
                        printf("-----\n");}
                }
                fim = 1; return 1; break;
                }
            case 2: {
                for(i = 0; i < qtd_professores - 1; i++){
                    
                    x = 0;
                    menor = i;
                    for(j = i + 1; j < qtd_professores; j++)
                {
                    x = 0;
                    while(lista_professor[menor].nome[x] == lista_professor[j].nome[x])
                    {
                            x++;
                    } 
                    if(lista_professor[menor].nome[x] > lista_professor[j].nome[x])
                        menor = j;
                    
                }
                if(menor != i){
                    strcpy(aux, lista_professor[menor].nome);
                    strcpy(lista_professor[menor].nome, lista_professor[i].nome);
                    strcpy(lista_professor[i].nome, aux);
                }
                }
                printf("\n****** Professor(es) Ordenado(s) por nome ******\n");
                for(i = 0; i < qtd_professores; i++){
                    printf("Nome do professor %d: %s%c", i + 1,lista_professor[i].nome, TAM);
                    printf("-----\n");}
                return 1; break;   
            }
            
            case 3: {
                for(j = 0; j < qtd_professores;j++)
                    for(i = 0; i<15;i++)
                        copiadatas[j][i] =  lista_professor[j].dataNascimento[i];
                
                if(qtd_professores == 1){
                    for(i = 0; i<15;i++){
                        printf("\nProfessor %d = %s%c", i + 1, copiadatas[i], 15);
                        return 1;break;} 
                }
                
                for(i = 0; i < qtd_professores; i++){
                    //calculo do dia
                    dia[i] = (copiadatas[i][0]-'0') * 10;
                    dia[i]+= copiadatas[i][1]-'0';
                    //calculo do mes
                    mes[i] = (copiadatas[i][3]-'0') * 10;
                    mes[i] += copiadatas[i][4]-'0';
                    //calculo do ano 
                    ano[i] = (copiadatas[i][6]-'0') * 1000;
                    ano[i] += (copiadatas[i][7]-'0') * 100;
                    ano[i] += (copiadatas[i][8]-'0') * 10;
                    ano[i] += copiadatas[i][9]-'0';
                    
                }
                
                for(j = 0; j < qtd_professores; j++){
                    cont = 0,contA = 0,contM = 0, contD = 0;
                    for(i = 0; i < qtd_professores - 1; i++){
                        if((ano[i] > ano[i + 1]) && cont == 0){
                            contA++;
                            for(x = 0; x < 15; x++){
                                auxCP[i][x] = copiadatas[i][x];
                                copiadatas[i][x] = copiadatas[i + 1][x];
                                copiadatas[i + 1][x] = auxCP[i][x];
                                cont++;
                            }
                        }
                        if(ano[i] == ano[i + 1]){
                            if(mes[i] > mes[i + 1] && cont == 0){
                                contD++;
                                for(x = 0; x < 15; x++){
                                    auxCP[i][x] = copiadatas[i][x];
                                    copiadatas[i][x] = copiadatas[i + 1][x];
                                    copiadatas[i + 1][x] = auxCP[i][x];
                                    cont++;
                                }
                            }
                            if(mes[i] == mes[i + 1]){
                                if(dia[i] > dia[i + 1] && cont == 0){
                                    contD++;
                                    for(x = 0; x < 15; x++){
                                    auxCP[i][x] = copiadatas[i][x];
                                    copiadatas[i][x] = copiadatas[i + 1][x];
                                    copiadatas[i + 1][x] = auxCP[i][x];
                                    cont++;
                                    }
                                }    
                            }
                        }   
                
                    if(cont != 0){
                        if(contA == 1 || contM == 1 || contD == 1){
                        for(z = 0; z != 1; z++){
                            auxdata = ano[z];
                            ano[z] = ano[z + 1];
                            ano[z + 1] = auxdata;
                            auxdata = mes[z];
                            mes[z] = ano[z + 1];
                            mes[z + 1] = auxdata;
                            auxdata = dia[z];
                            dia[z] = dia[z + 1];
                            dia[z + 1] = auxdata;
                        }}
                    }
                    }
                }
                printf("\n****** Professor(s) Ordenado(s) por data de nascimento ******\n"); 
                for(i = 0;i<qtd_professores;i++){
                    printf("\nProfessor %d = %s%c",i, copiadatas[i], 15);
                    printf("-----\n");
                }
                fim = 1; return 1; break; 
            }
            default: {
                printf("\nOpcao inválida retornando ao menu de listagem");}
            }
        } 
                
            }
            printf("\nOpção inválida retornando ao Menu principal");
		return 0;
    
}        
    
void aniversarianteMes(Aluno lista_aluno[], int qtd_alunos, Professor lista_professor[], int qtd_professores){
    int op;
    int i;
    int mesal[qtd_alunos], opmes;
    int mespr[qtd_alunos];
    int cont = 0 ;
    
    printf("\nDigite 1 se deseja consultar os Alunos e 2 para os Professores : ");
    scanf("%d",&op);
    getchar();
    
    if(op == 1 && qtd_alunos > 0){
        cont++;
        for(i = 0; i < qtd_alunos; i++){
        //calculo do mes
        mesal[i] = (lista_aluno[i].dataNascimento[3]-'0') * 10;
        mesal[i] += lista_aluno[i].dataNascimento[4]-'0';
        }
        
        printf("\nDigite o mes que deseja pesquisar : ");
        scanf("%d",&opmes);
        
        for(i = 0; i < qtd_alunos; i++){
             if(opmes == mesal[i])
                printf("\nAluno %d : %s", i + 1,lista_aluno[i].nome);
        }
    }
    
    if(op == 2 && qtd_professores > 0){
        cont++;
        for(i = 0; i < qtd_professores; i++){
        //calculo do mes
        mespr[i] = (lista_professor[i].dataNascimento[3]-'0') * 10;
        mespr[i] += lista_professor[i].dataNascimento[4]-'0';
        }
        
        printf("\nDigite o mes que deseja pesquisar : ");
        scanf("%d",&opmes);
        
        for(i = 0; i < qtd_professores; i++){
             if(opmes == mespr[i])
                printf("\nProfessor %d : %s", i + 1,lista_professor[i].nome);
        }
    }
    
    if(cont == 0)
        printf("\nOpção inválida");
}	

void listardisciplinas(Disciplina lista_disciplina[], int qtd_disciplinas){
    printf("\n****** Disciplinas Cadastradas ******#\n");
            int i;
        for (i = 0; i < qtd_disciplinas; i++){
            printf("-----\n");
            printf("Nome da disciplina: %s", lista_disciplina[i].nome);
            printf("Codigo da disciplina: %d\n", lista_disciplina[i].codigodisc);
            printf("Semestre: %d\n", lista_disciplina[i].semestre);
            printf("Codigo do professor: %d\n", lista_disciplina[i].codigoprof);
            printf("Nome do professor: %s\n", lista_disciplina[i].nomeprofdisc);
        }
        printf("-----\n\n");
}    

int listardiscalun(Aluno lista_aluno[], int qtd_alunos, Disciplina lista_disciplina[], int qtd_disciplinas,Disciplina lista_alundisc[], int qtd_alundisc){
        int coddisc = 0;
        int i,j;
        int conti = 0;
        int contj = 0;
        
        printf("\nDigite qual o codigo da disciplina que deseja pesquisar : ");
        scanf("%d",&coddisc);
        
        for (i = 0; i < qtd_disciplinas; i++){
            if(coddisc == lista_disciplina[i].codigodisc){
            printf("-----\n");
            printf("Nome da disciplina: %s", lista_disciplina[i].nome);
            printf("Codigo da disciplina: %d\n", lista_disciplina[i].codigodisc);
            printf("Semestre: %d\n", lista_disciplina[i].semestre);
            printf("Codigo do professor: %d\n", lista_disciplina[i].codigoprof);
            printf("Nome do professor: %s\n", lista_disciplina[i].nomeprofdisc);
            conti++;    
            }
            
            for (j = 0; j < qtd_alundisc; j++){
                if(lista_disciplina[i].codigodisc == lista_alundisc[j].codalundisc){
                    if(contj == 0){
                        printf("\n****** Aluno(s) Cadastrados na disciplina : %s ******#\n",lista_disciplina[i].nome);
                        printf("Nome do Aluno: %s", lista_alundisc[j].nomealundisc);
                        printf("-----\n");
                        contj++;}
                    else
                        printf("Nome do Aluno: %s", lista_alundisc[j].nomealundisc);
                        printf("-----\n");
                }
            }
            if(conti == 0){
                printf("\nNão existe disciplina com esse codigo");
                return 0;}
            if(contj == 0){
                printf("\nNão existem alunos cadastrados nessa disciplina");
                return 0;}
            
            return 1;    
            
        }
}*/
















