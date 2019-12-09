#include <stdio.h>
#include <string.h>

// Uma função utilitária que retorna o objeto máximo entre dois números inteiros 
int max(int a, int b) { return (a > b)? a : b; } 
  
// Retorna o valor máximo que pode ser colocado em uma mochila de capacidade cap_max
int knapSack(int cap_max, Objeto *objeto, int num_itens) 
{ 
   // Caso base
  if (num_itens == 0 || cap_max == 0) 
    return 0; 
  
   // Se o peso do enésimo item for maior que a capacidade cap_max da mochila, então 
   // esse item não pode ser incluído na solução ideal
  if (objeto[num_itens-1].peso > cap_max) {
    return knapSack(cap_max, objeto, num_itens-1); 
  }
   // Retorna o máximo de dois casos:  
   // (1) enésimo item incluído  
   // (2) não incluído 
  else{
    return max( objeto[num_itens-1].valor + knapSack(cap_max-objeto[num_itens-1].peso, objeto, num_itens-1), knapSack(cap_max, objeto, num_itens-1));
  }
}

