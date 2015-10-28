#include <stdio.h>

int main(int argc, char *argv[])
{
	int vari; //numero variabili
	int mint; //numero mintermini
	int max= 1; //massimo numero di mintermini (2^'numero variabili')
	int results=1; //numero di risultati
	int implicanti=0; //implicanti primi

	printf("Numero varabili? (massimo 26)\n");
	scanf("%d", &vari);

	for(int x=0; x < vari;x++)    // home-made 2^n 
		max= max*2;

	char minterm[max][vari]; //array bidimensionale: lista di mintermini
	char result[max][vari]; //array bidimensionale: risultato
	char impl[max][vari]; //implicanti primi

	if(argv[1]=="bho") //non funiona :C
		{
			mint=argc-2;
			
			for(int x=0; x < mint; x++)
				for(int y=0; y < vari; y++)
					minterm[x][y]=argv[x][y];
		}
	else
		{
			printf("Numero minterm? (massimo %d)\n", max);
			scanf("%d", &mint);
		
			printf("Inserire i minterm. ('0'=falso,'1'=vero,'-'=assente)\n");
	
			for(char lettera= 'A';lettera - 64 <= vari; lettera++) //stampa una lettera per variabile
				printf("%c", lettera);
			printf("\n");  
		
			for( int counter=1; counter <= mint; counter++ ) //salvo i minterm su array bidimensionale
				{   
					scanf("%s", &minterm[counter-1][0]);
					printf("Valori salvati: %d/%d\n",counter, mint);
				}
		}	
		
	printf("Calcolo...\n");

	while(results!=0)
		{
			results=0;
				for( int x=0; x < mint; x++)        // confronto ogni valore
					for( int f=0; f < mint -x; f++)   //con ogni altro valore successivo 
						{
							int match=0; //numero di riscontri positivi per minterm

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
			
								for(int y=0; y < vari; y++) //contollo ogni cifra
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
}
