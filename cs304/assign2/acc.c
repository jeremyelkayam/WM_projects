// @author Jeremy Elkayam
#include <stdio.h>
#include <ctype.h>

//read in numeric value in mode, return value
short get_operand(char mode);
//print out accumulator values
void print_acc(short acc);
//print menu and get option
char print_menu(void);


//main menu loop; execute option or call appropriate function
int main(void)
{
  short stored_value=0;
  char mode='d';
  char result;
  do{
    print_acc(stored_value);
    result=print_menu();

    if(result=='d')
      {
	mode=result;
	printf("Mode is Decimal.\n");
      }
    else if(result=='h')
      {
	mode='x';
	printf("Mode is Hexadecimal.\n");
      }
    else if(result=='o')
      {
	mode=result;
	printf("Mode is Octal.\n");
      }
    else if(result=='c')
      {
	stored_value=0;
	printf("Cleared.\n");
      }
    else if(result=='s')
      {
	printf("Value: ");
	stored_value=get_operand(mode);
      }
    else if(result=='q')
      {
	printf("Hope to see you again soon!\n");
      }
    else
      {
	printf("Invalid option specified.\n");
      }

    
    //printf("\nnumber of digits\n\ndecimal: %d\noctal: %d\nhex: %d",d_digits,o_digits,x_digits);

  }while(result!='q');

  return 0;
}

short get_operand(char mode)
{
  short result;
  
  char asking_for[2];
  asking_for[0]='%';
  asking_for[1]=mode;

  scanf(asking_for,&result);
  
  return result;
}

void print_acc(short acc)
{
  int decimal_digits=snprintf(NULL, 0, "%d", acc) - (acc < 0);
  int octal_digits=snprintf(NULL, 0, "%o", acc) - (acc < 0);
  int hex_digits=snprintf(NULL, 0, "%x", acc) - (acc < 0);
  
  printf("****************************************\n* Accumulator:                         *\n*   Hex     :  %X",acc);
  for(int z=0;z<24-hex_digits;z++)
    {
      printf(" ");
    }
  
  printf("*\n*   Octal   :  %o",acc);
  for(int z=0;z<24-octal_digits;z++)
    {
      printf(" ");
    }
  
  printf("*\n*   Decimal :  %d",acc);
  for(int z=0;z<24-decimal_digits;z++)
    {
      printf(" ");
    }
  printf("*\n****************************************\n");
  
}

char print_menu(void)
{
  
  printf("Please select one of the following options: \n\nO  Octal Mode \nH  Hexidecimal Mode \nD  Decimal Mode \n\nC  Clear Accumulator \nS  Set Accumulator \nQ  Quit \n\nOption: ");
  char output[100];
  
  scanf("%s",output);
  
  output[0]=tolower(output[0]);

  /*
  while(output!='o' &&
	output!='h' &&
	output!='d' &&
	output!='c' &&
	output!='s' &&
	output!='q'){
    printf("No valid input received.\nOption: ");
    scanf("%c",&output);
  }
  */
  return output[0];
}
