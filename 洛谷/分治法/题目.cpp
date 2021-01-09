#include <stdio.h>
int main() 
{
FILE *fp;
	char str[100];
    char i, *p;
	gets(str);
   p = str;
	for (i = 0; i < 100; i++) 
{
		if (*p >= 'a' && *p <= 'z')
{
*p = *p - 'a' + 'z';
}
p++;

	}
puts(p);

	fp = fopen("test.txt", "w");
if(fp==0){
return 0;
} 
fputs(str,fp);
return 0;
fclose(fp);
}
