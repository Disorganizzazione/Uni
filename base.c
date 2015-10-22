#include <stdio.h>

// Implement yourself of check the link down below
size_t custom_strlen(char* string);
unsigned int custom_strcmp(char* str1, char* str2);
// Implement yourself of check the link down below

int main()
{
  char *n;
  printf("...Programma avviato: 'quit' per terminare.\n");
  do
    {
      printf("------> %s\n",n);
    }
  while(scanf("%s", n) != EOF && !custom_strcmp(n,"quit"));
  // 1) While does not accept ','. To concatenate 2 or more conditions you must use a boolean operator such as "&&" "||" (and,or).
  // 2) Scanf returns the number of scanned and assigned values OR returns the EOF sequence (end of line).
  // 3) In order to compare strings is a good practice to include <string.h> and use the strcmp(char*,char*) function
  // 4) Using scanf for this kind of operations (and scanf in general) as you know it's not very recommended.
  // 4...) Use fgets() instead.

  printf("...Programma terminato.\n");
  return 0;
}

size_t custom_strlen(char* string)
{
  size_t _strlen = 0;
  while('\0' != *string)
    {
      string++;
      _strlen++;
    }
  return _strlen;
}

unsigned int custom_strcmp(char* str1, char* str2)
{
  unsigned int rt = 1;
  
  for(int _strlen = custom_strlen(str1); _strlen > 0; _strlen--)
    {
      if(*(str1+_strlen) != *(str2+_strlen))
	{
	  rt = 0;
	  break;
	}
    }
  return rt;
}
