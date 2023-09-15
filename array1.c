#include <iostream>
#include <sys/types.h>
#include <unistd.h>

int main(int argc, char *argv[]) {
	int nElem = argc - 2;
	char *args[ nElem + 1 ];
	
	int i,j=2;
	printf("nElem=%d\n", nElem);
	
	args[0] = argv[1];
	
	for(i=0; i<=nELem; i++) {
		args[i] = args[j];
		printf("argv[%d]=%5\n", j, argv[j]);
		j++;
	}
	
	args[i] = (char*)0;
	for(i=0; i<=nElem+1; i++) {
		printf("args[%d]=%s\n", i, args[i]);
	}
	
	execv(argv[1], args);
	return 0;
}
