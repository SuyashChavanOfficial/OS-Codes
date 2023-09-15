#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>

int main(int argc, char *argv[]) {
	char *args[3];
	
	args[0] = argv[1];
	args[1] = argv[2];
	args[2] = (char*)0;
	
	printf("args[0] = %s\n", args[0]);
	printf("args[1] = %s\n", args[1]);
	printf("args[2] = %s\n", args[2]);
	
	printf("h1\n");
	
	execv(argv[1], args);
	
	printf("h2\n");

return 0;	
}
