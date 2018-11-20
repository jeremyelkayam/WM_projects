/*
 * square.c
 * 
 * Purpose : Implement and test 2 simple squaring algorithms, as a warm-up for
 * implementing the same 2 processes in Y86 assembly-style language.
 * 
 * @author Jeremy Elkayam
 */
#include <stdio.h>

//Return the square of i as calculated by using repeated addition.
int squareadd(int i){
  int result=0;
  int z;
  for(z=0;z<i;z++){
    result+=i; //add i to itself i times, for a square
  }
  return result;
}
//Return the square of i as calculated by adding the powers of 2 for each bit in the binary representation of i.
int squarebit(int i){
  int sum = 0;
  int mult = i;
  int bit = 1;

  while(bit<=i){
    if(i & bit){ // if the bit is on in i, the bitwise & will be nonzero
      sum+=mult;
    }
    bit+=bit; // doubling bit is equivalent to a bitshift
    mult+=mult;
  }
  
  return sum; 
}

//Test squareadd and squarebit for values up to 20.
int main(){
  int i;
  for(i=1;i<=20;i++){
    int sqa=squareadd(i);
    int sqb=squarebit(i);

    printf("%3d%3X%4X%4X\n",i,i,sqa,sqb);
  }
  return 0;
}
