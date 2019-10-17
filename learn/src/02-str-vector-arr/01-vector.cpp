#include <iostream>
#include <vector>
using std::vector;
using std::string; using std::cout; using std::endl;

int main_02_01() {

	//vector<>是类模板，除引用(引用不是对象)外
	vector<string> svec; //默认初始化，不含任何元素
	vector<int> ivec{ 1,3,5 };
	ivec = { 2,4,6 };
	vector<int> ivec2(ivec); //元素拷贝
	vector<int> ivec3 = ivec;//拷贝

	vector<int> v1(10, -1); //10个-1
	vector<int> v2(10); //10个0
	vector<string> v7{ 10 };//10个元素，10无法初始化，转为元素个数
	vector<string> v8{ 10, "hi" }; //10个hi， 理由同上

	vector<int> v3;
	for (int i = 0; i < 100; i++) {
		v3.push_back(i);
	}

	//同字符串，支持[], ><, == !=, 前提是元素支持比较运算符
	vector<int> v{ 1,2,3,4,5 };
	for (auto& c : v) {
		c++;
	}
	for (auto c : v) {
		cout << c << " ";
	}
	cout << endl;

}
