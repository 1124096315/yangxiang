#include<stdio.h> 
#include<string.h>//通过这个程序，知道如何新建动态数组，字符串，以及字符串的数字化，以及提取字符串，函数的调用，别用fflush(stdin); 建立动态数组 int **p;p=(int**)malloc(sizeof(int*)*n）;
   //俊宇应该就是malloc里面的int*(这个属于二级指针的内容）搞错了，所以维数不能多。                     //要用动态字符串 char*p=(char*)malloc(sizeiof(char)*n); 回想起上一个建立动态链表，struct stu *p1=(struct stu*)malloc(sizeof(struct stu));p2->next=p1;p2=p1;              
#include<stdlib.h>
char*number(char a[]){
	char *b;b=(char *)malloc(sizeof(char)*strlen(a));int j=0;
  for(int i=0;i<strlen(a);i++){//返回本地变量 
  if(a[i]>='0'&&a[i]<='9'){
      b[j]=a[i];j++;
	  }
  }  
       b[j]=' ';
       
	   return b; 
}
char *zhuanhua(char *a){//返回局部变量 
    char*b;
    b=(char*)malloc(sizeof(char)*3);
	b[0]=a[0];
	b[1]=a[1];
	b[2]=0;
	return b;
}
void SRx1x2(int **p,int x1,int x2,int r,int s){//代表交换x1行和x2行 
	int a[s];//r=2,s=3
	for(int i=0;i<s;i++){
		a[i]=p[x1-1][i];
	}//代表一个temp；
	for(int i=0;i<s;i++)
	    p[x1-1][i]=p[x2-1][i];//代表交换
	for(int i=0;i<s;i++)
	    p[x2-1][i]=a[i];//交易成功； //已成功； 
}
void SCy1y2(int **p,int y1,int y2,int r,int s){//交换y1列和y2列 
    int b[r];//s=3,r=2
    for(int i=0;i<r;i++){//             //1 2 3
                                        //2 3 4
    	b[i]=(*(p+i))[y1-1];//代表一个temp值； 
	}
	for(int i=0;i<r;i++){
		(*(p+i))[y1-1]=(*(p+i))[y2-1];//代表交易。 
	} 
	for(int i=0;i<r;i++)
	 (*(p+i))[y2-1]=b[i];//交易成功。 //已完成。 
}
int** DR_x(int **p,int x,int r,int s){//删除x行 
    int**q;
    q=(int**)malloc((r-1)*sizeof(int*));//代表int*型的空间 
    for(int i=0;i<r-1;i++)
    q[i]=(int*)malloc(s*sizeof(int));
   
    for(int i=0;i<x-1;i++)
    for(int j=0;j<s;j++)
    q[i][j]=p[i][j];
    for(int i=x-1;i<r-1;i++)
    for(int j=0;j<s;j++)
    q[i][j]=p[i+1][j];
    return q;
}
int** DC_y(int **p,int y,int r,int s){//删除y列//dc很可能有问题， 上面那个也是回来改。 吗 
    int**q;//2行3列r=2 s=3
	         // 1 2 3
	         // 2 3 4
	
	      
    q=(int**)malloc((r)*sizeof(int*));
    for(int i=0;i<r;i++)
    q[i]=(int*)malloc((s-1)*sizeof(int));//定义完成 
    for(int i=0;i<r;i++){
    	for(int j=0;j<s-1;j++){
    		if(j<y-1){
    			q[i][j]=p[i][j];
			}
			else{
				q[i][j]=p[i][j+1];
			}
		}
	}return q; //终极折磨王，妈的原来是辣个原因 
}
int** IR_x(int **p,int x,int r,int s){//插入一行
    int**q;
     q=(int**)malloc((r+1)*sizeof(int*));
     for(int i=0;i<r+1;i++)
     q[i]=(int*)malloc((s)*sizeof(int));//定义完成 q[i】其实是一个一级指针，
     for(int i=0;i<x-1;i++)
     for(int j=0;j<s;j++)
     q[i][j]=p[i][j];
     for(int j=0;j<s;j++)
     q[x-1][j]=0;
     for(int i=x;i<r+1;i++)
     for(int j=0;j<s;j++)
     q[i][j]=p[i-1][j];    
	  return q;//perfect,离胜利只差一步。 
}
int** IC_y(int **p,int y,int r,int s){//插入一列 
	int**q;
	q=(int**)malloc((r)*sizeof(int*));
	for(int i=0;i<r;i++)
	 q[i]=(int*)malloc((s+1)*sizeof(int));//定义完成 q[i】其实是一个一级指针，
	 for(int i=0;i<r;i++){
	 	for(int j=0;j<s+1;j++){
	 		if(j<y-1){
	 			q[i][j]=p[i][j];
			 }
			else if(j==y-1){
				q[i][j]=0;
			}
			else{
				q[i][j]=p[i][j-1];
			}
		 }
	 } 
	 return q;//nice兄弟 
}
int main(){
int**p;
int r,s,n; char a1[11],a2[11];int x1,x2,y1,y2,x,y;int i=0;
scanf("%d %d",&r,&s);
getchar();
p=(int**)malloc(r*sizeof(int*));//申请了行的空间即p,可以进行p[]访问，p[] 
for(int i=0;i<r;i++){
p[i]=(int*)malloc(s*sizeof(int));//申请了列的空间即p[][]，可以完全进行访问了。 
}//即为每一个申请一行的空间。
     for(int i = 0; i < r; i ++){
        for(int j = 0; j < s; j ++){
            scanf("%d",&p[i][j]);
            getchar();
        }
    }
            scanf("%d",&n);
            getchar();
            for(int i=0;i<n;i++){
            	int j=0;
            	while((a1[j]=getchar())!='\n'){
            		j++;
				}
				a1[j]=0;
				strcpy(a2,zhuanhua(a1));
				if(strcmp(a2,"SR")==0){
					strcpy(a1,number(a1));
					x1=a1[0]-'0';
					x2=a1[1]-'0';
				   SRx1x2(p,x1,x2,r,s);
				}
				if(strcmp(a2,"SC")==0){
					strcpy(a1,number(a1));
					y1=a1[0]-'0';
					y2=a1[1]-'0';
					SCy1y2(p,y1,y2,r,s);
				}
				if(strcmp(a2,"DC")==0){//删除y列。 
					strcpy(a1,number(a1));
					y=a1[0]-'0';
				  p= DC_y(p,y,r,s);
                    s=s-1;
				}
			    if(strcmp(a2,"DR")==0){//删除x行。
				    strcpy(a1,number(a1));
				    x= a1[0]-'0';
				 p= DR_x(p,x,r,s);
				   r=r-1;
				}
				if(strcmp(a2,"IR")==0){//增加某行 
					strcpy(a1,number(a1));
					x= a1[0]-'0';
	                p=IR_x(p,x,r,s);
                    r++;
				}
				if(strcmp(a2,"IC")==0){
			       strcpy(a1,number(a1));
			       y= a1[0]-'0';
			       p=IC_y(p,y,r,s);
			       s++;
			}
			
			}
                    for(int i=0;i<r;i++){
                    if(i>=1){
					printf("\n");
				}
             for(int j=0;j<s;j++){
             printf("%d ",p[i][j]);//很细节
		}
         }
	}    
