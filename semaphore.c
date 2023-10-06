#include <stdio.h>
#include <pthread.h>
#include <semaphore.h>

#define NITERS 5

void *producer (void *argp);
void *consumer (void *argc);

typedef struct {
	int buff;
	sem_t full, empty;
} 

Shared;

Shared Sh;

int main() {
	pthread_t ptid, ctid;
	
	sem_init (&Sh.empty, 0, 1);
	sem_init (&Sh.full, 0, 1);
	
	pthread_create (&ptid, NULL, producer, NULL);
	pthread_create (&ctid, NULL, consumer, NULL);
	
	pthread_join (ptid, NULL);
	pthread_join (ctid, NULL);
	
	return 0;
}

void *producer (void *argp) {
	
	int i, item;
	
	for (i=0; i<NITERS; i++) {
		item = i;
		printf("produced %d\n", item);
		
		sem_wait (&Sh.empty);
		Sh.buff = item;
		sem_post (&Sh.full);
	}
	
	return NULL;
	
} 

void *consumer (void *argc) {
	int i, item;
	
	for(i = 0; i<NITERS; i++) {
		sem_wait (&Sh.full);
		item = Sh.buff;
		sem_post (&Sh.empty);
		
		printf("Consumed %d\n", item);	
	}
	
	return NULL;
	
}














