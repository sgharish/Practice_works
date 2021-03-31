#include <stdio.h>

int main(void) {
	int T;
	scanf("%d",&T);
	if(T%4==0){
	    T++;
	    printf("\n %d",T);
	}
	else{
	    T--;
	    printf("\n %d",T);
	}
	return 0;
}