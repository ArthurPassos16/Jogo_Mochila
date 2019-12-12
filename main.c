#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "leituras.h"
#include "logica.h"

int main(){

  Mochila *mochila=NULL;
  Jogador *jogador=NULL;
  int opcao1, opcao2, fase, nivelIA;
  char nome[100];

  srand(time(NULL));
  do{
    printf("----------------Problema da Mochila----------------\n");
    printf("1 - JOGAR\t2 - IA\t3 - RECORDES\t4 - SAIR\t\n");
    printf("Escolha uma das opcoes:\n");
    scanf("%d",&opcao1);
    switch(opcao1){
      case 1:
        getchar();
        printf("Informe seu nome:\n");
        fgets(nome,sizeof(nome),stdin);

        printf("Escolha uma fase de 1 a 5:\n");
        scanf("%d",&fase);
        if(fase>=1 && fase<=5){
          mochila=lerMochila(fase);
          Player(mochila);
        }else
          printf("Fase invalida!\n");
      break;

      case 2:
        printf("1 - 95%%\t\t2 - 75%%\t\t3 - 50%%\t\t\n");
        printf("Escolha o nivel da IA:\n");
        scanf("%d",&nivelIA);
        switch(nivelIA){
          case 1:
            printf("\nEscolha uma fase de 1 a 5:\n");
            scanf("%d",&fase);

            if(fase>=1 && fase<=6){
              mochila=lerMochila(fase);
              jogarIA95(mochila);
            }else
              printf("Fase invalida!\n\n");
          break;

          case 2:
            printf("\nEscolha uma fase de 1 a 5:\n");
            scanf("%d",&fase);

            if(fase>=1 && fase<=6){
              mochila=lerMochila(fase);
              jogarIA75(mochila);
            }else
              printf("Fase invalida!\n\n");
          break;

          case 3:
            printf("\nEscolha uma fase de 1 a 5:\n");
            scanf("%d",&fase);

            if(fase>=1 && fase<=6){
              mochila=lerMochila(fase);
              jogarIA50(mochila);
            }else
              printf("Fase invalida!\n\n");
          break;

          deafult:
            printf("Nivel invalido!\n\n");
          break;
        }
      break;

      case 3:
        jogador=lerRecorde();
        printf("\nRECORDES\n\n");
        for(int i=0;i<5;i++){
          printf("FASE %d\n",i+1);
          printf("Nome: %s\nResultado: %d\n\n",jogador[i].nome,jogador[i].recorde);
        }
      break;

      case 4:
        printf("JOGO ENCERRADO!\n");
      break;

      default:
        printf("Opcao Invalida!\n");
      break;
    }
  }while(opcao1!=4);

  if(mochila!=NULL){
    free(mochila->objeto);
    free(mochila);
    free(jogador);
  }
  return 0;
}
