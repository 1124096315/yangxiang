#include<stdio.h>
int hanpeizu(int n,int a,int k){
	int temp=a;
        if(n==1){return temp;}
	
	else{
	
		return hanpeizu(n-1,a+k,k);
	}}
 
int main(){
	int n,a,k,c;
	scanf("%d %d %d",&n,&a,&k);
	if(((n>=2)&&(n<=100))&&((a>0)&&(a<=100))&&((k>0)&&(k<=100))){
	
	c=hanpeizu(n,a,k);
	printf("%d\n",c);}
		else{
		printf("Wrong Number");
	return 0;
	}
	 
}
