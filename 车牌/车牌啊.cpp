#include <stdio.h>
#include<string.h>
int di_ji_wei_si_hanzi(char*a){
	int j,count,temp1;
	count=0;
	int len=strlen(a);
	for(j=0;j<len;j++){
		if(a[j]>=0)
			count++;
		if(a[j]<0)
		    break;
	}
	    return count;
}
int chinese_character(char*a)
{
    int j,count;
        count=0;
        int len=strlen(a);
        for(j=0;j<len;j+=2){
            if(a[j]<0) count++;
        }
        return count;
        }
    int main(){
    	int c,d,temp,temp1;
    	temp=0;
    	temp1=0;
		char b[500]="¾©¼½Ô¥ÔÆÁÉºÚÏæÍîÂ³ÐÂËÕÕã¸Ó¶õ½úÃÉÉÂ¼ªÃö¹óÔÁÇà²Ø´¨ÄþÇíÓå½ò»¦¹ð¸Ê¹ÒÑ§¾¯¸Û°ÄÊ¹Áì";
    	char a[500];
    	char *p[500]={"E4BAAC","E58680","E8B1AB","E4BA91","E8BEBD","E9BB91","E6B998","E79A96","E9B281","E696B0","E88B8F","E6B599",
    		"E8B5A3","E98482","E6998B","E89299","E99995","E59089","E997BD","E8B4B5","E7B2A4","E99D92","E8978F","E5B79D","E5AE81","E790BC",
    		"E6B89D","E6B4A5","E6B2AA","E6A182","E79498","E8ADA6","E68C82","E5ADA6","E8ADA6","E6B8AF","E6BEB3","E4BDBF","E9A286"};
    	gets(a);
    	c=chinese_character(a);
    	d=di_ji_wei_si_hanzi(a);
    	if(c==1){
        if(d==0){
        	for(int i=0;i<200;i=i+2,temp=temp+1){
           if((a[0]==b[i])&&(a[1]==b[i+1])){
           	break;
           	 }
			}
			printf("%s",p[temp]);
			printf("%s",&a[2]);
		}
		if(d==2){
        	for(int i=0;i<200;i=i+2,temp++){
           if((a[2]==b[i])&&(a[3]==b[i+1])){
           	break;
           	 }
			}	
			printf("WJ%s%s",p[temp],&a[4]);
		}	
		}
		if(c==2){
			for(int i=0;i<200;i=i+2,temp++){
           if((a[0]==b[i])&&(a[1]==b[i+1])){
           	break;
           	 }
			}	
			printf("%s",p[temp]);
			for(int m=2;m<7;m++){
			printf("%c",a[m]);
			}
		    for(int n=2;n<200;temp1+=temp1,n=n+2){
		    if((a[8]==b[n])&&(a[9]==b[n+1])){
		    break;
			}
			printf("%s",p[temp1]);
			}
		}
	}
