/*
Copyright (c) 2019 Mikeliu

"Anti 996" License Version 1.0 (Draft)

Permission is hereby granted to any individual or legal entity
obtaining a copy of this licensed work (including the source code,
documentation and/or related items, hereinafter collectively referred
to as the "licensed work"), free of charge, to deal with the licensed
work for any purpose, including without limitation, the rights to use,
reproduce, modify, prepare derivative works of, distribute, publish
and sublicense the licensed work, subject to the following conditions:

1. The individual or the legal entity must conspicuously display,
without modification, this License and the notice on each redistributed
or derivative copy of the Licensed Work.

2. The individual or the legal entity must strictly comply with all
applicable laws, regulations, rules and standards of the jurisdiction
relating to labor and employment where the individual is physically
located or where the individual was born or naturalized; or where the
legal entity is registered or is operating (whichever is stricter). In
case that the jurisdiction has no such laws, regulations, rules and
standards or its laws, regulations, rules and standards are
unenforceable, the individual or the legal entity are required to
comply with Core International Labor Standards.

3. The individual or the legal entity shall not induce, suggest or force
its employee(s), whether full-time or part-time, or its independent
contractor(s), in any methods, to agree in oral or written form, to
directly or indirectly restrict, weaken or relinquish his or her
rights or remedies under such laws, regulations, rules and standards
relating to labor and employment as mentioned above, no matter whether
such written or oral agreements are enforceable under the laws of the
said jurisdiction, nor shall such individual or the legal entity
limit, in any methods, the rights of its employee(s) or independent
contractor(s) from reporting or complaining to the copyright holder or
relevant authorities monitoring the compliance of the license about
its violation(s) of the said license.

THE LICENSED WORK IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,
EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF
MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.
IN NO EVENT SHALL THE COPYRIGHT HOLDER BE LIABLE FOR ANY CLAIM,
DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR
OTHERWISE, ARISING FROM, OUT OF OR IN ANY WAY CONNECTION WITH THE
LICENSED WORK OR THE USE OR OTHER DEALINGS IN THE LICENSED WORK.
*/


#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
#include<string.h>
#include<time.h>
#include<stdarg.h>
#include<math.h>


//#include "sl3.c" //lisp�籾������ 

#include "translator.h"

#define tint *(int *) 
#define tdouble *(double *)
#define create(x,type) globalVarietyFactory(x,sizeof(type))
#define refer(x,type) (*(type *)globalVariety(x))
#define address(x,type) ((type *)globalVariety(x))

#define dec(x,type,num,unit) (*(type *)globalVariety(x))-=num;printf("%s����%lf%s\n",trans_variety(x),(double)num,unit)
#define inc(x,type,num,unit) (*(type *)globalVariety(x))+=num;printf("%s����%lf%s\n",trans_variety(x),(double)num,unit)

#define createlist(x,type,size) globalVarietyFactory(x,sizeof(type)*size)

#define rnd(a,b) (((double)rand()/RAND_MAX)*(b-a)+a)
#define rndbl(n) (((double)rand()/RAND_MAX)*n)

#define __VER__ "1.0 beta1"
#define MAXLEN 19260817
#define width 45
#define tabs 2

#define bool char
#define true 1
#define false 0
#define exist(variety) __globalExist(variety)

int flag=0;
void startGame();
void caseDo_main(int caseNum);

//int __globalRefer(char* variety)
//{
//	static 
//	switch (variety)
//	{
//		case ""
//	}
// } 

int __globalHash(char* variety) //��ϣ���� ָ���ϣ�����洢���� ����֧�ֽű������ı��� 
{
	int value=0;
	int i=0;
	for(i=0;i<strlen(variety);i++)
	{
		
		value+=(variety[i])*(pow(2,i));
	}
	return value;	
} 

void *__globalHashMap[MAXLEN];//��ϣ�� 
char __globalHashCreated[MAXLEN];//��������ָʾ 
bool __globalExist(char* variety)
{
	return __globalHashCreated[__globalHash(variety)];
}
void *globalVariety(char* variety)//ȡ����ָ�� 
{
	return __globalHashMap[__globalHash(variety)]; 
}
int globalVarietyFactory(char* variety,size_t typesize) //�������� 
{
	int hashKey=__globalHash(variety);
	__globalHashCreated[hashKey]=1; 
	__globalHashMap[hashKey]=malloc(typesize);
	return hashKey;
}
void printTabs()
{
	int i=0;
	for(i=0;i<tabs;i++)printf("\t");
}
int getId()
{
	int num=0;
	int ret=scanf("%d",&num);
	//printf("%d",ret);
	if(ret==0)
	{
		
		fflush(stdin);
		printf("����������������룡\n");
		return getId();
		}	
	else
	return num;
}
double getNum()
{
	double num=0;
	int ret=scanf("%lf",&num);
	//printf("%d",ret);
	if(ret==0)
	{
		
		fflush(stdin);
		printf("����������������룡\n");
		return getNum();
		}	
	else
	return num;
}
void printMenu_fun(char* title,int firstNumber,int head,int length,char** menu)
{	
	int i=0;
	printf("\n");
	printf("\t%s\n",title);
	for(i=0;i<head;i++)printf("=");
	printf("\n");
	for(i=firstNumber;i<length+firstNumber;i++)
		{
			printf("\t%d. %s\n",i,menu[i-firstNumber]);
		}
	
	for(i=0;i<head;i++)printf("=");
	printf("\n");
}
void printMenu(char* title,int firstNumber,int head,int length,...)
{
	va_list ap;
	va_start(ap,length);
	printf("\n");
	printTabs();
	printf("%s",title);
	int i=0;
	printf("\n");
	for(i=0;i<head;i++)printf("=");
	printf("\n");
	for(i=firstNumber;i<length+firstNumber;i++)
		{
			printTabs();
			printf("%d. %s\n",i,va_arg(ap,char*));
		}
	
	for(i=0;i<head;i++)printf("=");
	printf("\n");
	va_end(ap);
}
#include "calc.h"
void infomation(int length)
{
	int i=0;
	printTabs();
	printf("�����ֽ�%lf\n",refer("money",double));
	printTabs();
	printf("�����ڵĳ���������ֵΪ%lf��Ԫ\n",refer("GDP",double));
	printTabs();
	printf("�����ڵĳ��������%lf�N2\n",refer("cover",double));
	printTabs();
	printf("�����ڵĳ������˿�%d����\n",refer("people",int));
	printTabs();
	printf("�����ڵĳ�����%d��ҽԺ\n",refer("hospital",int));
	printTabs();
	printf("�����ڵĳ�����%d��ѧУ\n",refer("school",int));
	printTabs();
	printf("�����ڵĳ�����%d�������\n",refer("policestation",int));
	printTabs();
	printf("���˽���%d��ҽԺ\n",refer("yourhospital",int));
	printTabs();
	printf("���˽���%d��ѧУ\n",refer("yourschool",int));
	printTabs();
	printf("���˽���%d�������\n",refer("yourpolicestation",int));
	printTabs();
	printf("���˽���%d��סլ¥\n",refer("house",int));
	printTabs();
	printf("���˽���%d������¥\n",refer("business",int));
	printTabs();
	printf("�������д����У�%lfԪ\n",refer("credit",double));
	printTabs();
	printf("�������д���У�%lfԪ\n",refer("save",double));
	printTabs();	
	printf("���ľ��ʱ��У�%lfԪ\n",refer("money",double)+refer("save",double)-refer("credit",double));
	printTabs();
	printf("��ǰ���н����ϢΪ��%lf%%\n",refer("borrowinterest",double));
	printTabs();
	printf("���������Ϊ��%lf%%\n",refer("saveinterest",double));
	printTabs();
	printf("����������Ϊ��%d\n",refer("happiness",int));
	printTabs();
	printf("��ǰ˰��Ϊ��%d%%\n",refer("tax",int));
	for(i=0;i<length;i++)printf("=");
	printf("\n");
}
void printTime()
{
	printTabs();
	printf("\n������%d��%d��\n",refer("year",int),refer("repeat",int)%12+1);
}
void pause()
{
	printf("�밴�س�������...");
	getchar();
	getchar();
}
#include "randEvent.h" 
int count=0;
void initGame(FILE* document)
{

	srand(time(NULL));
	if(flag==0)
	{
	printMenu("��ѡ����ʼ���",1989,width,12,"1989","1990","1991","1992","1993","1994","1995","1996","1997","1998","1999","2000");
	int temp;

	temp=getId();
	while(temp<1989||temp>2000)
	{
		temp=getId();
	}
	create("year",int);
	refer("year",int)=temp;
	refer("year",int)--;
	
	count++;
	create("repeat",int);
	refer("repeat",int)=-1;
	count++;
	create("credit",double);//��Ǯ Ԫ 
	refer("credit",double)=0;
	count++;
	create("save",double);//��� Ԫ
	refer("save",double)=0;
	count++; 
	create("money",double);//��Ǯ Ԫ 
	refer("money",double)=0;
	count++;
	create("people",int);//�˿� ���� 
	refer("people",int)=rnd(50,500);
	count++;
	create("cover",double);//��� ƽ��ǧ�� 
	refer("cover",double)=rndbl(1e3);
	count++;
	create("hospital",int);//ҽԺ
	refer("hospital",int)=rnd(1,10);
	count++;
	create("school",int);//ѧУ 
	refer("school",int)=rnd(1,3); 
	count++;
	create("policestation",int);//����� 
	refer("policestation",int)=rnd(1,3);
	count++;
	create("borrowinterest",double);//��Ǯ��Ϣ 
	refer("borrowinterest",double)=rndbl(10);
	count++;
	create("house",int);//סլ¥����
	refer("house",int)=0;
	count++; 
	create("business",int);//סլ¥����
	refer("business",int)=0;
	count++; 
	do
	{
		create("saveinterest",double);//��Ǯ��Ϣ 
		refer("saveinterest",double)=rndbl(10);	
	}
	while((refer("saveinterest",double)>refer("borrowinterest",double)));

	count++;
	create("yourhospital",int);//ҽԺ
	refer("yourhospital",int)=0;
	count++;
	create("yourschool",int);//ѧУ 
	refer("yourschool",int)=0; 
	count++;
	create("yourpolicestation",int);//����� 
	refer("yourpolicestation",int)=0;
	count++;
	create("GDP",double);
	refer("GDP",double)=calcGDP();
	count++;
	create("tax",int);
	refer("tax",int)=0;
	count++;
	create("happiness",int);
	refer("happiness",int)=calcHappiness();
	}
		create("passesTime",int);
	refer("passesTime",int)=1;
}

#include "casedo.h"

/*void evalEvent(char* eventNumber)
{
	create("script",FILE *);
	refer("script",FILE *)=fopen(eventNumber,"r");
	printf("���ڽ��;籾����\n");
	init_sl3();
	setinput(refer("script",FILE *));
  eval(readobj(), top_env);
 }*/ 
void startGame()
{
	while(1)
	{
//		if(refer("passesTime",int)==0)refer("passesTime",int)=1;
		while(refer("passesTime",int)>=1)
		{
			if(refer("passesTime",int)!=1)printf("���ʣ��%d����...",refer("passesTime",int));
			calc();
			printTime();
			randomEvent(); 
			if(refer("passesTime",int)==1)
			{
				printMenu("��Ǯ�������˵�",0,width,12,"�˳�","��Ǯ","��Ǯ","����","��˰","ο��","��Ǯ","ȡǮ","��ս","ʱ�����","ʱ������","����");
				infomation(width);
				
			} 
			refer("passesTime",int)--;
			yearMonthSmart();
		}
		if(refer("passesTime",int)==0)
		{
			refer("passesTime",int)=1;
			caseDo_main(getId());
			
		}
	}
}
void main()
{
//	fprintf(fopen)
	create("year",int);
//event1();
//	evalEvent("script.lsp"); 
	printf("��ӭ������Ǯ���ģ�\n");
	printf("������Ϣ��%s %s ����\n���ڵ�%d��\nC���Ա�׼֧�������%s\n",__DATE__,__TIME__,__LINE__,(__STDC__?"��":"��"));
	printf("��Ǯ���� Version %s ʹ��ANSI C��д ������ƽ̨ �����ϵͳ ��CPU�ܹ�֧�� �����ײ�\n",__VER__);
//	rndEvent1();
	#ifdef __ANDROID__ 
		printMenu("��ʼ��Ϸ",1,width,3,"���뱣�������","��ʼ����Ϸ","��ȡ���������(Android)");
		caseDo_start(getId());
	#else
		printMenu("��ʼ��Ϸ",1,width,3,"���뱣�������","��ʼ����Ϸ","��ȡ���������(Other Platform)");
		caseDo_start(getId());
	#endif 
	initGame(NULL);

	
	startGame(); 
	
	system("pause");
//	fclose(refer("script",FILE*));
}
