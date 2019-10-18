#include <iostream>
#include <vector>
#include "../01-var/Sales_data.h"

using namespace std;

void type_cast();
int main_03_00() {

	int i = 1024;
	int k = -i;//区负运算符
	bool b = true;
	bool b2 = -b;//bool被提升为int, -1为true

	//关系运算符返回bool值, 左结合率
	i = 1;
	int j = 2; k = 3;
	//if (i < j < k) i<j = 1 < k

	//赋值运算满足右结合律
	int ival, jval;
	ival = jval = 0; //赋值运算返回其左侧对象，所以ival被赋值为0

	vector<int> v{ 3,1,5,-2,0 };
	auto beg = v.begin();
	while (beg != v.end() && *beg > 0) {
		cout << *beg++ << " "; //后置递增运算符优先级高于解指针运算符
	}
	cout << endl;

	string temp = "sb";
	auto begs = temp.begin();
	while (begs != temp.end()) {
		*begs = toupper(*begs++); //sS 最好不要这么用
		break;
	}
	cout << temp << endl;

	int grade = 88;
	string finalgrade = grade < 60 ? "fail" : "pass";
	cout << finalgrade << endl;

	finalgrade = grade > 90 ? "high pass" : grade < 60 ? "fail" : "pass";
	cout << finalgrade << endl;

	//sizeof返回一条表达式或一个类型名字所占的字节数, 右结合律, size_t类型
	cout << sizeof(grade) << endl;
	Sales_data data, * p;
	cout << sizeof data << endl;//返回对象大小
	cout << sizeof(*p) << endl;//返回所指对象大小，指针不需有效
	cout << sizeof(p) << endl;//返回指针大小，指针不需有效
	cout << sizeof Sales_data::revenue << sizeof data.revenue << endl; //不需要提供对象

	int arr[] = { 0,1,2 };
	cout << sizeof arr << endl; //返回数组总大小, 此处arr不会转换为指针

	//逗号运算符，左侧结果被丢弃，结果是右侧对象的值, 常用语for(..,..; ..; ..,...)
	int a = 3, bb = 4;
	a++, bb = 5;
	cout << a << bb << endl;

	type_cast();

	return 0;
}

void type_cast() {

	int ival = 3.541 + 3; //隐式转换, 3转为double, 然后忽略整数
	//while(cin>>is) //cin可隐式转换为bool，根据状态确定

	//static_cast，任何具有明确类型的对象，只要不包含底层const, 都可以使用static_cast
	double d = 3.14;
	void* p = &d;
	double* dp = static_cast<double*>(p);

	char c = 'b';
	char* cp = &c;
	string str = static_cast<string>(cp); //char*转换为string
	string str1 = "hello";
	char* sp = &str[0];
	cout << str << endl;

	//const_cast，只能改变运算对象的底层const，只改变常量属性，不改变类型
	char ch = 'z';
	const char* pc = &ch;

	char* pca = const_cast<char*>(pc); //去除了底层const, pca可以修改值
	*pca = 'j';
	cout << ch << *pc << *pca << endl;

	//reinterpret_cast<>谨慎使用吧还是

	
}
