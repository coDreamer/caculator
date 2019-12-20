#include"dostack.h"
using namespace std;

int length = 0;
int error = 0;

bool isNumber(char a){
	if (a <= '9'&&a >= '0')
		return true;
	else
		return false;
}
bool isCharacter(char a){
	if (a == '*' || a == '-' || a == '+' || a == '/' || a == '%')
		return true;
	else
		return false;
}
//���Ϸ��ַ����
int one_analys(char p[]){
	cout << "��һ�����"<<endl;
	char Species_coding[18] = { '0', '1', '2', '3', '4', '5', '6', '7', '8', '9', '.', '+', '-', '*', '/', '(', ')', '%' };
	int i = 0, j = 0;
	while (i < length){
		for (j = 0; j < 18; j++){
			if (p[i] == Species_coding[j])
				break;
		}
		if (j >= 18){
			cout << "���ֲ��Ϸ��ַ���������������" << endl;
			return 0;
		}
		i++;
	}
	return 1;
}
//��������λ���Ƿ���ȷ
int second_analys(char p[]){
	cout << "�ڶ������" << endl;
	if (p[0] == '*' || p[0] == '/' || p[0] == '%'){
		cout << "���ַ�����Ϊ*��/��%" << endl;
		cout << "������������" << endl;
		return 0;
	}//*1+3-6
	if (isCharacter(p[length - 1]) == true){
		cout << "ĩβ�ַ�����Ϊ�����" << endl;
		cout << "������������" << endl;
		return 0;
		
	}
	int i = 1;
	while (i < length){
		if (isCharacter(p[i]) == true && p[i + 1] != NULL){
			if (p[i] == '/' && p[i + 1] == '0'&&p[i + 2] != '.'){
				cout << "����������Ϊ��";
				cout << "����Ȼ����������!" << endl;
				return 0;
			}
			if (p[i] == '%'){
				if (p[i + 1] == '0'){
					cout << "����ȡ�౻��������Ϊ���С��";
					cout << "����Ȼ����������!" << endl;
					return 0;
				}
				if (isNumber(p[i - 1]) == true){
					int n = i - 1;
					while (isNumber(p[n]) == true){
						n--;
					}
					if (p[n] == '.'){
						cout << "����ȡ���������Ϊ���С��";
						cout << "����Ȼ����������!" << endl;
						return 0;
					}
				}
			}
			if (isCharacter(p[i + 1]) == true){
				cout << "����������������ڶ��м�û�в�����" << endl;
				cout << "����Ȼ����������!" << endl;
				return 0;
			}//3*+2+5
			if (p[i + 1] == ')'){
				cout << "�������ֱ���������ţ�" << endl;
				cout << "����Ȼ����������!" << endl;
				return 0;
			}
			if (p[i - 1] == '(' && p[i] != '+'){
				if (p[i] != '-'){
					cout << "�����ź�ֱ�����������" << endl;
					cout << "����Ȼ����������!" << endl;
					return 0;
				}
			}
			if (p[i + 1] == '.'){
				cout << "�������ֱ����С���㣡" << endl;
				cout << "����Ȼ����������!" << endl;
				return 0;
			}//1+5-.3+5
			if (p[i - 1] == '.'){
				cout << "С�����ֱ�����������" << endl;
				cout << "����Ȼ����������!" << endl;
				return 0;
			}
		}
		i++;
	}
	return 1;
}
//���С����λ���Ƿ���ȷ
int third_analys(char p[]){
	cout << "���������" << endl;
	if (p[0] == '.' || p[length - 1] == '.'){
		cout << "��ĩ�ַ���.����" << endl;
		cout << "����Ȼ����������!" << endl;
		return 0;
	}//.1+3
	int i = 1;
	while (i < length){
		if (p[i] == '.'){
			if (p[i + 1] == '.'){
				cout << "����������С�������" << endl;
				cout << "����Ȼ����������!" << endl;
				return 0; 
			}//1..3+3
			if (p[i - 1] == '(' || p[i - 1] == ')'){
				cout << "���Ž�С�������" << endl;
				cout << "����Ȼ����������!" << endl;
				return 0;
			}//1+3*(.3+5)
			if (p[i + 1] == '(' || p[i + 1] == ')'){
				cout << "С��������ų���" << endl;
				cout << "����Ȼ����������!" << endl;
				return 0;
			}//1.(+3-5
		}
		i++;
	}
	return 1;
}
//���ż��
bool isEmpty(char ss[], int top){
	if (top == -1)
		return true;
	else
		return false;
}
char Pop(char ss[], int &top){
	if (top == -1){
		cout << "ջ�գ���ջ����" << endl;
		return 0;
	}
	char a;
	a = ss[top];
	top = top - 1;
	return a;
}
int Push(char ss[], char a, int &top){
	if (top == Maxlen - 1){
		cout << "ջ������ջ����" << endl;
		return 0;
	}
	top = top + 1;
	ss[top] = a;
	return 1;
}

int forth_analys(char p[]){
	cout << "���Ĳ����" << endl;
	char ss[Maxlen];
	int top = -1;
	int i = 0;
	while (i < length){
		if (p[i] == '('){
			if ((i - 1 >= 0) && isNumber(p[i - 1]) == true){
				cout << "���ֺ���ֱ���������ţ������������룡" << endl;
				return 0;
			}//3(+5
			else{
				Push(ss, p[i], top);
			}
		}
		if (p[i] == ')'){
			if (p[i - 1] == '('){
				cout << "����֮��û�����ݣ������������룡" << endl;
				return 0;
			}
			if (isNumber(p[i + 1]) == true){
				cout << "�����ź���ֱ�������֣������������룡" << endl;
				return 0;
			}
			else{
				if (Pop(ss, top) != '('){
					cout << "���ų��ִ��������������룡" << endl;
					return 0;
				}//9)%(3
			}
		}
		i++;
	}
	if (isEmpty(ss, top) == true){
		return 1;
	}
	else{
		cout << "���ų��ִ��������������룡" << endl;
		return 0;
	}
}

int Analysis(char p[]){
	length = 0;
	for (int i = 0; p[i] != '\0'; i++)
		length++;
	//cout << length;
	if (1 == one_analys(p)){
		if (1 == second_analys(p)){
			if (1 == third_analys(p)){
				if (1 == forth_analys(p)){
					return 1;
				}
				else{
					return 0;
				}
			}
			else{
				return 0;
			}
		}
		else{
			return 0;
		}
	}
	else{
		return 0;
	}
}