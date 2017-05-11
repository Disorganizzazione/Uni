#include <stdlib.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/mman.h>

#define N 1000

int main(){

  int fd= open("ciao_gio.txt",O_CREAT | O_WRONLY, S_IRUSR | S_IWUSR);
  //specifiche O_ per l'apertura, S_ per i diritti (solo in caso di creazione)

  char t[]="ciao giorgio!   ";
  
  for(int i= 0; i<N;i++)
    write(fd, &t[(i%16)], 1);

  void * mappa= mmap(NULL, N, PROT_NONE, MAP_SHARED, fd, 0);
  //shared => modifiche applicate su disco (inv: MAP_PRIVATE)


  munmap(mappa, N); //necessario
	 
  close(fd); //non elimina il mapping

  return 0;
}
