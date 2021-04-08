#include <stdio.h>

int main(void) {
	int T,a,c=0;
	scanf("%d",&T);
	while(T--){
	    scanf("%d",&a);
	    int n =a;
	    while(a!=0){
	        int r = a%10; 
	         c = c*10 + r;
	        a/=10; 
	    }
	   

	    if(n==c){
	        printf("\n wins");
	    }
	    else{
	        printf("\n loses");
	    }
	    c=0;
	}
	return 0;
}
