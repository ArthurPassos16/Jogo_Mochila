#include <stdio.h>
#include <string.h>

typedef struct{
  char *nome;
  int recorde;
}Jogador;

typedef struct{
  int peso;
  int valor;
}Objeto;

typedef struct{
  int cap_max;
  int num_itens;
  Objeto *objeto;
}Mochila;

Mochila *lerMochila(){
  Mochila *mochila=NULL;
  Objeto *objeto=NULL; 
  FILE *cenario=NULL;
  int num_itens,cap_max,peso,valor;

  cenario = fopen ("cenario1.txt" , "r");

  if (cenario == NULL){
    printf ("Erro de abertura");
    return NULL;
  }

  mochila=malloc(sizeof(Mochila));
  fscanf(cenario,"%d %d", &num_itens, &cap_max);
  
  mochila->num_itens=num_itens;
  mochila->cap_max=cap_max;

  mochila->objeto=(Objeto *)malloc(sizeof(Objeto)*num_itens);

  if(mochila->objeto==NULL)
    return NULL;

  for(int i=0;i<num_itens;i++){
    fscanf(cenario,"%d",&valor);
    mochila->objeto[i].valor=valor;
  }

  for(int i=0;i<num_itens;i++){
    fscanf(cenario,"%d",&peso);
    mochila->objeto[i].peso=peso;
  }

  fclose(cenario);

  return mochila;
}

int escreverRecorde(){
  FILE *recorde=NULL;
  Jogador *jogador=NULL;

  recorde = fopen("recorde.txt","w");

  if(recorde==NULL){
    printf ("Erro de abertura");
    return 0;
  }

  fprintf(recorde,"%s %d\n",jogador->nome,jogador->recorde);

  fclose(recorde);
  return 1;
}

Jogador *lerRecorde(){
  FILE *recorde=NULL;
  Jogador *jogador=NULL;

  char nome[100];
  int resultado;

  recorde = fopen("recorde.txt","r");

  if(recorde==NULL){
    printf ("Erro de abertura\n");
    return NULL;
  }

  
  jogador=malloc(sizeof(Jogador)*5);

  for(int i=0;i<5;i++){
    fscanf(recorde,"%s %d",nome, &resultado);
    
    jogador[i].nome=malloc(sizeof(char)*strlen(nome));

    strcpy(jogador[i].nome,nome);
    jogador[i].recorde=resultado;
  }

  fclose(recorde);
  
  return jogador;
}
