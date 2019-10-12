#include <iostream>

int c; //定义在函数体外部的变量被初始化为0
int global = 1000;
int main() {
	
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

	//int d; //未被初始化，危险。类对象默认初始化与否由类自己决定。
	std::cout << global << std::endl;
	int global = 100; //覆盖外层global变量
	std::cout << global << std::endl;

	//引用即别名。引用一旦赋值，无法修改。因此必须初始化

}
