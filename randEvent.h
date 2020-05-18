#define MAX_EVENT 3
#define IF if
#define IFE(a,b) if(a==b){
#define VAR(x) refer(x,int)
#define BEGIN {
#define END }
#define THEN  {
#define ELSE }else{
#define FUN void
#define FOR for(
#define DIM(type) type
#define get(variety) refer("variety",int)
void __log(char* str)
{
	printf("%s",str);
}
void __write(char* str)
{
	if(!exist(str))create(str,int);
	printf("%d",refer(str,int));
}
void __read(char* str)
{
	if(!exist(str))create(str,int);
	scanf("%d",address(str,int));
}
#define LOG(str) __log(str)
void MENU(char* title,int length,...)
{
	va_list ap;
	va_start(ap,length);
	printf("\n");
	printTabs();
	printf("%s",title);
	int i=0;
	printf("\n");
	for(i=0;i<width;i++)printf("=");
	printf("\n");
	for(i=1;i<=length;i++)
		{
			printTabs();
			printf("%d. %s\n",i,va_arg(ap,char*));
		}
	
	for(i=0;i<width;i++)printf("=");
	printf("\n");
	va_end(ap);
}
#define WRITE(str) __write(str)
#define PRINT(str) printf(str)
#define ASK(qest,var) __tip(qest,var)
#define INPUT(var) __read(var)
#define REFER(var) refer(var,int)
void __tip(char* question,char* variety)
{
	create(variety,int);
	printf("%s",question);
//	if(exist(variety)==0)create(variety,int);
	scanf("%d",address(variety,int));	
}
//insert your function here!!!

FUN event1()
BEGIN
	LOG("您好，请选择：");
	MENU("选择菜单",2,"选择1","选择2");
	INPUT("test"); 
	IF(REFER("test")==1)
	BEGIN
		WRITE("test");
	ELSE
	IF(REFER("test")==2)
		BEGIN
			PRINT("test2");
		END
	END
END
