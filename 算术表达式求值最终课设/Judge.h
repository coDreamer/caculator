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
//不合法字符检查
int one_analys(char p[]){
	cout << "第一步检测"<<endl;
	char Species_coding[18] = { '0', '1', '2', '3', '4', '5', '6', '7', '8', '9', '.', '+', '-', '*', '/', '(', ')', '%' };
	int i = 0, j = 0;
	while (i < length){
		for (j = 0; j < 18; j++){
			if (p[i] == Species_coding[j])
				break;
		}
		if (j >= 18){
			cout << "出现不合法字符！请检查重新输入" << endl;
			return 0;
		}
		i++;
	}
	return 1;
}
//检查运算符位置是否正确
int second_analys(char p[]){
	cout << "第二步检测" << endl;
	if (p[0] == '*' || p[0] == '/' || p[0] == '%'){
		cout << "首字符不该为*或/或%" << endl;
		cout << "请检查重新输入" << endl;
		return 0;
	}//*1+3-6
	if (isCharacter(p[length - 1]) == true){
		cout << "末尾字符不该为运算符" << endl;
		cout << "请检查重新输入" << endl;
		return 0;
		
	}
	int i = 1;
	while (i < length){
		if (isCharacter(p[i]) == true && p[i + 1] != NULL){
			if (p[i] == '/' && p[i + 1] == '0'&&p[i + 2] != '.'){
				cout << "被除数不能为零";
				cout << "请检查然后重新输入!" << endl;
				return 0;
			}
			if (p[i] == '%'){
				if (p[i + 1] == '0'){
					cout << "整除取余被除数不能为零或小数";
					cout << "请检查然后重新输入!" << endl;
					return 0;
				}
				if (isNumber(p[i - 1]) == true){
					int n = i - 1;
					while (isNumber(p[n]) == true){
						n--;
					}
					if (p[n] == '.'){
						cout << "整除取余除数不能为零或小数";
						cout << "请检查然后重新输入!" << endl;
						return 0;
					}
				}
			}
			if (isCharacter(p[i + 1]) == true){
				cout << "出现两个运算符相邻而中间没有操作数" << endl;
				cout << "请检查然后重新输入!" << endl;
				return 0;
			}//3*+2+5
			if (p[i + 1] == ')'){
				cout << "运算符后直接是右括号！" << endl;
				cout << "请检查然后重新输入!" << endl;
				return 0;
			}
			if (p[i - 1] == '(' && p[i] != '+'){
				if (p[i] != '-'){
					cout << "左括号后直接是运算符！" << endl;
					cout << "请检查然后重新输入!" << endl;
					return 0;
				}
			}
			if (p[i + 1] == '.'){
				cout << "运算符后直接是小数点！" << endl;
				cout << "请检查然后重新输入!" << endl;
				return 0;
			}//1+5-.3+5
			if (p[i - 1] == '.'){
				cout << "小数点后直接是运算符！" << endl;
				cout << "请检查然后重新输入!" << endl;
				return 0;
			}
		}
		i++;
	}
	return 1;
}
//检查小数点位置是否正确
int third_analys(char p[]){
	cout << "第三步检测" << endl;
	if (p[0] == '.' || p[length - 1] == '.'){
		cout << "首末字符是.出错！" << endl;
		cout << "请检查然后重新输入!" << endl;
		return 0;
	}//.1+3
	int i = 1;
	while (i < length){
		if (p[i] == '.'){
			if (p[i + 1] == '.'){
				cout << "连续的两个小数点出错！" << endl;
				cout << "请检查然后重新输入!" << endl;
				return 0; 
			}//1..3+3
			if (p[i - 1] == '(' || p[i - 1] == ')'){
				cout << "括号接小数点出错！" << endl;
				cout << "请检查然后重新输入!" << endl;
				return 0;
			}//1+3*(.3+5)
			if (p[i + 1] == '(' || p[i + 1] == ')'){
				cout << "小数点接括号出错！" << endl;
				cout << "请检查然后重新输入!" << endl;
				return 0;
			}//1.(+3-5
		}
		i++;
	}
	return 1;
}
//括号检查
bool isEmpty(char ss[], int top){
	if (top == -1)
		return true;
	else
		return false;
}
char Pop(char ss[], int &top){
	if (top == -1){
		cout << "栈空，出栈错误！" << endl;
		return 0;
	}
	char a;
	a = ss[top];
	top = top - 1;
	return a;
}
int Push(char ss[], char a, int &top){
	if (top == Maxlen - 1){
		cout << "栈满，入栈错误！" << endl;
		return 0;
	}
	top = top + 1;
	ss[top] = a;
	return 1;
}

int forth_analys(char p[]){
	cout << "第四步检测" << endl;
	char ss[Maxlen];
	int top = -1;
	int i = 0;
	while (i < length){
		if (p[i] == '('){
			if ((i - 1 >= 0) && isNumber(p[i - 1]) == true){
				cout << "数字后面直接是左括号，请检查重新输入！" << endl;
				return 0;
			}//3(+5
			else{
				Push(ss, p[i], top);
			}
		}
		if (p[i] == ')'){
			if (p[i - 1] == '('){
				cout << "括号之间没有数据，请检查重新输入！" << endl;
				return 0;
			}
			if (isNumber(p[i + 1]) == true){
				cout << "右括号后面直接是数字，请检查重新输入！" << endl;
				return 0;
			}
			else{
				if (Pop(ss, top) != '('){
					cout << "括号出现错误！请检查重新输入！" << endl;
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
		cout << "括号出现错误！请检查重新输入！" << endl;
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