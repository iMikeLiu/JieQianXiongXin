const char* trans_Level(int level)
{
	static char* trans[]={"ERROR LEVEL",
	"D级乙等",
	"D级甲等",
	"C级乙等",
	"C级甲等", 
	"B级乙等",
	"B级甲等",
	"A级乙等",
	"A级甲等",
	"5等",
	"4等",
	"3等",
	"2等",
	"1等",
	"0等"};
	return trans[level];
}
const char* trans_variety(char name[])
{
	if(name=="yourhospital")return "医院";
	if(name=="yourpolicestation")return "警察局";
	if(name=="yourschool")return "学校";
	if(name=="business")return "商业区";
	if(name=="house")return "住宅区";
	if(name=="people")return "人口";
	if(name=="GDP")return "生产总值";
	if(name=="happiness")return "满意度";
}
