#include <stdio.h>
#include <omp.h>
#include <malloc.h>
#include <stdlib.h>

int main(int argc, char** argv)
{
  int *vect1, *vect2, *somme;
  int x = 10;

  vect1 = (int*)malloc(5*sizeof(int));
  vect2 = (int*)malloc(5*sizeof(int));
  
  somme = (int*)malloc(5*sizeof(int));

  if(vect1 == NULL){
     printf("Error! Memory not allocated vec1.");
     exit(0);
  }

 if(vect2 == NULL){
   printf("Error! Memory not allocated vec2.");
   exit(0);
  }
  
  if(somme == NULL){
   printf("Error! Memory not allocated somme.");
   exit(0);
  }
  
  
  for(int i =0; i<5 ; i++)
  {
    vect1[i] = rand()%x;
  }
  
  for(int i =0; i<5 ; i++)
  {
    vect2[i] = rand()%x;
  }
  
  int j;
  # pragma omp parallel for private(j) shared(somme, vect1, vect2)
    for(j =0; j<5; j++)
    {
       somme[j] = vect1[j] + vect2[j];
    }
     printf("vect1: \n");
    for(int j =0; j<5; j++)
    {
       printf("%d \t",vect1[j]);
    }
   printf("\n");
   printf("vect2: \n");
   for(int j =0; j<5; j++)
    {
       printf("%d \t",vect2[j]);
    }
   printf("\n");
    printf("somme: \n");
   for(int j =0; j<5; j++)
    {
       printf("%d \t",somme[j]);
    }
   printf("\n");
 return 0;
}
