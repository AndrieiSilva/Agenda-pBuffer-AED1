#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

#define TAM_NOME (10 * sizeof(char))
#define TAM_EMAIL (10 * sizeof(char))
#define TAM_TELEFONE (sizeof(int))

int main(){
    void * pBuffer = malloc(sizeof(int) * 2 + TAM_NOME + sizeof(int) + TAM_EMAIL);

    void * opcao = (int *)pBuffer;
    void * qtde = ((int *)pBuffer + sizeof(int));
    *(int *)qtde = 1;

    while(1) {
    printf ("\n- - - - M E N U - - - -\n");
    printf ("\n1. \tInserir pessoa");
    printf ("\n2. \tRemover pessoa");
    printf ("\n3. \tBuscar pessoa");
    printf ("\n4. \tListar Todos");
    printf ("\n5. \tSair");
    printf ("\n- - - - - - - - - - - -\n");

    printf ("\nE S C O L H A :\t");
    scanf ("%d", &*(int *)opcao);

    
        switch (*(int *)opcao)
        {
        case 1:
            printf("\nDIGITE NOME: ");
            
            pBuffer = realloc (pBuffer, (sizeof(int) * 2) + ((TAM_EMAIL + TAM_NOME + TAM_TELEFONE) * *(int *)qtde));
            
            void * primeiraPessoa = ((int *)pBuffer + sizeof(int) + sizeof(char));
            void * posATual = primeiraPessoa + ((TAM_EMAIL + TAM_NOME + TAM_TELEFONE) * *(int *)qtde);

            scanf(" %[^\n]", (char *)(posATual));
            void * verificaFIM = posATual;
            while(isalpha(*(char *)verificaFIM)) {
                verificaFIM++;
            }
            *(char *)verificaFIM = '\0';
            
            *(int *)qtde = *(int *)qtde + 1;
            break;
        
        case 2:
            
            break;
        case 3:
            void * novoBuffer = malloc ( (sizeof(int) * 2) + ((TAM_EMAIL + TAM_NOME + TAM_TELEFONE) * *(int *)qtde) + (TAM_EMAIL + TAM_NOME + TAM_TELEFONE) );
            memcpy(novoBuffer,pBuffer,(sizeof(int) * 2) + ((TAM_EMAIL + TAM_NOME + TAM_TELEFONE) * *(int *)qtde));
            primeiraPessoa = ((int *)novoBuffer + sizeof(int) + sizeof(char));
            posATual = primeiraPessoa + ((TAM_EMAIL + TAM_NOME + TAM_TELEFONE) * *(int *)qtde);
            scanf(" %[^\n]", (char *)(posATual));
            verificaFIM = posATual;
            while (isalpha(*(char *)verificaFIM))
            {
                verificaFIM++;
            }
            *(char *)verificaFIM = '\0';
            verificaFIM = primeiraPessoa;
            while(strcmp(verificaFIM,posATual)){
                verificaFIM = verificaFIM + (TAM_EMAIL + TAM_NOME + TAM_TELEFONE);
            }

            printf("\n");

            while(*(char *)verificaFIM != '\0') {
                printf("%c", *(char *)verificaFIM);
                verificaFIM++;
            }
            
            printf("\n");
            memcpy(pBuffer,novoBuffer,(sizeof(int) * 2) + ((TAM_EMAIL + TAM_NOME + TAM_TELEFONE) * *(int *)qtde));
            free(novoBuffer);
            primeiraPessoa = ((int *)pBuffer + sizeof(int) + sizeof(char));
            break;
        case 4:
            void * novoBuffer2 = malloc ( (sizeof(int) * 2) + ((TAM_EMAIL + TAM_NOME + TAM_TELEFONE) * *(int *)qtde) + sizeof(int));
            memcpy(novoBuffer2,pBuffer,(sizeof(int) * 2) + ((TAM_EMAIL + TAM_NOME + TAM_TELEFONE) * *(int *)qtde));
            
            primeiraPessoa = ((int *)novoBuffer2 + sizeof(int) + sizeof(char));
            void * final = novoBuffer2 + (sizeof(int) * 2) + ((TAM_EMAIL + TAM_NOME + TAM_TELEFONE) * *(int *)qtde + sizeof(int));
            *(int *)final = 1;

            verificaFIM =  primeiraPessoa + ((TAM_EMAIL + TAM_NOME + TAM_TELEFONE) * *(int *)final);

            while(verificaFIM <= final) {
            
                printf("\n");
                printf("NOME %d:\t", *(int *)final);
                while(isalpha(*(char *)verificaFIM)) {
                    printf("%c", *(char *)verificaFIM);
                    verificaFIM++;
                }
                printf("\n");

                *(int *)final = *(int *)final + 1;
                verificaFIM =  primeiraPessoa + ( (TAM_EMAIL + TAM_NOME + TAM_TELEFONE) * *(int *)final);
            }
            free(novoBuffer2);
            primeiraPessoa = ((int *)pBuffer + sizeof(int) + sizeof(char));
            break;
        case 5:
            exit(0);
            break;
        default:
            break;
        }
    }
}
