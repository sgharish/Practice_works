/* coding challenge manipulating a long int variable that has two variables and operation combined as a single binary variable 
Implement a function with the following signature to perform a
mathematical operation on two unsigned values.
int32_t instructionDecodeAndExecute(int32_t instruction);
The argument "int32_t instruction" holds the information about the operation and
the operands to be used in the following way:
res = operand1 (15bits) operation(2bits) operand2 (15bits) 
operation :
00 - add
01 -sub
10 - multi
11 - divide
*/

#include <stdio.h>
#include <stdint.h>
#include <math.h>
int calculate (long int bin){
   int  dec=0, i=0, j=0, k=0,a=0,op=0,c;
  while ((bin)>0){
      if (i<=6){
          int v = (bin)%10;
          a+= v*(pow(2,i));
          bin=(bin)/10;
      }else if(i<=8){
          int v = (bin)%10;
          op+= v*(pow(2,j));
          j++;
          bin=(bin)/10;
      }else if(i<=15){
          int v = (bin)%10;
          dec+= v*(pow(2,k));
          k++;
          bin=(bin)/10;
       if(i==15){
         printf("%d\t %d\t %d\n", a, op, dec);
       switch (op){
              case 0:
                    c = a+dec;
                    break;
              case 1:
                    c= a - dec;
                    break;
              case 2:
                    c= a* dec;
                    break;
              default:
                    c= a / dec;
                    break;
       }
      }
      }
      i++;
      }
  return c;  
}

void main(void){
  long int bin = 1100000101000001;
  int c =  calculate(bin);
    printf("%d\n", c);
}
