#include<stdio.h>
#include<sys/types.h>

int a_sort(int a[], int l) {
	int i, j;
	for(i = 0; i<l; i++) {
		for(j=1; j<l; j++) {
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
	
	printf("Enter the limit: ");
	scanf("%d", &a[i]);

	printf("\nDisplaying the aray\n");
	for(i = 0; i < l; i++) {
		printf("%d\t", a[i]);
	}
	
	pid = fork();
	if(pid == -1) {
		printf("Error!");
		printf("\n");
	} else if(pid == 0) {
		pid = getpid();
		ppid = getppid();
		printf("The parent id(PID) of child is: %d \n The parent process is(PPID) of parent is: %d", pid, ppid);
		a_sort(a, l);
		printf("\n");
	} else {
		system("ps -el\grep Z");
		
		int i;
		i = wait(0);
		printf("\nThe teminated process' id which is in zombie state is: %\n", i);
		printf("\nIn Parent\n");
		pid = getpid();
		ppid = getppid();
		printf("The bparent id(PID) of parent is: %d \n The Parent Process id(PPID) of grand parent(basg) is : %d, pid, ppid");
		d_sort(a, l);
		printf("\n")
	}
	
	int a_sort(int a[10]);
	printf("\n");
	return 0;
}

