# include<stdio.h>
#include<stdlib.h>
int main(){
	int n;int temp=1; int i=0;int j=0;int i0=0;int j0=0;
	scanf("%d",&n);
	int**a;
	int N=n;
	a=(int**)malloc(sizeof(int*)*n);
	for(int i=0;i<n;i++)
	a[i]=(int*)malloc(sizeof(int)*n);
	for(int k=0;k<n%2+n/2;k++){
	   for(;i<N;i++){
			for(;j<N;j++){
				a[i][j]=temp;
				if(j==N-1){
					j=j0;break;
				}
			}
	}
	temp++;j0++;i0++;N--;i=i0;j=j0;
}
printf("%d\n",a[2][1]);

for(int i=0;i<n;i++){
	for(int j=0;j<n;j++){
		printf("%d",a[i][j]);
		
	}
	printf("\n");
}
}
