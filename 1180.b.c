# AED-1

#include <stdio.h>
#include <stdlib.h>

int main (){

  int n;
  printf("DIGITE O VALOR: ");
  scanf("%d",&n);

  int* vet= (int*)malloc(n*sizeof(int));

  if(vet==NULL){
    printf("ERRO DE ALOCACAO DE MEMORIA!! \n");
       return 1;
         }

  printf("---PREENCHA O VETOR----\n");
    for (int i=0; i<n;i++){
    printf("POSICAO %d: ",i+1);
    scanf("%d",&vet[i]);
    }

    int menor= vet[0];
    int posicao=0;

        for(int i=0; i<n;i++){
            if(vet[i]<menor){
                menor=vet[i];
                posicao=i;
            }
        }

            printf("A MENOR POSICAO E : %d \t",menor);
            printf("A POSICAO E:%d ",posicao+1);
     free(vet);
     vet=NULL;

}


