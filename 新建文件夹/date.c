#include<stdio.h>
int main(){
	int year,month,day;
	int a,b,c,d,e,f,g,h;
	printf("plese enter a day as (xxxx-x-x):\n");
	scanf("%d-%d-%d",&year,&month,&day);
	a=year%100;//����˵�����˼���һ���ꣻ
	b=year%400;//����˵����������400�ꣻ
	c=b+24*a;//��ȷ�������ڹ��м������ꣻ
	d=c+(year-a*100)%4;//����˵����ȷ�������м������ꣻ
	e=d*2+(year-d);//�ۼƵ������� 
	g=e%7;//��ȷ���������������
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
		{printf("������������"); 
		}
		else{
		 
		printf("today is ����%d",h);}
		return 0;
}
 
