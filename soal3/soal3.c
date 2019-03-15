#include  <fcntl.h>
#include  <stdio.h>
#include  <stdlib.h>
#include  <string.h>
#include  <sys/types.h>
#include  <sys/wait.h>
#include  <sys/stat.h>
#include  <termios.h>
#include  <unistd.h>


int main()
{
    pid_t pid1;
    pid_t pid2;
    pid_t pid3;
    
    int status;
    int fd[2];

    pipe(fd);

	pid1 = fork();
	if (pid1==0)
	{
	execlp ("unzip", "unzip", "/home/z/modul2/campur2.zip", NULL);
    	} 
	else 
	{	
		pid2 = fork();
		
		if(pid2==0)
		{
	    	execlp ("touch", "touch", "daftar.txt", NULL);
		} 
	else
	{

	    pid3 = fork();
	    if (pid3==0)
	    {
		close(fd[0]);
		dup2(fd[1], 1);
		execlp ("ls", "ls", "campur2", NULL);
    	    }
	else
	    {
	
	char buffer [1000];
	while ((wait(&status)) > 0);
        close(fd[1]);
	FILE* temp = fdopen(fd[0], "r");
	FILE *file = fopen ("daftar.txt", "w");
	int i=0;
	while (fgets(buffer, sizeof(buffer), temp) !=NULL);
	{ if (strstr(&buffer[strlen(buffer)-5], ".txt") !=NULL)
	fprintf (file, "%s", buffer); }
	close(fd[0]);
	fclose(file);
    	   }
	}
    }	
return 0;
}                         
