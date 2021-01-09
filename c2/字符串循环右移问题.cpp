#include<stdio.h> 
#include<string.h>
int main(){
	char a[9999];
	int n;
    int i = 0;
	scanf("%d",&n);
	fflush(stdin); 
	while((a[i]=getchar())!='\n'){
    i++;}
    a[i]='\0';
	int len=strlen(a);
	for(int i=0;i<len;i++){
		if(i<n){
		printf("%c",a[len-n+i]);}
		else{
		printf("%c",a[i-n]);
		}
	}
//	}//oj别用fflush（stdin)//千万别 
