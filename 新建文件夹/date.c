#include<stdio.h>
int main(){
	int year,month,day;
	int a,b,c,d,e,f,g,h;
	printf("plese enter a day as (xxxx-x-x):\n");
	scanf("%d-%d-%d",&year,&month,&day);
	a=year%100;//用于说明过了几个一百年；
	b=year%400;//用于说明经过几个400年；
	c=b+24*a;//精确到百年内共有几个闰年；
	d=c+(year-a*100)%4;//用于说明精确到该年有几个闰年；
	e=d*2+(year-d);//累计的天数。 
	g=e%7;//精确到该年的星期数；
	if((year%4==0&year%100!=0)||(year%400==0)){
	
	switch(month){
		case 1:h=(day%7+g)%7;
		case 2:h=(31+(day%7+g))%7;
		case 3:h=(60+(day%7+g))%7;
		case 4:h=(91+(day%7+g))%7;
		case 5:h=(121+(day%7+g))%7;
		case 6:h=(152+(day%7+g))%7;
		case 7:h=(182+(day%7+g))%7;
		case 8:h=(213+(day%7+g))%7;
		case 9:h=(244+(day%7+g))%7;
		case 10:h=(274+(day%7+g))%7;		
		case 11:h=(305+(day%7+g))%7;
		case 12:h=(335+(day%7+g))%7;
		
	} }
	else  {switch(month){
		case 1:h=(day%7+g)%7;
		case 2:h=(31+(day%7+g))%7;
		case 3:h=(59+(day%7+g))%7;
		case 4:h=(90+(day%7+g))%7;
		case 5:h=(120+(day%7+g))%7;
		case 6:h=(151+(day%7+g))%7;
		case 7:h=(181+(day%7+g))%7;
		case 8:h=(212+(day%7+g))%7;
		case 9:h=(243+(day%7+g))%7;
		case 10:h=(273+(day%7+g))%7;	
		case 11:h=(304+(day%7+g))%7;
		case 12:h=(334+(day%7+g))%7;}}
		if(h==0)
		{printf("今天是星期天"); 
		}
		else{
		 
		printf("today is 星期%d",h);}
		return 0;
}
 
