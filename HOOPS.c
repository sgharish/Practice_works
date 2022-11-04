#include <stdio.h>
#include <stdint.h>

int last_hoop(int N){
    int result = (N+1)/2;
    printf("\n %d",result);
}
int main(void) {
	int T,N;
	scanf("%d",&T);
	while(T--){
	    scanf("%d",&N);
	    last_hoop(N);
	}
	return 0;
}

