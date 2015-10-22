#include <stdio.h>

int main()
{
  char n[4];
  printf("...Programma avviato: 'quit' per terminare.\n");
  do
    {
      printf("Numero varabili?");
      int variabili;
      scanf("%d",&variabili);
      for(char variabile= 'A'; variabile - 64 <= variabili; variabile++)
	printf("%c", variabile);
    }
  while(scanf("%s", n), n[0]!='q', n[1]!='u', n[2]!='i',n[3]!='t');
  printf("...Programma terminato.\n");
  return 0;
}
