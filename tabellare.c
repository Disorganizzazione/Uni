#include <stdio.h>
#include <string.h>

int main(int argc, char *argv[])
{
  if(argc==1)
    {
      printf("Inserire i minterm dopo %s\n", argv[0]);
      return 1;
    }  

  int vari= strlen(argv[1]); //numero variabili
  int mint; //numero mintermini
  int max= 1; //massimo numero di mintermini (2^'numero variabili')
  int results=1; //numero di risultati
  int implicanti=0; //implicanti primi

  for(int x=0; x < vari;x++)    // home-made 2^n 
    max= max*2;

  char input[argc-1][vari];

  char minterm[max][vari]; //array bidimensionale: lista di mintermini
  char result[max][vari]; //array bidimensionale: risultato
  char impl[max][vari]; //implicanti primi

  mint=argc-1;
			
  for(int x=0; x < mint; x++)
    for(int y=0; y < vari; y++)
      input[x][y]=minterm[x][y]=argv[x+1][y];

  printf("Calcolo...\n");

  while(results!=0)
    {
      results=0;
      for( int x=0; x < mint; x++)        // confronto ogni valore
	for( int f=0; f < mint -x; f++)   //con ogni altro valore successivo 
	  {
	    int match=0;   //numero di riscontri positivi per minterm

	    for( int y=0; y < vari; y++)  //per 'numero di variabili' cifre
	      if(minterm[x][y]==minterm[x+f][y])
		match++;

	    if(match==vari-1)              //se differiscono di un solo carattere 
	      {
		for( int y=0; y < vari; y++)
		  {
		    if(minterm[x][y]!=minterm[x+f][y])
		      result[results][y]='-';    //salva il valore meno quel carattere
		    else
		      result[results][y]=minterm[x][y];
		  }	 
		results++;
	      }      
	
	  }
		
      for(int x=0; x < results; x++)
	{
	  for(int y=0; y < vari; y++)
	    printf("%c", result[x][y]);
	  printf("\n");
	}
      printf("... %d da ridurre.\n", results);
		
      for(int x=0; x < mint; x++)  //confronta ogni valore
	{
	  int nope=0; 
						
	  for(int s=0; s < results; s++)  //con ogni risultato
	    {
	      int match=0;   //numero riscontri positivi
			
	      for(int y=0; y < vari; y++) //controllo ogni cifra
		if(minterm[x][y]==result[s][y])
		  match++;
	      if(match < vari-1)
		nope++;
	    }
							
	  if(nope==results)
	    {
	      int idem=0;

	      for(int t=0; t < implicanti; t++)
		{
		  int match=0;
				
		  for(int y=0; y < vari; y++)
		    if(impl[t][y]==minterm[x][y])
		      match++;
		  if(match==vari)
		    idem++;
		}
								
	      if(idem==0)
		{
		  for(int y=0; y < vari; y++)    
		    impl[implicanti][y]=minterm[x][y];
		  implicanti++;
		}
	    }
	}


      for(int x=0; x < implicanti; x++)
	{
	  for(int y=0; y < vari; y++)
	    printf("%c", impl[x][y]);
	  printf("\n");
	}
      printf("... %d implicanti primi.\n", implicanti);

      mint=results;
      for(int x=0; x < mint; x++)
	for(int y=0; y < vari; y++)
	  minterm[x][y]=result[x][y];
					
      printf("-----------------\n");
    }

  int implres= implicanti;
  int mintres= argc-1;

  printf("'y' per continuare: ");
  if(getc(stdin)=='y')
  for(int x =0; x <8; x++)
    {  
      for(int x=0; x < mintres; x++)
	{
	  for(int y=0; y < vari; y++)
	    printf("%c", input[x][y]);
	  printf("\n");
	}
      printf("... %d minterm non coperti.\n", mintres);
  
      int tot=0;

      {
	for(int x=0; x < mintres; x++)
	  {
	    int yep=0;
	
	    for(int z=0; z < implres; z++)
	      {
		int match=0;
	    
		for(int y=0; y < vari; y++)
		  if(impl[z][y]==input[x][y] || impl[z][y]=='-')
		    match++;
		if(match==vari)
		  yep++;
	      }
	    if(yep==1)
	      {
		
	      }
      
	  }
      }
    }
  return 0;
}

