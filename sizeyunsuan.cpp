#include<stdio.h> 
#include<string.h> 
#include<stdlib.h> 
#include<time.h>
float A=0;
int nu=0;
int hourA,hourB,minA,minB;
time_t start,end;
struct Student 
{    char name[21];    //����
     char num[10];     //ѧ�Ż���
     float avscore;
}s[50];   //�ṹ�����飬�洢ѧ������Ϣ���ڴ˳���Ϊ50���ɸ�


void Savemessage()   //����ѧ��������Ϣ�ĺ���
{
 FILE *fp,*fp1;   //�����ļ�ָ�룬//�����ж��ļ������ ,"a"��ʽ��������ļ�βд����

if((fp=fopen("studentmessage.txt","wb+"))==NULL)   //���ļ�studentmessage.txt
    { printf("���ļ�ʧ��\n");
          exit(0);}
if((fp1=fopen("TestResult.txt","a"))==NULL)   //���ļ�TestResult.txt
    { printf("���ļ�ʧ��\n");
       exit(0);}

    printf("    ����������");   //����ΪҪѧ�����������Ϣ
    scanf("%s",s[0].name);

    printf("    ����ѧ�ţ�");
    scanf("%s",&s[0].num);


fwrite(&s[0],sizeof(struct Student),1,fp);    //���ļ�studentmessage.txt��д��һ����¼�����ո������ѧ����Ϣ
    fprintf(fp1,"    ������%s\n",s[0].name);   //����Ϊ���ļ�TestResult.txt��д��ո������ѧ����Ϣ
    fprintf(fp1,"    ѧ�ţ�%s\n",s[0].num);
    fclose(fp);     //�ر��ļ�studentmessage.txt
fclose(fp1);
system("cls");   //����
}


void Judge()   //�жϺ���
{int i=0;
FILE *fp;         //�ļ�ָ��//�����ж��ļ������ ,"r"Ϊֻ���򿪷�ʽ
printf("\n\n\n");
  printf("         **********************Сѧ����������ϰ����*******************\n");
  printf("         *-----------------------------------------------------------*\n");
  printf("         *-----------------------------------------------------------*\n");
  printf("         *************************************************************\n");
  printf("         *----------------------------ע    ��-----------------------*\n");
  printf("         *-----------------------------------------------------------*\n");
  printf("         *----------------------------��������-----------------------*\n");
  printf("         *-----------------------------------------------------------*\n");
  printf("         *----------------------------����ѧ��-----------------------*\n");
  printf("         *-----------------------------------------------------------*\n\n\n");
if((fp=fopen("studentmessage.txt","r"))==NULL)        //�����ж��ļ������ "a"��ʽ��������ļ�βд����//���ļ�studentmessage.txt
        {   fp=fopen("studentmessage.txt","w+");    //���û��studentmessage.txt�ļ������½����ļ���"w+"�򿪷�ʽΪ�½�һ���ļ�
            printf("���ļ���¼�����½�.\n");
        }

while(!feof(fp))   //�ж��Ƿ����ļ�β
    {
    fread(&s[i],sizeof(struct Student),1,fp); //һ��һ�д��ļ��ж���ѧ����Ϣ�������ڽṹ������student[]��
    fscanf(fp,"\n");                           //��ȡ���з�
    i++;         //i��������ѧ����¼����
if(i==50)        //��������ʱ��50������ʱ����Ϊ�����±��0��ʼ�����Ե�iΪ29ʱ
        {
    printf("���������������޷�����.\n");
    fclose(fp);
        
    exit(0);
        }
    }
}


void Addition(int number)       //�ӷ����㺯����numberΪ��Ŀ���β�
{
    
FILE *fp,*fp2,*fp3;
if((fp=fopen("TestResult.txt","a"))==NULL)
        { printf("���ļ�ʧ��\n");
   exit(0);}
if((fp2=fopen("failedResult.txt","a"))==NULL)
    {printf("���ļ�ʧ��\n");
    exit(0);}

if((fp3=fopen("rightResult.txt","a"))==NULL)
    {printf("���ļ�ʧ��\n");
        exit(0);}
int num1,num2,num3,num4,m,n,count1=0,count2=0;
float average=0.0;                //��ȷ�ʱ�����ע����float����
    srand(time(0));               //��ʼ������������û�д���䣬��ÿ�����г���ʱ���������һ����
    fprintf(fp,"    �ӷ����ԣ�\n");   //���ļ�д��
    fprintf(fp,"    ������ + ���� =      ��Ľ��      ��ȷ���   �Ƿ���ȷ\n");//���ļ�д��
{
    printf("         *************************************************************\n");/*ѡ���Ѷ�*/
    printf("         *------------------------- ��ѡ���Ѷ�:------------------------*\n");
    printf("         *-------------------------  1.��  �� -------------------------*\n");
    printf("         *-------------------------  2.һ  �� -------------------------*\n");
    printf("         *-------------------------  3.��  �� -------------------------*\n");
    printf("         *-------------------------------------------------------------*\n\n\n");
printf("��ѡ���Ѷ�: "); scanf("%d",&m);system("cls"); //����
{    if(m==1) n=10  ;      /*��m��ֵת��Ϊ��Ӧ��nֵ���Ӷ�ʹ�����������һλ��2λ��3λ��*/
    if(m==2) n=100 ;
else if(m==3) n=1000 ;}
    printf(" \n  **************************************************************************\n\n");
for(int i=0;i<number;i++)   /*С�ڲ�����Ŀ��ʱ��ѭ��*/
    {
    if(m==1)
        {num1=rand()%n; num2=rand()%n;  }  //����һλ�����,num1,num2

    if(m==2)
    {
        num1=10+rand()%(n-10);           //������λ����� num1,num2     
        num2=10+rand()%(n-10);
    }
    if(m==3)
    {   num1=100+rand()%(n-100);         //������λ����� num1,num2         
        num2=100+rand()%(n-100);
    }
     num3=num1+num2;        //num3������ȷ���
     printf("    %d + %d = ",num1,num2);   //���ն���Ļ�������Ŀ
     scanf("%d",&num4);     //��Ҫ����ļ�����

if(num3==num4)   //��ȷ����������Ľ���Ƚϣ���ȷ�Ļ�
    {
    fprintf(fp,"             %d + %d =\t\t%d\t\t%d\t�� \n",num1,num2,num4,num3);//�������¼��TestResult.txt��
    count1++;
    }   //����count1��¼��ȷ��Ŀ�ĸ���
            
else   //����Ļ�����num1!=num2ʱ
    {
    fprintf(fp,"             %d + %d =\t\t%d\t\t%d\t�� \n",num1,num2,num4,num3);   //�������¼��TestResult.txt��
    fprintf(fp2,"    %d + %d =\n",num1,num2,num4,num3);   //���������¼��failedResult.txt��
    fprintf(fp3,"    %d + %d =  %d \n",num1,num2,num3);   //����������ȷ�����¼��failedResult.txt��
    }
}
}

average=float(count1)/float(number);   //������ȷ�ʣ�ע��int����Ҫת��Ϊfloat����

fprintf(fp,"    ��ȷ %d �������� %d ��,��ȷ��Ϊ��%f\n\n",count1,count2,average);
A=A+average*100;
nu++;
fclose(fp);
fclose(fp3);
fclose(fp2);
}


void Subtracter(int number)   //�������㺯����ע����ӷ�һ��
{
FILE *fp,*fp2,*fp3;
if((fp=fopen("TestResult.txt","a"))==NULL)
    {
    printf("���ļ�ʧ��\n");
    exit(0);
    }
if((fp2=fopen("failedResult.txt","a"))==NULL)
    {
    printf("���ļ�ʧ��\n");
    exit(0);
    }
if((fp3=fopen("rightResult.txt","a"))==NULL)
    {
    printf("���ļ�ʧ��\n");
    exit(0);
    }

int num1,num2,num3,num4,count1=0,n,m,count2=0;
float average=0.0;
    srand(time(0));
    fprintf(fp,"    �������ԣ�\n");
    fprintf(fp,"    ������ - ���� =      ��Ľ��      ��ȷ���   �Ƿ���ȷ\n");

    printf("         *************************************************************\n");/*ѡ���Ѷ�*/
    printf("         *------------------------- ��ѡ���Ѷ�:------------------------*\n");
    printf("         *-------------------------  1.��  �� -------------------------*\n");
    printf("         *-------------------------  2.һ  �� -------------------------*\n");
    printf("         *-------------------------  3.��  �� -------------------------*\n");
    printf("         *-------------------------------------------------------------*\n\n\n");
    printf("��ѡ��: "); scanf("%d",&m);system("cls"); //����
{if(m==1) n=10  ;
if(m==2) n=100 ;
else if(m==3) n=1000 ;}
    printf(" \n  **************************************************************************\n\n");
for(int i=0;i<number;i++)
    {if(m==1)
        {num1=rand()%n; num2=rand()%n;  }  //����һλ�����,num1,num2

    if(m==2)
        {num1=10+rand()%(n-10);           //������λ����� num1,num2     
        num2=10+rand()%(n-10);}
    if(m==3)
        {num1=100+rand()%(n-100);         //������λ����� num1,num2         
        num2=100+rand()%(n-100);}
    num3=num1-num2;
    printf("    %d - %d = ",num1,num2);
    scanf("%d",&num4);
if(num3==num4)
    {
    fprintf(fp,"             %d - %d =\t\t%d\t\t%d\t�� \n",num1,num2,num4,num3);
    count1++;  
    }
else
    {
    fprintf(fp,"             %d - %d =\t\t%d\t\t%d\t�� \n",num1,num2,num4,num3);
    count2++;
    fprintf(fp2,"    %d - %d =\n",num1,num2,num4,num3);
    fprintf(fp3,"    %d - %d =  %d \n",num1,num2,num3);
    }
}
    average=float(count1)/float(number);

fprintf(fp,"    ��ȷ %d �������� %d ��,��ȷ��Ϊ��%f\n\n",count1,count2,average);
A=A+average*100;
nu++;
fclose(fp);fclose(fp2);
fclose(fp3);
}


void Multiplication(int number)//�˷����㺯����ע����ӷ�һ��
{
FILE *fp,*fp2,*fp3;
if((fp=fopen("TestResult.txt","a"))==NULL)
    {
    printf("���ļ�ʧ��\n");
    exit(0);
    }

if((fp2=fopen("failedResult.txt","a"))==NULL)
    {
    printf("���ļ�ʧ��\n");
    exit(0);
    }
if((fp3=fopen("rightResult.txt","a"))==NULL)
    {
    printf("���ļ�ʧ��\n");
    exit(0);
    }

int num1,num2,num3,num4,m,n,count1=0,count2=0;
float average=0.0;
    srand(time(0));
    fprintf(fp,"    �˷����ԣ�\n");
    fprintf(fp,"    ������ * ���� =      ��Ľ��      ��ȷ���   �Ƿ���ȷ\n");

{   printf("         *************************************************************\n");/*ѡ���Ѷ�*/
    printf("         *------------------------- ��ѡ���Ѷ�:------------------------*\n");
    printf("         *-------------------------  1.��  �� -------------------------*\n");
    printf("         *-------------------------  2.һ  �� -------------------------*\n");
    printf("         *-------------------------  3.��  �� -------------------------*\n");
    printf("         *-------------------------------------------------------------*\n\n\n");
    printf("��ѡ��: ");} 
    scanf("%d",&m);
    system("cls"); //����

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
    fprintf(fp,"             %d * %d =\t\t%d\t\t%d\t��\n",num1,num2,num4,num3);
    count1++;
    }
else
    {
    fprintf(fp,"             %d * %d =\t\t%d\t\t%d\t��\n",num1,num2,num4,num3);
    count2++;
    fprintf(fp2,"    %d * %d =\n",num1,num2,num4,num3);
    fprintf(fp3,"    %d * %d =  %d \n",num1,num2,num3);
    }
 }
average=float(count1)/float(number);

fprintf(fp,"    ��ȷ %d �������� %d ��,��ȷ��Ϊ��%f\n\n",count1,count2,average);
A=A+average*100;
nu++;
fclose(fp);
fclose(fp2);
fclose(fp3);
}

void Division(int number)       // �ͼӷ����㺯��ע��һ��
{
    FILE *fp,*fp2,*fp3;
if((fp=fopen("TestResult.txt","a"))==NULL)
    {
    printf("���ļ�ʧ��\n");
    exit(0);
    }

if((fp2=fopen("failedResult.txt","a"))==NULL)
    {
    printf("���ļ�ʧ��\n");
    exit(0);
    }
if((fp3=fopen("rightResult.txt","a"))==NULL)
    {
    printf("���ļ�ʧ��\n");
    exit(0);
    }

int num1,num2,m,n,count1=0,count2=0;
float num3,num4,average;        //��ȷ�ʱ�����ע����float����
    srand(time(0));             //��ʼ������������û�д���䣬��ÿ�����г���ʱ���������һ����
    fprintf(fp,"    �ӷ����ԣ�\n");   //���ļ�д��
    fprintf(fp,"    ������/������=      ��Ľ��      ��ȷ���   �Ƿ���ȷ\n");//���ļ�д��

{   printf("         *************************************************************\n");/*ѡ���Ѷ�*/
    printf("         *------------------------- ��ѡ���Ѷ�:------------------------*\n");
    printf("         *-------------------------  1.��  �� -------------------------*\n");
    printf("         *-------------------------  2.һ  �� -------------------------*\n");
    printf("         *-------------------------  3.��  �� -------------------------*\n");
    printf("         *-------------------------------------------------------------*\n\n\n"); 
    printf("��ѡ��");
    scanf("%d",&m);system("cls");   //����

{if(m==1) n=10  ;
if(m==2) n=100 ;
else if(m==3) n=1000 ;}
    
    printf(" \n  **************************************************************************\n\n");
    printf("    �뱣������С�����һλ    \n");
for(int i=0;i<number;i++)   //С�ڲ�����Ŀ��ʱ��ѭ��
{if(m==1)
    num1=rand()%n;   
if(m==2)
    num1=10+rand()%(n-10);               

if(m==3)
    num1=100+rand()%(n-100);                  
    num2=n/10+rand()%(n-n/10);       //������������������num3
    num3=(float)(num1)/(float)(num2);   //num3������ȷ���
    printf("    %d / %d = ",num1,num2);    //���ն���Ļ�������Ŀ
    scanf("%f",&num4);   //��Ҫ����ļ�����
    num3=(int)(num3*10)/10.0;   //ʵ�ֱ���С����һλ
if(num3==num4)                                        //��ȷ����������Ľ���Ƚϣ���ȷ�Ļ�
    {fprintf(fp,"             %d / %d =\t\t%.1f\t\t%.1f\t�� \n",num1,num2,num4,num3);//���ļ���д��
    count1++;                                       //����count1��¼��ȷ��Ŀ�ĸ���
    }
else                        //����Ļ�����num1!=num2ʱ
    {fprintf(fp,"             %d / %d =\t\t%.1f\t\t%.1f\t�� \n",num1,num2,num4,num3);
    count2++;   //����count2��¼������Ŀ�ĸ���
    fprintf(fp2,"    %d / %d = \n",num1,num2);
    fprintf(fp3,"    %d / %d =  %.1f \n",num1,num2,num3);}}}
average=float(count1)/float(number);   //������ȷ�ʣ�ע��int����Ҫת��Ϊfloat����
fprintf(fp,"    ��ȷ %d �������� %d ��,��ȷ��Ϊ��%f\n\n",count1,count2,average);
A=A+average*100;
nu++;
fclose(fp);
fclose(fp2);
fclose(fp3);
}

void  rework()   // ��������
{int a;
 char ch;
 FILE *fp2,*fp3;
    
if((fp2=fopen("failedResult.txt","a+"))==NULL)
    {printf("���ļ�ʧ��\n");
   exit(0);}
    
if((fp3=fopen("rightResult.txt","a+"))==NULL)
    {printf("���ļ�ʧ��\n");
     exit(0);}
    printf("********************��������***************************************\n");
while(!feof(fp2))  
    {ch=fgetc(fp2);printf("%c",ch);   //��ȡfailedResult.txt�еĴ���
if(ch=='=')  
    scanf("%d",&a);}              //�����
    fp2=fopen("failedResult.txt","w");   //���֮ǰ����
    fclose(fp2);
    printf("========��鿴��ȷ��===========================================\n");
while(!feof(fp3))  
    { 
    ch=fgetc(fp3);printf("%c",ch);}   //��ȡrightResult.txt�еĴ���Ĵ�
    fclose(fp3);fp3=fopen("rightResult.txt","w");//���
    fclose(fp3);
    }


void sort()      //ʵ������
{FILE *fp5;
int i,j,m;
   s[0].avscore=A/nu;
   fp5=fopen("nrecord.txt","a+");
   fprintf(fp5,"%s        %s        %f\n",s[0].name,s[0].num,s[0].avscore);   //���ո������Ĳ��Լ�¼���ļ�nrecord.txt��
   fclose(fp5);
    fp5=fopen("nrecord.txt","rb");
for(i=0;!feof(fp5);i++)
   {
    fscanf(fp5,"%s        %s        %f\n",s[i].name,s[i].num,&s[i].avscore);}   //���ļ�nrecord.txt�ļ�¼�浽�ṹ��struct Student��
   fclose(fp5);
//ʵ������   
    m=i;
struct Student temp;
for(i=0;i<m;i++)
{  
for(j=0;j<m-1;j++)
    if(s[j].avscore<s[j+1].avscore)
    {
    strcpy(temp.name,s[j].name);      //������ʱ�ṹ����tempʵ������Ԫ�صĽ���
    strcpy(temp.num,s[j].num);
    temp.avscore=s[j].avscore;

    strcpy(s[j].name,s[j+1].name);
    strcpy(s[j].num,s[j+1].num);
    s[j].avscore=s[j+1].avscore;

    strcpy(s[j+1].name,temp.name);
    strcpy(s[j+1].num,temp.num);
    s[j+1].avscore=temp.avscore;
    }
          //��n=0����ζ��û�н����ˣ������Ѿ����
}
//����������
    printf(" ****************************************************************\n");
    printf("   ---------�鿴����������������ɸߵ���):--------------------\n");
    printf("   -------------����        ѧ��        ����------------\n");
for(i=0;i<m;i++)
    {printf("        %s        %s        %4.2f\n",s[i].name,s[i].num,s[i].avscore);}}





void TestOver()   //���������Ϻ���
{
printf("\n\n------���������Ĳ��Խ�������� %s ��------\n\n",s[0].num);    //������Խ����¼��ʾ
}


void ShowResult()   //��ʾ���Խ������
{
FILE *fp;
if((fp=fopen("TestResult.txt","r"))==NULL)
{   printf("���ļ�ʧ��\n");
    exit(0);}
char ch;
     ch=fgetc(fp);   //�ļ���ͷ�ַ�
while(ch!=EOF)   //���ļ�û�е�βʱ��һֱѭ��
{   putchar(ch);   //����ַ�
   ch=fgetc(fp);}
 fclose(fp);
}


void FileCopy()   //�ļ����ƺ���������������Խ������Ȼ�ļ��������ظ���
{
FILE *in,*out;
    strcat(s[0].num,".txt");   //���ַ���".txt"���ӵ��ַ���student[0].num�󣬼���ѧ��Ϊ�ļ�������׺Ϊ.txt���ļ��У������ڹ���Ŀ¼��
if((in=fopen("TestResult.txt","r"))==NULL)
    {   in=fopen("TestResult.txt","w+");
     printf("���ļ���¼�����½�.\n");
    }
if((out=fopen(s[0].num,"w"))==NULL)   //���ļ�ѧ��.txt �ļ�����03071361.txt����"w"��ʽΪֻд��ʽ
    {   printf("���ļ�ʧ��\n");
    exit(0);
    }
while(!feof(in))   //���ļ�TestResult.txtû�н���ʱѭ��
    fputc(fgetc(in),out);   //����ַ�д��
    fclose(in);
    fclose(out);}

void ChooseFunc();
void begain()
    {
    printf("\n\n\n");
    printf("         \n");
    printf("         *************************************************************\n");
    printf("         *--------------------------1.�ӷ�����-----------------------*\n");
    printf("         *--------------------------2.��������-----------------------*\n");
    printf("         *--------------------------3.�˷�����-----------------------*\n");
    printf("         *--------------------------4.��������-----------------------*\n");
    printf("         *--------------------------5.�������˵�----------------------*\n");
    printf("         *------------------------------------------------------------*\n\n\n");
int choose,thnum;   // bool judge=false;
    printf("         ѡ���ܣ�");
    scanf("%d",&choose);
while(choose<1||choose>5)   //�����������еĹ�������ʱѭ��
{
    printf("         �������ܷ�Χ��������ѡ��(1---5):");
   scanf("%d",&choose);
}
switch(choose)   //switch���ѡ��ִ�й���
{
case 1:   //ִ�й���1
     system("cls");   //����
     printf("\n\n\n");
     printf("         �ӷ����ԣ�����Ҫ���Ե���Ŀ��(5/10/20/50/100):��",&thnum);
     scanf("%d",&thnum);

while(thnum<5||thnum>5&&thnum<10||thnum>10&&thnum<20||thnum>20&&thnum<50||thnum>50&&thnum<100||thnum>100)   //�����������еĹ�������ʱѭ��
{    printf("�������ܷ�Χ��������ѡ��(5/10/20/50/100):");
     scanf("%d",&thnum);}

     system("cls");//����
     
     Addition(thnum);   //���üӷ����㺯��
     begain();

 break;
case 2:
     system("cls");   //����
     printf("\n\n\n");
     printf("         �������ԣ�����Ҫ���Ե���Ŀ��(5/10/20/50/100):",&thnum);
     scanf("%d",&thnum);

while(thnum<5||thnum>5&&thnum<10||thnum>10&&thnum<20||thnum>20&&thnum<50||thnum>50&&thnum<100||thnum>100)   //�����������еĹ�������ʱѭ��
{    printf("�������ܷ�Χ��������ѡ��(5/10/20/50/100):");
     scanf("%d",&thnum);}

     system("cls");   //����
     Subtracter(thnum);
     begain();
    break;
case 3:
     system("cls");   //����
     printf("\n\n\n");
     printf("         �˷����ԣ�����Ҫ���Ե���Ŀ��(5/10/20/50/100):",&thnum);
     scanf("%d",&thnum);
while(thnum<5||thnum>5&&thnum<10||thnum>10&&thnum<20||thnum>20&&thnum<50||thnum>50&&thnum<100||thnum>100)//�����������еĹ�������ʱѭ��
{    
       printf("�������ܷ�Χ��������ѡ��(5/10/20/50/100):");
    scanf("%d",&thnum);}
     
    system("cls");   //����
    printf("\n\n\n");
    Multiplication(thnum);
    begain();
   break;
case 4:
    system("cls");   //����
    printf("\n\n\n");
    printf("         �������ԣ�����Ҫ���Ե���Ŀ��(5/10/20/50/100):",&thnum);
    scanf("%d",&thnum);
while(thnum<5||thnum>5&&thnum<10||thnum>10&&thnum<20||thnum>20&&thnum<50||thnum>50&&thnum<100||thnum>100)//�����������еĹ�������ʱѭ��
{   printf("�������ܷ�Χ��������ѡ��(5/10/20/50/100):");
    scanf("%d",&thnum);}
    system("cls");   //����
    printf("\n\n\n");
    Division(thnum);begain();
   break;
case 5:
    system("cls");   //����

    ChooseFunc();
   break;}}


void ChooseFunc()   //����ѡ����
{
    printf("\n\n\n");
    printf("         *************************************************************\n");
    printf("         *--------------------------1.��ʼ����-----------------------*\n");
    printf("         *--------------------------2.�鿴���-----------------------*\n");
    printf("         *--------------------------3.�鿴����-----------------------*\n");
    printf("         *--------------------------4.��������-----------------------*\n");
    printf("         *--------------------------5.�������� ----------------------*\n");
    printf("         *-----------------------------------------------------------*\n\n\n");
int choose;


    printf("         ѡ���ܣ�");
scanf("%d",&choose);
while(choose<1||choose>5)   //�����������еĹ�������ʱѭ��
{
    printf("         �������ܷ�Χ��������ѡ��(1---5):");
    scanf("%d",&choose);
}
switch(choose)   //switch���ѡ��ִ�й���
{
case 1:    //����1
    system("cls");
    printf("  *************************************************************\n");
    {
    start =time(NULL);
    system("cls");  
    } 
//��ʾʱ��

     begain();
    
break;
case 2:   //����2
    system("cls");
    printf("\n\n");
    ShowResult();   //���ô˺�������������Խ��
    ChooseFunc();
break;
case 3:   //����2
    system("cls");
    printf("\n\n");
    sort();   //���ô˺�������������Խ��
    ChooseFunc();
    break;

case 4:   //����4
    system("cls");   //����
    printf("\n\n");
    rework();   //���ô˺�������������Խ��
    ChooseFunc();
    break;
case 5:   //����5
    system("cls");   //����
    printf("\n\n");
    
    { 
        end =time(NULL);
        printf("   *-----------------------------------------------------------------*\n");
        printf("   *------------------�������ʱΪ:%d��------------------------*\n",end-start);
    }
        FileCopy();   //���ô˺����������Ʋ��Խ��
        TestOver();
    break;
    }
}


int main(int argc, char *argv[])    
{
    system("color b0");        

    FILE *fp,*fp2,*fp3;
    fp=fopen("TestResult.txt","w");   //��ֻд��ʽ���ļ�������ļ����ڣ�����գ������Ϊʲô��������ʱҪ���Ʋ��Խ����
    fp2=fopen("failedResult.txt","w");   //���֮ǰ����
    fclose(fp2);
    fp3=fopen("rightResult.txt","w");   //���
    fclose(fp3);
    Judge();              //���ô˺���
    Savemessage();        //���ô˺���
    ChooseFunc();         //���ô˺���
    
}