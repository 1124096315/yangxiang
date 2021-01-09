#include<stdio.h>
#include<stdlib.h>

int main()
{
   char table[21][31];//显示
   int num[20];//接收数字
   char sign[20];//接收符号
   int n,i,j;
   char a[20];int b[20];
    for(int i=0;i<5;i++){
   scanf("%d",&b[i]);
   scanf("%c",&a[i]);
   }
   for(int i=0;i<5;i++)
   printf("%c",a[i]);
}
