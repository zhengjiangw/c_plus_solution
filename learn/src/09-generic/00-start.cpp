#include <iostream>
#include <algorithm>
#include <numeric>
#include <vector>
#include <iterator>
using namespace std;

// 泛型算法作用与各种容易和内置数组类型。使用迭代器，不依赖于容器
// 但算法依赖于元素类型的操作。如支持==, < 等操作。
// 可能改变值和移动元素，但永远不会添加或删除元素。
int main_09_00() {

	vector<int> vec{ 0,1,2,3 };
	
	int var = 31;
	auto ite = find(vec.begin(), vec.end(), var);
	if (ite == vec.end()) {
		cout << "not found" << endl;
	}
	else {
		cout << *ite << endl;
	}

	int sum = accumulate(vec.begin(), vec.end(), 0);
	cout << "sum=" << sum << endl;

	//string sumStr = accumulate(vec.cbegin(), vec.cend(), string("")); 错误, 字符串不能和整数相加
	vector<string> strs{ "a","b","c","d" };
	// string sumStr = accumulate(strs.begin(), strs.end(), ""); ""是const char*类型，没有加操作
	string sumStr = accumulate(strs.begin(), strs.end(), string(""));

	//第二个长度至少应和前面范围一样多。元素支持==
	vector<string> ano{ "1","2" };
	equal(strs.cbegin(), strs.cbegin() + 2, ano.cbegin());

	//填充为0.写操作不会改变容器的大小。原序列大小至少不小于写入数据个数
	fill(vec.begin(), vec.end(), 9);

	vector<int> vw{ 0,1,2 };
	fill_n(vw.begin(), vw.size(), 9);
	//fill_n(vw.begin(), 99, 9); 错误，99大于容器个数

	auto endIterator = back_inserter(vw);
	*endIterator = 100; //赋值运算符会调用push_back()
	//fill_n是迭代器赋值，back_inserter刚好会调用push_back()，因此不限制数量。
	fill_n(back_inserter(vw), 10, 9);

	int a1[] = { 0,1,2,3,4,2,4,3 };
	int a2[sizeof(a1) / sizeof(*a1)];
	// a2的元素至少和拷贝个数一样多。 ret指向插入后元素
	int* ret = copy(cbegin(a1), cend(a1), a2); 

	replace(begin(a1), end(a1), 2, 6); //把2替换为6, a1内容改变

	vector<int> result; //result是a1的拷贝，其中2被替换为6，a1内容不变
	replace_copy(begin(a1), end(a1), back_inserter(result), 2, 6);
	cout << result.size() << endl;

	vector<string> words{ "the","quick","red","fox","jumps","over","the","slow","the","turtle" };
	sort(words.begin(), words.end());
	// unique并不删除元素，把重复元素移到最后，返回指向第一个元素，若没有重复，返回end()
	auto repeatIte = unique(words.begin(), words.end());
	words.erase(repeatIte, words.end());
	cout << words.size() << endl;
	
	void test_predicate();
	test_predicate();

	return 0;
}

bool isShorter(const string& str1, const string& str2) {

	return str1.size() < str2.size();
}

void test_predicate() {

	vector<string> words{ "the","quick","red","fox","jumps","over","the","slow","the","turtle" };
	sort(words.begin(), words.end(), isShorter);

	//lambda 格式：[capture list] (parameter list) -> return type {function body}
	// capture list捕获列表，值lambda内定义的局部变量列表;
	auto f = [] {return 42; };
	cout << f() << endl;
}