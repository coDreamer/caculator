#include "windows.h"
#include"Judge.h"
using namespace std;

void meun()
{
	system("color 0a");
	cout << "\t\t **************************************" << endl;
	cout << "\t\t            2018安徽工程大学计算机与信息学院软件工程专业课设" << endl;
	cout << "\t\t            算术表达式求值系统" << endl;
	cout << "\t\t            课题完成人：葛琦" << endl;
	cout << "\t\t            请输入表达式(支持四则及求余混合运算，括号不支持中文!!!)" << endl;
	cout << "\t\t **************************************" << endl;
	cout << endl;
	cout << "\t\t 输入end可结束本程序" << endl;
}

int main()
{
	char p[400], q[400];
	double k;
	void meun(); //声明菜单函数 
	int change(char *p, char q[]); //声明转换函数 
	double calculator(char *q); //声明计算函数 
	meun();
	for (;;) //循环执行 
	{
		cout << "\t\t 请输入:";
		cin >> p;
		if (strcmp(p, "end") == 0)
			return 0;
		int a = Analysis(p);
		//cout << a;
		if (a == 1){
			if (change(p, q) == 1)
			{
				k = calculator(q);
				cout << "\t\t 计算结果为:" << k << endl;
			}
		}
		else{
			continue;
		}
		system("pause"); //控制输出格式 
		system("cls");//清屏
		meun();
	}
	return 0;
}