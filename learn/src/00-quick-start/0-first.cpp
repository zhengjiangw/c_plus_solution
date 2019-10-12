#include <iostream>

int main_first() {
	
	std::cout << "please input two nums" << std::endl;
	int v1, v2;
	std::cin >> v1 >> v2;
	int v3 = v1 + v2;

	// "<<"运算符左值必须为ostream对象,返回对象本身，故可以连续使用<<运算符。
	// ">>"运算符类似， 定义不同的输入输出运算符，来实现支持多类型
	std::cout << "v1+v2=" << v3 << std::endl;

	int sum = 0, i = 0;
	while (i <= 10) {
		sum += i;
		i++;
	}
	std::cout << "1+2+3...+10=" << sum << std::endl;

	sum = 0;
	//i的作用域只存在于for语句中
	for (int j = 0; j <= 10; j++) {
		sum += j;
	}
	std::cout << "1+2+3...+10=" << sum << std::endl;

	sum = 0;
	int value = 0;
	// cin>>value当遇到文件结束符或者无效字符, istream对象无效, 条件为假
	while (std::cin >> value) {
		sum += value;
	}
	std::cout << "Sum is :" << sum << std::endl;

	return 0;
}
