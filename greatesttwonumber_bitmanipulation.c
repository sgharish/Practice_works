//Relational Operators are operators which check relationship between two values. Given two numerical values A and B you need to help chef in finding the relationship between them that is,

//First one is greater than second or, First one is less than second or, First and second one are equal.

// Greatest of two numbers using bit manipulation

#include <stdio.h>
#include <stdint.h>


int main(void) {
	int a,b;
 // get input number
	scanf("%d %d",&a,&b);
// by sutracting we can find if it equal or there is a difference
	int x = a-b;
	if (!x){
	    printf ("a is equal to b\n");
	}
  else {
//finding if the resulted value is signed or not to find if a is great or lesser than b
	    if ((x&(1<<31))){
	        printf("a is smaller than b\n");
	    }
      else{
	         printf("a is greater than b\n");
	    }
	}
	return 0;
}
