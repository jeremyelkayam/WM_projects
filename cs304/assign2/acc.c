// @author Jeremy Elkayam
#include <stdio.h>
#include <ctype.h>

//read in numeric value in mode, return value
short get_operand(char mode);
//print out accumulator values
void print_acc(short acc);
//print menu and get option
char print_menu(void);

int value=0;

//main menu loop; execute option or call appropriate function
int main(void)
{
  char result;
  do{
    result=print_menu();
    printf("result: %c\n",result);

  }while(result!='q');

  return 0;
}

short get_operand(char mode)
{
  // TODO: implement
  return 0;
}

void print_acc(short acc)
{
  //TODO: implement
}

char print_menu(void)
{
  printf("****************************************\n* Accumulator:                         *\n*   Hex     :  %x,                    *\n*   Octal   :  %o                  *\n*   Decimal :  %d                       *\n****************************************\nPlease select one of the following options: \n\nO  Octal Mode \nH  Hexidecimal Mode \nD  Decimal Mode \n\nC  Clear Accumulator \nS  Set Accumulator \nQ  Quit \n\nOption: ",value,value,value);

  char output;
  
  scanf("%c",&output);
  
  output=tolower(output);

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
  return output;
}
