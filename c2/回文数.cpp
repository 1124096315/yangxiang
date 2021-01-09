#include<stdio.h>
int huiwen(long int a){
	long int num=a; long int s=num;long int y=0;
    while(s>0){
     y=y*10+s%10;
     s=s/10;
    if(y==num){
	
      return 1;
     }}
	 
      return -1;}
int main(){
	long int a;int n;
	scanf("%d",&n);
	for(int i=0;i<n;i++){
		scanf("%d",&a);
		int c=huiwen(a);
		if(c==1){
			printf("Yes\n");
		}
		if(c==-1){
			printf("No\n");
		}
	}
}//基本思想是那这个数倒过来看是否相等 当然用字符串会更简单。 
