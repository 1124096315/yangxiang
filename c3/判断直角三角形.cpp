#include<stdio.h>
int main(){
    int a,b,c;
	int n;
	scanf("%d",&n);
	for(int i=0;i<n;i++){
		scanf("%d %d %d",&a,&b,&c);
      if(a<0||b<0||c<0){
      	printf("No\n");
	  }	
	  else{
	  	if((a+b>c)||(a+c>b)||(b+c>a)){
	  		if((a*a+b*b==c*c)||(b*b+c*c==a*a)||(a*a+c*c==b*b))
	  		printf("Yes\n");
	  		else 
	  		printf("No\n");
		  }
		  else
		  printf("No\n");
	  }
}
}//�����Ҫ���������γ��ȴ���0 ������֮�ʹ��ڵ����ߣ��򵥵���Ҫע����Щ 
