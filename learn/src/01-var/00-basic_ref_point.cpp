#include <iostream>

int c; //定义在函数体外部的变量被初始化为0
int global = 1000;
int main_00() {
	
	//内置基本数据类型分为 “算术类型”和“空类型(void)”
	//算术类型分为“整型”和“浮点型”
	
	unsigned int a = 3;
	bool b = 10; //0为false，其余为true
	int i = true; //true:1, false:0
	bool c = false;
	std::cout << a << b << c << i << "a very very long "
		"long string\n";

	wchar_t me = '我';
	std::cout << me << std::endl;

	int units_sold = 0;
	int units_sold_2(0);
	//下两种为列表初始化，当应用在内置类型中，若存在丢失信息的风险，编译器将报错
	int units_sold_0 = { 0 }; //int units_sold_0 = { 0.5 }; 报错!
	int units_sold_1{ 0 };

	std::cout << c << std::endl;

	//int d; //未被初始化，危险！类对象默认初始化与否由类自己决定。
	std::cout << global << std::endl;
	int global = 100; //覆盖外层global变量
	std::cout << global << std::endl;

	//引用即别名(不是对象)。引用一旦赋值，无法修改。因此必须初始化
	// refg, p为引用，g为int类型
	int& refg = global, & pp = units_sold, g = global;
	refg = 200;
	std::cout << refg << global << std::endl;

	//指针本身就是一个对象/类型
	int val = 42;
	int* null = nullptr; //空指针，不指向任何对象, 等效于：int* p1 = 0;
	//空指针为0，因此条件是flase
	if (!null) {
		std::cout << "null pointer" << std::endl;
	}
	int* p; //未初始化
	int* q = &val;

	// 指针赋值, p,q均指向val
	p = &val;
	p = q;

	p == q; //指针比较，需类型相同才可比较(==, !=)

	*p = 0; //改变p所指对象的值

	//void* 指针，可存放任意对象的地址
	double pi = 3.14, *pd = &pi;
	void* pi_p = &pi; //存放double*
	pi_p = q; //存放int*
	// std::cout << *pi_p << std::endl; void*类型不可访问对象，
	pi_p == q; //可以比较和赋值

	// i:int，i_p:int*，i_r:int引用
	int ii = 1024, *i_p = &i, &i_r = i;

	//引用指针
	int m = 42;
	int* m_p;
	int*& r = m_p; //r是一个指针(m_p)的引用, 从右往左理解
	r = &m; //r和m_p均指向了m, r是一个指针的引用
	*r = 0;
	std::cout << m << *m_p << std::endl;

	return 0;

}

