#include <stdio.h>

int main(void) {
	int A,B,C;
	scanf("%d %d %d",&A,&B,&C);
	if(A>=1&&A <= 10&&B>=1&&B <= 10&&C>=1&&C <= 10){
	    if(A==B||B==C||A==C){
	        printf("\n yes");
	    }
	    else{
	        printf("\n no");
	    }
	}
}
