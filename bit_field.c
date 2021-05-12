#include<stdio.h>
#include<stdint.h>

struct {
	unsigned int age : 4;
	unsigned int sl_No : 3;
}winners;

int main(){
	winners.sl_No = 7;
	winners.age = 10;



	printf("\n size is : %ld\n winner list number: %d,age : %d",sizeof(winners),winners.sl_No,winners.age);
		
}

