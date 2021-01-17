#include<stdio.h>
#include<math.h>
int r_a, c_a, r_b,c_b, a=0;

int mat_a[10][10],mat_b[10][10];
int add(){
	int i,j,sum[r_a][c_a];
	for(i=0;i<r_a;i++){
		for(j=0;j<c_a;j++){
			sum[i][j]= mat_a[i][j]+mat_b[i][j]; 
		}
	}
	for(i=0;i<r_a;i++){
		for(j=0;j<c_a;j++){
			printf("ans:\n%d\t",sum[i][j]);
	}
	}
	printf(";");
	return 0;
}

int sub(){
	int i,j,sub[r_a][c_a];
	
	for(i=0;i<r_a;i++){
		for(j=0;j<c_a;j++){
			sub[i][j]= mat_a[i][j]-mat_b[i][j]; 
		}
	}
	for(i=0;i<r_a;i++){
		for(j=0;j<c_a;j++){
			printf("ans:\n%d\t",sub[i][j]);
	}
	}
	printf(";");
	return 0;
}

int product(){
	int i,j,k,product[r_a][c_b];
	for(i=0;i<r_a;i++){
		for(j=0;j<c_b;j++){
			for(k=0;k<=j;k++){
				a = a + (mat_a[i][k]*mat_b[k][j]);
			}
			product[i][j] = a;
		a=0;
		}
	}
	for(i=0;i<r_a;i++){
		for(j=0;j<c_b;j++){
			printf("ans:\n%d\t",product[i][j]);
	}
	}
	printf(";");
	return 0;
}

int transpose(){
	int i,j,trans[10][10];
	for(i=0;i<r_a;i++){
		for (j=0;j<c_a;j++){
		trans[i][j] = mat_a[j][i];
		}
	}
	for(i=0;i<r_a;i++){
		for(j=0;j<c_b;j++){
			printf("\n%d\t",trans[i][j]);
	}
	}
	printf(";");
	return 0;
}
int matrix(){
	int i,j,opt;
	printf("enter the matrix");
	for(i=0;i<r_a;i++){
		for(j=0;j<c_a;j++){
			scanf("%d",&mat_a[i][j]);
		}
	}
	for(i=0;i<r_a;i++){
		for(j=0;j<c_a;j++){
			printf("\n%d\t",mat_a[i][j]);
		}
	}
	printf(";");
	
	for(i=0;i<r_b;i++){
		for(j=0;j<c_b;j++){
			scanf("%d",&mat_b[i][j]);
		}
	}
	for(i=0;i<r_b;i++){
		for(j=0;j<c_b;j++){
			printf("\n%d\t",mat_b[i][j]);
		}
	}
	printf(";");
	printf("\n 1 addition \n 2 subtraction 3 Multiply 4 transpose \n");
	scanf("%d",&opt);
	switch(opt){
		case 1:
			add(mat_a,mat_b);
			break;
		
		case 2:
			sub();
			break;
		
		case 3:
			product();
			break;
		
		default:
			transpose();
			break;
	}		
}	



int elements(){
	printf("\n Enter the rows and column of the matrix");
	scanf("%d %d %d %d",&r_a,&c_a,&r_b,&c_b);
	if(r_a==r_b && c_a==c_b){
		printf("\n addition and subtraction is possible \n");
		matrix();
	}
	else if(c_a == r_b){
		printf("\n Multiplication is possibble");
		matrix();
	}
}

int main(){
	printf("hello world from my new linux system!");
	elements();
}