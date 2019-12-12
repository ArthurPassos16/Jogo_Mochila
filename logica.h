#include <stdio.h>
#include <string.h>
#define max(a,b) (a)>(b)? a:b
// Uma macro utilitária que retorna o objeto máximo 
// entre dois números inteiros 
  
// Retorna o valor máximo que pode ser colocado 
// em uma mochila de capacidade cap_max
void progamacaoDinamicaMochila(int cap_max, Objeto *objeto, int n) 
{
    int i, j=1, pesoInicial, pesoFinal, val_max;
    int K[n + 1][cap_max + 1]; 
  
    // Crie a tabela K[][] de maneira ascendente 
    for (i = 0; i <= n; i++) { 
        for (pesoInicial = 0; pesoInicial <= cap_max; pesoInicial++) { 
            if (i == 0 || pesoInicial == 0) 
                K[i][pesoInicial] = 0; 
            else if (objeto[i - 1].peso <= pesoInicial) 
                K[i][pesoInicial] = max(objeto[i - 1].valor + K[i - 1][pesoInicial - objeto[i - 1].peso], K[i - 1][pesoInicial]); 
            else
                K[i][pesoInicial] = K[i - 1][pesoInicial]; 
        } 
    }

    // val_max é o valor máximo de objetos dentro da mochila
    val_max=K[n][cap_max];
    pesoFinal = cap_max; 
    
    printf("A IA selecionou o melhor conjunto de objetos que cabem dentro da mochila e que possuem o maior valor possivel.\n\n");
    printf("Conjunto de objetos:\n");
    for (i = n; i > 0 && val_max > 0; i--) { 
          
        // O resultado vem do topo (K[i-1][pesoFinal]) ou
        // do (objeto[i-1] + K[i-1][pesoFinal-objeto[i-1]]).peso 
        // como na tabela da KnapSack. 
        // Se vier do último, significa que 
        // o item está incluído.
        if (val_max == K[i - 1][pesoFinal])  
            continue;         
        else { 
            // Esse item está incluído
            // Como esse peso é incluído 
            // seu valor é reduzido
            val_max = val_max - objeto[i - 1].valor; 
            pesoFinal = pesoFinal - objeto[i - 1].peso;
            if(val_max!=0) 
              printf("%d - ",i);
            else
              printf("%d\n",i);

        } 
    } 
    printf("\nValor total dos objetos da mochila: %d\n\n",K[n][cap_max]);
} 

// Função de Ordenação por Seleção
// Quick sort function
void quick_sort(Objeto *objeto, int left, int right) {
    int i, j, x, y;
     
    i = left;
    j = right;
    x = objeto[left + right / 2].valor ;
     
    while(i <= j) {
        while(objeto[i].valor < x && i < right) {
            i++;
        }
        while(objeto[j].valor > x && j > left) {
            j--;
        }
        if(i <= j) {
            //Alternando os valores de peso de forma crescente
            y = objeto[i].valor;
            objeto[i].valor = objeto[j].valor;
            objeto[j].valor = y;
            //Alternando os valores de valor de forma crescente
            y = objeto[i].peso;
            objeto[i].peso = objeto[j].peso;
            objeto[j].peso = y;
            /*Alternando os indices de solucao de forma crescente
            y=i;
            solucao[i]=solucao[j];
            solucao[j]=y;*/
            i++;
            j--;
        }
    }
     
    if(j > left) {
        quick_sort(objeto, left, j);
    }
    if(i < right) {
        quick_sort(objeto, i, right);
    }
}

void metodoGulosoMochila(int num_itens, int cap_max, Objeto *objeto){
  int *solucao, valorminimo, melhorValor;
  
  solucao=malloc(sizeof(int)*num_itens);

  quick_sort(objeto,0,num_itens-1);

  valorminimo=objeto[0].valor;
  melhorValor=0;

  for(int i=0;i<num_itens;i++){
    if(objeto[i].peso <= cap_max){
      cap_max = cap_max - objeto[i].peso;
      solucao[i]=i+1;
      melhorValor = melhorValor + objeto[i].valor;

      //if(objeto[i].peso==)
    }
  }
  if(melhorValor >= valorminimo){
    for(int i=0;i<num_itens;i++)
      printf("%d - ",solucao[i]);
  }else{
    printf("Não!\n\n");
  }
  printf("\n\nValor total dos objetos da mochila: %d\n\n",melhorValor);
}

void jogarIA95(Mochila *mochila){
  printf("-----------------------JOGO-----------------------\n");
  printf("OBJETO\tPESO\tVALOR\t\n");
  for(int i=0;i<mochila->num_itens;i++){
    printf("%d\t\t%d\t\t%d\t\n",i+1,mochila->objeto[i].peso,mochila->objeto[i].valor);
  }
  printf("\nCapacidade maxima da mochila: %d\n\n",mochila->cap_max);
  progamacaoDinamicaMochila(mochila->cap_max,mochila->objeto,mochila->num_itens);
}

void jogarIA75(Mochila *mochila){
  printf("-----------------------JOGO-----------------------\n");
  printf("OBJETO\tPESO\tVALOR\t\n");
  for(int i=0;i<mochila->num_itens;i++){
    printf("%d\t\t%d\t\t%d\t\n",i+1,mochila->objeto[i].peso,mochila->objeto[i].valor);
  }
  printf("\nCapacidade maxima da mochila: %d\n\n",mochila->cap_max);
}

void jogarIA50(Mochila *mochila){
  printf("-----------------------JOGO-----------------------\n");
  printf("OBJETO\tPESO\tVALOR\t\n");
  for(int i=0;i<mochila->num_itens;i++){
    printf("%d\t\t%d\t\t%d\t\n",i+1,mochila->objeto[i].peso,mochila->objeto[i].valor);
  }
  printf("\nCapacidade maxima da mochila: %d\n\n",mochila->cap_max);
  metodoGulosoMochila(mochila->num_itens,mochila->cap_max,mochila->objeto);
}