/* 
   acc.c
   Purpose: An integer accumulation and calculation program. Allows for the user
   to enter any integer in binary, octal, hexadecimal, or decimal mode, and have
   that integer displayed in binary, octal, hex, and decimal bases. Also allows
   simple bit-level calculations including negation, bitwise boolean operations,
   and addition.
   
   @author Jeremy Elkayam
 */
#include <stdio.h>
#include <string.h>
/*
  The below include statement is commented out because the assignment required
  students to only use the stdio.h and string.h built-in libraries. On the
  William & Mary CS department's lab machines, tolower is a member of string.h
  and not ctype.h. If you get errors or warnings when trying to compile, just
  un-comment the line below and it should work.
 */
//#include <ctype.h>

//read in numeric value in mode, return value
short get_operand(char mode);
//print out accumulator values
void print_acc(short acc);
//print menu and get option
char print_menu(void);
// convert bin str to short; return value
unsigned short get_binary_op (char *bin);
// convert acc to binary str for output
void convert_to_binary (short acc, char *bin);
// call get_operand to get val in mode to add to accum; detect pos/neg overflow
void add (short *acc, char mode);
// similar to add, but subtract
void subtract (short *acc, char mode);

//minimum and maximum short 
const short MIN_SHORT=-32768;
const short MAX_SHORT=32767;  

//main menu loop; execute option or call appropriate function
int main(void)
{

  //mode defaults to decimal and accumulator to 0
  char mode='d';
  short stored_value=0;
  char result;

  do{
    print_acc(stored_value);
    result=print_menu();

    switch(result)
      {
      case 'b':
	mode=result;
	printf("Mode is Binary\n");
	break;
	
      case 'd':
	mode=result;
	printf("Mode is Decimal\n");
	break;
	
      case 'h':
	mode='x';
	printf("Mode is Hexadecimal\n");
	break;
	
      case 'o':
	mode=result;
	printf("Mode is Octal\n");
	break;
	
      case 'c':
	stored_value=0;
	break;

      case 'n':
	//just use built-in negation as the machine does two's complement for us
	stored_value=-stored_value;
	break;

      case '~':
	//once again, C has built-in bitwise negation so no need to do anything
	//fiddly
	stored_value=~stored_value;
	break;

      case '<':
	printf("Enter number of positions to left shift accumulator: ");
	//built-in left shift
        stored_value = stored_value << get_operand('d');
	break;

      case '>':
	printf("Enter number of positions to right shift accumulator: ");
	//built-in right shift
        stored_value = stored_value >> get_operand('d');
	break;

      case '&':
	switch(mode)
	  {
	  case 'b':
	    printf("Enter binary value: ");
	    break;
	    
	  case 'd':
	    printf("Enter decimal value: ");
	    break;
	    
	  case 'o':
	    printf("Enter octal value: ");
	    break;
	    
	  case 'x':
	    printf("Enter hex value: ");
	    break;
	    
	  }
	//just use the built-in bitwise and for the current value and the
	//entered value
	stored_value = stored_value & get_operand(mode);
	break;
	
      case '|':
	switch(mode)
	  {
	  case 'b':
	    printf("Enter binary value: ");
	    break;
	    
	  case 'd':
	    printf("Enter decimal value: ");
	    break;
	    
	  case 'o':
	    printf("Enter octal value: ");
	    break;
	    
	  case 'x':
	    printf("Enter hex value: ");
	    break;
	    
	  }
	//this assignment was much easier for me than the first one, since you
	//mostly just need to use a bunch of built-in operators, as seen below.
	stored_value = stored_value | get_operand(mode);
	break;
	
      case '^':
	switch(mode)
	  {
	  case 'b':
	    printf("Enter binary value: ");
	    break;
	    
	  case 'd':
	    printf("Enter decimal value: ");
	    break;
	    
	  case 'o':
	    printf("Enter octal value: ");
	    break;
	    
	  case 'x':
	    printf("Enter hex value: ");
	    break;
	    
	  }
	//bitwise xor
	stored_value = stored_value ^ get_operand(mode);
	break;
	
      case '+':
	switch(mode)
	  {
	  case 'b':
	    printf("Enter binary value: ");
	    break;
	    
	  case 'd':
	    printf("Enter decimal value: ");
	    break;
	    
	  case 'o':
	    printf("Enter octal value: ");
	    break;
	    
	  case 'x':
	    printf("Enter hex value: ");
	    break;
	    
	  }
	//call appropriate function
	add(&stored_value,mode);
	
	break;
	
      case '-':
	switch(mode)
	  {
	  case 'b':
	    printf("Enter binary value: ");
	    break;
	    
	  case 'd':
	    printf("Enter decimal value: ");
	    break;
	    
	  case 'o':
	    printf("Enter octal value: ");
	    break;
	    
	  case 'x':
	    printf("Enter hex value: ");
	    break;
	    
	  }
	//call appropriate function
	subtract(&stored_value,mode);
	
	break;
	
      case 's':
	switch(mode)
	  {
	  case 'b':
	    printf("Enter binary value: ");
	    break;
	    
	  case 'd':
	    printf("Enter decimal value: ");
	    break;
	    
	  case 'o':
	    printf("Enter octal value: ");
	    break;
	    
	  case 'x':
	    printf("Enter hex value: ");
	    break;
	    
	  }
	//call appropriate function
	stored_value=get_operand(mode);
	break;
	
      }
  }while(result!='q');

  printf("\n");

  return 0;
}

short get_operand(char mode)
{
  short result;
  char bin[200];
  int count;

  switch(mode)
    {
    case 'b':
      do{
	  scanf("%s",bin);
	  printf("%s\n",bin);

	  for(count=0;bin[count]!=0;count++);
	  if(count>16)
	    {
	      printf("Invalid input: %s \n",bin);
	      printf("Input must be 16 digits or less, without spaces.\n\nEnter binary value: ");
	    }
      }while(count>16);
      //We have a separate function for binary conversion.
      result=get_binary_op(bin);

      break;
      
    case 'x':
      //h to denote that this value is a short; x for hexadecimal
      scanf("%hx",&result);
      printf("%hX\n",result);
      break;
      
    case 'd':
      //h -> short, d -> decimal
      scanf("%hd",&result);
      printf("%hd\n",result);
      break;
      
    case 'o':
      //o -> octal, h -> short
      scanf("%ho",&result);
      printf("%ho\n",result);
      break;
      
    }
  
  return result;
}

void print_acc(short acc)
{
  int decimal_digits=snprintf(NULL, 0, "%d", acc) - (acc < 0);
  int octal_digits=snprintf(NULL, 0, "%o", acc) - (acc < 0);
  int hex_digits=snprintf(NULL, 0, "%x", acc) - (acc < 0);
  
  printf("\n**************************************\n");
  printf("* Accumulator:                       *\n");

  char bin_str[20];
  convert_to_binary(acc,bin_str);
  
  printf("*   Binary  :  %s   *\n",bin_str);
  
  
  printf("*   Hex     :  ");

  int z=0;
  //count the 0's you add until it's correct padding for all of these
  for(z=0;z<4-hex_digits;z++)
    {
      printf("0");
    }

  printf("%hX",acc);
  
  for(z=0;z<18;z++)
    {
      printf(" ");
    }
  
  printf("*\n*   Octal   :  ");

  for(z=0;z<6-octal_digits;z++)
    {
      printf("0");
    }
  
  printf("%ho",acc);
  
  for(z=0;z<16;z++)
    {
      printf(" ");
    }
  
  printf("*\n*   Decimal :  %d",acc);

  for(z=0;z<22-decimal_digits-(acc<0);z++)
    {
      printf(" ");
    }
  
  printf("*\n**************************************\n");
  
}

char print_menu(void)
{
  
  printf("\nPlease select one of the following options: \n\n");
  printf("B  Binary Mode             &  AND with Accumulator           +  Add to Accumulator\n");
  printf("O  Octal Mode              |  OR  with Accumulator           -  Subtract from Accumulator\n");
  printf("H  Hexadecimal Mode        ^  XOR with Accumulator           N  Negate Accumulator\n");
  printf("D  Decimal Mode            ~  Complement Accumulator\n\n");
  printf("C  Clear Accumulator       <  Shift Accumulator Left\n");
  printf("S  Set Accumulator         >  Shift Accumulator Right\n\n");
  printf("Q  Quit \n\n");
  printf("Option: ");
  

  char output[110];
  
  scanf("%s",output);
  printf("%s\n",output);
  
  char lower_output=tolower(output[0]);
  //the correct options
  while(strlen(output)!=1 ||
	(lower_output!='+' &&
	 lower_output!='-' &&
	 lower_output!='^' &&
	 lower_output!='|' &&
	 lower_output!='&' &&
	 lower_output!='>' &&
	 lower_output!='<' &&
	 lower_output!='~' &&
	 lower_output!='n' &&
	 lower_output!='b' &&
	 lower_output!='o' &&
	 lower_output!='h' &&
	 lower_output!='d' &&
	 lower_output!='c' &&
	 lower_output!='s' &&
	 lower_output!='q')){

    printf("\nInvalid option: %s\n",output);
    

    printf("\nPlease select one of the following options: \n\n");
    printf("B  Binary Mode             &  AND with Accumulator           +  Add to Accumulator\n");
    printf("O  Octal Mode              |  OR  with Accumulator           -  Subtract from Accumulator\n");
    printf("H  Hexadecimal Mode        ^  XOR with Accumulator           N  Negate Accumulator\n");
    printf("D  Decimal Mode            ~  Complement Accumulator\n\n");
    printf("C  Clear Accumulator       <  Shift Accumulator Left\n");
    printf("S  Set Accumulator         >  Shift Accumulator Right\n\n");
    printf("Q  Quit \n\n");
    printf("Option: ");


    
    scanf("%s",output);
    printf("%s\n",output);
    
    lower_output=tolower(output[0]);
    
  }
  
  return lower_output;
}


//TODO: implement the following

unsigned short get_binary_op (char *bin)
{
  int total=0;
  int dex;

  for(dex=0;bin[dex]!=0;dex++)
    {
      total *= 2;
      if(bin[dex]=='1')
	{
	  total++;
	}
    }
  
  return total;
}

void convert_to_binary (short acc, char *bin)
{
  //convert acc to an unsigned short
  unsigned short max_u_short=-1;
  unsigned short u_acc=acc+max_u_short+1;
  
  short rem;
  int dex;
  for(dex=18;dex>=0;dex--)
    {
      if(dex==4 || dex==9 || dex==14)
	{
	  //account for proper spacing between groups of 4 digits
	  bin[dex]=' ';
	}
      else
	{
	  rem=u_acc%2;
	  u_acc=u_acc/2;
	  //remainder will be 0 or 1, so advancing 1 in the ascii table gets us
	  //the digit 1
	  bin[dex]=rem+'0';
	}
    }
  bin[19]=0;
}

void add (short *acc, char mode)
{
  short part=get_operand(mode);
  if(part > 0)//adding a positive
    {
      if(part > MAX_SHORT - *acc)
	{
	  printf("Overflow Error\n");
	}
    }
  else if(part < 0)//adding a negative
    {
      if(part < MIN_SHORT - *acc)
	{
	  printf("Negative Overflow Error\n");
	}
    }
  
  *acc+=part;
}

void subtract (short *acc, char mode)
{
  short part=get_operand(mode);

  if(part > 0) // subtract a positive
    {
      if(*acc < MIN_SHORT + part )
	{
	  printf("Negative Overflow Error\n");
	}
    }
  else if(part < 0)// subtract a negative
    {
      if(*acc > MAX_SHORT + part )
	{
	  printf("Overflow Error\n");
	}
    }

  *acc-=part;
}
