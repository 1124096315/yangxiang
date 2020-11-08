#include<stdio.h>
int main(){
	int year,month,day;
	int a,b,c,d,e,f,g,h;
	printf("Enter date (mm/dd/yy):\n");
	scanf("%d/%d/%d",&day,&month,&year);
	printf("Dated this %d",day);
	switch(day){
		case 1: case 21: case 31:
			printf("st");break;
		case 2:case 22:
		    printf("nd");break;
		case 3:case 23:
		    printf("rd");break;
			default:printf("th");break;}
	switch(month){
		case 1:printf(" January");break;
		case 2:printf(" February");break;
		case 3:printf(" Match");break;
		case 4:printf(" April");break;
		case 5:printf(" May");break;
		case 6:printf(" june");break;
		case 7:printf(" July");break;
		case 8:printf(" August");break;
		case 9:printf(" September");break;
		case 10:printf(" October");break;
		case 11:printf(" November");break;
		case 12:printf(" December");break;
		printf(", 20%.2d.\n",year);
		
	} 
	
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
		{printf("星期天"); 
		}
		else{
		 
		printf("星期%d",h);}
		return 0;
}
 
