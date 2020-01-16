#include <iostream>
#include <memory>
#include <vector>
#include <string>
using namespace std;

//每个程序拥有一个内存池，称为“自由空间”或“堆”，来存储动态分配的内存
//动态对象的生存期由程序来控制, 通过new和delete管理
//new:分配空间并返回指针；delete:接受动态类型指针，销毁对象，释放内存
//两种智能指针类型来管理动态类型
//shared_ptr:允许多个指针指向同一对象，unique_ptr:独占所指向对象
//引用计数为0或者shared_ptr, unique_ptr离开作用域，就会自动释放自己管理的对象
int main() {

	shared_ptr<string> p1; //默认初始化空指针 p1 == nullptr

	shared_ptr<int> p3 = make_shared<int>(42);
	shared_ptr<string> p4 = make_shared<string>(10, '9');
	shared_ptr<int> p5 = make_shared<int>(); //p5指向默认初始化的int，为0

	auto p = make_shared<int>(42);
	auto q(p); //p赋值给q，拷贝,拷贝的时候引用计数会增加
	auto r = make_shared<int>(42);
	r = q; //给r赋值，r原来的引用次数减少，q引用计数增加

	//shared_ptr的析构函数会递减它指向对象的引用计数，若变为0，会销毁对象并释放内存

	int* pi = new int; //pi指向一个未初始化的int
	string* ps = new string; //指向一个空string
	string* ps2 = new string(10, '9');
	int* pi2 = new int(1024); //pi2指向的对象值为1024
	vector<int>* pv = new vector<int>{ 0,1,2,3,4 };

	//new分配const对象
	const int* pic = new const int(1024);
	const string* pcs = new const string;

	int F();
	F();
	return 0;
}

int count_3(int n);

int F() {

	int count = 0;
	int n = 1;
	while (n<=9999)
	{
		count += count_3(n);
		++n;
	}
	cout << "count:" << count << endl;
	return count;

}

int count_3(int n) {

	int count = 0;
	string res = to_string(n);
	for (char ch : res) {
		if (ch == '3')
			++count;
	}
	return count;
}