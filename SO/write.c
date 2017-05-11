#include <stdlib.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/mman.h>
#include <string.h>

int main(){
  int in, out;
  void* from, *to;
  size_t size;
  char endchar= '\0';
  
  if((in= open("ciao_gio.txt",O_RDONLY))==-1)
    {
      fprintf(stderr,"impossibile aprire ciao_gio.txt");
      exit(2);
    }
  
  if((out= open("copia.txt",O_CREAT | O_RDWR | O_TRUNC, 0666))==-1) // specifiche == fopen(, "w")
    {
      close(in);
      fprintf(stderr,"impossibile creare copia.txt");
      exit(2);
    }

  size= lseek(in, 0, SEEK_END); //modo veloce per conoscere la lunghezza del file
  lseek(out, size-1, SEEK_SET); //torno all'inizio
  write(out, &endchar, 1);
  
  if((from= mmap(NULL, size, PROT_READ, MAP_SHARED, in, 0)) == MAP_FAILED) //MAP_FAILED= (void*) -1
    {
      close(out);
      close(in);
      fprintf(stderr,"impossibile mappare ciao_gio.txt");
      exit(2);
    }

  if((to= mmap(NULL, size, PROT_WRITE, MAP_SHARED, out, 0)) == MAP_FAILED) //MAP_FAILED= (void*) -1
    {
      close(out);
      close(in);
      munmap(from,size);
      fprintf(stderr,"impossibile mappare copia.txt");
      exit(2);
    }

  memcpy(to,from,size);

  munmap(from, size);
  munmap(to, size);	 
  close(in);	 
  close(out);

  return 0;
}
