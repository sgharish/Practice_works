#include <stdio.h>
#define MAX 100
int main(void) {
	int T,i,a[MAX],ce =0,co =0;
	scanf("%d",&T);
	for(i=0;i<T;i++){
	    scanf("%d",&a[i]);
	    if(a[i]%2 == 0){
	    ce++;
	    }
	    else{
	        co++;
	    }
	}
if(ce>co){
    printf("\n READY FOR BATTLE");
}
else{
    printf("\n NOT READY");
}
return 0;
}
