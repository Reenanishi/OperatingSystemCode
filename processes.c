#include <stdio.h>
#include <unistd.h>
int main(int argc, char* argv[])
{
/* fork a child process */
fork();
/* and fork another child process */
fork();
/* and fork another */
fork();
printf("hello\n");
return 0;
}
