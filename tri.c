#include <stdio.h>

int main(void) {
	int T,a,b,c;
	scanf("%d",&T);
	while(T--){
	    scanf("%d %d %d",&a,&b,&c);
	    int sum =0;
	    sum = a+b+c;
	    if(sum==180){
	        printf("\n YES");
	    }
	    else{
	        printf("\n NO");
	    }
	}
	return 0;
}