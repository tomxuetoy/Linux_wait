#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <stdio.h>

int main()
{
	pid_t pid;
	int status,i;
	
	if(fork() == 0){
		printf("This is the child process .pid =%d\n", getpid());
		exit(5);
	}
	else{
		sleep(1);
		printf("This is the parent process, its pid = %d, wait for child...\n", getpid());
        //wait(): on success, returns the process ID of the terminated child; on error, -1 is returned. 
		pid=wait(&status);
		printf("status = %d\n", status);
        //WEXITSTATUS(status): returns the exit status of the child
		i=WEXITSTATUS(status);
		printf("child's pid =%d .exit status=%d\n",pid,i);
	}
}
/*
$ ./example
This is the child process .pid =3719
This is the parent process, wait for child...
status = 1280
child's pid =3719 .exit status=5

about "status":
If status is not NULL, wait() and waitpid() store status information in the int to which it points. This integer can be inspected with the following macros: WEXITSTATUS...
*/
