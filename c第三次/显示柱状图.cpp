#include<stdio.h>
#include<string.h>
#include<stdlib.h>
int add(char*a){
	for(int i=0;i<strlen(a);i++){
		if((a[i]>'0'&&a[i]<='9')&&(a[i+1]>'0'&&a[i+1]<='9')&&a[i+2]==45)
		return 1;
		if((a[i]>'0'&&a[i]<='9')&&a[i+1]==45)
		return 1;
		
	}
	return -1;
} 
int panduan(char*a){
	for(int i=0;i<strlen(a);i++){
		if((a[i]<'0'||a[i]>'9')&&(a[i]!=45))
		return 1; //�����в��Ǹ��ŵ��ַ��ͷ���1 
	}
	    return -1;//����û�У���������ģ��ַ��ͷ���0�� 
}
int *number(char**a,int m){
	int*p;
	p=(int*)malloc(sizeof(int)*(m));
	for(int i=0;i<m;i++){
		if(panduan(a[i])==1){//�������ַ� 
		  if(strlen(a[i])==2){//����1a 
		  	p[i]=a[i][0]-'0';
		  }
		  
		  if(strlen(a[i])==3){
		  	if(a[i][0]==45){//�����и���������-1a 
		  	p[i]=-(a[i][1]-'0');
			  }
			if(a[i][0]!=45){//�����޸���������12a 
			p[i]=(a[i][0]-'0')*10+((a[i][1])-'0');
			}
		  }
		  if(strlen(a[i])==4){//����-12a
		    p[i]=-((a[i][1]-'0')*10+(a[i][2]-'0')); 
		  }
		}
		if(panduan(a[i])==-1){//����û���ַ��ġ�	
		  if(strlen(a[i])==1)
		    p[i]=a[i][0]-'0';
		  if(strlen(a[i])==2){
		  	if(a[i][0]==45){//����-1 
		  		p[i]=-(a[i][1]-'0');
			  }
			if(a[i][0]!=45){
			    p[i]=(a[i][0]-'0')*10+(a[i][1]-'0');
			}
		}
		  if(strlen(a[i])==3){//ֻ����-12�� 
		  	    p[i]=-((a[i][1]-'0')*10+(a[i][2]-'0')); 
		  }	  
		  } 
		 
		 
		 }
		 return p; 
}
char*character(char**a,int m){
	char*p;
	p=(char*)malloc(sizeof(char)*(m));
	for(int i=0;i<m;i++){
		if(panduan(a[i])==1){//���ַ� 
		  if(strlen(a[i])==2){//����1a 
		  	p[i]=a[i][1];
		  }
		  if(strlen(a[i])==3){
		  	if(a[i][0]==45){//�����и���������-1a 
		  	p[i]=a[i][2];
			  }
		    if(a[i][0]!=45){//�����޸���������12a 
			p[i]=a[i][2];
			}
		}
		  if(strlen(a[i])==4){//����-12a
		    p[i]=a[i][3];
		  }	
	}
	   		if(panduan(a[i])==-1&&add(a[i])==-1){//����û���ַ��ġ�	
            p[i]='+';  
		  } 

}
      return p;
} 

int main(){
	char**a;int m;int up=0,down=0;
	char table[200][300];//��ʾ
	scanf("%d",&m);
	getchar();
	a=(char**)malloc(sizeof(char*)*m);
	for(int i=0;i<m;i++){
		a[i]=(char*)malloc(sizeof(char)*4);
	}
	for(int i=0;i<m;i++){
		int j=0;
		while(((a[i][j]=getchar())!='\n')&&((a[i][j]!=' '))){
			j++;
		}
		a[i][j]=0;
	}//����Ϊ�ԣ� 
	int*p=number(a,m);char*b=character(a,m);
	    for(int i=0;i<m;i++)
    {
        if(p[i]>0&&up<p[i])
        {
            up=p[i];

        }
        else if(p[i]<=0&&down>p[i])
        {
            down=p[i];

        }//ȷ����up��down 
    }
    //��ͷϷ��ʼ 
     int row=up-down+1;//0Ҳ��һ�� 
     for(int j=0;j<m;j++){
     	if(p[j]>0){
     		for(int i=0;i<row;i++){//�����row���ܸ�Ϊup+1��������е�����ռ丳ֵ 
			    if(i<up&&i>=up-p[j]){
					table[i][j]=b[j];
				}
				else if(i==up){
					table[i][j]='-';
				}
				else
				table[i][j]=' ';
			 }
		 }
		 if(p[j]<0){
		 	for(int i=0;i<row;i++){
		 		if(i>up&&i<=up-p[j]){
		 			table[i][j]=b[j];
				 }
				 else if(i==up){
					table[i][j]='-';
				}
				else
				table[i][j]=' ';
				
			 }
		 }
	 } 
	 for(int i=0;i<row;i++){
	 	if(i==up){//ǡǡΪ������ 
	 	for(int j=0;j<m;j++) {
	 		if(j==m-1)//Ϊ���һ�� 
			 printf("%c",table[i][j]);
	 		else 
			 printf("%c-",table[i][j]); 
		 }
	}   
	    else{
	    	for(int j=0;j<m;j++)
	    	printf("%c ",table[i][j]);
		}
		printf("\n");
	 }
}//�����ɢģ���Ѿ��ɹ��� 
