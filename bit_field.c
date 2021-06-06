#include<stdio.h>
#include<stdint.h>

struct {
	unsigned int age : 4; \\ size is 4 bits (values between 0 - 15)
	unsigned int sl_No : 3; \\ size is 3 bits (values between 0- 7)
}winners;

int main(){
	winners.sl_No = 7;
	winners.age = 10;



	printf("\n size is : %ld\n winner list number: %d,age : %d",sizeof(winners),winners.sl_No,winners.age);
		
}

