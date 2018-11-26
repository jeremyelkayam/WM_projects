/*
 * mult.c
 * 
 * Purpose: Implement and test 2 simple, machine-style methods of computing
 *          the multiple of 2 numbers.
 * @author Jeremy Elkayam
 */

#include <stdio.h>

int rmult(int i, int j)
{
  if(j == 1){
    return i;
  }
  return i + rmult(i,j-1);
}

int bmult(int i, int j)
{
  int hi,lo,result;
  
  if(i<j){
    hi=j;
    lo=i;
  }else{
    hi=i;
    lo=j;
  }//initialize hi to the higher one and lo to the lower one
  result=0;
  
  int bit = 1;

  while(bit <= lo) //if bit is higher than the lower number, it's already been
    {             // shifted past all of its contents so we're done 
      if(bit & lo)// check if bit is set in lo
	{
	  result+=hi;
	}
      hi+=hi;   //doubling hi here means it will always equal hi_init * bit
                // saving us computations :)
      bit+=bit; //adding bit to itself = doubling it = shifting it left by 1
  }
  
  return result;
}

int main()
{
  int fac1,fac2;
  for(fac1=9;fac1<=12;fac1++)
    {
      printf("***********************************\n");
    for(fac2=1;fac2<=7;fac2+=2)
      {
	//native multiplication
	printf("%2d * %d = %2d  ",fac1,fac2,fac1*fac2);
	
	//rmult
	int rec=rmult(fac1,fac2);
	printf("0x%08x  ",rec);

	//bmult
	int bit=bmult(fac1,fac2);
	printf("0x%08x\n",bit);
      }
    }
  printf("***********************************\n");
}
