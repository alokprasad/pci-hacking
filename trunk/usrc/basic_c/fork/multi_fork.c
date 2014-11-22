#include<stdio.h>
#include<sys/types.h>
int main()
{
pid_t pid;

pid = fork();
pid = fork();
pid = fork();

printf("\n hello :%d\n ", pid);

}
