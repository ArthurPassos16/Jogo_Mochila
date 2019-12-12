#include <stdio.h>
#include <string.h>
#include <locale.h>
#define linguagem_ptr 	setlocale(LC_ALL,"Portuguese")

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

Mochila *lerMochila(int fase){
  Mochila *mochila=NULL;
  Objeto *objeto=NULL; 
  FILE *cenario=NULL;
  int num_itens,cap_max,peso,valor;
  char cen_text[15]="cenario", fase_text[3];

  //Convertendo o inteiro fase em string
  sprintf(fase_text, "%d" , fase);
  strcat(cen_text,fase_text);
  strcat(cen_text,".txt");

  cenario = fopen (cen_text, "r");

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

// ----------------------------------------------------JOGAR INDIVIDUAL----------------------------------------------------------------


// ----------------------------------------função reordena_vetor -------------------------------------------

void organiza_placar(Mochila *mochila, int objetoP[], int valorP[], int pesoP[], int tamanho, int guarda_valor)
{
  int h,placar_opçoes_OB[tamanho], placar_opçoes_valores[tamanho],placar_opçoes_pesos[tamanho], recebe_valor[tamanho];
  for(int f=0; f<tamanho;f++)
    {
      placar_opçoes_OB[f] = f+1;
      placar_opçoes_valores[f] = mochila->objeto[f].valor;
      placar_opçoes_pesos[f] = mochila->objeto[f].peso;
    }

  for(int j=0; j<tamanho;j++)
  {
    for(int h=0; h<tamanho;h++)
    {
      if(placar_opçoes_OB[j] == objetoP[h])
      {
        placar_opçoes_OB[j] = 0;
        placar_opçoes_pesos[j] = 0;
        placar_opçoes_valores[j] = 0;
      }
    }
  }
  
  printf("-----------------------JOGO-----------------------\n");
  printf("OBJETO\tPESO\tVALOR\t\n");
  for(int l=0;l<tamanho;l++)
  {
    printf("%d\t\t%d\t\t%d\t\n",placar_opçoes_OB[l], placar_opçoes_pesos[l],placar_opçoes_valores[l]);
  }
  printf("\nCapacidade maxima da mochila:%d\n\n",mochila->cap_max);

}

// -------------------------------------------------função verifica valor------------------------------------------

void verifica_valor(int valor, int tamanho)
{
  int valor_Total1 = 900;
  int valor_Total2 = 309;
  int tam1 = 8, tam2 =10;
  if(tamanho == tam1)
  {
    if(valor == valor_Total1) 
    {
      printf("\nPARABÉNS!!!!!\n");
    }
    else
    {
      printf("\nTENTE OUTRA VEZ!!!!!\n");
    }
  }
  if(tamanho == tam2)
  {
    if(valor == valor_Total2) 
    {
      printf("\nPARABÉNS!!!!!\n");
    }
    else
    {
      
      printf("\nTENTE OUTRA VEZ!!!!!\n");
    }
  }
 

}



// ----------------------------------------função Player -------------------------------------------
void Player(Mochila *mochila)
{
  linguagem_ptr; // define  para função da biblioteca de lingua.
  static int i=0,verifica=0, valor_escolhido=0, peso_escolhido=0;
  int tamanho = 0,guarda_valor,capacidade_restante;
  tamanho = mochila->num_itens; // pega a quantidade de itens contidas no vetor do arquivo
  int objeto_escolha[tamanho], valores[tamanho], pesos[tamanho];
  //int h, placar_opçoes_OB[tamanho], placar_opçoes_valores[tamanho],placar_opçoes_pesos[tamanho];
  int escolha = 1;
  while(escolha != 0)
  {  
    organiza_placar(mochila, objeto_escolha, valores, pesos, tamanho,guarda_valor);   
    printf("\nDigite o número do objeto o qual deseja colocar na mochila:\n");
    scanf("%d",&objeto_escolha[i]);
    guarda_valor = objeto_escolha[i];
   

    printf("\nESCOLHA[%d]:\nOBJETO:%d",i+1,objeto_escolha[i]);

    for(int j=0;j<i;j++)
    {
      if(guarda_valor == objeto_escolha[j])
      {
        printf("\nEssa escolha já foi feita\n");
        verifica = 1;
      }
    }
  if((guarda_valor>tamanho)||(guarda_valor<0 )||(guarda_valor==0))
  {
    printf("\nO objeto digitado não existe:\n");
    verifica = 1;
  }   
  if(verifica != 1)
  {
    valor_escolhido += mochila->objeto[guarda_valor-1].valor; // atualiza o valor da mochila
    valores[i] = mochila->objeto[guarda_valor-1].valor;
    peso_escolhido += mochila->objeto[guarda_valor-1].peso; // atualiza o peso
    pesos[i] = mochila->objeto[guarda_valor-1].peso;
    capacidade_restante = mochila->cap_max - peso_escolhido;
    if(capacidade_restante < 0)
    {
      capacidade_restante = 0;
    }
    
    printf("\n\n\t--------------------SUA MOCHILA----------------------- \nVALOR ATUAL:%d\nPESO ATUAL:%d \nCAPACIDADE RESTANTE: %d\n",valor_escolhido,peso_escolhido,capacidade_restante);
    printf("\n\t---------------OBJETOS DENTRO DA MOCHILA-------------\n");
    for(int s=0;s<=i;s++)
    {
      printf("\nOBJETO[%d]\n",objeto_escolha[s]);
    }
    
    i++;
    verifica = 0; 
  }
  verifica = 0; 
  

  if((peso_escolhido < mochila->cap_max))
  {
    printf("\nDeseja continuar: SIM = 1 / Não = 0");
    scanf("%d",&escolha);
  }
  else
  {
    break;
  } 
    
  }
  if(i>0)
  {
    printf("\nEssas foram todas as suas escolhas:");
    printf("\nOBJETO\tPESO\tVALOR\t\n");
  
    for(int k=0; k<i; k++)
    {
      printf("\n%d\t\t%d\t\t%d\t\n",objeto_escolha[k],pesos[k],valores[k]);
    }

  }
  if((peso_escolhido > mochila->cap_max) ||(peso_escolhido == mochila->cap_max))
  {
    printf("\nO peso limite da mochila foi atingido!!!\n");
    verifica_valor(valor_escolhido,tamanho);
  }
  if(peso_escolhido < mochila->cap_max)
  {
    printf("\nO peso limite não foi atingido!!!!!\n");
    verifica_valor(valor_escolhido,tamanho);
  }
  
  i = 0;
}  


// ----------------------------------------------------JOGAR INDIVIDUAL----------------------------------------------------------------























































































































