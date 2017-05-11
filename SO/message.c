#include <stdlib.h>
#include <stdio.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <unistd.h>

int sock;

int main()
{
  printf("ciaone mi chiamo %d\n", getpid());
  return 0;
}
