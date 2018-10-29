#include<stdio.h> 
#include<string.h> 
#include<stdlib.h> 
#include<time.h>
float A=0;
int nu=0;
int hourA,hourB,minA,minB;
time_t start,end;
struct Student 
{    char name[21];    //姓名
     char num[10];     //学号或编号
     float avscore;
}s[50];   //结构体数组，存储学生的信息，在此初定为50，可改


void Savemessage()   //保存学生输入信息的函数
{
 FILE *fp,*fp1;   //定义文件指针，//以下判断文件打开与否 ,"a"方式打开则可向文件尾写数据

if((fp=fopen("studentmessage.txt","wb+"))==NULL)   //打开文件studentmessage.txt
    { printf("打开文件失败\n");
          exit(0);}
if((fp1=fopen("TestResult.txt","a"))==NULL)   //打开文件TestResult.txt
    { printf("打开文件失败\n");
       exit(0);}

    printf("    输入姓名：");   //以下为要学生输入个人信息
    scanf("%s",s[0].name);

    printf("    输入学号：");
    scanf("%s",&s[0].num);


fwrite(&s[0],sizeof(struct Student),1,fp);    //向文件studentmessage.txt中写入一条记录，即刚刚输入的学生信息
    fprintf(fp1,"    姓名：%s\n",s[0].name);   //以下为向文件TestResult.txt中写入刚刚输入的学生信息
    fprintf(fp1,"    学号：%s\n",s[0].num);
    fclose(fp);     //关闭文件studentmessage.txt
fclose(fp1);
system("cls");   //清屏
}


void Judge()   //判断函数
{int i=0;
FILE *fp;         //文件指针//以下判断文件打开与否 ,"r"为只读打开方式
printf("\n\n\n");
  printf("         **********************小学四则运算练习软件*******************\n");
  printf("         *-----------------------------------------------------------*\n");
  printf("         *-----------------------------------------------------------*\n");
  printf("         *************************************************************\n");
  printf("         *----------------------------注    册-----------------------*\n");
  printf("         *-----------------------------------------------------------*\n");
  printf("         *----------------------------输入姓名-----------------------*\n");
  printf("         *-----------------------------------------------------------*\n");
  printf("         *----------------------------输入学号-----------------------*\n");
  printf("         *-----------------------------------------------------------*\n\n\n");
if((fp=fopen("studentmessage.txt","r"))==NULL)        //以下判断文件打开与否 "a"方式打开则可向文件尾写数据//打开文件studentmessage.txt
        {   fp=fopen("studentmessage.txt","w+");    //如果没有studentmessage.txt文件，则新建此文件，"w+"打开方式为新建一个文件
            printf("无文件记录，已新建.\n");
        }

while(!feof(fp))   //判断是否到了文件尾
    {
    fread(&s[i],sizeof(struct Student),1,fp); //一行一行从文件中读出学生信息，保存在结构体数组student[]中
    fscanf(fp,"\n");                           //读取换行符
    i++;         //i变量保存学生记录个数
if(i==50)        //当人数满时即50个人满时，因为数组下标从0开始，所以当i为29时
        {
    printf("人数已满，你已无法测试.\n");
    fclose(fp);
        
    exit(0);
        }
    }
}


void Addition(int number)       //加法运算函数，number为题目数形参
{
    
FILE *fp,*fp2,*fp3;
if((fp=fopen("TestResult.txt","a"))==NULL)
        { printf("打开文件失败\n");
   exit(0);}
if((fp2=fopen("failedResult.txt","a"))==NULL)
    {printf("打开文件失败\n");
    exit(0);}

if((fp3=fopen("rightResult.txt","a"))==NULL)
    {printf("打开文件失败\n");
        exit(0);}
int num1,num2,num3,num4,m,n,count1=0,count2=0;
float average=0.0;                //正确率变量，注意是float类型
    srand(time(0));               //初始化随机数，如果没有此语句，则每次运行程序时的随机数是一样的
    fprintf(fp,"    加法测试：\n");   //向文件写入
    fprintf(fp,"    被加数 + 加数 =      你的结果      正确结果   是否正确\n");//向文件写入
{
    printf("         *************************************************************\n");/*选择难度*/
    printf("         *------------------------- 请选择难度:------------------------*\n");
    printf("         *-------------------------  1.简  单 -------------------------*\n");
    printf("         *-------------------------  2.一  般 -------------------------*\n");
    printf("         *-------------------------  3.困  难 -------------------------*\n");
    printf("         *-------------------------------------------------------------*\n\n\n");
printf("请选择难度: "); scanf("%d",&m);system("cls"); //清屏
{    if(m==1) n=10  ;      /*将m的值转化为对应的n值，从而使随机函数出现一位，2位，3位，*/
    if(m==2) n=100 ;
else if(m==3) n=1000 ;}
    printf(" \n  **************************************************************************\n\n");
for(int i=0;i<number;i++)   /*小于测试题目数时，循环*/
    {
    if(m==1)
        {num1=rand()%n; num2=rand()%n;  }  //产生一位随机数,num1,num2

    if(m==2)
    {
        num1=10+rand()%(n-10);           //产生两位随机数 num1,num2     
        num2=10+rand()%(n-10);
    }
    if(m==3)
    {   num1=100+rand()%(n-100);         //产生三位随机数 num1,num2         
        num2=100+rand()%(n-100);
    }
     num3=num1+num2;        //num3保存正确结果
     printf("    %d + %d = ",num1,num2);   //在终端屏幕上输出题目
     scanf("%d",&num4);     //你要输入的计算结果

if(num3==num4)   //正确结果与你计算的结果比较，正确的话
    {
    fprintf(fp,"             %d + %d =\t\t%d\t\t%d\t√ \n",num1,num2,num4,num3);//将结果记录到TestResult.txt中
    count1++;
    }   //变量count1记录正确题目的个数
            
else   //错误的话，即num1!=num2时
    {
    fprintf(fp,"             %d + %d =\t\t%d\t\t%d\t× \n",num1,num2,num4,num3);   //将结果记录到TestResult.txt中
    fprintf(fp2,"    %d + %d =\n",num1,num2,num4,num3);   //将错误题记录到failedResult.txt中
    fprintf(fp3,"    %d + %d =  %d \n",num1,num2,num3);   //将错误题正确结果记录到failedResult.txt中
    }
}
}

average=float(count1)/float(number);   //计算正确率，注意int整型要转换为float类型

fprintf(fp,"    正确 %d 道，错误 %d 道,正确率为：%f\n\n",count1,count2,average);
A=A+average*100;
nu++;
fclose(fp);
fclose(fp3);
fclose(fp2);
}


void Subtracter(int number)   //减法运算函数，注释与加法一样
{
FILE *fp,*fp2,*fp3;
if((fp=fopen("TestResult.txt","a"))==NULL)
    {
    printf("打开文件失败\n");
    exit(0);
    }
if((fp2=fopen("failedResult.txt","a"))==NULL)
    {
    printf("打开文件失败\n");
    exit(0);
    }
if((fp3=fopen("rightResult.txt","a"))==NULL)
    {
    printf("打开文件失败\n");
    exit(0);
    }

int num1,num2,num3,num4,count1=0,n,m,count2=0;
float average=0.0;
    srand(time(0));
    fprintf(fp,"    减法测试：\n");
    fprintf(fp,"    被减数 - 减数 =      你的结果      正确结果   是否正确\n");

    printf("         *************************************************************\n");/*选择难度*/
    printf("         *------------------------- 请选择难度:------------------------*\n");
    printf("         *-------------------------  1.简  单 -------------------------*\n");
    printf("         *-------------------------  2.一  般 -------------------------*\n");
    printf("         *-------------------------  3.困  难 -------------------------*\n");
    printf("         *-------------------------------------------------------------*\n\n\n");
    printf("请选择: "); scanf("%d",&m);system("cls"); //清屏
{if(m==1) n=10  ;
if(m==2) n=100 ;
else if(m==3) n=1000 ;}
    printf(" \n  **************************************************************************\n\n");
for(int i=0;i<number;i++)
    {if(m==1)
        {num1=rand()%n; num2=rand()%n;  }  //产生一位随机数,num1,num2

    if(m==2)
        {num1=10+rand()%(n-10);           //产生两位随机数 num1,num2     
        num2=10+rand()%(n-10);}
    if(m==3)
        {num1=100+rand()%(n-100);         //产生三位随机数 num1,num2         
        num2=100+rand()%(n-100);}
    num3=num1-num2;
    printf("    %d - %d = ",num1,num2);
    scanf("%d",&num4);
if(num3==num4)
    {
    fprintf(fp,"             %d - %d =\t\t%d\t\t%d\t√ \n",num1,num2,num4,num3);
    count1++;  
    }
else
    {
    fprintf(fp,"             %d - %d =\t\t%d\t\t%d\t× \n",num1,num2,num4,num3);
    count2++;
    fprintf(fp2,"    %d - %d =\n",num1,num2,num4,num3);
    fprintf(fp3,"    %d - %d =  %d \n",num1,num2,num3);
    }
}
    average=float(count1)/float(number);

fprintf(fp,"    正确 %d 道，错误 %d 道,正确率为：%f\n\n",count1,count2,average);
A=A+average*100;
nu++;
fclose(fp);fclose(fp2);
fclose(fp3);
}


void Multiplication(int number)//乘法运算函数，注释与加法一样
{
FILE *fp,*fp2,*fp3;
if((fp=fopen("TestResult.txt","a"))==NULL)
    {
    printf("打开文件失败\n");
    exit(0);
    }

if((fp2=fopen("failedResult.txt","a"))==NULL)
    {
    printf("打开文件失败\n");
    exit(0);
    }
if((fp3=fopen("rightResult.txt","a"))==NULL)
    {
    printf("打开文件失败\n");
    exit(0);
    }

int num1,num2,num3,num4,m,n,count1=0,count2=0;
float average=0.0;
    srand(time(0));
    fprintf(fp,"    乘法测试：\n");
    fprintf(fp,"    被乘数 * 乘数 =      你的结果      正确结果   是否正确\n");

{   printf("         *************************************************************\n");/*选择难度*/
    printf("         *------------------------- 请选择难度:------------------------*\n");
    printf("         *-------------------------  1.简  单 -------------------------*\n");
    printf("         *-------------------------  2.一  般 -------------------------*\n");
    printf("         *-------------------------  3.困  难 -------------------------*\n");
    printf("         *-------------------------------------------------------------*\n\n\n");
    printf("请选择: ");} 
    scanf("%d",&m);
    system("cls"); //清屏

{if(m==1) n=10  ;
if(m==2) n=100 ;
else if(m==3) n=1000 ;}
    printf(" \n  **************************************************************************\n\n");
for(int i=0;i<number;i++)
{if(m==1)
    {num1=rand()%n; num2=rand()%n;  }  
if(m==2)
    {num1=10+rand()%(n-10);               
    num2=10+rand()%(n-10);}
if(m==3)
    {
    num1=100+rand()%(n-100);                  
    num2=100+rand()%(n-100);
    }
    num3=num1*num2;
    printf("    %d * %d = ",num1,num2);
    scanf("%d",&num4);
if(num3==num4)
    {
    fprintf(fp,"             %d * %d =\t\t%d\t\t%d\t√\n",num1,num2,num4,num3);
    count1++;
    }
else
    {
    fprintf(fp,"             %d * %d =\t\t%d\t\t%d\t×\n",num1,num2,num4,num3);
    count2++;
    fprintf(fp2,"    %d * %d =\n",num1,num2,num4,num3);
    fprintf(fp3,"    %d * %d =  %d \n",num1,num2,num3);
    }
 }
average=float(count1)/float(number);

fprintf(fp,"    正确 %d 道，错误 %d 道,正确率为：%f\n\n",count1,count2,average);
A=A+average*100;
nu++;
fclose(fp);
fclose(fp2);
fclose(fp3);
}

void Division(int number)       // 和加法运算函数注释一样
{
    FILE *fp,*fp2,*fp3;
if((fp=fopen("TestResult.txt","a"))==NULL)
    {
    printf("打开文件失败\n");
    exit(0);
    }

if((fp2=fopen("failedResult.txt","a"))==NULL)
    {
    printf("打开文件失败\n");
    exit(0);
    }
if((fp3=fopen("rightResult.txt","a"))==NULL)
    {
    printf("打开文件失败\n");
    exit(0);
    }

int num1,num2,m,n,count1=0,count2=0;
float num3,num4,average;        //正确率变量，注意是float类型
    srand(time(0));             //初始化随机数，如果没有此语句，则每次运行程序时的随机数是一样的
    fprintf(fp,"    加法测试：\n");   //向文件写入
    fprintf(fp,"    除数数/被除数=      你的结果      正确结果   是否正确\n");//向文件写入

{   printf("         *************************************************************\n");/*选择难度*/
    printf("         *------------------------- 请选择难度:------------------------*\n");
    printf("         *-------------------------  1.简  单 -------------------------*\n");
    printf("         *-------------------------  2.一  般 -------------------------*\n");
    printf("         *-------------------------  3.困  难 -------------------------*\n");
    printf("         *-------------------------------------------------------------*\n\n\n"); 
    printf("请选择：");
    scanf("%d",&m);system("cls");   //清屏

{if(m==1) n=10  ;
if(m==2) n=100 ;
else if(m==3) n=1000 ;}
    
    printf(" \n  **************************************************************************\n\n");
    printf("    请保留保留小数点后一位    \n");
for(int i=0;i<number;i++)   //小于测试题目数时，循环
{if(m==1)
    num1=rand()%n;   
if(m==2)
    num1=10+rand()%(n-10);               

if(m==3)
    num1=100+rand()%(n-100);                  
    num2=n/10+rand()%(n-n/10);       //产生不等于零的随机数num3
    num3=(float)(num1)/(float)(num2);   //num3保存正确结果
    printf("    %d / %d = ",num1,num2);    //在终端屏幕上输出题目
    scanf("%f",&num4);   //你要输入的计算结果
    num3=(int)(num3*10)/10.0;   //实现保留小数点一位
if(num3==num4)                                        //正确结果与你计算的结果比较，正确的话
    {fprintf(fp,"             %d / %d =\t\t%.1f\t\t%.1f\t√ \n",num1,num2,num4,num3);//向文件中写入
    count1++;                                       //变量count1记录正确题目的个数
    }
else                        //错误的话，即num1!=num2时
    {fprintf(fp,"             %d / %d =\t\t%.1f\t\t%.1f\t× \n",num1,num2,num4,num3);
    count2++;   //变量count2记录错误题目的个数
    fprintf(fp2,"    %d / %d = \n",num1,num2);
    fprintf(fp3,"    %d / %d =  %.1f \n",num1,num2,num3);}}}
average=float(count1)/float(number);   //计算正确率，注意int整型要转换为float类型
fprintf(fp,"    正确 %d 道，错误 %d 道,正确率为：%f\n\n",count1,count2,average);
A=A+average*100;
nu++;
fclose(fp);
fclose(fp2);
fclose(fp3);
}

void  rework()   // 错题重做
{int a;
 char ch;
 FILE *fp2,*fp3;
    
if((fp2=fopen("failedResult.txt","a+"))==NULL)
    {printf("打开文件失败\n");
   exit(0);}
    
if((fp3=fopen("rightResult.txt","a+"))==NULL)
    {printf("打开文件失败\n");
     exit(0);}
    printf("********************错题重做***************************************\n");
while(!feof(fp2))  
    {ch=fgetc(fp2);printf("%c",ch);   //读取failedResult.txt中的错题
if(ch=='=')  
    scanf("%d",&a);}              //输入答案
    fp2=fopen("failedResult.txt","w");   //清空之前数据
    fclose(fp2);
    printf("========请查看正确答案===========================================\n");
while(!feof(fp3))  
    { 
    ch=fgetc(fp3);printf("%c",ch);}   //读取rightResult.txt中的错题的答案
    fclose(fp3);fp3=fopen("rightResult.txt","w");//清空
    fclose(fp3);
    }


void sort()      //实现排序
{FILE *fp5;
int i,j,m;
   s[0].avscore=A/nu;
   fp5=fopen("nrecord.txt","a+");
   fprintf(fp5,"%s        %s        %f\n",s[0].name,s[0].num,s[0].avscore);   //将刚刚做过的测试记录到文件nrecord.txt中
   fclose(fp5);
    fp5=fopen("nrecord.txt","rb");
for(i=0;!feof(fp5);i++)
   {
    fscanf(fp5,"%s        %s        %f\n",s[i].name,s[i].num,&s[i].avscore);}   //将文件nrecord.txt的记录存到结构体struct Student中
   fclose(fp5);
//实现排序   
    m=i;
struct Student temp;
for(i=0;i<m;i++)
{  
for(j=0;j<m-1;j++)
    if(s[j].avscore<s[j+1].avscore)
    {
    strcpy(temp.name,s[j].name);      //利用临时结构变量temp实现数组元素的交换
    strcpy(temp.num,s[j].num);
    temp.avscore=s[j].avscore;

    strcpy(s[j].name,s[j+1].name);
    strcpy(s[j].num,s[j+1].num);
    s[j].avscore=s[j+1].avscore;

    strcpy(s[j+1].name,temp.name);
    strcpy(s[j+1].num,temp.num);
    s[j+1].avscore=temp.avscore;
    }
          //若n=0，意味着没有交换了，排序已经完成
}
//输出排名结果
    printf(" ****************************************************************\n");
    printf("   ---------查看你的排名（排序结果由高到低):--------------------\n");
    printf("   -------------姓名        学号        分数------------\n");
for(i=0;i<m;i++)
    {printf("        %s        %s        %4.2f\n",s[i].name,s[i].num,s[i].avscore);}}





void TestOver()   //程序测试完毕函数
{
printf("\n\n------测试完毕你的测试结果保存在 %s 中------\n\n",s[0].num);    //输出测试结果记录提示
}


void ShowResult()   //显示测试结果函数
{
FILE *fp;
if((fp=fopen("TestResult.txt","r"))==NULL)
{   printf("打开文件失败\n");
    exit(0);}
char ch;
     ch=fgetc(fp);   //文件开头字符
while(ch!=EOF)   //当文件没有到尾时，一直循环
{   putchar(ch);   //输出字符
   ch=fgetc(fp);}
 fclose(fp);
}


void FileCopy()   //文件复制函数，用来保存测试结果，当然文件名不能重复，
{
FILE *in,*out;
    strcat(s[0].num,".txt");   //将字符串".txt"连接到字符串student[0].num后，即以学号为文件名，后缀为.txt的文件中，保存在工程目录下
if((in=fopen("TestResult.txt","r"))==NULL)
    {   in=fopen("TestResult.txt","w+");
     printf("无文件记录，已新建.\n");
    }
if((out=fopen(s[0].num,"w"))==NULL)   //打开文件学号.txt 文件（如03071361.txt），"w"方式为只写方式
    {   printf("打开文件失败\n");
    exit(0);
    }
while(!feof(in))   //当文件TestResult.txt没有结束时循环
    fputc(fgetc(in),out);   //逐个字符写入
    fclose(in);
    fclose(out);}

void ChooseFunc();
void begain()
    {
    printf("\n\n\n");
    printf("         \n");
    printf("         *************************************************************\n");
    printf("         *--------------------------1.加法测试-----------------------*\n");
    printf("         *--------------------------2.减法测试-----------------------*\n");
    printf("         *--------------------------3.乘法测试-----------------------*\n");
    printf("         *--------------------------4.除法测试-----------------------*\n");
    printf("         *--------------------------5.返回主菜单----------------------*\n");
    printf("         *------------------------------------------------------------*\n\n\n");
int choose,thnum;   // bool judge=false;
    printf("         选择功能：");
    scanf("%d",&choose);
while(choose<1||choose>5)   //不在以上所列的功能以内时循环
{
    printf("         超出功能范围，请重新选择(1---5):");
   scanf("%d",&choose);
}
switch(choose)   //switch语句选择执行功能
{
case 1:   //执行功能1
     system("cls");   //清屏
     printf("\n\n\n");
     printf("         加法测试：输入要测试的题目数(5/10/20/50/100):：",&thnum);
     scanf("%d",&thnum);

while(thnum<5||thnum>5&&thnum<10||thnum>10&&thnum<20||thnum>20&&thnum<50||thnum>50&&thnum<100||thnum>100)   //不在以上所列的功能以内时循环
{    printf("超出功能范围，请重新选择(5/10/20/50/100):");
     scanf("%d",&thnum);}

     system("cls");//清屏
     
     Addition(thnum);   //调用加法运算函数
     begain();

 break;
case 2:
     system("cls");   //清屏
     printf("\n\n\n");
     printf("         减法测试：输入要测试的题目数(5/10/20/50/100):",&thnum);
     scanf("%d",&thnum);

while(thnum<5||thnum>5&&thnum<10||thnum>10&&thnum<20||thnum>20&&thnum<50||thnum>50&&thnum<100||thnum>100)   //不在以上所列的功能以内时循环
{    printf("超出功能范围，请重新选择(5/10/20/50/100):");
     scanf("%d",&thnum);}

     system("cls");   //清屏
     Subtracter(thnum);
     begain();
    break;
case 3:
     system("cls");   //清屏
     printf("\n\n\n");
     printf("         乘法测试：输入要测试的题目数(5/10/20/50/100):",&thnum);
     scanf("%d",&thnum);
while(thnum<5||thnum>5&&thnum<10||thnum>10&&thnum<20||thnum>20&&thnum<50||thnum>50&&thnum<100||thnum>100)//不在以上所列的功能以内时循环
{    
       printf("超出功能范围，请重新选择(5/10/20/50/100):");
    scanf("%d",&thnum);}
     
    system("cls");   //清屏
    printf("\n\n\n");
    Multiplication(thnum);
    begain();
   break;
case 4:
    system("cls");   //清屏
    printf("\n\n\n");
    printf("         除法测试：输入要测试的题目数(5/10/20/50/100):",&thnum);
    scanf("%d",&thnum);
while(thnum<5||thnum>5&&thnum<10||thnum>10&&thnum<20||thnum>20&&thnum<50||thnum>50&&thnum<100||thnum>100)//不在以上所列的功能以内时循环
{   printf("超出功能范围，请重新选择(5/10/20/50/100):");
    scanf("%d",&thnum);}
    system("cls");   //清屏
    printf("\n\n\n");
    Division(thnum);begain();
   break;
case 5:
    system("cls");   //清屏

    ChooseFunc();
   break;}}


void ChooseFunc()   //功能选择函数
{
    printf("\n\n\n");
    printf("         *************************************************************\n");
    printf("         *--------------------------1.开始测试-----------------------*\n");
    printf("         *--------------------------2.查看结果-----------------------*\n");
    printf("         *--------------------------3.查看排名-----------------------*\n");
    printf("         *--------------------------4.错题重做-----------------------*\n");
    printf("         *--------------------------5.结束测试 ----------------------*\n");
    printf("         *-----------------------------------------------------------*\n\n\n");
int choose;


    printf("         选择功能：");
scanf("%d",&choose);
while(choose<1||choose>5)   //不在以上所列的功能以内时循环
{
    printf("         超出功能范围，请重新选择(1---5):");
    scanf("%d",&choose);
}
switch(choose)   //switch语句选择执行功能
{
case 1:    //功能1
    system("cls");
    printf("  *************************************************************\n");
    {
    start =time(NULL);
    system("cls");  
    } 
//显示时间

     begain();
    
break;
case 2:   //功能2
    system("cls");
    printf("\n\n");
    ShowResult();   //调用此函数，即输出测试结果
    ChooseFunc();
break;
case 3:   //功能2
    system("cls");
    printf("\n\n");
    sort();   //调用此函数，即输出测试结果
    ChooseFunc();
    break;

case 4:   //功能4
    system("cls");   //清屏
    printf("\n\n");
    rework();   //调用此函数，即输出测试结果
    ChooseFunc();
    break;
case 5:   //功能5
    system("cls");   //清屏
    printf("\n\n");
    
    { 
        end =time(NULL);
        printf("   *-----------------------------------------------------------------*\n");
        printf("   *------------------你答题用时为:%d秒------------------------*\n",end-start);
    }
        FileCopy();   //调用此函数，即复制测试结果
        TestOver();
    break;
    }
}


int main(int argc, char *argv[])    
{
    system("color b0");        

    FILE *fp,*fp2,*fp3;
    fp=fopen("TestResult.txt","w");   //以只写方式打开文件，如果文件存在，则清空，这就是为什么结束程序时要复制测试结果了
    fp2=fopen("failedResult.txt","w");   //清空之前数据
    fclose(fp2);
    fp3=fopen("rightResult.txt","w");   //清空
    fclose(fp3);
    Judge();              //调用此函数
    Savemessage();        //调用此函数
    ChooseFunc();         //调用此函数
    
}