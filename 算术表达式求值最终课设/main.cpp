#include "windows.h"
#include"Judge.h"
using namespace std;

void meun()
{
	system("color 0a");
	cout << "\t\t **************************************" << endl;
	cout << "\t\t            2018���չ��̴�ѧ���������ϢѧԺ�������רҵ����" << endl;
	cout << "\t\t            �������ʽ��ֵϵͳ" << endl;
	cout << "\t\t            ��������ˣ�����" << endl;
	cout << "\t\t            ��������ʽ(֧���������������㣬���Ų�֧������!!!)" << endl;
	cout << "\t\t **************************************" << endl;
	cout << endl;
	cout << "\t\t ����end�ɽ���������" << endl;
}

int main()
{
	char p[400], q[400];
	double k;
	void meun(); //�����˵����� 
	int change(char *p, char q[]); //����ת������ 
	double calculator(char *q); //�������㺯�� 
	meun();
	for (;;) //ѭ��ִ�� 
	{
		cout << "\t\t ������:";
		cin >> p;
		if (strcmp(p, "end") == 0)
			return 0;
		int a = Analysis(p);
		//cout << a;
		if (a == 1){
			if (change(p, q) == 1)
			{
				k = calculator(q);
				cout << "\t\t ������Ϊ:" << k << endl;
			}
		}
		else{
			continue;
		}
		system("pause"); //���������ʽ 
		system("cls");//����
		meun();
	}
	return 0;
}