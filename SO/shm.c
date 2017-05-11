#include <sys/ipc.h>
#include <sys/shm.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <string.h>

int main(int argc, char* argv[]){
  int shmid= 0;
  int pid= 0;
  char *p;
  if((shmid= shmget(IPC_PRIVATE,sizeof("ciao giorgio!"),0644|IPC_CREAT|IPC_EXCL)) == -1)
    puts("errore");
  printf("%d\n",shmid);
  pid= fork();
  switch(pid)
    {
    case 0://figlio
      p= shmat(shmid,(void*)0,0);
      if(p== (void*)-1) puts("figlio: memoria non accessibile");
      strcpy(p,"ciao giorgio!");
      shmdt(p);
      break;
    case -1:
      puts("altro errore");
      break;
    default://padre
      wait(NULL);
      p=shmat(shmid,(void*)0,0);
      if(p== (void*) -1) puts("padre: memoria non accessibile");
      else
	printf("Nella memoria c'è scritto: %s\n",p);
      shmdt(p);
      shmctl(shmid,IPC_RMID,0);
    }
  return 0;
}
