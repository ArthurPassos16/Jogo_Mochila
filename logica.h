#include <stdio.h>
#include <string.h>
#define max(a,b) (a)>(b)? a:b
// Uma macro utilitária que retorna o objeto máximo entre dois números inteiros 
  
// Retorna o valor máximo que pode ser colocado em uma mochila de capacidade cap_max
int *knapSack(int cap_max, Objeto *objeto, int n) 
{
    int i,j=1, w, aux; 
    int K[n + 1][cap_max + 1]; 
  
    // Build table K[][] in bottom up manner 
    for (i = 0; i <= n; i++) { 
        for (w = 0; w <= cap_max; w++) { 
            if (i == 0 || w == 0) 
                K[i][w] = 0; 
            else if (objeto[i - 1].peso <= w) 
                K[i][w] = max(objeto[i - 1].valor +  
                    K[i - 1][w - objeto[i - 1].peso], K[i - 1][w]); 
            else
                K[i][w] = K[i - 1][w]; 
        } 
    } 
  
    int *solucao;

    solucao = malloc(sizeof(int)*j);
    //solucao[0] é o valor máximo de objetos dentro da mochila
    solucao[0]=K[n][cap_max];
    aux=solucao[0];
    w = cap_max; 
    
    for (i = n; i > 0 && solucao[0] > 0; i--) { 
          
        // either the result comes from the top 
        // (K[i-1][w]) or from (objeto[i-1] +.valor K[i-1] 
        // [w-objeto[i-1]]).peso as in Knapsack table. If 
        // it comes from the latter one/ it means  
        // the item is included. 
        if (aux == K[i - 1][w])  
            continue;         
        else { 
            solucao = (int *)realloc(solucao,sizeof(int)*(j+1));
            // Esse item está incluído
            // Como esse peso é incluído 
            // seu valor é reduzido 
            solucao[j] = i;
            aux = aux - objeto[i - 1].valor; 
            w = w - objeto[i - 1].peso; 
            j++;
        } 
    } 
    return solucao;
} 

void jogarIndividual(Mochila *mochila){
  int resultado;
  printf("-----------------------JOGO-----------------------\n");
  printf("OBJETO\tPESO\tVALOR\t\n");
  for(int i=0;i<mochila->num_itens;i++){
    printf("%d\t\t%d\t\t%d\t\n",i+1,mochila->objeto[i].peso,mochila->objeto[i].valor);
  }
  printf("Capacidade maxima da mochila:%d\n\n",mochila->cap_max);
}

void jogarIA(Mochila *mochila){
  int resultado;
  int *solucao;
  printf("-----------------------JOGO-----------------------\n");
  printf("OBJETO\tPESO\tVALOR\t\n");
  for(int i=0;i<mochila->num_itens;i++){
    printf("%d\t\t%d\t\t%d\t\n",i+1,mochila->objeto[i].peso,mochila->objeto[i].valor);
  }
  printf("Capacidade maxima da mochila: %d\n\n",mochila->cap_max);
  printf("A IA selecionou os seguintes objetos que compoem o maior valor possivel dentro da capacidade maxima da mochila:\n");

  solucao=knapSack(mochila->cap_max, mochila->objeto, mochila->num_itens);

  for(int i=1;i<sizeof(solucao)-1;i++)
    printf("%d - ",solucao[i]);
  printf("\nValor total dos objetos da mochila: %d\n\n",solucao[0]);
}
