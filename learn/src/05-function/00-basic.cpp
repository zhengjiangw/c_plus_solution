#include <iostream>
#include <vector>
using namespace std;

size_t count_calls() {
	static size_t count = 0; //局部静态变量,第一次用到，若没有初始化则默认初始化。不受函数结束影响
	return ++count;
}

void resnet(int& i) { //传递引用, 可以避免拷贝
	i = 0;
}

void fcn(const int i) {} //顶层const被忽略，传递const int i，int i都可以
//void fcn(int i) {} 因为上同时可以传int i，所以定义重复了

void sum(initializer_list<int> eles);

char& get_val(const string&, string::size_type);
void test();
int main_05_00() {

	string str = "hello";
	const char* ch = "helo";
	cout << *ch << endl;
	size_t count = 0;
	for (int i = 0; i < 5; i++) {
		count = count_calls();
	}
	cout << count << endl;

	int j = 42;
	resnet(j);
	cout << j << endl;

	initializer_list<int> eles{ 1,2,3 };
	initializer_list<int> aug = eles; //拷贝
	sum(aug);
	sum({ 1,2,3,4,5 });

	const string strs = "hello";
	//返回的是引用，可以作为左值使用
	get_val(strs, 0) = 'b';
	cout << strs << endl;

	test();

	return 0;
}

int a = 3;
int fact(int a) {
	return a++;
}

//等价，对于三种，只检查是不是const int*
void print(const int*);
void print(const int[]);//数组不允许赋值，因此是Int*
void print(const int[5]); //[5]实际中不严格校验，只代表期望值
void print(const int(&)[5]); //数组的引用，必须传递int[5]类型。

void print(const int* a) {}

//initializer_list<>适合处理类型相同，个数未知的对象！
void sum(initializer_list<int> eles) {
	
	int sum = 0;
	for (auto beg = eles.begin(); beg != eles.end(); ++beg) {
		sum += *beg;
		//(*beg)++; 元素都是只读的，不可修改。
	}
	cout << "size:" << eles.size() << ", sum:" << sum << endl;
}

//返回引用的函数可以作为左值使用
char& get_val(const string& str, string::size_type ix) {
	
	//此处没有必要，可把str定义成string&即可，这里主要是复习下const_cast<>
	return const_cast<char&>(str[ix]);
}

vector<string> process() {

	//vector<string> temp = { "a", "b", "c" };

	//可以返回列表来初始化vector
	//return {};
	return { "ab", "cd", "ef" };
}

//数组不允许拷贝，因此不能返回数组，但可以返回引用和指针
//返回指向int[5]的指针, 引用类似
int(*func1(int idx))[5];

//效果同上，引用类似
auto func2(int idx) -> int(*)[5];

int arr[5] = {};
//效果同上，因为decltype不会自动转指针，因此再加一个*
decltype(arr) *func3(int idx);

void lookup(string str);
void lookup(const string str); //顶层const被忽略，因此是重复声明

void lookup(string* str);
//这是底层const, 因此不算是重复声明, 根据传入参数的类型决定调用哪个。引用也类似
void lookup(const string* str);

void print(const string& str);
void print(double);
void fooBar(int ival) {

	void print(int);
	//print("value");
	//c++里，名字查找发生在类型检查之前。"print", 首先找到了print(int)。
	//然后再检查能否调用。注:根据名字现在当前作用域查找，找不到再去外层查找。
	//print(ival);正确，调用print(double)
	//print(3.14);调用print(double)
}

typedef string::size_type st;

string screen(st ht = 24, st wid = 80, char backgrnd = ' ');

//默认参数
string screen(st ht, st wid, char backgrnd) { return ""; }

void default_param(int a, string b);
void default_param(int a, string ="hello"); //正确，添加默认参数
//void default_param(int a, string = "2"); 错误，重复声明默认参数，调用的时候不知道用哪个 ？
void default_param(int a, string b) { cout << a << b << endl; }

string str_test = "hello---";
void test() {

	string str = "hello";
	//void default_param(int a, string b = str);错误，局部变量不能做默认实参，因为编译的时候值不存在
	void default_param(int a, string b = str_test); //正确！str_test编译时值已经存在.

	default_param(4);
}

//内联函数，编译时直接插入调用位置。省去了函数调用开销
inline const string& shortter(const string& s1, const string& s2) {

	return s1.size() < s2.size() ? s1 : s2;
}

//constexpr都是内联函数
constexpr size_t scale() {
	return 42;
}

constexpr size_t scale(size_t cnt) {
	return cnt * 10;
}

int arr1[scale()];
int arr2[scale(1)];
int ii = 1;
//int arr3[scale(ii)];错误，ii是变量，scale(ii)不是常量表达式
