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
	    tag[n]=1;//���Ϊ1��˵��Ҫ�����������һ����
	f(p,tag,n+1);
	tag[n]=0;//���Ϊ0�������
	f(p,tag,n+1);// �ݹ�������һ��
}
int main(){
	int n,m;//n������һ��������n�����֣�m��ʾ����m������ 
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
