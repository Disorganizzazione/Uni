#include <stdio.h>
#include <stdlib.h>

int rows= 0;
int cols= 0;
float* tab;

void intab();
void printab();
void gauss(int i, int j);
int notnull(int i, int j);
void rowswap(int i);
void rowdux(int i, int j, int r);

int main(int argc, char* argv[])
{
  if(argc!=3)
    { printf("Input errato:\n %s (int_righe) (int_colonne)\n", argv[0]); return -1; }
  else 
    if((rows=atoi(argv[1]))<=0 || (cols=atoi(argv[2]))<=0)
      { printf("Valori non ammessi:\n  %s (int_righe) (int_colonne)\n", argv[0]); return -1; }

  float local[rows][cols];
  tab= local[0];
  
  intab();
  gauss(0,0);

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
	printf("%.2g\t", tab[c+r*cols]);
      puts("\n");
    }
  puts("");
}

void gauss(int i, int j)
{
  printab();
  if(i+1<rows && j+1<cols)
    {
      if(notnull(i,j)==rows)
	gauss(i,j+1);
      else
	{
	  if(!tab[j+i*cols])
	    {
	      rowswap(notnull(i+1,j));
	      gauss(i,j);
	    }
	  else
	    if(notnull(i+1,j)!=rows)
	      {
		rowdux(i,j,notnull(i+1,j));
		gauss(i,j);
	      }
	    else
	      gauss(i+1,j+1);
	}
    }
}

int notnull(int i, int j)
{
  int r;
  for(r= i; r<rows; r++)
    if(tab[j+r*cols])
      break;
  return r;
}

void rowswap(int i)
{
  float temp;
  for(int x=0; x<cols; x++)
    {
      temp= tab[x];
      tab[x]= tab[i*cols+x];
      tab[i*cols+x]= temp;
    }
}

void rowdux(int i, int j, int r)
{
  float lambda= tab[j+r*cols]/tab[j+i*cols];
  for(; j<cols; j++)
    tab[j+r*cols]-= lambda*tab[j+i*cols];
}
