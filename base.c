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
  // 3b) Assuming that you want to create your own function here is the implementation
  // 3c) **SPOILERS** In order to challenge you i'm not directly sharing it. If you give up crating your own, here is the code: http://bit.ly/1jVToka
  // 4) Using scanf for this kind of operations (and scanf in general) as you know it's not very recommended.
  // 4...) Use fgets() instead.

  printf("...Programma terminato.\n");
  return 0;
}
