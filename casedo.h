#include "libio.h"
char* global_changeAbleList[]={"yourhospital","yourschool","yourpolicestation","house","business"};

void borrowMoney()
{
	double Money;
	printf("请输入您要借的钱数：");
	Money=getNum();
	if(Money>=0)
	{
			refer("credit",double)=refer("credit",double)+Money;
			refer("money",double)=refer("money",double)+Money;
	}
	else
	{
		printf("输入错误！请重新输入！\n");
		fflush(stdin);
		borrowMoney();
	}
//u19080501修复BUG 借钱子程序未做错误判断 
 } 

void retMoney()
{
	double Money;
	printf("请输入您要还的钱数：");
	Money=getNum();
	if(Money>=0&&(Money<=refer("money",double)))
	{
			refer("credit",double)=refer("credit",double)-Money;
			refer("money",double)=refer("money",double)-Money;
	}
	else
	{
		printf("输入错误！请重新输入！\n");
		fflush(stdin);
		retMoney();
	}

	
 } 

void saveMoney()
{
	double Money;
	printf("请输入您要存的钱数：");
	Money=getNum();
	if(Money>=0&&(Money<=refer("money",double)))
	{
			refer("save",double)=refer("save",double)+Money;
			refer("money",double)=refer("money",double)-Money;
	}
	else
	{
		printf("输入错误！请重新输入！\n");
		fflush(stdin);
		saveMoney();
	}

 } 
 
void pickMoney()
{
	double Money;
	printf("请输入您要取的钱数：");
	Money=getNum(); 
	if(Money>=0&&(Money<=refer("save",double)))
	{
			refer("save",double)=refer("save",double)-Money;
			refer("money",double)=refer("money",double)+Money;
	}
	else
	{
		printf("输入错误！请重新输入！\n");
		fflush(stdin);
		pickMoney();
	}

 } 
void war()
{
	double money;
	double random;
	printf("\n您的出资：");
	money=getNum();
	printf("对方正在出资...\n"); 
	random=(rand()*1.0/RAND_MAX)*rnd(1,10000);
	printf("对方出资%lf元！！！\n",random);
	getchar();
	if(random>money)
	{
		printf("您失败了！！！\n");
		int temp=rnd(0,4);
		if(refer(global_changeAbleList[temp],int)-temp<0)
		{
			printf("您要赔偿%d个%s，但由于你没有建那么多，所以你只能赔给对方一些钱。\n",temp,trans_variety(global_changeAbleList[temp])); 
			printf("将从您的现金中扣除%d元",temp*1500);
			calcDecMoney(temp*1500);
		}
		refer(global_changeAbleList[temp],int)=refer(global_changeAbleList[temp],int)-rnd(1,4);
		refer("GDP",double)=refer("GDP",double)-rnd(1,10);
		refer("people",int)=refer("people",int)-rnd(1,5);
	}
	else
	{
		printf("您成功了！！！\n");
		int temp=rnd(0,4);
		refer(global_changeAbleList[temp],int)=refer(global_changeAbleList[temp],int)+rnd(1,4);
		refer("GDP",double)=refer("GDP",double)+rnd(1,10)*0.01;
		refer("people",int)=refer("people",int)+rnd(1,5);
	}
	pause(); 
}
void build()
{
	int caseNum;
	double money;
	printMenu("兴建菜单",0,width,5,"学校","医院","警察局","商务区","住宅区");
	caseNum=getId();
	printf("请输入您的计划投入资金：");
	money=getNum();
	printf("这是一个%s级的建筑",trans_Level(calcLevel(money)));
	getchar();
	getchar();
	if(money<=refer("money",double)+refer("save",double))
	{ 
	if(caseNum>=0&&caseNum<=2)
	{
//	buildingInformation[refer("yourpolicestation",int)+refer("yourhospital",int)+refer("yourschool",int)+1].Type=caseNum;
//	buildingInformation[refer("yourpolicestation",int)+refer("yourhospital",int)+refer("yourschool",int)+1].Level=calcLevel(money);
	}
	switch (caseNum)
	{
		case 0:{refer("yourschool",int)=refer("yourschool",int)+1;break;}
		case 1:{refer("yourhospital",int)=refer("yourhospital",int)+1;break;}
		case 2:{refer("yourpolicestation",int)=refer("yourpolicestation",int)+1;break;}
		case 4:{refer("house",int)=refer("house",int)+1;refer("people",int)=refer("people",int)+calcLevel(money);break;}
		case 3:{refer("GDP",double)=refer("GDP",double)+calcLevel(money)*0.008;refer("business",int)=refer("business",int)+1;break;}
		default:{build();break;}
	}
	if(money>refer("money",double))
	{
		refer("save",double)=refer("save",double)-money+refer("money",double);
		refer("money",double)=0;
	}
	else
	{
		refer("money",double)=refer("money",double)-money;
	}
	}
}
void tax()
{
	printf("\n请输入税率，为整数，介于1-100之间，不得带有小数点："); 
	refer("tax",int)=getId();
	if(refer("tax",int)>100||refer("tax",int)<=0)tax();
	
	
}
void caseDo_main(int caseNum)
{
	switch (caseNum)
	{
		case 0:
			{
				exit(0);
				break;
			}
		case 1:
			{
				borrowMoney();
				break;
			}
		case 2:
			{
				retMoney();	
				break;
			} 
		case 3:
			{
				build();
				break;
			}
		case 8:
			{
				war();	
			} 
		case 9:
			{
				printf("请输入流逝的时间（月）：");
				int passedMonth;
				passedMonth=getId();
				while(passedMonth<1||passedMonth>20)
				{
					printf("一次只能快进1~20个月\n");
					printf("请输入流逝的时间（月）：");
					passedMonth=getId();
				}
				refer("passesTime",int)=passedMonth;
				printf("请稍等，即将为您快进...\n");
				pause();
				return; 
				break; 
			}
		case 10:
			{
				refer("passesTime",int)=1;
				return; 
				break; 
			}
		case 6:
			{
				saveMoney();	
				break;
			} 
		case 7:
			{
				pickMoney();
				break;	
			}
		case 11:
			{
				int t;
				#ifdef __ANDROID__
				printf("输入1原样输出，否则输入2，自动保存：");
				t=getId();
				if(t==1)
					writeListStd();
				else
					writeList(fopen("./save.jqx","w"));
				#else
				printMenu("保存菜单",1,width,2,"原样输出","保存文件");
				t=getId();
				if(t==1)
					writeListStd();
				else
				{
					char File[65535];
					
					getchar();
					printf("请输入保存文件路径：");
					gets(File);
					writeList(fopen(File,"w"));
				}
				#endif
				break;
			}
		case 4:
			{
				tax();
				break;
			}
		default:
			{
				printf("\n错误输入！请重新输入！\n");
				caseDo_main(getId());
				break;
			}
	}
}
void caseDo_start(int caseNum)
{
	switch (caseNum)
	{
		case 1:
			{
				readListStd();
				break;
			}
		case 2:
			{
				return;
				break;
			}
		#ifdef __ANDROID__
		case 3:
			{
				readList(fopen("./save.jqx","r"));	
				break;
			}
		#else
		case 3:
			{
				char t[65535];
				printf("请输入合法路径，最大长度65535："); 
				scanf("%s",t);
//				printf("%s",t);
				readList(fopen(t,"r"));	
				break;
			}
		#endif
		default:
			{
				printf("输入错误！请重新输入！\n");
				caseDo_start(getId());
			}
	}
}
