#include <stdio.h>

int main(void) {
	int T,a,count=0;
	scanf("%d",&T);
	while(T--){
	    scanf("%d",&a);
	    while(a!=0){
	    if(a>=100){
	        a = a -100;
	        count++;
	    }
	    else if(a>=50&&a<100){
	        a= a - 50;
	        count++;
	    }
	    else if(a>=10&&a<50){
	        a = a-10;
	        count++;
	    }
	    else if(a>=5&&a<10){
	        a =a-5;
	        count++;
	    }
	    else if(a>=2&&a<5){
	        a=a - 2;
	        count++;
	    }
	    else {
	        a = a-1;
	        count++;
	    }
	    }
	    printf("\n %d",count);
	    count =0;
	}
	return 0;
}

