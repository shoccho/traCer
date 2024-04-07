#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/ptrace.h>
#include <syscall.h>
#include <sys/wait.h>
#include <sys/user.h>
#include "syscall_names.h"

int main(int argc, char **argv){

	if(argc<2){
		fprintf(stderr, "%s\n","no command provided to trace" );
		return 1;
	}
	printf("tracing process %s\n", argv[1]);
	int pid = fork();
	int status;
	if(pid == 0){
		ptrace(PTRACE_TRACEME, 0, 0, 0);

		char * childArgv[] = { argv[1], NULL };
		int r = execvp(argv[1],  childArgv);
		printf("execve returned %d\n",r);
		perror("execve");
	}else{
		waitpid(pid, &status, 0);
		
	}
	
	while (status == 1407) {
		long orig_eax = ptrace(PTRACE_PEEKUSER, pid, 120, NULL);
		if(orig_eax!=-1){

			printf("syscall %s\n", syscall_names[orig_eax]);
		}
		ptrace(PTRACE_SINGLESTEP, pid, 0, 0);
		waitpid(pid, &status, 0);
	}
	return 0;
}