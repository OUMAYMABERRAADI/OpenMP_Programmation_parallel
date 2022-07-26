#include <omp.h>
#include <malloc.h>
#include <stdlib.h>
#include <time.h>


int main(int argc, char** argv)
{
  int  **matrice2, **matrice1, **produit;
  int x = 10;
  double temps_initial, temps_final, temps_cpu;
  
  
  matrice1 = malloc(sizeof(int*) * 3);
  for(int i =0; i<3 ; i++){
    matrice1[i] = malloc(sizeof(int) * 3);
  }
  
  
  matrice2 = malloc(sizeof(int*) * 3);
  for(int i =0; i<3 ; i++){
    matrice2[i] = malloc(sizeof(int) * 3);
  }
  
  produit = malloc(sizeof(int*) * 3);
  for(int i =0; i<3 ; i++){
    produit[i] = malloc(sizeof(int) * 3);
  }
  
   if(matrice1== NULL){
    printf("Error! Memory not allocated matrice.");
    exit(0);
   }
  
   if(matrice2== NULL){
    printf("Error! Memory not allocated matrice.");
    exit(0);
  }
  
  
  for (int i=0;i<3;i++)
  {
     for (int j=0;j<3;j++)
     {
            matrice1[i][j]= rand()%x;
     }
  }
  
  for (int i=0;i<3;i++)
  {
     for (int j=0;j<3;j++)
     {
            matrice2[i][j]= rand()%x;
     }
  }
  temps_initial = clock();
   int i, j, k;
   # pragma omp parallel for default ( none ) private (i ,j, k) shared (matrice1, matrice2, produit)
  for(i = 0; i < 3; i++)
  {
    for(j = 0; j < 3; j++)
    {
      produit[i][j]=0;
      for(k = 0; k < 3; k++)
      {
        produit[i][j] += matrice1[i][k] * matrice2[k][j];
      }
    }
  } 
    
   printf("le produit de deux matrices carrees \n");
   for (int i=0;i<3;i++)
   {
      for (int j=0;j<3;j++)
      {
            printf("%d \t",produit[i][j]);
      }
      printf("\n");
   }
    
   temps_final = clock();
   temps_cpu =( temps_final - temps_initial)/ CLOCKS_PER_SEC; 
   printf("temps d'execution est %2.8lf\n", temps_cpu);
  
 return 0;
}
