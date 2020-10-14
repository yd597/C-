#include"address.h"

int main()
{
	count Con = { 0 };
	Con.size = 0;//size一定要初始化为 0；
	/*
	注意:要在函数内修改函数外的内容一定得注意传参；
	注意这里是传址，函数内部一定得用指针接收！
	*/

	while (1)
	{
		Check(&Con);
	}

	system("pause");
	return 0;
}