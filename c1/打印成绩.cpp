#include<stdio.h>
#include<string.h>
int main(){
	struct stu{
		char id[19];
		char name[10];
		char point[10];
	}c,a[100];
	int n;//nÎªÈËÊý£» 
	scanf("%d\n",&n);
	for(int i=0;i<n;i++){
		gets(a[i].name);
		gets(a[i].id);
		gets(a[i].point); 
	} 
	for(int j=0;j<n;j++){
		for(int k=j+1;k<=n-1;k++){
			if((strlen(a[j].point)>strlen(a[k].point))||(((strlen(a[j].point)==strlen(a[k].point))&&(strcmp(a[j].point,a[k].point)==1)))){
			if(a[j].point==a[k].point){
				if(strcmp(a[j].point,a[k].point)==1){
					c=a[k];
				}
				else{
					c=a[j];
				}
			}
			}
		}
	}
	printf("%s %s %s\n",c.name,c.id,c.point);
	for(int j=0;j<n;j++){
		for(int k=j+1;k<=n-1;k++){
			if((strlen(a[j].point)>strlen(a[k].point))||(((strlen(a[j].point)==strlen(a[k].point))&&(strcmp(a[j].point,a[k].point)==1)))){
			if(a[j].point==a[k].point){
				if(strcmp(a[j].point,a[k].point)==1){
					c=a[j];
				}
				else{
					c=a[k];
				}
			}
			}
		}
	}
   printf("%s %s %s\n",c.name,c.id,c.point);
}
