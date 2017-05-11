#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <sys/wait.h>
#include <string.h>

int main(int argc, char* argv[])
{
  int pipefd[2]; // [0] read, [1] write
  int ceci_nes_pas_une;
  pid_t cpid;
  char buff;

  assert(argc == 2); // x debug, esce se non passa il controllo
  
  ceci_nes_pas_une= pipe(pipefd); //unidirectional, FIFO
  if(ceci_nes_pas_une == -1)
    {
      fprintf(stderr,"no pipe"); exit(1);
    }

  //STDOUT_FILENO == standard output
  cpid= fork();
  switch(cpid)
    {
    case -1:
      fprintf(stderr,"aborto"); exit(1);
    case 0: //figlio
      fprintf(stdout,"figlio: ciao\nfiglio: ");
      int i= 0;
      while(argv[1][i]!='\0')
	{
	  if(!(write(pipefd[1],&argv[1][i], 1)))
	    {
	      fprintf(stderr,"figlio: non so scrivere\n"); exit(1);
	    }
	  else i++;
	}
      write(pipefd[1],&argv[1][i],1);
      break;
    default: //padre
      fprintf(stdout,"padre: ciaone\n");
      while(1)
	{
	  if(!(read(pipefd[0],&buff,1)))
	    {
	      fprintf(stderr,"padre: non so leggere\n"); exit(1);
	    }
	  if(buff=='\0')
	    break;
	  fprintf(stdout,"%c",buff);
	}
      puts("");
    }
  
  return 0;  
}

