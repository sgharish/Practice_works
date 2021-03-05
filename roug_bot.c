#include<stdio.h>
#include<math.h>
#define MAX 100
int a[MAX][MAX];
int i,j,r_1,r_2,c_1,c_2,rc_1,rc_2,cc_1,cc_2;
int N,M;
int check(){
	if(rc_1==r_1 && cc_1==c_1||rc_1==r_2&&cc_1==c_2||rc_2==r_1&&cc_2==c_1||rc_2==r_2&&cc_2==c_2){
		printf("\n no");
	}
	else if((rc_1==r_1&&(cc_1>c_1&&cc_1<c_2))||(rc_2==r_1&&(cc_2>c_1&&cc_2<c_2))||(rc_1==r_2&&(cc_1>c_1&&cc_2<c_2))||(rc_2==r_2&&(cc_2>c_1&&cc_2<c_2))){
		printf("\n no");
	}
	else if((cc_1==c_1&&(rc_1>r_1&&rc_1<r_2))||(cc_2==c_1&&(rc_2>r_1&&rc_2<r_2))||(cc_1==c_2&&(rc_1>r_1&&rc_2<r_2))||(cc_2==c_2&&(rc_2>r_1&&rc_2<r_2))){
		printf("\n no");
	}
	else if((((rc_1<r_1||rc_1>r_2)&&(cc_1<c_1||cc_1>c_2))&&((rc_2>r_1&&rc_2<r_2)&&(cc_2>c_1&&cc_2<c_2)))){
	printf("\n no");
	}
	else if(((((rc_1>r_1&&rc_1<r_2)&&(cc_1>c_1&&cc_1<c_2))&&((rc_2<r_1||rc_2>r_2)&&(cc_2<c_1||cc_2>c_2))))){
		printf("\n no");
	}
	else if(((rc_1>r_1&&rc_1<r_2)&&(cc_1>c_1&&cc_1<c_2))&&((rc_2>r_1&&rc_2<r_2)&&(cc_2>c_1&&cc_2<c_2))){
		printf("\n yes");
	}
	else{
		printf("\n yes");
	}
}
int  bot(){
	
for(i = r_1-1; i<=r_2-1;i++){
for(j=c_1-1;j<=c_2-1;j++){
if(i==r_1-1||j==c_1-1||i==r_2-1||j==c_2-1){
a[i][j]=0;
}
	else {
		a[i][j] = 1;
	}
}
}
for(i = 0;i<N;i++){
for(j=0;j<M;j++){
printf("%d",a[i][j]);
}
	printf("\n");
}
}

int main(){
int e_type,Q;
scanf("%d %d %d",&N,&M,&Q);
for(i = 0; i<N;i++){
for(j=0;j<M;j++){
a[i][j]=1;
}
}
for(i = 0; i<N;i++){
for(j=0;j<M;j++){
printf("%d",a[i][j]);
}
	printf("\n");
}
while(Q--){
scanf("%d ",&e_type);
if(e_type==1){
	scanf("%d %d %d %d",&r_1,&c_1,&r_2,&c_2);
bot();
}
	else{
		scanf("%d %d %d %d",&rc_1,&cc_1,&rc_2,&cc_2);
		check();
	}
}
}