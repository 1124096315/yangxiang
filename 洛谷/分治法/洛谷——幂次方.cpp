#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>
void fenzhi(int n){
	for(int i=14;i>=0;i--){
		if(pow(2,i)<=n){
			if(i==1){
				printf("2");
			}
			else if(i==0){
				printf("2(0)");
			}
			else{
				printf("2(");
				fenzhi(i);
				printf(")");
			}
			n-=pow(2,i);
			if(n!=0){
				printf("+");
			}
		}
	}
}
int main(){
	int n;
	scanf("%d",&n);
	fenzhi(n);
}
