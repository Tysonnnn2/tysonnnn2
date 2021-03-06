#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <string.h>


char getSignal();                      //获取随机运算符函数
int random(double,double);             //获取随机数函数
int getResult(int,int,char);           //结果计算函数
int takeTest();                        //题目生成函数

void main()  
{
	int n,a,right=0;
	double percent;
	printf("请输入题目数量:");
	scanf("%d",&n);
	for(int i=0;i<n;i++)
	{
		a=takeTest();
		right=right+a;
	}
	printf("厉害!\n");
	printf("正确题数:%d\n",right);
	percent=((double)right*100.00)/(double)n;
	printf("正确率:%0.2f %%\n",percent);
}
 
char getSignal()
{
    char signal[4]={'+','-','*','/'};
    srand((unsigned)time(NULL));
    return signal[rand()%4];
}
 
int random(double start, double end)
{
    return (int)(start+(end-start)*rand()/(RAND_MAX+ 1.0));
}
 
int getResult(int num1,int num2,char signal)
{
    int res;
    switch(signal)
    {
    case '+':
        res=num1+num2;break;
    case '-':
        res=num1-num2;break;
    case '*':
        res=num1*num2;break;
    case '/':
        res=num1/num2;break;
    default:
        printf("运算符错误！\n");
    }
    return res;
}
 

int takeTest()
{
    int get;
    int num1,num2,a;
    char signal;
 
    srand((unsigned)time(NULL));
    signal=getSignal();
    num1=random(0,10);
    num2=random(1,10);
 
    if(signal=='-')
    {
        if(num1<num2)
        {
            int temp;
            temp=num1;
            num1=num2;
            num2=temp;
        }
    }
 
    if(signal=='/')
    {
        if(num2==0)
        {
            int temp;
            temp=num1;
            num1=num2;
            num2=temp;
        }
    }
 
    printf("%d%c%d=",num1,signal,num2);
    scanf("%d",&get);
    fflush(stdin);   //清空输入缓冲区
 
    if(getResult(num1,num2,signal)==get)
	{
        printf("You're right!\n");
		a=1;
	}
    else
    {
        printf("错误!\n");
        printf("正确答案是: %d\n",getResult(num1,num2,signal));
		a=0;
    }
	return a;
}