#include <stdio.h>
#include <stdlib.h>

void parseExpression(const char *expression);

typedef struct varStack
{
  int stackCounter;
  char stack[400];
}varStack;

varStack *createStack()
{
  varStack *vs = malloc(sizeof(varStack));
  vs->stackCounter = 0;
  return vs;
}

void destroyStack(varStack *vs)
{
  free(vs);
}

void pushStack(varStack *vs, char a)
{
  //printf("Stack counter :%d",vs->stackCounter);
  vs->stack[vs->stackCounter] = a;
  vs->stackCounter++;
}

char popStack(varStack *vs)
{
  //printf("Stack counter :%d",vs->stackCounter-1);
  char output = vs->stack[vs->stackCounter-1];
  vs->stackCounter--;
  return output;
}

int operatorValue(char c)
{
  switch(c)
    {
    case '+':
      return 1;
    case '-':
      return 2;
    case '*':
      return 3;
    case '/':
      return 4;
    case '^':
      return 5;
    case '(':
      return 0;
    }
   return 0;
}

int main()
{
  int t;
  scanf("%d\n",&t);
  while(t--)
    {
      char c[400];
      fgets(c, 400, stdin);
      //printf("%s\n",c);
      parseExpression(c);
    }
}

void parseExpression(const char *expression)
{
  int i=0,j=0;
  varStack *vars = createStack();
  char output[400];
  while(expression[i]!='\0')
  {
    if((96 < (int)expression[i]) && (expression[i] < 123))
    {
     output[j] = expression[i];
     //printf("added letter %c",output[j]);
     j++;
    }
   else if(expression[i] == '(')
   {
	 pushStack(vars,expression[i]);
   }
   else if(expression[i] == ')')
   {
	   char cTemp;
           while((cTemp=popStack(vars))!='(')
	     {
	       output[j] = cTemp;
	       j++;
	     }
   }
   else if(expression[i] == '*' || expression[i] == '/' || expression[i] == '+' || expression[i] == '-' || expression[i] == '^') 
   {
     //printf("Stack counter :%d",vars->stackCounter);
     if(vars->stackCounter > 0)
      {
      //printf("New operator is %c on top of stack is %c \n", expression[i],vars->stack[vars->stackCounter-1]);
      while(operatorValue(expression[i]) <= operatorValue(vars->stack[vars->stackCounter-1]))
      {
         output[j] = popStack(vars);
         //printf("popped %c",output[j]);
         j++;
        //else
      }
      }
     pushStack(vars,expression[i]);
   }
   else
   {
     break;
   }
  i++;
  }
  while(vars->stackCounter > 0)
    {
      char a  = popStack(vars);
      if(a != '(')
	{
	output[j] = a;
	j++;
	}
    }
  output[j]='\0';
  printf("%s\n",output);
  //printf("Pointer to stack: %p", vars);
  //destroyStack(vars);
}
