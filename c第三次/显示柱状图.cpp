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
		return 1; //代表有不是负号的字符就返回1 
	}
	    return -1;//代表没有（除负号外的）字符就返回0； 
}
int *number(char**a,int m){
	int*p;
	p=(int*)malloc(sizeof(int)*(m));
	for(int i=0;i<m;i++){
		if(panduan(a[i])==1){//代表有字符 
		  if(strlen(a[i])==2){//代表1a 
		  	p[i]=a[i][0]-'0';
		  }
		  
		  if(strlen(a[i])==3){
		  	if(a[i][0]==45){//代表有负数，形如-1a 
		  	p[i]=-(a[i][1]-'0');
			  }
			if(a[i][0]!=45){//代表无负数，形如12a 
			p[i]=(a[i][0]-'0')*10+((a[i][1])-'0');
			}
		  }
		  if(strlen(a[i])==4){//代表-12a
		    p[i]=-((a[i][1]-'0')*10+(a[i][2]-'0')); 
		  }
		}
		if(panduan(a[i])==-1){//代表没有字符的。	
		  if(strlen(a[i])==1)
		    p[i]=a[i][0]-'0';
		  if(strlen(a[i])==2){
		  	if(a[i][0]==45){//形如-1 
		  		p[i]=-(a[i][1]-'0');
			  }
			if(a[i][0]!=45){
			    p[i]=(a[i][0]-'0')*10+(a[i][1]-'0');
			}
		}
		  if(strlen(a[i])==3){//只能是-12了 
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
		if(panduan(a[i])==1){//有字符 
		  if(strlen(a[i])==2){//代表1a 
		  	p[i]=a[i][1];
		  }
		  if(strlen(a[i])==3){
		  	if(a[i][0]==45){//代表有负数，形如-1a 
		  	p[i]=a[i][2];
			  }
		    if(a[i][0]!=45){//代表无负数，形如12a 
			p[i]=a[i][2];
			}
		}
		  if(strlen(a[i])==4){//代表-12a
		    p[i]=a[i][3];
		  }	
	}
	   		if(panduan(a[i])==-1&&add(a[i])==-1){//代表没有字符的。	
            p[i]='+';  
		  } 

}
      return p;
} 

int main(){
	char**a;int m;int up=0,down=0;
	char table[200][300];//显示
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
	}//以上为对； 
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

        }//确立好up和down 
    }
    //重头戏开始 
     int row=up-down+1;//0也算一行 
     for(int j=0;j<m;j++){
     	if(p[j]>0){
     		for(int i=0;i<row;i++){//这里的row不能改为up+1必须给所有的数组空间赋值 
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
	 	if(i==up){//恰恰为坐标轴 
	 	for(int j=0;j<m;j++) {
	 		if(j==m-1)//为最后一个 
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
}//这个离散模型已经成功， 
