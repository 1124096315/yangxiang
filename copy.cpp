#include<stdio.h>
#include<stdlib.h>
int main() {
	int i=0;char ch;
	FILE* b;
	while((b=fopen("11.JPG","rb"))==0){
		printf("NO\n");
		return 0;
	}
	
	while(feof(b)==0){
		ch=fgetc(b);
		//putchar(ch);
		printf("%d", ch);
	}
	fclose(b);
	
}
