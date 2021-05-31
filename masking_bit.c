#include<stdio.h>
#include<stdint.h>
int main(){
	int a =7;
	int b = 3;
	int c = a+b;
	int d =a*b;
	int e = a&b;
	int f = a|b;
	f = f^1;
	e = e&1;
	d = ~d;
	printf("\n %d \t%d \t%d \t%d",c,d,e,f^1);
}
