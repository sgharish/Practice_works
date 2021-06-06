#include<stdio.h>
#include<math.h>

int a[10][10],K,i,j;

int time_cal(int r){

	int m=0,n=0;
	for(i=0;i<K,i++){
		if(a[i][0]==a[i][2]&&a[i][1]>a[i][3]){
			 m = a[i][1]-a[i][3]+m;
			if(a[i][0]==r){
				printf("\n time is %d",m);
			}
			else{
				printf("\n %d is the time",(m*2));
			}
	}
		else if(a[i][0]==a[i][2]&&a[i][1]<a[i][3]){
			 m = a[i][3]-a[i][1]+m;
			if(a[i][0]==r){
				printf("\n time is %d",m);
			}
			else{
				printf("\n %d is the time",(m*2));
			}
		}
		else if(a[i][1]==a[i][3]&&a[i][0]<a[i][2]){
			 n = a[i][2]-a[i][0]+n;
			if(a[i][1]==r){
				printf("\n time is %d",n);
			}
			else{
				printf("\n %d is the time",(n*2));
			}
	}
		else if(a[i][1]==a[i][3]&&a[i][0]>[i][2]){
			n = a[i][0]-a[i][2]+n;
			if(a[i][1]==r){
				printf("\n time is %d",n);
			}
			else{
				printf("\n %d is the time",(n*2));
			}
	}
		else if(a[i][1]>a[i][3]&&a[i][0]<a[i][2]){
			 n = a[i][2]-a[i][0]+n;
			m = a[i][1]-a[i][3]+m;
	}
		else if(a[i][1]>a[i][3]&&a[i][0]<a[i][2]){
			 n = a[i][2]-a[i][0]+n;
			m = a[i][1]-a[i][3]+m;
}
		
	}
}
int check_up(){
	int r_count=0,c_count=0,max_r=0,max_c=0;
	for(j=1;j<4;j++){
	 for(i=0;i<K;i++){
			if(a[i][j]>max_r){
				max_r=a[i][j];
			}
	 }
		j++;
}
	for(j=1;j<4;j++){
	 for(i=0;i<K;i++){
			if(a[i][j]=max_r){
				r_count++;
			}
	 }
		j++;
}
	for(j=0;j<3;j++){
	 for(i=0;i<K;i++){
			if(a[i][j]>max_c){
				max_c=a[i][j];
			}
	 }
		j++;
}
for(j=1;j<4;j++){
	 for(i=0;i<K;i++){
			if(a[i][j]=max_c){
				c_count++;
			}
	 }
		j++;
}
	if(r_count>=c_count){
		printf("\n Updated highway is along %d row",max_r);
	}
	else if(c_count>=r_count){
		printf("\n Updated highway is along %d coloumn",max_c);
	}
	else{
		printf("\n optimal is %d",max_r);	
	}		
}
	
int main(){
	int N,M;
	scanf("%d %d %d",&N,&M,&K);
 	for(i =0;i<K;i++){
		for(j=0;j<4;j++){
			scanf("%d",&a[i][j]);
			if(a[i][j]<=N||a[i][j]<=M){
				a[i][j] = a[i][j];
			}
			else{
				break;
			}
		}
		
	}
	check_up();
}
	