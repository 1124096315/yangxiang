#include<stdio.h>
#include<string.h>//����һ��%d���Ὣ֮ǰ�ո�Ļ�������� 
#include<stdlib.h>
int main(){
	int n;
	char table[21][31];
	int number[20];
	char character[20];
	scanf("%d",&n);
	for(int i=0;i<n;i++){
		scanf("%d",&number[i]);
		scanf("%c",&character[i]);
	}
	int max,min;
	max=0;min=0;
	for(int i=0;i<n;i++){
		if(max<number[i]&&number[i]>0){
			max=number[i];
		}
	}
		for(int i=0;i<20;i++){
		if(min>number[i]&&number[i]<0){
			min=number[i];
		}
	}
	int row=max-min+1;
	for(int j=0;j<n;j++){
		if(number[j]>0){
			for(int i=0;i<row;i++){
				if(i<max-number[j]){
					table[i][j]=' ';
				}
				else if(i<max&&i>=max-number[j]){
					if(character[j]==' '||character[j]=='\n'){
						table[i][j]='+';
					}
					else{
						table[i][j]=character[j];
					}
				}
				else if(i==max){
					table[i][j]='-';
				}
				else {
					table[i][j]=' ';
				}
				
			}
		}
			if(number[j]<=0){
				for(int i=0;i<row;i++){
					if(i<max){
						table[i][j]=' ';
					}
					else if(i==max){
						table[i][j]='-';
					}
					else if(i>max&&i<=max-number[j]){
						if(character[j]==' '||character[j]=='\n')
						table[i][j]='+';
						else
						table[i][j]=character[j];
					}
					else
					table[i][j]=' ';
					
				}
			}
		}
	for(int i=0;i<row;i++){
		if(i==max){
			for(int j=0;j<n;j++){
				if(j==n-1){
				printf("-");
			}
				else{
				printf("--");
			}
			}
		}
		else{
			for(int j=0;j<n;j++)
			printf("%c ",table[i][j]);
	}
	printf("\n");
	
}
} 
