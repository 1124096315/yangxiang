#include<iostream>
#include<cstring>
#include<iomanip>
#include<cstdio>
#define MAXN 110
bool b[MAXN][MAXN];
long long a[MAXN][MAXN];
int dx[8]={2,1,-1,-2,-2,-1,1,2};//�������ߵĻ��ָ���� 
int dy[8]={1,2,2,1,-1,-2,-2,-1};
int n,m,x,y;
using namespace std;
int main(){
	cin>>n>>m>>x>>y;//n,mΪ���յ㣬xyΪ��ĵ�ַ 
	memset(b,0,sizeof(b));//��bָ���ʣ�µ�sizeof��b)�Ŀռ�ĳ�ֵ����Ϊ0; 
	b[x][y]=1;//����ĵط�����Ϊ1�� 
	for(int i=0;i<=7;i++){
		 if(x+dx[i]>=0&&x+dx[i]<=n&&y+dy[i]>=0&&y+dy[i]<=m){
		 	b[x+dx[i]][y+dy[i]]=1;//�������ŵ�����Ϊ1�� 
		 }
	}
	int k=0;
	while(!b[k][0]&&k<=n){//�����еĳ�ֵ����Ϊ1�� 
		a[k++][0]=1;
	}
	int l=0;
	while(!b[0][l]&&l<=m){
		a[0][l++]=1;//����һ�еĳ�ֵ����Ϊ1�� 
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			if(b[i][j]){//�������ص�����Ϊ0��//���Ϊ��ص㣬 
				a[i][j]=0;  //g[i][j]=1
			}
			else{ 
				a[i][j]=a[i-1][j]+a[i][j-1];  //�����û�߹����͵õ�������һ��ķ����м��� 
			}// 
		}
	}
	cout<<a[n][m];
	return 0;
}
