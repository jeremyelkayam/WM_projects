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
	stored_value=get_operand(mode);
      }
    
    printf("result: %c\n",result);

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
  printf("****************************************\n* Accumulator:                         *\n*   Hex     :  %X                    *\n*   Octal   :  %o                  *\n*   Decimal :  %d                       *\n****************************************\nPlease select one of the following options: \n\nO  Octal Mode \nH  Hexidecimal Mode \nD  Decimal Mode \n\nC  Clear Accumulator \nS  Set Accumulator \nQ  Quit \n\n",acc,acc,acc);
}

char print_menu(void)
{
  printf("Option: ");
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
