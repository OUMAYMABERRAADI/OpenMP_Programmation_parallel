#include <stdio.h>
#include <omp.h>

int main(int argc, char** argv)
{
  int N=20;
  int L = -1;
  #pragma omp parallel shared(N)
  {
    for(int i=0; i< omp_get_max_threads() ;i++)
    {
      if(i == omp_get_thread_num())
      {
        if(L < N-1)
        {
          printf("Processeur %d execute de %d à %d\n", omp_get_thread_num()+1, L+1, L+5);
          L= L+5;
        }
        
      }
      #pragma omp barrier //pour trie des threads
    }
  }
  return 0;
}
