#include <iostream>
#include <unistd.h>
#include <sys/wait.h>
#include <stdlib.h>

using namespace std;

int main(void)
{
	pid_t pid;
	pid = fork();
	if (pid<0)
		exit(0);
	else if (pid == 0)
	{
		//������ӽ���˯��1��
		cout<<"children: "<<getpid()<<endl;
		sleep(1);
	}
	else
	{ 
		cout<<"hello! i'm parent process!"<<endl;
		//����Ǹ�����������ȴ�
        //wait(): on success, returns the process ID of the terminated child; on error, -1 is returned. 
		pid_t pr = wait(NULL);
		cout<<pr<<endl;
	}
	
	return 0;
}

/*
$ ./example
hello! i'm parent process!
children: 2928
2928
*/
