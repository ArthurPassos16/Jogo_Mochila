#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "leituras.h"
#include "logica.h"

int main(){

    Mochila *mochila=NULL;
    Jogador *jogador=NULL;
    int opcao1, opcao2, cargaBolsa;

    mochila=lerMochila();
    
    srand(time(NULL));
    do{
        printf("Problema da Mochila\n");
        printf("1 - JOGAR\t2 - RECORDES\t3 - SAIR\t\n");
        scanf("%d",&opcao1);
        switch(opcao1){
            case 1:
                printf("1 - MODO INDIVIDUAL\t2 - MODO IA\t\n");
                scanf("%d",&opcao2);
                switch(opcao2){
                    case 1:
                      jogarIndividual(mochila);
                    break;
                    case 2:
                      jogarIA(mochila);
                    break;
                    default:
                      printf("opcao invalida!\n");
                    break;
                }
            break;
            case 2:
                jogador=lerRecorde();
                printf("\nRECORDES\n\n");
                for(int i=0;i<5;i++){
                  printf("FASE %d\n",i+1);
                  printf("Nome: %s\t Resultado: %d\t\n",jogador[i].nome,jogador[i].recorde);
                }
            break;
            case 3:
                printf("JOGO ENCERRADO!\n");
            break;
            default:
                printf("Opcao Invalida!\n");
            break;
        }
    }while(opcao1!=3);
    free(mochila);
    return 0;
}
