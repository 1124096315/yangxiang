#include<stdio.h>
int main(){
	float a,b,c,d,e,f,g,h,i,j;int m=0;
	

	for(;;){
	scanf("%f %f %f %f %f",&a,&b,&c,&d,&e);
	if((a==0)&&(b==0)&&(c==0)&&(d==0)&&(e==0)){return 0;}//代表结束。 
	else if((a==b)&&(b==c)&&(c==d)&&(d==e)){
	       //既是等差又是等比 
 printf("case one\n%.0f %.0f %.0f %.0f %.0f\ncase two\n%.0f %.0f %.0f %.0f %.0f\n",a,b,c,d,e,a,b,c,d,e);
	      continue;
	}
	else if(((e/d)==(d/c))&&((d/c)==(c/b))&&((c/b)==(b/a))){
		m=e/d;
		m=m*m*m*m*m;   //代表等比数列 
	printf("case two\n%.0f %.0f %.0f %.0f %.0f\n",a*m,b*m,c*m,d*m,e*m);	continue;
	}
	else if(((e-d)==(d-c))&& ((d-c)==(c-b))&&((c-b)==(b-a))){
		m=5*(e-d);
		printf("case one\n%.0f %.0f %.0f %.0f %.0f\n",a+m,b+m,c+m,d+m,e+m);	continue;//表示等差 
	}
	else if((c==a+b)&&(d==b+c)&&(e==c+d)){
	
	     	f=d+e;
	      	g=e+f;
		    h=g+f;
	    	i=h+g;
	      	j=i+h;
	     	printf("case three\n%.0f %.0f %.0f %.0f %.0f\n",f,g,h,i,j);continue;
		
	}

	}}
