#include <iostream>

using namespace std;

void arr_and_pointer();
int main() {

	//数组个数也是数组类型的一部分，编译可知， arr类型为：int arr[10]
	unsigned cnt = 42;
	constexpr unsigned sz = 3;
	int arr[10]; //数组默认初始化， int[]初始化为0
	//string bad[cnt];//错误, cnt不是常量表达式
	int* parr[sz]; //含有3个int*的数组 数组内是对象，因此无引用

	//定义数组的时候必须制定类型，不允许用auto关键字

	int ial[sz] = { 0,1,2 }; //个数不能超过总长度
	int a2[] = { 0,1,2 }; //反推出a2类型为：int a2[3];
	int a3[5] = { 0,1,2 }; //相当于 {0,1,2,0,0}

	char c1[] = { 'c','+','+' ,'!' };
	char c2[] = "c++"; //char c2[4], 字符串有结束符

	//c1 = c2;//错误！！！数组禁止拷贝和赋值
	int* ptrs[10]; //10个int*类型的数组
	int(*Parry)[10]; //Parry是指针，指向数组类型。数组含有10个int
	int(&arrRef)[5] = a3; //arrRef是一个数组的引用，数组含有5个int
	//int* (&ref)[5] = ..; ref是一个数组的引用，数组含有5个int*

	arr_and_pointer();
	return 0;
}

//数组和指针
void arr_and_pointer() {

	//使用数组的时候，编译器“一般”会把它转换成指针
	string nums[3] = { "one", "two", "three" };
	string* p = &nums[0]; //p指向第一个元素
	string* p2 = nums; //与上等价, 在很多用到数组名的时候，编译器自动替换为指向第一个元素的指针
	cout << (p == p2) << endl; //true

	auto ia2 = nums; //
}
