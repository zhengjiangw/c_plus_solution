#include <iostream>
using namespace std;

// 函数指针指向某种类型，函数类型由返回值和形参类型共同决定，和函数名无关
bool lengthCompare(const string s1, const string& s2);
bool lengthCompare(const string s1, const string& s2) {
	return s1.size() > s2.size();
}

void ff(int*) {};
void ff(unsigned int) {};
void (*pf1)(unsigned int) = ff; //必须精确匹配
//void(&pf2)(int) = ff;错误，必须精确匹配

//函数指针形参，形参看起来是函数类型，实际上当做函数指针使用, 等价声明
void useBigger(const string& s1, const string& s2, bool pf(const string&, const string&));
void useBigger(const string& s1, const string& s2, bool (*pf)(const string&, const string&)) {
	cout << pf(s1, s2) << endl;
}

typedef decltype(lengthCompare) Func; //Func是函数类型
typedef decltype(lengthCompare)* FuncP; //FuncP是函数指针
//等价声明, 简化后的
void useBigger(const string&, const string&, Func);
void useBigger(const string&, const string&, FuncP);

//返回函数指针, 返回类型不会自动把函数名转换为指针，因此需要显式定义
using F=int(int*, int);//F是函数类型
using PF = int(*)(int*, int);//PF是函数指针
//F f1(int); 错误，不允许返回函数
PF f1(int);
F* f1(int); //正确，返回F*，函数指针。
int (*f1(int))(int*, int);//直接声明
auto f1(int)->int(*)(int*, int); //后置声明

int main_05_01() {

	//把函数名替换掉
	bool (*pf)(const string, const string&); //没有初始化
	pf = lengthCompare;
	pf = &lengthCompare;// 与上等价，把函数名作为值使用时，自动转换为指针

	bool b1 = pf("helo", "hello");
	bool b2 = (*pf)("helo", "hello");
	bool b3 = lengthCompare("helo", "hello"); //等价调用

	return 0;
}
