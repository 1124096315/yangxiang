#include<stdio.h> 
#include<string.h>//ͨ���������֪������½���̬���飬�ַ������Լ��ַ��������ֻ����Լ���ȡ�ַ����������ĵ��ã�����fflush(stdin); ������̬���� int **p;p=(int**)malloc(sizeof(int*)*n��;
   //����Ӧ�þ���malloc�����int*(������ڶ���ָ������ݣ�����ˣ�����ά�����ܶࡣ                     //Ҫ�ö�̬�ַ��� char*p=(char*)malloc(sizeiof(char)*n); ��������һ��������̬����struct stu *p1=(struct stu*)malloc(sizeof(struct stu));p2->next=p1;p2=p1;              
#include<stdlib.h>
char*number(char a[]){
	char *b;b=(char *)malloc(sizeof(char)*strlen(a));int j=0;
  for(int i=0;i<strlen(a);i++){//���ر��ر��� 
  if(a[i]>='0'&&a[i]<='9'){
      b[j]=a[i];j++;
	  }
  }  
       b[j]=' ';
       
	   return b; 
}
char *zhuanhua(char *a){//���ؾֲ����� 
    char*b;
    b=(char*)malloc(sizeof(char)*3);
	b[0]=a[0];
	b[1]=a[1];
	b[2]=0;
	return b;
}
void SRx1x2(int **p,int x1,int x2,int r,int s){//������x1�к�x2�� 
	int a[s];//r=2,s=3
	for(int i=0;i<s;i++){
		a[i]=p[x1-1][i];
	}//����һ��temp��
	for(int i=0;i<s;i++)
	    p[x1-1][i]=p[x2-1][i];//������
	for(int i=0;i<s;i++)
	    p[x2-1][i]=a[i];//���׳ɹ��� //�ѳɹ��� 
}
void SCy1y2(int **p,int y1,int y2,int r,int s){//����y1�к�y2�� 
    int b[r];//s=3,r=2
    for(int i=0;i<r;i++){//             //1 2 3
                                        //2 3 4
    	b[i]=(*(p+i))[y1-1];//����һ��tempֵ�� 
	}
	for(int i=0;i<r;i++){
		(*(p+i))[y1-1]=(*(p+i))[y2-1];//�����ס� 
	} 
	for(int i=0;i<r;i++)
	 (*(p+i))[y2-1]=b[i];//���׳ɹ��� //����ɡ� 
}
int** DR_x(int **p,int x,int r,int s){//ɾ��x�� 
    int**q;
    q=(int**)malloc((r-1)*sizeof(int*));//����int*�͵Ŀռ� 
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
int** DC_y(int **p,int y,int r,int s){//ɾ��y��//dc�ܿ��������⣬ �����Ǹ�Ҳ�ǻ����ġ� �� 
    int**q;//2��3��r=2 s=3
	         // 1 2 3
	         // 2 3 4
	
	      
    q=(int**)malloc((r)*sizeof(int*));
    for(int i=0;i<r;i++)
    q[i]=(int*)malloc((s-1)*sizeof(int));//������� 
    for(int i=0;i<r;i++){
    	for(int j=0;j<s-1;j++){
    		if(j<y-1){
    			q[i][j]=p[i][j];
			}
			else{
				q[i][j]=p[i][j+1];
			}
		}
	}return q; //�ռ���ĥ�������ԭ��������ԭ�� 
}
int** IR_x(int **p,int x,int r,int s){//����һ��
    int**q;
     q=(int**)malloc((r+1)*sizeof(int*));
     for(int i=0;i<r+1;i++)
     q[i]=(int*)malloc((s)*sizeof(int));//������� q[i����ʵ��һ��һ��ָ�룬
     for(int i=0;i<x-1;i++)
     for(int j=0;j<s;j++)
     q[i][j]=p[i][j];
     for(int j=0;j<s;j++)
     q[x-1][j]=0;
     for(int i=x;i<r+1;i++)
     for(int j=0;j<s;j++)
     q[i][j]=p[i-1][j];    
	  return q;//perfect,��ʤ��ֻ��һ���� 
}
int** IC_y(int **p,int y,int r,int s){//����һ�� 
	int**q;
	q=(int**)malloc((r)*sizeof(int*));
	for(int i=0;i<r;i++)
	 q[i]=(int*)malloc((s+1)*sizeof(int));//������� q[i����ʵ��һ��һ��ָ�룬
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
	 return q;//nice�ֵ� 
}
int main(){
int**p;
int r,s,n; char a1[11],a2[11];int x1,x2,y1,y2,x,y;int i=0;
scanf("%d %d",&r,&s);
getchar();
p=(int**)malloc(r*sizeof(int*));//�������еĿռ伴p,���Խ���p[]���ʣ�p[] 
for(int i=0;i<r;i++){
p[i]=(int*)malloc(s*sizeof(int));//�������еĿռ伴p[][]��������ȫ���з����ˡ� 
}//��Ϊÿһ������һ�еĿռ䡣
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
				if(strcmp(a2,"DC")==0){//ɾ��y�С� 
					strcpy(a1,number(a1));
					y=a1[0]-'0';
				  p= DC_y(p,y,r,s);
                    s=s-1;
				}
			    if(strcmp(a2,"DR")==0){//ɾ��x�С�
				    strcpy(a1,number(a1));
				    x= a1[0]-'0';
				 p= DR_x(p,x,r,s);
				   r=r-1;
				}
				if(strcmp(a2,"IR")==0){//����ĳ�� 
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
             printf("%d ",p[i][j]);//��ϸ��
		}
         }
	}    
