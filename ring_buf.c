#include<stdio.h>
#include<math.h>
#include<stdlib.h>
#include<pthread.h>

#define MAX 10
int buf_write();
int buf_read();
int r_buf[MAX];
int head = 0, tail =0, n=1,m =0,a= 1;
void *add_t(){
	int r =0;
	while(r<100){
	 r += a;
	 buf_write(r);
	}

}
void *multi_t(){
	int r = buf_read();
	int c = buf_read();
	printf("\n %d \t %d",r,c);
	printf("%d",r*c);
}		
int buf_write(int n){
	r_buf[head] = n;
	head++;
	
	if(head==MAX-1){
		head = 0;
	}else{
		return 0;
	}
}
int buf_read(){
	int c;
	if(tail <= head){
		c = r_buf[tail%MAX];
		tail++;	
	}
	if(tail>= MAX){
		tail = 0;
	}
}

int main(){
	pthread_t t_1;
	pthread_t t_2;
	pthread_create(&t_1,NULL,&add_t,NULL);
	pthread_create(&t_2,NULL,&multi_t,NULL);
	pthread_join(t_1,NULL);
	pthread_join(t_2,NULL);
	pthread_exit(NULL);
}
