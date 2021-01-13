#include<stdio.h>
#include<string.h>
#include<stdlib.h>
int main(){
	int n;
	int R;
	int a[20];
	for(int i=0;i<20;i++)
	a[i]=0;
	char p[20];
	scanf("%s%d",p,&R);
	for(int i=0;i<strlen(p);i++){
		if(p[i]>='0'&&p[i]<='9')
		a[i]=p[strlen(p)-1-i]-'0';
		else{
			a[i]=p[strlen(p)-1-i]-55;//µ¹Ðò¸³Öµ£» 
		}
	}
	for(int i=0;i<strlen(p);i++){
		if(a[i]/n>=1){
			a[i+1]+=a[i]/n;
			a[i]=a[i] %n;
		} 
   		if(a[i]/n<=-1){
   			a[i+1]+=a[i]/n;
   			a[i]=a[i] %n;
		   }
	
	} 
	printf("%d",a[0]);
} 
