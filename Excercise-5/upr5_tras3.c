#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <wait.h>

#define CMD "wc -l $PWD"

int main(int argc, char *argv[])
{
  int fd, i = 2, nb1, status;
  char buf[5];
  if (fork() == 0)
  {
    ++i;
    exit(0);
  }
  else
  {
    if (execlp(CMD, CMD, (char *)0) == -1)
    {
      --i;
      wait(&status);
      printf("Stoinostta na i= %d\n", i);
    }
    else
      printf("Stoinostta na i= %d\n", i);
  }
}
