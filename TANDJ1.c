#include <stdio.h>
#include <stdint.h>

int check_left_step(int l, int k){
    if(((k%2!=0)&&(l%2!=0))||((k%2==0)&&(l%2==0))){
        printf("\n YES");
    }else {
        printf ("\n NO");
    }
}
int step(int a, int b, int c, int d){
    int step, step1, step2;
    if(a>c){
        step1 = a-c;
    }else{
        step1 = c-a;
    }
    
    if(b>d){
        step2 = b-d;
    }else{
        step2 = d-b;
    }
    step = step1+step2;
    return step;
}

int main(void) {
	int T,a,b,c,d,K;
	scanf("%d",&T);
	while(T--){
	    scanf("%d %d %d %d %d",&a,&b,&c,&d,&K);
	    int tjK = step(a,b,c,d);
	    if(tjK>K)
	    {
	        printf("\n NO");
	    }else if (tjK == K)
	    {
	        printf("\n YES");
	    }else
	    {
	        check_left_step (tjK, K);
	    }
	}
	return 0;
}

