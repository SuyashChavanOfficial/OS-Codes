#include <pthread.h>
#include <semaphore.h>
#include <stdio.h>

void *thread(void *argp);

int main() {
	pthread_t tid;
	int value;
	pthread_create(&tid, NULL, thread, NULL);
	pthread_join(tid, (void*)&value);
	printf("val=%d\n", value);
	
	return 0;
}

void* thread(void *argp) {
	int a = 5;
	
	return (void*)a;
}
