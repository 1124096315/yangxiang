#include<stdio.h>
#include<stdlib.h>
#define N 10000
int*zhishu() {//建立素数的动态数组。然后拿这个数组满足相加等于输入的偶数，来自动寻找分解的数。缺点是不能搞N很大，要不然就超时。 
	int *p;int temp=0;
	p=(int*)malloc(sizeof(int)*N);
	for(int i=3;i<N;i++){
      for(int k=2;k<N;k++){
      	if(i%k==0){
      		if(k<i)
      		break;
      	
      	if(k==i){
      		p[temp]=i;
      		temp++;
      		break;
		  }
		  }
		}
	  }
	  return p;
	}
	
int main(){
	int *p;int a;
	scanf("%d",&a);
	if(a<=6||a%2!=0){
		printf("ERROR");
	}
	p=zhishu();
	for(int i=0;i<N;i++){
		for(int j=i;j<N;j++){
			if(p[i]+p[j]==a){
			printf("%d %d\n",p[i],p[j]);
			break;
		}
		else continue;
		}
	}
}
