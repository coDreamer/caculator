#include "iostream" 
#include "math.h" 
#include "string" 
#include "stdlib.h"  
#define Maxlen 400
using namespace std;

struct operater
{
	char data[Maxlen];
	int top;
}operater; //定义运算符栈，并定义全局变量 

struct record
{
	double data[Maxlen];
	int top;
}record; //定义操作数栈，并定义全局变量 

int change(char *p, char q[]) //将算术表达式p转换成表达式后缀表达式q
{
	int i = 0; //i作为q的下标 
	int dh = 1; //dh=1表示是负号 
	operater.top = -1; //初始化运算符栈 
	while (*p != '\0') //p表达式未扫描完时循环 
	{
		switch (*p) //判断各种情况,并做相应的处理 
		{
		case '(':{
			operater.top++;
			operater.data[operater.top] = *p; dh = 1;
			p++;
			break;
		}
		case ')':{
			while (operater.data[operater.top] != '(')
			{
				q[i] = operater.data[operater.top];
				operater.top--;
				i++;
			}
			operater.top--;
			p++;
			dh = 0;
			break;
		}
		case '+':
		case '-': if (dh == 1) // +,-是正负号 
		{
			if (*p == '-')
				operater.top++;
			operater.data[operater.top] = '@'; 
			p++;
			break;
		}
			while (operater.top != -1 && operater.data[operater.top] != '(')
			{
				q[i] = operater.data[operater.top];
				operater.top--; i++;
			}
			operater.top++;
			operater.data[operater.top] = *p;
			p++; dh = 0;
			break;
		case '*':
		case '/': 
			while (operater.data[operater.top] == '*' || operater.data[operater.top] == '/')
		{
			q[i] = operater.data[operater.top];
			operater.top--;
			i++;
		}
			operater.top++;
			operater.data[operater.top] = *p;
			p++; dh = 0;
			break;
		case '%':
			while (operater.data[operater.top] == '%')
		{
			q[i] = operater.data[operater.top];
			operater.top--;
			i++;
		}
			operater.top++;
		    operater.data[operater.top] = *p;
			p++;
			dh = 0;
			break;
		case ' ': p++;
			break; //消除空格 

		default:
			while (*p >= '0' && *p <= '9') //判断是否为数字 
			{
				q[i] = *p;
				i++;
				p++;
			}
			if (*p == '.')
			{
				q[i] = '.';
				i++;
				p++;
				while (*p >= '0' && *p <= '9')
				{
					q[i] = *p;
					i++;
					p++;
				}
			}
			q[i] = '#'; 
			i++; 
			dh = 0;//用#标识一个数值串结束 
		}
	}
	while (operater.top != -1) //栈不空时循环 
	{
		q[i] = operater.data[operater.top];
		i++;
		operater.top--;
	}
	q[i] = '\0'; //给q表达式添加结束标识 
	return 1;
}

double calculator(char *q) //计算后缀表达式的值 
{
	double d, x;
	record.top = -1; //初始化操作数栈 
	while (*q != '\0') //q字符串未扫描完时循环 
	{
		switch (*q) //判断各种情况，并做相应的运算,并入栈 
		{
		case '+':record.data[record.top - 1] = record.data[record.top - 1] + record.data[record.top];
			record.top--;
			break;
		case '-':record.data[record.top - 1] = record.data[record.top - 1] - record.data[record.top];
			record.top--;
			break;
		case '*':record.data[record.top - 1] = record.data[record.top - 1] * record.data[record.top];
			record.top--;
			break;
		case '/': 
			if (record.data[record.top] != 0)
			        record.data[record.top - 1] = record.data[record.top - 1] / record.data[record.top];
				  record.top--;
				  break;
		case '%':
			record.data[record.top - 1] = fmod(record.data[record.top - 1], record.data[record.top]);
			record.top--;
			break;
		case '@':
			record.data[record.top] = -(record.data[record.top]);
			break;
		default:
			d = 0; //将数字字符转换成数值存放到d中 
			while (*q >= '0' && *q <= '9') //为数字字符 
			{
				d = 10 * d + (*q - '0'); //转变成整形 
				q++;
			}
			x = 0.1;
			if (*q == '.') //小数点 
			{
				q++;
				while (*q >= '0' && *q <= '9') //为数字字符 
				{
					d = d + x*(*q - '0');
					x *= 0.1;
					q++;
				}
			}
			record.top++;
			record.data[record.top] = d; //入操作数栈 
		}
		q++;
	}
	return record.data[record.top]; //返回计算结果
}