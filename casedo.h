#include "libio.h"
char* global_changeAbleList[]={"yourhospital","yourschool","yourpolicestation","house","business"};

void borrowMoney()
{
	double Money;
	printf("��������Ҫ���Ǯ����");
	Money=getNum();
	if(Money>=0)
	{
			refer("credit",double)=refer("credit",double)+Money;
			refer("money",double)=refer("money",double)+Money;
	}
	else
	{
		printf("����������������룡\n");
		fflush(stdin);
		borrowMoney();
	}
//u19080501�޸�BUG ��Ǯ�ӳ���δ�������ж� 
 } 

void retMoney()
{
	double Money;
	printf("��������Ҫ����Ǯ����");
	Money=getNum();
	if(Money>=0&&(Money<=refer("money",double)))
	{
			refer("credit",double)=refer("credit",double)-Money;
			refer("money",double)=refer("money",double)-Money;
	}
	else
	{
		printf("����������������룡\n");
		fflush(stdin);
		retMoney();
	}

	
 } 

void saveMoney()
{
	double Money;
	printf("��������Ҫ���Ǯ����");
	Money=getNum();
	if(Money>=0&&(Money<=refer("money",double)))
	{
			refer("save",double)=refer("save",double)+Money;
			refer("money",double)=refer("money",double)-Money;
	}
	else
	{
		printf("����������������룡\n");
		fflush(stdin);
		saveMoney();
	}

 } 
 
void pickMoney()
{
	double Money;
	printf("��������Ҫȡ��Ǯ����");
	Money=getNum(); 
	if(Money>=0&&(Money<=refer("save",double)))
	{
			refer("save",double)=refer("save",double)-Money;
			refer("money",double)=refer("money",double)+Money;
	}
	else
	{
		printf("����������������룡\n");
		fflush(stdin);
		pickMoney();
	}

 } 
void war()
{
	double money;
	double random;
	printf("\n���ĳ��ʣ�");
	money=getNum();
	printf("�Է����ڳ���...\n"); 
	random=(rand()*1.0/RAND_MAX)*rnd(1,10000);
	printf("�Է�����%lfԪ������\n",random);
	getchar();
	if(random>money)
	{
		printf("��ʧ���ˣ�����\n");
		int temp=rnd(0,4);
		if(refer(global_changeAbleList[temp],int)-temp<0)
		{
			printf("��Ҫ�⳥%d��%s����������û�н���ô�࣬������ֻ������Է�һЩǮ��\n",temp,trans_variety(global_changeAbleList[temp])); 
			printf("���������ֽ��п۳�%dԪ",temp*1500);
			calcDecMoney(temp*1500);
		}
		refer(global_changeAbleList[temp],int)=refer(global_changeAbleList[temp],int)-rnd(1,4);
		refer("GDP",double)=refer("GDP",double)-rnd(1,10);
		refer("people",int)=refer("people",int)-rnd(1,5);
	}
	else
	{
		printf("���ɹ��ˣ�����\n");
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
	printMenu("�˽��˵�",0,width,5,"ѧУ","ҽԺ","�����","������","סլ��");
	caseNum=getId();
	printf("���������ļƻ�Ͷ���ʽ�");
	money=getNum();
	printf("����һ��%s���Ľ���",trans_Level(calcLevel(money)));
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
	printf("\n������˰�ʣ�Ϊ����������1-100֮�䣬���ô���С���㣺"); 
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
				printf("���������ŵ�ʱ�䣨�£���");
				int passedMonth;
				passedMonth=getId();
				while(passedMonth<1||passedMonth>20)
				{
					printf("һ��ֻ�ܿ��1~20����\n");
					printf("���������ŵ�ʱ�䣨�£���");
					passedMonth=getId();
				}
				refer("passesTime",int)=passedMonth;
				printf("���Եȣ�����Ϊ�����...\n");
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
				printf("����1ԭ���������������2���Զ����棺");
				t=getId();
				if(t==1)
					writeListStd();
				else
					writeList(fopen("./save.jqx","w"));
				#else
				printMenu("����˵�",1,width,2,"ԭ�����","�����ļ�");
				t=getId();
				if(t==1)
					writeListStd();
				else
				{
					char File[65535];
					
					getchar();
					printf("�����뱣���ļ�·����");
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
				printf("\n�������룡���������룡\n");
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
				printf("������Ϸ�·������󳤶�65535��"); 
				scanf("%s",t);
//				printf("%s",t);
				readList(fopen(t,"r"));	
				break;
			}
		#endif
		default:
			{
				printf("����������������룡\n");
				caseDo_start(getId());
			}
	}
}
