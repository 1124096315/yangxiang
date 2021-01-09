#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int main(){
	int n;
	scanf("%d",&n);
	getchar();
	char**a;
	a=(char**)malloc(sizeof(char*)*n);
	for(int i=0;i<n;i++){
		a[i]=(char*)malloc(sizeof(char)*11);
	}
    int i=0,j=0;
    while((a[i][j]=getchar())!='\n'){
        if(a[i][j]==' '){
        	a[i][j]=0;
        	i++;j=0;
		}
		else{
			j++;
		}
	}
	a[i][j]=0;
	char b[11];
	for(int m=0;m<n-1;m++){
		i=0;j=0;int k=0;
	for(;i<n-1;){
		if(a[i][j]==0||a[i+1][k]==0){
			if(a[i][j]==0){
				j=0;
			}
			if(a[i+1][k]==0){
				k=0;
			}
			continue;
		} 
		if(a[i][j]==a[i+1][k]){
			j++;k++;
		    continue;
		}
		if(a[i][j]>=a[i+1][k]){
			j=0;k=0;i++;continue;
		}
		if(a[i][j]<a[i+1][k]){
			strcpy(b,a[i]);
			strcpy(a[i],a[i+1]);
			strcpy(a[i+1],b);
			j=0;k=0;i++;continue;
		}

	}
	}
	for(int i=0;i<n;i++){
		printf("%s",a[i]);
}
}
