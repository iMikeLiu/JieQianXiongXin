void writeList(FILE* file)
{
	fprintf(file,"%d ",refer("year",int));
	fprintf(file,"%d ",refer("repeat",int));
	fprintf(file,"%lf ",refer("credit",double));
	fprintf(file,"%lf ",refer("save",double));
	fprintf(file,"%lf ",refer("money",double));
	fprintf(file,"%d ",refer("people",int));
	fprintf(file,"%lf ",refer("cover",double));
	fprintf(file,"%d ",refer("hospital",int));
	fprintf(file,"%d ",refer("school",int));
	fprintf(file,"%d ",refer("policestation",int));
	fprintf(file,"%lf ",refer("borrowinterest",double));
	fprintf(file,"%d ",refer("house",int));
	fprintf(file,"%d ",refer("business",int));
	fprintf(file,"%lf ",refer("saveinterest",double));
	fprintf(file,"%d ",refer("yourhospital",int));
	fprintf(file,"%d ",refer("yourschool",int));
	fprintf(file,"%d ",refer("yourpolicestation",int));
	fprintf(file,"%lf ",refer("GDP",double));
	fprintf(file,"%d ",refer("tax",int));
	fprintf(file,"%d\n",refer("happiness",int));
	pause();
}
void writeListStd()
{
	printf("%d ",refer("year",int));
	printf("%d ",refer("repeat",int));
	printf("%lf ",refer("credit",double));
	printf("%lf ",refer("save",double));
	printf("%lf ",refer("money",double));
	printf("%d ",refer("people",int));
	printf("%lf ",refer("cover",double));
	printf("%d ",refer("hospital",int));
	printf("%d ",refer("school",int));
	printf("%d ",refer("policestation",int));
	printf("%lf ",refer("borrowinterest",double));
	printf("%d ",refer("house",int));
	printf("%d ",refer("business",int));
	printf("%lf ",refer("saveinterest",double));
	printf("%d ",refer("yourhospital",int));
	printf("%d ",refer("yourschool",int));
	printf("%d ",refer("yourpolicestation",int));
	printf("%lf ",refer("GDP",double));
	printf("%d ",refer("tax",int));
	printf("%d\n",refer("happiness",int));
	pause();
}
void readList(FILE* file)
{
	create("year",int);
	refer("year",int)=1989;
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
	create("saveinterest",double);//存钱利息 
	refer("saveinterest",double)=rndbl(10);	
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
	refer("happiness",int)=0;

	fscanf(file,"%d",address("year",int));
//	printf("%d",refer("year",int));
	fscanf(file,"%d",address("repeat",int));
	fscanf(file,"%lf",address("credit",double));
	fscanf(file,"%lf",address("save",double));
	fscanf(file,"%lf",address("money",double));
	fscanf(file,"%d",address("people",int));
	fscanf(file,"%lf",address("cover",double));
	fscanf(file,"%d",address("hospital",int));
	fscanf(file,"%d",address("school",int));
	fscanf(file,"%d",address("policestation",int));
	fscanf(file,"%lf",address("borrowinterest",double));
	fscanf(file,"%d",address("house",int));
	fscanf(file,"%d",address("business",int));
	fscanf(file,"%lf",address("saveinterest",double));
	fscanf(file,"%d",address("yourhospital",int));
	fscanf(file,"%d",address("yourschool",int));
	fscanf(file,"%d",address("yourpolicestation",int));
	fscanf(file,"%lf",address("GDP",double));
	fscanf(file,"%d",address("tax",int));
	fscanf(file,"%d",address("happiness",int));
	refer("year",int)--;
	refer("repeat",int)=refer("repeat",int)-1;
	flag=1;
}
void readListStd()
{
	create("year",int);
	refer("year",int)=1989;
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
	create("saveinterest",double);//存钱利息 
	refer("saveinterest",double)=rndbl(10);	
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
	refer("happiness",int)=0;

	scanf("%d",address("year",int));
//	printf("%d",refer("year",int));
	scanf("%d",address("repeat",int));
	scanf("%lf",address("credit",double));
	scanf("%lf",address("save",double));
	scanf("%lf",address("money",double));
	scanf("%d",address("people",int));
	scanf("%lf",address("cover",double));
	scanf("%d",address("hospital",int));
	scanf("%d",address("school",int));
	scanf("%d",address("policestation",int));
	scanf("%lf",address("borrowinterest",double));
	scanf("%d",address("house",int));
	scanf("%d",address("business",int));
	scanf("%lf",address("saveinterest",double));
	scanf("%d",address("yourhospital",int));
	scanf("%d",address("yourschool",int));
	scanf("%d",address("yourpolicestation",int));
	scanf("%lf",address("GDP",double));
	scanf("%d",address("tax",int));
	scanf("%d",address("happiness",int));
	refer("year",int)--;
	refer("repeat",int)=refer("repeat",int)-1;
	flag=1;
}
