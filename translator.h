const char* trans_Level(int level)
{
	static char* trans[]={"ERROR LEVEL",
	"D���ҵ�",
	"D���׵�",
	"C���ҵ�",
	"C���׵�", 
	"B���ҵ�",
	"B���׵�",
	"A���ҵ�",
	"A���׵�",
	"5��",
	"4��",
	"3��",
	"2��",
	"1��",
	"0��"};
	return trans[level];
}
const char* trans_variety(char name[])
{
	if(name=="yourhospital")return "ҽԺ";
	if(name=="yourpolicestation")return "�����";
	if(name=="yourschool")return "ѧУ";
	if(name=="business")return "��ҵ��";
	if(name=="house")return "סլ��";
	if(name=="people")return "�˿�";
	if(name=="GDP")return "������ֵ";
	if(name=="happiness")return "�����";
}
