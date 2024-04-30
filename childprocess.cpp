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
return 0;
}
