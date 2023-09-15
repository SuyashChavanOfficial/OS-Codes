#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
	int nElem = argc - 1;
	
	int i, elem;
	
/*	printf("argv[0]=%s\n", argv[0]);
	printf("argv[1]=%s\n", argv[1]);
	printf("argv[2]=%s\n", argv[2]);
	printf("argv[3]=%s\n", argv[3]);
	
	sum = num1 + num2;
	
*/

	for(i=1; i<nElem; i++) {
		elem = atoi(argv[i]);
		printf("args[%d]=%d\n", i, elem);
	}
	
	return 0;
}
