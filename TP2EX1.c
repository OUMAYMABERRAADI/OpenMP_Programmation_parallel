#include <stdio.h>
#include <omp.h>

int main(int argc, char** argv)
{
  int i,j;
  i=1;
  j=2;
  #pragma omp parallel default(none) shared(i)  private(j)
  {
    i = i+1;
    j = i+1;
    
    printf("i = %d j= %d\n", i, j);
  }
  return 0;
}
