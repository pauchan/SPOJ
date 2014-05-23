#include <stdio.h>
#include <math.h>
#include <stdlib.h>

void generatePrimes(long int x,long int y);

int main()
{
  int i;
  long int x,y;
  scanf("%d",&i);
  while(i--)
    {
      scanf("%ld %ld", &x,&y);
      generatePrimes(x,y);
    }
  return 0;
}

void generatePrimes(long int x, long int y)
{
  int a;
  long int i,j;
  int *sito = calloc(y-x,sizeof(int));
  for(i=2;i<sqrt(y+1);i++)
    {
      if(x>i)
	a = x-(x%i);
      else if(x==i)
	a = x+i;
      else
	a = 2*i+x-(x%i);
      for(j=a;j<y+1;j=j+i)
	if(j >=  x)
	     sito[j-x] = -1;
    } 

  if(x == 1) sito[0] = -1;

  for(i=0;i<y-x+1;i++)
    if(sito[i]== 0)
      printf("%ld\n",i+x);
  printf("\n");
  // for some reasons spoj gives aigarbt for free
  //free(sito);
}
