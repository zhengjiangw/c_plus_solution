#include <iostream>

void top_bottom_const();
void const_expr();
void type_alias();
void type_auto();
void decl_type();
int main_01() {

	//常数，必须初始化，不可修改
	const int bufsize = 512;

	//const常量的引用
	const int ci = 1024;
	const int& rl = ci; //正确，引用及引用的对象都是常量
	// rl = 42;错误, rl是常量引用
	//int& r2 = ci; //错误, ci是常量,否则可以通过r2修改值

	int i = 42;
	const int& r1 = i; //允许
	const int& r2 = 42; //常量引用
	const int& r3 = i * 8; //常量引用
	//int& r4 = i * 5; //错误
	const int& r5 = r1 * 8;//常量引用
	//int& r6 = r1 * 8; //错误, 非常量引用
	
	double dval = 3.14;
	const int& d = dval; //3

	//指向常量的指针，不能改变所指对象的值
	const double pi = 3.14;
	//double* ptr = &pi; //错误，只能通过常量指针
	const double* ptr = &pi; //常量对象必须使用指向常量的指针(因为不允许通过指针修改值)
	//*ptr = 42; //错误, 不能改变值
	ptr = &dval; //指向常量的指针可以指向非常量对象

	//const指针，指针也是对象，常量对象，不允许被修改所指向的对象。
	int errNum = 0;
	int another = 0;
	int* const curErr = &errNum; //curErr将一直指向errNum，不可改变
	//curErr = &another; 错误，不能改变所指向的对象
	*curErr = 100; //正确,可以改变所指对象的值
	const double pi2 = 3.14159;
	const double* const pi2_p = &pi2; //pi2_p是指向常量对象的常量指针。

	top_bottom_const();
	const_expr();
	type_alias();
	type_auto();
	decl_type();
	
	return 0;
}

void top_bottom_const() {
	//顶层const:对象(包括指针)是个常量,不能改变值
	//底层const:指针所指对象是一个常量，常量引用都是底层const
	//指针类型既可以是顶层const又可以是底层const

	int i = 0;
	const int ci = 42;//顶层const，不能改变cr的值
	int* const p1 = &i; //顶层const，不能改变p1的值
	const int* p2 = &ci; //底层const，p2值可变，不能通过指针改变所指对象的值
	const int* const p3 = p2; //即是底层const也是顶层const
	const int& r = ci; //常量引用都是底层const

	//int* p = p3; //错误, p3包含底层const
	p2 = p3;//正确，p2,p3都包含底层const
	p2 = &i; //正确, 非const可以转换为const
	//int& r = ci; 错误
	const int& r2 = i;
}

int j = 0;
constexpr int i = 42;
void const_expr() {

	//常量表达式在编译过程就能得到结果, 有几种情况需要常量表达式
	const int max_files = 20; //是常量表达式
	const int limit = max_files + 1; //是
	int staff_size = 27;//不是
	int get_size();
	const int sz = get_size(); //不是, get_size()运行时才知道
	std::cout << sz << std::endl;

	//声明为constexpr一定是一个常量，且必须用常量表达式初始化
	constexpr int mf = 20; //20是常量表达式
	constexpr int lim = mf + 1; //mf+1是常量表达式
	//constexpr int limit = staff_size + 1; staff_size是变量
	//constexpr int sz = get_size(); get_size()必须声明为constexpr才正确

	//constexpr 常量表达式的值必须编译的时候就能知道结果, 算术类型，引用和指针。
	//其他不可以使用constexpr修饰(因为无法编译的时候知道值)如字符串, 类
	//constexpr修饰的又称为字面量类型

	const int* p = nullptr; //同：const int* p = 0, p是一个指向常量的指针
	constexpr int* q = nullptr; //q是一个指向常量的常量指针

	//constexpr修饰为常量指针，const修饰指向常量的指针
	constexpr const int* p1 = &i; //i定义在函数体之外，编译时已确定值
	constexpr int* p2 = &j; //同上
}


void type_alias() {

	//传统方法
	typedef double wages; //类型别名typedef
	typedef wages base, * p; //p是double*指针类型别名
	base b = 3;
	p pe = &b;

	//新标准using
	using hourly = wages;
	using doub = double;
}

void type_auto() {

	auto ii = 0, *p = &ii;
	//auto sz = 0, pi = 3.14; 错误, sz和pi类型不一致，一条声明只能有一个基本数据类型
	int i = 0, &r = i;
	auto a = r;//a是int类型对象

	//auto一般会忽略掉顶层const，保留底层const
	const int ci = i, & cr = ci;
	auto b = ci; //int b
	auto c = cr; //intc cr是别名。引用的对象是顶层const 
	auto d = &i; //int* d
	auto e = &ci; //const int* e

	//若希望是顶层const，需要手动指出
	const auto f = ci; //const int f;
	
	auto& g = ci; //const int& g;
	const auto& h = 42; //const int& h;
}

void decl_type() {

	//引用通常所指对象的别名，只有decltype例外
	const int ci = 0, &cj = ci;
	decltype(ci) x = 0; //const int x;
	decltype(cj) y = x; //const int& y;
	//decltype(cj) z; cj是引用, 必须初始化

	int i = 42, *p = &i, &r = i;
	decltype(r + 0) b; //int b;
	//decltype(*p) c; 解指针后的类型是int&, 因此c必须被赋值
	//decltype((i)) d; int& d;必须初始化
	decltype(i) e; //int e;

	//decltype((var))永远是引用类型
	//decltype(var)只有当var是引用的时候才是引用类型
}


int get_size() {
	int a = 0;
	return ++a;
}
