#include <omp.h>
#include <malloc.h>
#include <stdlib.h>
#include <time.h>


int main(int argc, char** argv)
{
  int *vect, **matrice, *a;
  int x = 10;
  double temps_initial, temps_final, temps_cpu;
  
  vect = (int*)malloc(10000*sizeof(int));
  matrice = malloc(sizeof(int*) * 10000);
  for(int i =0; i<10000 ; i++){
    matrice[i] = malloc(sizeof(int) * 10000);
  }
  a = (int*)malloc(10000*sizeof(int));
  if(vect == NULL){
     printf("Error! Memory not allocated vec.");
     exit(0);
  }

 if(matrice== NULL){
   printf("Error! Memory not allocated matrice.");
   exit(0);
  }
  
  # pragma omp parallel for
  for(int i =0; i<10000; i++)
  {
    vect[i] = rand()%x;
  }
  # pragma omp parallel for
  for (int i=0;i<10000;i++)
  {
     for (int j=0;j<10000;j++)
     {
            matrice[i][j]= rand()%x;
     }
  }
  /*
  # pragma omp parallel for
  for(int i =0; i<10000 ; i++)
  {
    printf("%d \t",vect[i]);
  }*/
   printf("\n end vecteur\n");
  /* # pragma omp parallel for
  for (int i=0;i<10000;i++)
  {
     for (int j=0;j<10000;j++)
     {
            printf("%d \t",matrice[i][j]);
     }
     printf("\n");
  }
  */
   printf("\n end matrice\n ");
  temps_initial = clock();
   int i, j;
   int sum;
   # pragma omp parallel for default ( none ) private (i ,j , sum ) shared (vect ,matrice,a)
     for (i =0; i<10000; i++) {
        sum = 0;
        for (j =0; j<10000; j ++){
           sum += matrice[i][j]*vect[j];
        }
      a[i] = sum ;
    }
    
    printf("le produit de matrice et vecteur\n");
  for(int i =0; i<10000 ; i++)
  {
    printf("%d \t",a[i]);
  }
    
   temps_final = clock();
   temps_cpu =( temps_final - temps_initial)/ CLOCKS_PER_SEC; 
   printf("temps d'execution est %2.8lf\n", temps_cpu);
  
 return 0;
}
