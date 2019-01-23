//simple execution of other things
//i forgot how to do this so it's good to relearn
#include <stdio.h>
#include <unistd.h>
#include <error.h>
#include <errno.h>

int main(int argc, char **argv)
{
  int kidpid = fork();
  char *cmd_args[] = {"./first", NULL};

  printf("before exec\n");
  
  if(execv("./firt",cmd_args) < 0){
    printf("errno %d\n", errno);
    perror("error while attempting to use exec");
  }
  
  printf("after exec\n");
    
  return 0;
}
