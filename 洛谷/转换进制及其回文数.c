#include<stdio.h>
#include<string.h>
#include<stdlib.h>
char s[101];
int a[401];
int max;
int huiwen(){
	for(int i=0;;i++){
		if(a[i]==a[max-1-i]){
			if(i<max-1-i){
				continue;
			}
			if(i>=max-1-i){
				return 1;
			}
		}
		else
		    return 0;
	}
}
int main(){
	for(int i=0;i<401;i++)
	a[i]=0;
	int n;int step=0;
	scanf("%d%s",&n,s);
	max=strlen(s);
	for(int i=0;i<max;i++){
		if(s[i]>='0'&&s[i]<='9'){
			a[i]=s[strlen(s)-1-i]-'0';
		}
		else{
			a[i]=s[strlen(s)-1-i]-55;
		}
	}
		for(;huiwen()==0;){
			for(int i=0;i<=(max-1)/2;i++){
				a[i]+=a[max-1-i];
				a[max-1-i]=a[i];
			}
			for(int i=0;i<max;i++){
				if(a[i]>=n){
					a[i+1]+=a[i]/n;
					a[i]=a[i]%n;
				}
			}
			step++;
			if(a[max]==1){
				max++;
			}
			if(step>30){
				printf("Impossible!");
				return 0;
			}
		}
		printf("STEP=%d\n",step);
	
}
