#include<stdio.h>
#include<string.h>
int main(){
	char a[100];
	char b[]="SCU";
	char c[]="ASCUA";
	int n;
	printf(" ‰»Î\t ‰≥ˆ\n"); 
	scanf("%d",&n);printf("\tyes\n");

        for(int i=0;i<n;i++){
		scanf("%s",a);
		if((strcmp(a,b)==0)||(strcmp(a,c)==0)){
			printf("\tyes\n");
		}
		else{
			printf("\tno\n");
		}
	
	
}
} 
