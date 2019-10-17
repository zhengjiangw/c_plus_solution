#include <iostream>
#include <string>
using std::string;
using std::cin; using std::cout; using std::endl; using std::getline;

int main_02_00() {

	string s1; //默认初始化空字符串
	string s2 = s1;//副本, 拷贝初始化
	string s3 = "hiya";//副本 拷贝初始化
	string s4(10, 'c'); //直接初始化

	string s5 = "";
	cout << s5.empty() << endl;

	/*
	while (cin >> s5) {
		cout << s5 << endl;
	}
	*/

	//从cin中读取一行赋值给s1
	/*
	while (getline(cin, s1)) {
		if (!s1.empty() && s1.size() > 10) {
			cout << s1 << endl;
		}
	}
	*/
	auto len = s3.size();
	cout << len << endl;
	cout << s1 << s1.empty() << s1.size() << s1 + s3 << s1[0] << endl;

	string str = "Hello\n";
	string phase = "Hello world";
	string slang = "Hiya";
	cout << (str < phase) << (str < slang) << endl;

	//字符串相加需要保证至少一个是string类型
	//因为历史原因，字符串字面量和string是不同类型，字面量不能直接相加
	string a = "hello", b = "world";
	string c = a + " " + b;
	//string d = "helo" + "world"; 错误, 字面量不能直接相加

	cout << "isalnum" << std::isalnum(a[5]) << endl;

	str = "some string";
	for (auto c : str) {
		cout << c << endl;
	}

	for (auto& c : str) {
		c = std::toupper(c);
	}
	cout << str << str[10] << endl;

	return 0;
}
