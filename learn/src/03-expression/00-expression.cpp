#include <iostream>
#include <vector>
#include "../01-var/Sales_data.h"

using namespace std;

void type_cast();
int main_03_00() {

	int i = 1024;
	int k = -i;//���������
	bool b = true;
	bool b2 = -b;//bool������Ϊint, -1Ϊtrue

	//��ϵ���������boolֵ, ������
	i = 1;
	int j = 2; k = 3;
	//if (i < j < k) i<j = 1 < k

	//��ֵ���������ҽ����
	int ival, jval;
	ival = jval = 0; //��ֵ���㷵��������������ival����ֵΪ0

	vector<int> v{ 3,1,5,-2,0 };
	auto beg = v.begin();
	while (beg != v.end() && *beg > 0) {
		cout << *beg++ << " "; //���õ�����������ȼ����ڽ�ָ�������
	}
	cout << endl;

	string temp = "sb";
	auto begs = temp.begin();
	while (begs != temp.end()) {
		*begs = toupper(*begs++); //sS ��ò�Ҫ��ô��
		break;
	}
	cout << temp << endl;

	int grade = 88;
	string finalgrade = grade < 60 ? "fail" : "pass";
	cout << finalgrade << endl;

	finalgrade = grade > 90 ? "high pass" : grade < 60 ? "fail" : "pass";
	cout << finalgrade << endl;

	//sizeof����һ�����ʽ��һ������������ռ���ֽ���, �ҽ����, size_t����
	cout << sizeof(grade) << endl;
	Sales_data data, * p;
	cout << sizeof data << endl;//���ض����С
	cout << sizeof(*p) << endl;//������ָ�����С��ָ�벻����Ч
	cout << sizeof(p) << endl;//����ָ���С��ָ�벻����Ч
	cout << sizeof Sales_data::revenue << sizeof data.revenue << endl; //����Ҫ�ṩ����

	int arr[] = { 0,1,2 };
	cout << sizeof arr << endl; //���������ܴ�С, �˴�arr����ת��Ϊָ��

	//������������������������������Ҳ�����ֵ, ������for(..,..; ..; ..,...)
	int a = 3, bb = 4;
	a++, bb = 5;
	cout << a << bb << endl;

	type_cast();

	return 0;
}

void type_cast() {

	int ival = 3.541 + 3; //��ʽת��, 3תΪdouble, Ȼ���������
	//while(cin>>is) //cin����ʽת��Ϊbool������״̬ȷ��

	//static_cast���κξ�����ȷ���͵Ķ���ֻҪ�������ײ�const, ������ʹ��static_cast
	double d = 3.14;
	void* p = &d;
	double* dp = static_cast<double*>(p);

	char c = 'b';
	char* cp = &c;
	string str = static_cast<string>(cp); //char*ת��Ϊstring
	string str1 = "hello";
	char* sp = &str[0];
	cout << str << endl;

	//const_cast��ֻ�ܸı��������ĵײ�const��ֻ�ı䳣�����ԣ����ı�����
	char ch = 'z';
	const char* pc = &ch;

	char* pca = const_cast<char*>(pc); //ȥ���˵ײ�const, pca�����޸�ֵ
	*pca = 'j';
	cout << ch << *pc << *pca << endl;

	//reinterpret_cast<>����ʹ�ðɻ���

	
}
