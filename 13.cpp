#include <stdio.h>
#include<string.h>
#include<stdlib.h>
char*dajiafa(char*a,char*b){
	static char a1[200]={0};char b1[200]={0};
	int a2[200]={0};int b2[200]={0};int temp[200]={0};
	for(int i=0;a[i]!=0;i++){
    	a2[i]=a[strlen(a)-1-i]-'0';
	}
	for(int i=0;b[i]!=0;i++){
        b2[i]=b[strlen(b)-1-i]-'0';
	}
//	for(int i=0;i<200;i++){
//		printf("%d ",a2[i]);
//	}
//	printf("\n");
//	for(int i=0;i<200;i++){
//	printf("%d ",b2[i]);
//	}
	int max=(strlen(a)>=strlen(b))?strlen(a):strlen(b);
	for(int i=0;i<max;i++){
		temp[i]=a2[i]+b2[i];
	}
	for(int i=0;i<max;i++){
		temp[i+1]+=temp[i]/10;
		temp[i]%=10;
	}
	for(int i=0;i<max+1;i++){
		a1[i]=temp[max-i]+'0';
	}
    if(a1[0]='0'){
    	return &a1[1];
	}
	else if(a1[0]!='0'){
		return a1;
	}
 
} 
int main(){
	char a[200]="1";
	char b[200]="123";
	char d[200]="1213";
	char*c=dajiafa(a,b);
	printf("%s",c);
	c=dajiafa(d,c);
	printf("%s",c);
}
