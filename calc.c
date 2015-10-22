#include <stdio.h>

int main()
{
  float num;
  float num2;
  char operatore;
  printf("Introduci l'espressione:\n");
  scanf("%f",&num);
  do 
    {
      scanf("%c",&operatore);
      switch(operatore)
	{
	case '+':
	  scanf("%f",&num2);
	  num=num+num2;
	  break;
	case '*':
	  scanf("%f",&num2);
	  num=num*num2;
	  break;
	case '/':
	  scanf("%f",&num2);
	  num=num/num2;
	  break;
	case '-':
	  scanf("%f",&num2);
	  num=num-num2;
	  break;
	case '=':
	  break;
	default:
	  {
	    printf("ERRORE\n");
	    return 1;
	  }
	}
    }
  while (operatore!='=');
  printf("%g\n",num);
  return 0;
}
