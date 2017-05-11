#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

int dayone(int* arr, int len);
int afterthought(int* arr, int len);

int main(int argc, char *argv[]){

  int len= argc-1;
  int arr[len];

  for(int i= 0; i < len; i++)
    arr[i]= atoi(argv[i+1]);

  puts("\ndayone() = O(n^2)");

  dayone(arr,len);

  puts("\nafterthought() = O(n)");
  
  printf("max: %d\n",afterthought(arr, len));

  printf("\ndivide et impera O(n)\nmax:%d\n\n",divetimp(arr,0,len-1));

  return 0;
}

int afterthought(int* arr, int len){

  int ret= arr[0];
  int las= ret;
  
  for(int i=1; i<len; i++){
    if(las > 0)
      las+= arr[i];
    else
      las= arr[i];
    if(las > ret)
      ret= las;
  }
  
  return ret;
}

int dayone(int* arr, int len){

  int par= len%2? 0: 1;
  int ret= INT_MIN;
  int str= (len-1)/2;
  int end= str +par;
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
    printf("%d,%d: %d ",str,end,lef);
    if(lef > ret)
      ret= lef;
    else{
      rig= tot-lef;
      printf("%d,%d: %d",str,end,rig);
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
    
    for(int i= str; i < end ; i++){
      
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

  return ret;

}
