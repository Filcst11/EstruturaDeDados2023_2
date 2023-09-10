#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>


char nome[50];
char telefone[20];
char curso[30];
char n1[4];
char n2[4];
char vazio[50];


int main(void){
    //cria arquivo de enrada
    FILE *arquivoEntrada;

    arquivoEntrada = fopen("./DadosEntrada.csv","r");

    if(arquivoEntrada == NULL){
        printf("\nErro ao abrir o arquivo\n");
        return 1;
    }
    printf("\nabriu o arquivo\n");
    
    //cria variaveis auxiliares para ajudar a me localizar no arquivo
    char x;
    int contLetras = 0, contLinhas = 0, contPalavras = 0;
    char pulouLinha ='\n', mudouPalavra = ',' ;

    while(fscanf(arquivoEntrada,"%c",&x) != EOF){
        
        
        //notifica quando encontra um '\n'
        if(x == pulouLinha){
            //variáveis estão preenchidas
            if(contLinhas > 0){
                FILE *arquivosaida;
                arquivosaida = fopen("SituacaoFinal.cvs","a");
                float nota1, nota2;
                nota1 = atof(n1);
                nota2 = atof(n2);

                if(((nota1+nota2)/2) >= 7){ 
                    fprintf(arquivosaida,"%s,%.1f,APROVADO\n",nome,(nota1+nota2)/2);
                }else{
                    fprintf(arquivosaida,"%s,%.1f,REPROVADO\n",nome,(nota1+nota2)/2);
                }
                
                fclose(arquivosaida);
            }    
            
            printf("\n\nNome: %s\nTelefone: %s\nCurso: %s\nN1: %s\nN2: %s\n\n",nome,telefone,curso,n1,n2);
            //zerando as variáveis
            strcpy(nome,vazio);
            strcpy(telefone,vazio);
            strcpy(curso,vazio);
            strcpy(n1,vazio);
            strcpy(n2,vazio);

            printf("pulou linha\n");
            contLinhas+=1;
            contPalavras = 0;  
            contLetras = 0;


        //notifica quando encontra uma ','
        }if(x == mudouPalavra){
            contPalavras+=1;
            printf("Mudou a palavra\n");
            contLetras = 0;

        //vai criando as variáveis nome, telefone, curso, n1, n2 como char    
        }else{             

            printf("%c - contLetras: %d ",x,contLetras);

            if(contPalavras == 0){
                printf("(Nome[%d])\n",contLinhas);
                if(contLetras > 0) nome[contLetras - 1] = x;
                
            }
            if(contPalavras == 1){
                printf("(Telefone[%d])\n",contLinhas);
                telefone[contLetras] = x;
            }
            if(contPalavras == 2){
                printf("(Curso[%d])\n",contLinhas);
                curso[contLetras] = x;
            }
            if(contPalavras == 3){
                printf("(N1[%d])\n",contLinhas);
                n1[contLetras] = x;
            }
            if(contPalavras == 4){
                printf("(N2[%d])\n",contLinhas);
                n2[contLetras] = x;
            }
            contLetras +=1;
        }
        
    }
    FILE *arquivosaida;
    arquivosaida = fopen("SituacaoFinal.cvs","a");
    float nota1, nota2;
    nota1 = atof(n1);
    nota2 = atof(n2);

    if(((nota1+nota2)/2) >= 7){ 
        fprintf(arquivosaida,"%s,%.1f,APROVADO\n",nome,(nota1+nota2)/2);
    }else{
        fprintf(arquivosaida,"%s,%.1f,REPROVADO\n",nome,(nota1+nota2)/2);
    }
    
    fclose(arquivosaida);
    //printf("\n\nNome: %s\nTelefone: %s\nCurso: %s\nN1: %s\nN2: %s\n\n",nome,telefone,curso,n1,n2);
    fclose(arquivoEntrada);

    
    
    
    
    return 0;  
}