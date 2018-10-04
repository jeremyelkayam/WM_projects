/* 
   acc.c
   Purpose: An integer accumulation program. Allows for the user to enter any integer in
   octal, hexadecimal, or decimal mode, and have that integer displayed in octal, hex,
   and decimal bases.
   
   @author Jeremy Elkayam
 */
#include <stdio.h>
#include <ctype.h>
#include <string.h>

//read in numeric value in mode, return value
short get_operand(char mode);
//print out accumulator values
void print_acc(short acc);
//print menu and get option
char print_menu(void);


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
  char menu[200]="Please select one of the following options: \n\nO  Octal Mode \nH  Hexadecimal Mode \nD  Decimal Mode \n\nC  Clear Accumulator \nS  Set Accumulator \nQ  Quit \n\nOption: ";
  
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

    printf("\nInvalid option: %s\n\n%s",output,menu);
    
    scanf("%s",output);
    printf("%s\n",output);
    
    lower_output=tolower(output[0]);
    
  }
  
  return lower_output;
}
