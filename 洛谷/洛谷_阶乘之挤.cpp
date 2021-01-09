#include<stdio.h>
#include<stdlib.h>
#include<string.h> 
char**your_atoc(int*a,int n){
	char**b=(char**)malloc(sizeof(char*)*n);
	for(int i=0;i<n;i++)
	b[i]=(char*)malloc(sizeof(char)*4);
	int j=0;
	for(int i=0;i<n;i++){
		for(j=0;;j++){
			if(a[i]/10==0){
				b[i][j]=a[i]+'0';
				b[i][j+1]=0;
				break;
			}
			else{
				b[i][j]=a[i]/10+'0';
				b[i][j+1]=a[i]%10+'0';
				b[i][j+2]=0;	
				break;
			}
		}
	}
	return b;
}
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
char* dachengfa(char *a1,char *a2){
	char *result1,result2[1000]={0};
	result1=(char*)malloc(sizeof(char)*1000);

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
	}result1[strlen(a1)+strlen(a2)]=0;
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
int main(){
	int n;
	scanf("%d",&n);	
	int a[50];
	for(int i=0;i<50;i++){
		a[i]=i+1;
	} 
	char **b;
	b=your_atoc(a,n);
	char*num;
num=(char*)malloc(sizeof(char)*2000);
    for(int i=0;i<2000;i++)
	      num[i]=0;
			char **c;
			c=(char**)malloc(sizeof(char*)*(n));
			for(int i=0;i<n;i++){
				c[i]=(char*)malloc(sizeof(char)*200); 	
			}
			for(int i=0;i<n;i++){
				c[i][0]='1';
				c[i][1]=0;
				}
			int k=0; int i=0;
				int temp=n,sign=0;
				for(;;){
			for(int i=0;i<temp;i++)	
			c[sign]=dachengfa(c[sign],b[i]);
	        sign++;temp--;if(temp==0) break;
		}
			//	for(int i=0;i<n;i++)
		//	printf("%s ",c[i]);
		int temp1=n,sign1=0;
		 for(int i=0;i<temp1;i++){
		 	num=dajiafa(num,c[i]);
		 }
		 printf("%s",num);
}
