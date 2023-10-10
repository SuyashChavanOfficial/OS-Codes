#include<stdio.h>
#include<stdlib.h>
#include<pthread.h>
#include<sys/types.h>

void *reader(void *argp);
void *writer(void *argp);
int buf;

int getbuff(){
	int temp;
	printf("\nEnter the item in buffer: ");
	scanf("%d",&temp);
	return temp;
}

void readbuff(int buf) {
	printf("\nItem Read from buffer: %d\n", buf);
}

pthread_mutex_t mutex1 = PTHREAD_MUTEX_INITIALIZER;
pthread_mutex_t wrt = PTHREAD_MUTEX_INITIALIZER;

int read_count = 0;
int flag = 0;

void *writer(void *argp) {
	while(1) {
		pthread_mutex_lock(&wrt);
		if(flag == 0) {
			buf = getbuff();
			flag = 1;
		}
		pthread_mutex_unlock(&wrt);
	}
}

void *reader(void *argp) {
	while(1) {
		pthread_mutex_lock(&mutex1);
		read_count++;
		if(read_count == 1) {
			pthread_mutex_lock(&wrt);
		}
		
		pthread_mutex_unlock(&mutex1);
		
		if(flag == 1) {
			readbuff(buf);
			sleep(1);
			flag = 0;
		}
		
		pthread_mutex_lock(&mutex1);
		read_count--;
		
		if(read_count == 0) {
			pthread_mutex_unlock(&wrt);
		}
		
		pthread_mutex_unlock(&mutex1);
	}
}

int main() {

	pthread_t tid1, tid2, tid3;
	
	pthread_create(&tid1, NULL, writer, NULL);
	pthread_create(&tid2, NULL, reader, NULL);
	pthread_create(&tid3, NULL, reader, NULL);
	
	pthread_join(tid1, NULL);
	pthread_join(tid2, NULL);
	pthread_join(tid3, NULL);

	return 0;
}

/*

Enter the item in buffer: 4

Item Read from buffer: 4

Item Read from buffer: 4

Enter the item in buffer: 7

Item Read from buffer: 7

Item Read from buffer: 7

Enter the item in buffer: 11

Item Read from buffer: 11

Item Read from buffer: 11


*/
