#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int main()
{
  pid_t pid;
  int sock;
  
  printf("Sono %d\n", getpid());

  puts("fork()");

  switch(pid=fork())
    {
    case -1: //error
      perror("aborto"); exit(1);
      break;
    case 0: //child
      if(execl("./message","message", (char*)0))
	{perror("errore"); exit(1);}
      break;
    default: //parent
      ;
      int status;
      if((waitpid(-1,&status,0))==0) {perror("hoffretta"); exit(1);}
      else if(WIFEXITED(status))
	puts("mio figlio è morto (bene)");
      else
	puts("mio figlio è morto male");
    }
  return 0;
}
