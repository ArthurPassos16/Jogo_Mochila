#include <stdio.h>
#include <string.h>

typedef struct{
  int peso;
  int valor;
}Objeto;

typedef struct{
  int cap_max;
  int num_itens;
  Objeto *objeto;
}Mochila;

Objeto *leituraObjeto() {
  FILE* cenario;
  Objeto *objeto=NULL; 
  int num_itens,cap_max,peso,valor;

  cenario = fopen ("cenario.txt" , "r");
  if (cenario == NULL){
    printf ("Erro de abertura");
    return NULL;
  }

  fscanf(cenario,"%d %d", &num_itens, &cap_max);

  objeto=(Objeto *)malloc(sizeof(Objeto)*num_itens);

  if(objeto==NULL)
    return NULL;

  for(int i=0;i<num_itens;i++){
    fscanf(cenario,"%d",&peso);
    objeto[i].peso=peso;
  }
  for(int i=0;i<num_itens;i++){
    fscanf(cenario,"%d",&valor);
    objeto[i].valor=valor;
  }
  fclose (cenario);
  return objeto;
}

Mochila *leituraMochila(){
  Mochila *mochila=NULL;
  FILE *cenario=NULL;
  int num_itens,cap_max;

  cenario = fopen ("cenario.txt" , "r");

  if (cenario == NULL){
    printf ("Erro de abertura");
    return NULL;
  }

  mochila=malloc(sizeof(Mochila));
  fscanf(cenario,"%d %d", &num_itens, &cap_max);
  
  mochila->num_itens=num_itens;
  mochila->cap_max=cap_max;
  return mochila;
}
