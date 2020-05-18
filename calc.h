
void died() 
{
	printf("哎~\n你破产了！\n再见了！\n");
	exit(0);
}
double calcDecMoney(double decMoney)
{
	if(refer("money",double)<decMoney)
	{
		if(refer("money",double)+refer("save",double)<decMoney)
		{
			died();
		}
		else
		{
			refer("save",double)=refer("save",double)-(decMoney-refer("money",double));
			refer("money",double)=0;
		}
	}
	else
	{
		refer("moeny",double)=refer("money",double)-decMoney;
	 } 
}
double calcGDP()
{
	 //GDP=0.0118people???? + 134.1127627cover????????? 
 
	return refer("people",int)*0.0118+(refer("cover",double)*134.1127627/10000.00);
}
double calcBorrowInterest()
{
	 //??????=0.0098people???? + 0.226GDP
 
	return refer("people",int)*0.0118+(refer("GDP",double)*0.226);
}
double calcSaveInterest()
{
	 //??????=0.0118people???? + 0.112GDP
 
	return refer("people",int)*0.0118+(refer("GDP",double)*0.112);
}
int calcLevel(int money)
/*
	????????? 
	1 D?????
	2 D?????
	3 C?????
	4 C?????
	5 B?????
	6 B?????
	7 A?????
	8 A?????
	9 5??
	10 4??
	11 3??
	12 2??
	13 1??
	14 0?? 
*/ 
{
	return (money/100) ;
}
void calc()
{
			
		//信息更新 
		
		refer("repeat",int)+=1;
		refer("borrowinterest",double)=calcBorrowInterest();//存款利息更新
		refer("saveinterest",double)=calcSaveInterest();//取款利息更新 
		refer("happiness",int)=calcHappiness();//幸福指数更新 
		refer("credit",double)=refer("credit",double)*(1+refer("borrowinterest",double)/1200.00);//存款利息计算 
		refer("save",double)=refer("save",double)*(1+refer("saveinterest",double)/1200.00);//存款利息计算 
		
		//利益生成
		
		refer("GDP",double)+=refer("yourschool",int)*0.0015;
		refer("people",int)+=refer("yourhospital",int)*1.5;
		refer("GDP",double)+=refer("yourpolicestation",int)*0.003;
		
		refer("money",double)+=refer("yourschool",int)*150;
		refer("money",double)+=refer("yourhospital",int)*150;
		refer("money",double)+=refer("yourpolicestation",int)*150;
		refer("money",double)+=refer("business",int)*refer("tax",int)/100.00+refer("house",int)*refer("tax",int)/100.00;
		
		//年份 
		
		if(refer("repeat",int)%12==0)
		{
			refer("year",int)+=1;
		}
		
}
int calcHappiness()
{
	return 	-refer("people",int)+(refer("GDP",double)*100)-refer("tax",int);
}
