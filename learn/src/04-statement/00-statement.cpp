#include <iostream>
using namespace std;

int main_04_01() {

	//switch��������ö������
	switch ('c')
	{
	case 'a':
	case 'b':
	case 'c':
		//string ival; ��Ϊ���ܻ��Թ�������ֻ�����������ܶ���.��Ϊ��ߵ�case����a����������
		int a; //��ȷ
		cout << 'a' << endl;
		break;
	case 'd':
	{
		int b = 3; //����{}��b��������ֻ�ڵ�ǰcase�ڣ�����ǿ��Ե�
	}
		a = 4;
	default:
		a = 3;
		cout << "not found" << a << endl;
		break;
	}



	return 0;

}