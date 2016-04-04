#include <stdio.h>
#include <stdlib.h>

int rows= 0;
int cols= 0;
int* tab;

void intab();
void printab();
void gauss(int i, int j);
int colsum();

int main(int argc, char* argv[])
{
  if(argc!=3)
    { printf("Input errato:\n %s (int_righe) (int_colonne)\n", argv[0]); return -1; }
  else 
    if((rows=atoi(argv[1]))<=0 || (cols=atoi(argv[2]))<=0)
      { printf("Valori non ammessi:\n  %s (int_righe) (int_colonne)\n", argv[0]); return -1; }

  int local[rows][cols];
  tab= local[0];
  
  intab();
  printab();
  gauss(0,0);
  printab();

  return 0;
}

void intab()
{
  char input[20];
  for(int r= 0; r< rows; r++)
    for(int c= 0; c< cols; c++)
      {
	printf("a[%d][%d]: ",r+1 ,c+1 );
	scanf("%s", input);
	if(input[0]=='q')
	  exit(0);
	tab[c+r*cols]= atoi(input);
      }
}

void printab()
{
  puts("");
  for(int r= 0; r< rows; r++)
    {
      for(int c= 0; c< cols; c++)
	printf("%d ", tab[c+r*cols]);
      puts("");
    }
}

void gauss(int i, int j)
{
  if(i!=rows && j!=cols)
    {
      if(!colsum(j))
	gauss(i, j-1);
    }
}

int colsum(int j)
{
  int ret= 0;
  for(int r= j; r<rows; r++)
    ret+= tab[r*cols];
  return ret;
}
