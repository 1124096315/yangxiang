#include<stdio.h>
#include<stdlib.h>
int main(){
	char pic[200];FILE *pi; char ch;
	char zip[200];FILE *zi;
	char _new[200];FILE *ne; 
		printf("��������Ҫ�ϳɵ�ͼƬ��ѹ����Ŷ\n"); 
		printf("������ͼƬ�����ƣ�\n");
		scanf("%s",pic);
		printf("������ѹ���������ƣ�\n");
		scanf("%s",zip);
		printf("������������Ƭ������:\n"); 
		scanf("%s",_new);
		if((pi=fopen(pic,"rb"))==0){ 
		printf("�Ҳ��ܴ�����ļ�����ȷ������ļ�������ɡ��0��\n");
		return 0;
		}
	    if((zi=fopen(zip,"rb"))==0){
		printf("�Ҳ��ܴ�����ļ�����ȷ������ļ�������ɡ��1��\n");
	    return 0;
    	} 
 	    if((ne=fopen(_new,"wb"))==0){
    	printf("�Ҳ��ܴ�����ļ�����ȷ������ļ�������ɡ��2��\n");
	    return 0;
	} 
	while(feof(pi)==0) {
		ch=fgetc(pi);
		fputc(ch,ne);
	}
	fclose(pi);
	
	while(feof(zi)==0) {
     	ch=fgetc(zi);
    	fputc(ch,zi);
	}
	fclose(zi);
	fclose(ne);
	
}
