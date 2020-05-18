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


//#include "sl3.c" //lisp剧本解释器 

#include "translator.h"

#define tint *(int *) 
#define tdouble *(double *)
#define create(x,type) globalVarietyFactory(x,sizeof(type))
#define refer(x,type) (*(type *)globalVariety(x))
#define address(x,type) ((type *)globalVariety(x))

#define dec(x,type,num,unit) (*(type *)globalVariety(x))-=num;printf("%s减少%lf%s\n",trans_variety(x),(double)num,unit)
#define inc(x,type,num,unit) (*(type *)globalVariety(x))+=num;printf("%s增加%lf%s\n",trans_variety(x),(double)num,unit)

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

int __globalHash(char* variety) //哈希函数 指针哈希表来存储变量 后期支持脚本和中文变量 
{
	int value=0;
	int i=0;
	for(i=0;i<strlen(variety);i++)
	{
		
		value+=(variety[i])*(pow(2,i));
	}
	return value;	
} 

void *__globalHashMap[MAXLEN];//哈希表 
char __globalHashCreated[MAXLEN];//变量创建指示 
bool __globalExist(char* variety)
{
	return __globalHashCreated[__globalHash(variety)];
}
void *globalVariety(char* variety)//取变量指针 
{
	return __globalHashMap[__globalHash(variety)]; 
}
int globalVarietyFactory(char* variety,size_t typesize) //变量工厂 
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
		printf("输入错误！请重新输入！\n");
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
		printf("输入错误！请重新输入！\n");
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
	printf("您的现金：%lf\n",refer("money",double));
	printTabs();
	printf("您所在的城市生产总值为%lf亿元\n",refer("GDP",double));
	printTabs();
	printf("您所在的城市面积是%lf㎞2\n",refer("cover",double));
	printTabs();
	printf("您所在的城市有人口%d万人\n",refer("people",int));
	printTabs();
	printf("您所在的城市有%d所医院\n",refer("hospital",int));
	printTabs();
	printf("您所在的城市有%d所学校\n",refer("school",int));
	printTabs();
	printf("您所在的城市有%d所警察局\n",refer("policestation",int));
	printTabs();
	printf("您兴建了%d所医院\n",refer("yourhospital",int));
	printTabs();
	printf("您兴建了%d所学校\n",refer("yourschool",int));
	printTabs();
	printf("您兴建了%d所警察局\n",refer("yourpolicestation",int));
	printTabs();
	printf("您兴建了%d栋住宅楼\n",refer("house",int));
	printTabs();
	printf("您兴建了%d栋商务楼\n",refer("business",int));
	printTabs();
	printf("您的银行贷款有：%lf元\n",refer("credit",double));
	printTabs();
	printf("您的银行存款有：%lf元\n",refer("save",double));
	printTabs();	
	printf("您的净资本有：%lf元\n",refer("money",double)+refer("save",double)-refer("credit",double));
	printTabs();
	printf("当前央行借款利息为：%lf%%\n",refer("borrowinterest",double));
	printTabs();
	printf("存款年利率为：%lf%%\n",refer("saveinterest",double));
	printTabs();
	printf("人民的满意度为：%d\n",refer("happiness",int));
	printTabs();
	printf("当前税率为：%d%%\n",refer("tax",int));
	for(i=0;i<length;i++)printf("=");
	printf("\n");
}
void printTime()
{
	printTabs();
	printf("\n现在是%d年%d月\n",refer("year",int),refer("repeat",int)%12+1);
}
void pause()
{
	printf("请按回车键继续...");
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
	printMenu("请选择起始年份",1989,width,12,"1989","1990","1991","1992","1993","1994","1995","1996","1997","1998","1999","2000");
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
	create("credit",double);//借钱 元 
	refer("credit",double)=0;
	count++;
	create("save",double);//存款 元
	refer("save",double)=0;
	count++; 
	create("money",double);//金钱 元 
	refer("money",double)=0;
	count++;
	create("people",int);//人口 万人 
	refer("people",int)=rnd(50,500);
	count++;
	create("cover",double);//面积 平方千米 
	refer("cover",double)=rndbl(1e3);
	count++;
	create("hospital",int);//医院
	refer("hospital",int)=rnd(1,10);
	count++;
	create("school",int);//学校 
	refer("school",int)=rnd(1,3); 
	count++;
	create("policestation",int);//警察局 
	refer("policestation",int)=rnd(1,3);
	count++;
	create("borrowinterest",double);//借钱利息 
	refer("borrowinterest",double)=rndbl(10);
	count++;
	create("house",int);//住宅楼个数
	refer("house",int)=0;
	count++; 
	create("business",int);//住宅楼个数
	refer("business",int)=0;
	count++; 
	do
	{
		create("saveinterest",double);//存钱利息 
		refer("saveinterest",double)=rndbl(10);	
	}
	while((refer("saveinterest",double)>refer("borrowinterest",double)));

	count++;
	create("yourhospital",int);//医院
	refer("yourhospital",int)=0;
	count++;
	create("yourschool",int);//学校 
	refer("yourschool",int)=0; 
	count++;
	create("yourpolicestation",int);//警察局 
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
	printf("正在解释剧本……\n");
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
			if(refer("passesTime",int)!=1)printf("快进剩余%d个月...",refer("passesTime",int));
			calc();
			printTime();
			randomEvent(); 
			if(refer("passesTime",int)==1)
			{
				printMenu("借钱雄心主菜单",0,width,12,"退出","借钱","还钱","建设","征税","慰问","存钱","取钱","商战","时间加速","时间流逝","保存");
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
	printf("欢迎来到借钱雄心！\n");
	printf("编译信息：%s %s 编译\n处于第%d行\nC语言标准支持情况：%s\n",__DATE__,__TIME__,__LINE__,(__STDC__?"是":"否"));
	printf("借钱雄心 Version %s 使用ANSI C编写 真正跨平台 多操作系统 多CPU架构支持 贴近底层\n",__VER__);
//	rndEvent1();
	#ifdef __ANDROID__ 
		printMenu("开始游戏",1,width,3,"输入保存的数据","开始新游戏","读取保存的数据(Android)");
		caseDo_start(getId());
	#else
		printMenu("开始游戏",1,width,3,"输入保存的数据","开始新游戏","读取保存的数据(Other Platform)");
		caseDo_start(getId());
	#endif 
	initGame(NULL);

	
	startGame(); 
	
	system("pause");
//	fclose(refer("script",FILE*));
}
