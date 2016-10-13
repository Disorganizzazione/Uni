#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

int main(int argc, char *argv[]){

  int len= argc-1;
  int arr[len];

  for(int i= 0; i < len; i++)
    arr[i]= atoi(argv[i+1]);

  int par= len%2? 0: 1;
  int ret= INT_MIN;
  int str= (len-1)/2;
  int end= str +par;
  int mid= str + 1;
  int tot= arr[str];
  int lef= 0;
  int rig= 0;

  printf("%d,%d\n",str,end);
  if(par)
    tot+= arr[end];
  printf("tot: %d\n", tot);
  if(tot > ret)
    ret= tot;
  if(par){
    lef= arr[str];
    printf("left: %d ", lef);
    if(lef > ret)
      ret= lef;
    else{
      rig= tot-lef;
      printf("right: %d", rig);
      if(rig > ret)
	ret= rig;
    }
    puts("");
  }
  printf("max: %d\n", ret);
  str--;
  end++;
  
  while(str >= 0){
    
    printf("\n%d,%d\n",str,end);
    tot+= arr[str] + arr[end];
    printf("tot: %d\n", tot);
    if(tot > ret)
      ret= tot;   
    lef= 0;
    
    for(int i= str; i <= mid ; i++){
      
      lef+= arr[i];
      printf("left: %d ", lef);
      if(lef > ret)
	ret= lef;
      else{
	rig= tot-lef;
	printf("right: %d", rig);
	if(rig > ret)
	  ret= rig;
      }
      puts("");
    }
    printf("max: %d\n", ret);
    str--;
    end++;
  }
  printf("\n[%d]\n",ret);
}
