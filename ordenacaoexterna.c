#include <stdio.h>
#include <stdlib.h>
#define N 200000

void merge(int vetor[], int inicio, int meio, int fim) 
{
    int ini1 = inicio, ini2 = meio+1, comAux = 0, tam = fim-inicio+1;
    int *vetAux;
    vetAux = (int*)malloc(tam * sizeof(int));

    while(ini1 <= meio && ini2 <= fim)
    {
        if(vetor[ini1] < vetor[ini2]) 
        {
            vetAux[iniAux] = vetor[ini1];
            ini1++;
        } else {
            vetAux[iniAux] = vetor[ini2];
            ini2++;
        }
        iniAux++;
    }


    while(ini1 <= meio)
    {  
        vetAux[iniAux] = vetor[ini1];
        iniAux++;
        ini1++;
    }

    while(ini2 <= fim) 
    {   
        vetAux[iniAux] = vetor[ini2];
        iniAux++;
        ini2++;
    }

    for(iniAux = inicio; iniAux <= fim; iniAux++)
    {    
        vetor[iniAux] = vetAux[iniAux-inicio];
    }
    
    free(vetAux);
}

void mergeSort(int vetor[], int inicio, int fim)
{
    if (inicio < fim)
    {
        int meio = (fim+inicio)/2;

        mergeSort(vetor, inicio, meio);
        mergeSort(vetor, meio+1, fim);
        merge(vetor, inicio, meio, fim);
    }
}
int main(int argc, char** argv)
{
  int vet[N], i;
  for(i=0; i<N; i++)
  {
      vet[i] = rand() % 100000;
  }

  mergeSort(vet,0,N);

  return 0;
}