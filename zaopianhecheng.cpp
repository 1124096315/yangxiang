#include<stdio.h>
#include<stdlib.h>
int main(){
	char pic[200];FILE *pi; char ch;
	char zip[200];FILE *zi;
	char _new[200];FILE *ne; 
		printf("请输入需要合成的图片和压缩包哦\n"); 
		printf("请输入图片的名称：\n");
		scanf("%s",pic);
		printf("请输入压缩包的名称：\n");
		scanf("%s",zip);
		printf("请输入最终照片的名称:\n"); 
		scanf("%s",_new);
		if((pi=fopen(pic,"rb"))==0){ 
		printf("我不能打开这个文件，你确定这个文件存在吗伞兵0。\n");
		return 0;
		}
	    if((zi=fopen(zip,"rb"))==0){
		printf("我不能打开这个文件，你确定这个文件存在吗伞兵1。\n");
	    return 0;
    	} 
 	    if((ne=fopen(_new,"wb"))==0){
    	printf("我不能打开这个文件，你确定这个文件存在吗伞兵2。\n");
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
