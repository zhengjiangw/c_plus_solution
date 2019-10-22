#include <iostream>
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

int main() {

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
