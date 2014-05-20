#include <stdio.h>

int main()
{
  int c;

  while(1)
    {
      scanf("%d",&c);
      if(c == 42)
	break;
      else
	printf("%d\n",c);
    }
  return 0;
}
