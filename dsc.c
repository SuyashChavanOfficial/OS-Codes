#include<stdlib.h>
#include<stdio.h>

void dsc(int *a, int nElem);

int main(int argc, char *argv[]) {
	int nElem = argc - 1;
	int i, elem, j=0;
	int a[ nElem ];
	
	for(i=1; i<=nElem; i++) {
		elem = atoi(argv[i]);
		a[j] = elem;
		j++;
	}
	
	dsc(a, nElem);
	printf("Sorted in the descending order:\n");
	
	for(i=0; i<nElem; i++) {
		printf("%d", a[i]);
	}
	printf("\n");
	
	return 0;
}

void dsc(int *a, int nElem) {
	int i, j, temp;
	
	for(i=0; i<nElem; i++) {
		for(j=i+1; j<nElem; j++) {
			if(a[i] < a[j]) {
				temp = a[i];
				a[i] = a[j];
				a[j] = temp;
			}
		}
	}
}
