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
}operater; //���������ջ��������ȫ�ֱ��� 

struct record
{
	double data[Maxlen];
	int top;
}record; //���������ջ��������ȫ�ֱ��� 

int change(char *p, char q[]) //���������ʽpת���ɱ��ʽ��׺���ʽq
{
	int i = 0; //i��Ϊq���±� 
	int dh = 1; //dh=1��ʾ�Ǹ��� 
	operater.top = -1; //��ʼ�������ջ 
	while (*p != '\0') //p���ʽδɨ����ʱѭ�� 
	{
		switch (*p) //�жϸ������,������Ӧ�Ĵ��� 
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
		case '-': if (dh == 1) // +,-�������� 
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
			break; //�����ո� 

		default:
			while (*p >= '0' && *p <= '9') //�ж��Ƿ�Ϊ���� 
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
			dh = 0;//��#��ʶһ����ֵ������ 
		}
	}
	while (operater.top != -1) //ջ����ʱѭ�� 
	{
		q[i] = operater.data[operater.top];
		i++;
		operater.top--;
	}
	q[i] = '\0'; //��q���ʽ��ӽ�����ʶ 
	return 1;
}

double calculator(char *q) //�����׺���ʽ��ֵ 
{
	double d, x;
	record.top = -1; //��ʼ��������ջ 
	while (*q != '\0') //q�ַ���δɨ����ʱѭ�� 
	{
		switch (*q) //�жϸ��������������Ӧ������,����ջ 
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
			d = 0; //�������ַ�ת������ֵ��ŵ�d�� 
			while (*q >= '0' && *q <= '9') //Ϊ�����ַ� 
			{
				d = 10 * d + (*q - '0'); //ת������� 
				q++;
			}
			x = 0.1;
			if (*q == '.') //С���� 
			{
				q++;
				while (*q >= '0' && *q <= '9') //Ϊ�����ַ� 
				{
					d = d + x*(*q - '0');
					x *= 0.1;
					q++;
				}
			}
			record.top++;
			record.data[record.top] = d; //�������ջ 
		}
		q++;
	}
	return record.data[record.top]; //���ؼ�����
}