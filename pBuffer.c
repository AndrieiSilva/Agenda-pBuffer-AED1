#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

#define TAM_NOME (10 * sizeof(char))
#define TAM_EMAIL (10 * sizeof(char))
#define TAM_IDADE (sizeof(int))
#define PESSOA (TAM_EMAIL + TAM_IDADE + TAM_NOME)

int main() {
    void * pBuffer = malloc(sizeof(int) * 2);
    void * menu = (int *)pBuffer;
    void * qtde = (int *)pBuffer + 1;
    
    void * aux = NULL;
    void * comecoPessoa = NULL;
    void * incrementador = NULL;
    void * final = NULL;
    void * atual = NULL;

    *(int *)menu = 0;
    *(int *)qtde = 0;

    while(1) {
        
        printf("\n- - - - M E N U - - - -\n");
        printf("\n1.\tADIONAR PESSOA");
        printf("\n2.\tREMOVER PESSOA");
        printf("\n3.\tBUSCAR PESSOA");
        printf("\n4.\tLISTAR TUDO");
        printf("\n5.\tSAIR");
        printf("\n- - - - - - - - - - - -\n");
    
        printf("\nE S C O L H A : ");
        
        scanf("%d", &*(int *)menu);



        switch (*(int *)menu) {
            case 1:
                (*(int *)qtde)++;

                pBuffer = realloc(pBuffer,(sizeof(int) * 2) + PESSOA * (*(int *)qtde));
                menu = (int *)pBuffer;
                qtde = (int *)pBuffer + 1;                

                incrementador = (char *)pBuffer + sizeof(int) * 2 + PESSOA * (*(int *)qtde - 1);
                printf("\n");
                printf("NOME: ");
                scanf("%s", (char *)(incrementador));
                printf("IDADE: ");
                scanf("%d", (int *)(incrementador + TAM_NOME));
                printf("EMAIL: ");
                scanf("%s", (char *)(incrementador + TAM_IDADE + TAM_NOME));
                break;
            case 2:
                printf("PESSOA NOME: ");
                pBuffer = realloc(pBuffer,(sizeof(int) * 2) + PESSOA * (*(int *)qtde) + PESSOA);
                menu = (int *)pBuffer;
                qtde = (int *)pBuffer + 1;
                
                comecoPessoa = ((char *)pBuffer + (sizeof(int) * 2));
                atual = comecoPessoa;

                incrementador = (pBuffer + (sizeof(int) * 2) + (PESSOA * (*(int *)qtde)) + sizeof(char));
                scanf("%s", (char *)incrementador);

                while( strcmp((char *)incrementador , (char *)atual) != 0) {
                    atual = atual + PESSOA;
                }

                incrementador = (char *)pBuffer + sizeof(int) * 2 + PESSOA * (*(int *)qtde - 1);
                aux = calloc (PESSOA,1);
                memcpy(aux,incrementador,PESSOA);
                memcpy(atual,aux,PESSOA);
                
                *(int *)qtde -= 1;

                free(aux);
                pBuffer = realloc(pBuffer,(sizeof(int) * 2) + PESSOA * (*(int *)qtde));
                menu = (int *)pBuffer;
                qtde = (int *)pBuffer + 1;

                break;
            case 3:
                printf("PESSOA NOME: ");
                pBuffer = realloc(pBuffer,(sizeof(int) * 2) + PESSOA * (*(int *)qtde) + PESSOA);
                menu = (int *)pBuffer;
                qtde = (int *)pBuffer + 1;
                
                comecoPessoa = ((char *)pBuffer + (sizeof(int) * 2));
                atual = comecoPessoa;

                incrementador = (pBuffer + (sizeof(int) * 2) + (PESSOA * (*(int *)qtde)) + sizeof(char));
                scanf("%s", (char *)incrementador);

                while( strcmp((char *)incrementador , (char *)atual) != 0) {
                    atual = atual + PESSOA;
                }

                printf("\n- - - - I N F O - - - -\n");
                printf("NOME:\t%s", (char *)(atual));
                printf("\nIDADE:\t%d", *(int *)(atual + TAM_NOME));
                printf("\nEMAIL:\t%s", (char *)(atual + TAM_NOME + TAM_IDADE));
                printf("\n- - - - - - - - - - - -\n");

                pBuffer = realloc(pBuffer,(sizeof(int) * 2) + PESSOA * (*(int *)qtde));
                menu = (int *)pBuffer;
                qtde = (int *)pBuffer + 1;

                break;
            case 4:
                pBuffer = realloc(pBuffer,(sizeof(int) * 2) + PESSOA * (*(int *)qtde) + sizeof(int));
                menu = (int *)pBuffer;
                qtde = (int *)pBuffer + 1; 
                final = ((int *)pBuffer + (sizeof(int) * 2) + PESSOA * (*(int *)qtde));

                *(int *)final = *(int *)qtde;
                
                comecoPessoa = ((char *)pBuffer + (sizeof(int) * 2));
                incrementador = comecoPessoa;

                while ((*(int *)final) > 0) {
                    printf("\n");
                    printf("NOME:\t%s", (char *)(incrementador));
                    printf("\nIDADE:\t%d", *(int *)(incrementador + TAM_NOME));
                    printf("\nEMAIL:\t%s", (char *)(incrementador + TAM_NOME + TAM_IDADE));
                    printf("\n");
                    incrementador = incrementador + PESSOA;
                    *(int *)final -= 1;
                }

                pBuffer = realloc(pBuffer,(sizeof(int) * 2) + PESSOA * (*(int *)qtde));
                menu = (int *)pBuffer;
                qtde = (int *)pBuffer + 1;
                break;
            case 5:
                exit(0);
                break;
        }
    }
}