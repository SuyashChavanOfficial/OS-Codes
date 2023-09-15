#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

void a_sort(int a[], int l) {
	int i, j;
	for(i = 0; i<l; i++) {
		for(j=i+1; j<l; j++) {
			if(a[j] < a[i]) {
				int temp = 0;
				temp = a[i];
				a[i] = a[j];
				a[j] = temp;
			}
		}
	}
}

int main() {
	int a[10];
	int l, i;
	pid_t pid; // Declared pid and ppid variables.
    pid_t ppid;

	printf("Enter the limit: ");
	scanf("%d", &l);

	printf("\nDisplaying the array\n");
	for(i = 0; i < l; i++) {
		printf("%d\t", a[i]);
	}
	
	pid = fork();
	if(pid == -1) {
		printf("Error!\n");
	} else if(pid == 0) {
		pid = getpid();
		ppid = getppid();
		printf("The parent id(PID) of child is: %d\n The parent process is(PPID) of parent is: %d\n", pid, ppid);
		a_sort(a, l);
		printf("\n");
	} else {
		system("ps -el | grep Z");
		
		int i;
		i = wait(0);
		printf("\nThe teminated process' id which is in zombie state is: %d\n", i);
		printf("\nIn Parent\n");
		pid = getpid();
		ppid = getppid();
		printf("The bparent id(PID) of parent is: %d\n The Parent Process id(PPID) of grand parent(basg) is : %d\n", pid, ppid);
		a_sort(a, l);
		printf("\n");
	}

	return 0;
}

