#include <stdio.h>

int squareadd(int i){
  int result=0;
  int z;
  for(z=0;z<i;z++){
    result+=i;
  }
  return result;
}

int squarebit(int i){
  int sum = 0;
  int mult = i;
  int bit = 0;

  while(bit<=i){
    if(i & (1<<bit)){
      sum+=mult;
    }
    bit+=1;
    mult+=mult;
  }
  
  return sum; 
}

int main(){
  int i;
  for(i=1;i<=20;i++){
    int sqa=squareadd(i);
    int sqb=squarebit(i);

    printf("%3d%3X%4X%4X\n",i,i,sqa,sqb);
  }
  return 0;
}
