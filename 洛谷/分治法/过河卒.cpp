#include<iostream>
#include<cstring>
#include<iomanip>
#include<cstdio>
#define MAXN 110
bool b[MAXN][MAXN];
long long a[MAXN][MAXN];
int dx[8]={2,1,-1,-2,-2,-1,1,2};//将马能走的积分搞出来 
int dy[8]={1,2,2,1,-1,-2,-2,-1};
int n,m,x,y;
using namespace std;
int main(){
	cin>>n>>m>>x>>y;//n,m为最终点，xy为马的地址 
	memset(b,0,sizeof(b));//将b指针的剩下的sizeof（b)的空间的初值设置为0; 
	b[x][y]=1;//将马的地方设置为1； 
	for(int i=0;i<=7;i++){
		 if(x+dx[i]>=0&&x+dx[i]<=n&&y+dy[i]>=0&&y+dy[i]<=m){
		 	b[x+dx[i]][y+dy[i]]=1;//将马的落脚点设置为1； 
		 }
	}
	int k=0;
	while(!b[k][0]&&k<=n){//将第列的初值设置为1； 
		a[k++][0]=1;
	}
	int l=0;
	while(!b[0][l]&&l<=m){
		a[0][l++]=1;//将第一行的初值设置为1； 
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			if(b[i][j]){//将马和马控点设置为0；//如果为马控点， 
				a[i][j]=0;  //g[i][j]=1
			}
			else{ 
				a[i][j]=a[i-1][j]+a[i][j-1];  //如果还没走过，就得到到达这一点的方法有几种 
			}// 
		}
	}
	cout<<a[n][m];
	return 0;
}
