#include <iostream>
using namespace std;

class ConstRef {
public:
	//构造函数体一开始，初始化就完成了。因此给常量和引用初始化只能这样
	ConstRef() :ConstRef(0) {} //委托构造函数
	ConstRef(int i):ci(i),ri(i) { this->i = i; }
	string desc = "ConstRef";
	
private:

	//成员初始化顺序只和“定义顺序”有关，与构造函数中的“书写顺序”无关。
	int i;
	const int ci;
	int& ri;
};

class Account {

	//类的静态成员跟对象无关，但可以通过对象访问。
	//static关键字只能出现在类内
public:
	void calculate() { amount += amount * interestRate; }
	static double rate() { return interestRate; }
	static void rate(double rate);

private:
	string owner;
	double amount;

	//必须在类的外部初始化每个静态数据成员
	static double interestRate;
	//constexpr可以在类内部定义
	static constexpr int period = 30;
	static double initRate();
};

void Account::rate(double newrate) {
	interestRate = newrate;
}
double Account::interestRate = Account::initRate();
double Account::initRate() {
	return 0.75;
}

class Bar {
public:
	
private:
	static Bar mem1; //定义完成之前，静态类型可作为不完全类型
	Bar* mem2; //指针可作为不完全类型
	Bar& mem3; //引用可以作为不完全类型
	//Bar mem4;
	Bar get() { return *this; }; //返回类型可作为不完全类型
	static const char background;
};


int main_06_02() {

	ConstRef arr[2];
	cout << arr[0].desc << endl;

	double r = Account::rate();
	Account ac1, * ac2 = &ac1;
	r = ac1.rate();
	r = ac2->rate();
	cout << r << endl;

	return 0;
}
