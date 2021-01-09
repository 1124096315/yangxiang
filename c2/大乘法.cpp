#include<stdio.h>
#include<string.h>
#include<stdio.h>
#include<string.h> 
void dachengfa(char a1[],char a2[]){
	char result1[1000]={0},result2[1000]={0};
	int b1[500]={0},b2[500]={0},temp[1000]={0},temp2[1000]={0};int n;int k=0;
    for(int i=0;a1[i]!=0;i++){
    	b1[i]=a1[strlen(a1)-1-i]-'0';
	}//到上面是对的 形如00000000012461 
	for(int i=0;a2[i]!=0;i++){
		b2[i]=a2[strlen(a2)-1-i]-'0'; //形如0000000015561  倒序赋值 
	}
	for(int i=0;i<strlen(a1);i++){                                           
	for(int j=0;j<strlen(a2);j++){
		temp[i+j]+=b1[i]*b2[j];//形如0 12 15 5 14 1 00000 //用数组相乘并存放在相应位置 a*b放到a+b位 并且将a+b位的数字累加。 
	}
}
	for(int i=0;i<=strlen(a1)-1+strlen(a2)-1;i++){
		temp[i+1]+=temp[i]/10;//2位数相乘不会超过4位数 
		temp[i]=temp[i]%10;
    }
    for(int i=0;i<=strlen(a1)+strlen(a2)-1;i++){
	result1[strlen(a1)+strlen(a2)-1-i] =temp[i] + '0';//倒序字符串化 形如0000 1131331 
	}
		for(int i=0;;i++){
			if(result1[i]=='0'&&result1[i+1]!='0'){
				return &result1[i+1];
				break;
			}
			else{
				return &result1[0];
				break;
			}
		}
}
int main(){int n;
	char a1[500]={0};char a2[500]={0};
	scanf("%d",&n);
	fflush(stdin);
    for(int i=0;i<n;i++){
    scanf("%s %s",a1,a2);
	fflush(stdin);
    dachengfa(a1,a2);
	}
}
