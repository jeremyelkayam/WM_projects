/* 
   acc.c
   Purpose: An integer accumulation program. Allows for the user to enter any integer in
   octal, hexadecimal, or decimal mode, and have that integer displayed in octal, hex,
   and decimal bases.
   
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
#include <ctype.h>

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

//main menu loop; execute option or call appropriate function
int main(void)
{
  
  char mode='d';
  short stored_value=0;
  char result;

  do{
    print_acc(stored_value);
    result=print_menu();

    switch(result)
      {
	
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
	
      case 's':
	switch(mode)
	  {
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

  switch(mode)
    {
    case 'x':
      scanf("%hx",&result);
      printf("%hX\n",result);
      break;
      
    case 'd':
      scanf("%hd",&result);
      printf("%hd\n",result);
      break;
      
    case 'o':
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
  
  printf("\n**************************************\n* Accumulator:                       *\n*   Hex     :  ");

  int z=0;
  
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
  char menu[200]="\nPlease select one of the following options: \n\nO  Octal Mode \nH  Hexadecimal Mode \nD  Decimal Mode \n\nC  Clear Accumulator \nS  Set Accumulator \n\nQ  Quit \n\nOption: ";
  
  printf("%s",menu);
  char output[110];
  
  scanf("%s",output);
  printf("%s\n",output);
  
  char lower_output=tolower(output[0]);

  while(strlen(output)!=1 ||
	
	(lower_output!='o' &&
	 lower_output!='h' &&
	 lower_output!='d' &&
	 lower_output!='c' &&
	 lower_output!='s' &&
	 lower_output!='q')){

    printf("\nInvalid option: %s\n%s",output,menu);
    
    scanf("%s",output);
    printf("%s\n",output);
    
    lower_output=tolower(output[0]);
    
  }
  
  return lower_output;
}


//TODO: implement the following

unsigned short get_binary_op (char *bin)
{
  return 0;
}

void convert_to_binary (short acc, char *bin)
{

}

void add (short *acc, char mode)
{

}

void subtract (short *acc, char mode)
{

}
