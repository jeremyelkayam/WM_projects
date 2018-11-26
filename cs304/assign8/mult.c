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
  return 0;
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
	printf("0x%08d  ",rec);

	//bmult
	int bit=bmult(fac1,fac2);
	printf("0x%08d\n",bit);
      }
    }
  printf("***********************************\n");
}
