#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int getAnswer(int n, int p);

int main()
{
	int x;
	scanf("%d",&x);
	int n = 4000000007;
	int resp = getAnswer(x,n);
	printf("%d\n",resp);
	return 0;
}


int getAnswer(int n, int p)
{
  long double  k = 2;
  int val = powl(k,(long double)(p-1)/2)%p;
  printf("%d",val);
  
  printf("%d",k);
  long double x = powl((k + sqrt(k^2-n)),(p+1)/2);
  return (int)x;
}
