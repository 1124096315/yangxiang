#include<stdio.h>
#include<stdlib.h>
int N;
int f(int*p,int*tag,int n){
	if (n==N){ 
	
	printf("--> ");
	for(int i=0;i<N;i++){
		if(tag[i]==1)
		printf("%d ",p[i]); 
		
	}printf("\n");
		return 0;
	}
	    tag[n]=1;//标记为1，说明要输出，跳到下一个。
	f(p,tag,n+1);
	tag[n]=0;//标记为0，不输出
	f(p,tag,n+1);// 递归跳到下一个
}
int main(){
	int n,m;//n代表有一个数含有n个数字，m表示输入m个数。 
	scanf("%d",&m);
	int*p;
	for(int i=0;i<m;i++){
		scanf("%d",&N);
		p=(int *)malloc(sizeof(int)*N);
	for(int j=0;j<N;j++){
		
		scanf("%d",&p[j]);
	}
	int tag[N];
	f(p,tag,0);
}
}
