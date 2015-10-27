#include <stdio.h>
#include <string.h>//forse
#include <malloc.h>//dunno

int main()
{
  int vari; //numero variabili
  int mint; //numero mintermini
  int max= 1; //massimo numero di mintermini (2^'numero variabili')
  int results=0; //numero di risultati

  printf("Numero varabili? (massimo 26)\n");
  scanf("%d", &vari);

  for(int x=1; x <= vari;x++)    // home-made 2^n 
    max= max*2;

  printf("Numero minterm? (massimo %d)\n", max);
  scanf("%d", &mint);

  char minterm[mint][vari]; //array bidimensionale: lista di mintermini
  char result[mint][vari]; //array bidimensionale: risultato

  printf("Inserire i minterm. ('0'=falso,'1'=vero,'-'=assente)\n");

  for(char lettera= 'A';lettera - 64 <= vari; lettera++) //stampa una lettera per variabile
    printf("%c", lettera);
  printf("\n");  

  for( int counter=1; counter <= mint; counter++ ) //salvo i minterm su array bidimensionale
    {   
      scanf("%s", &minterm[counter-1][0]);
      printf("Valori salvati: %d/%d\n",counter, mint);
    }
  
  printf("Calcolo...\n");
  for( int x=1; x <= mint; x++)        // confronto ogni valore
    for( int f=1; f <= mint -x; f++)   //con ogni altro valore successivo 
      {

	int match=0; //numero di riscontri positivi per minterm

	for( int y=1; y <= vari; y++)  //per 'numero di variabili' cifre
	  if(minterm[x-1][y-1]==minterm[x+f-1][y-1])
	    match++;
	if(match==vari-1)              //se differiscono di un solo carattere 
	  {
	    for( int y=1; y <= vari; y++)
	      {
		if(minterm[x-1][y-1]!=minterm[x+f-1][y-1])
		  result[results][y-1]='-';    //salva il valore meno quel carattere
		else
		  result[results][y-1]=minterm[x-1][y-1];
	      }	 
	    results++;
	  }      
	
      }
  for(int x=1; x <= results; x++)
    {
      for(int y=1; y <= vari; y++)
	printf("%c", result[x-1][y-1]);
      printf("\n");
    }
  printf("... %d risultati.\n", results);
}

