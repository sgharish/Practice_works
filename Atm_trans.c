#include<stdio.h>
#include<math.h>

float A_balance = 2000;
int debit_amount;

int Account_stat(){
	printf("\n Current Available balance is %.2f",A_balance);
	printf("\n Transaction ended.\n Thank you");
	return 0;
}

int withdraw(){
	int a;
	A_balance = 2000;
	printf("\n Please enter the amount");
	scanf("%d",&debit_amount);
	a = debit_amount%5;
	if(a!=0){
		printf("\n Invalid entry please enter right amount");	
	}
	else if(debit_amount+0.50>A_balance){
		printf("\n Insufficent balance");
		printf("\n Transaction ended.\n Thank you");
	}
	else{
		printf("\n Please collect the virtual cash");
		A_balance = A_balance - debit_amount - 0.50;
		Account_stat();
	}
	return 0;
}
int main(){
	int options;
	printf("\n Please select anyone of the following action \n 1. Withdraw \n 2. Account statement \n 3. Cancle transaction \n info: press the number to select");
	scanf("%d",&options);
	switch(options){
		case 1:
			withdraw();
			break;
			
		case 2:
			Account_stat();
			break;
			
		default: 
			printf("\n Transaction cancelled.\n Thank you");
			break;
	}
}