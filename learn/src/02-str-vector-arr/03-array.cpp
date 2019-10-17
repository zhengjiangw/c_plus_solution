#include <iostream>
#include <vector>

using namespace std;

void arr_and_pointer();
void multi_arr();
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

	int int_arr[] = { 0,1,2,3,4,5 };
	vector<int> ivec(begin(int_arr), end(int_arr));

	arr_and_pointer();
	multi_arr();
	return 0;
}

//数组和指针
void arr_and_pointer() {

	//使用数组的时候，编译器“一般”会把它转换成指针
	string nums[3] = { "one", "two", "three" };
	string* p = &nums[0]; //p指向第一个元素
	string* p2 = nums; //与上等价
	cout << (p == p2) << endl;

	auto ia2(nums); //string* ia2;
	//decltype不会不会发生转换
	decltype(nums) ia3; //string ia3[3];

	//指针也是迭代器，支持所有迭代器操作!!!
	int ia[5] = { 0,1,2,3,4 };
	int* beg = begin(ia), * e = end(ia);
	while (beg < e) {
		cout << *beg << " ";
		beg++;
	}

	int i = ia[2]; //2
	int* pa = ia; //p指向ia首元素
	i = *(pa + 2); //等价于ia[2]

	int* pp = &ia[2];//pp指向第三个 2
	int j = pp[1]; //向右移动一个 3
	int k = pp[-2]; //左移两个 0
	cout << "right" << j << "left" << k << endl; //3, 0


	int i1 = 1, i2 = 2, *p1 = &i1, *p3 = &i2;
	cout << (p1 == p3) << endl;
}

void multi_arr() {

	//多维数组，即为数组的数组
	int ia[3][4]; //大小为3的数组，每个元素是4个元素的数组

	//ia = { {0,1,2,3},{4,5,6,7},{8,9,10,11} };数组不允许赋值
	int ia1[3][4] = { {0,1,2,3},{4,5,6,7},{8,9,10,11} };
	int ia2[3][4] = { {0,1,2,3},{4,5,6,7},{8,9,10,11} };
	int ia3[3][4] = { 0,1,2,3,4,5,6,7,8,9,10,11 }; //与上等价
	int ia4[3][4] = { {0},{1},{2} }; //初始化每一行第一个元素
	int ia5[3][4] = { 0,1,2,3 }; //初始化第一行

	int(&row)[4] = ia1[0]; //row引用ia1第一行
	size(ia);

	const size_t rowcnt = 3, colcnt = 4;
	int ia6[rowcnt][colcnt];
	for (size_t i = 0; i < rowcnt; i++) {
		for (size_t j = 0; j < colcnt; j++) {
			ia6[i][j] = i * colcnt + j;
		}
	}

	for (auto& row : ia6) { //外层不用auto&的话，row会被转为指针
		for (auto col : row) {
			cout << col << "\t";
		}
		cout << endl;
	}

	//int ia[3][4] 因为是多维数组，ia指向了第一个(元素)即第一行数组
	int(*p)[4] = ia;
	p = &ia[2]; //p指向了最后一行数组
	int* pa = ia[2]; //pa指向了最后一行第一个元素
}
