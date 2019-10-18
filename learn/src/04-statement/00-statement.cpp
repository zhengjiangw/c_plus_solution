#include <iostream>
using namespace std;

int main_04_01() {

	//switch是整数或枚举类型
	switch ('c')
	{
	case 'a':
	case 'b':
	case 'c':
		//string ival; 因为可能会略过，变量只能声明，不能定义.因为后边的case都在a的作用域内
		int a; //正确
		cout << 'a' << endl;
		break;
	case 'd':
	{
		int b = 3; //加上{}后b的作用域只在当前case内，因此是可以的
	}
		a = 4;
	default:
		a = 3;
		cout << "not found" << a << endl;
		break;
	}



	return 0;

}