#include <iostream>
#include <vector>
using namespace std;

int main_02_02() {

	vector<string> v{ "a", "b", "c" };
	vector<int> i{ 1,2,3 };

	//end()指向末尾后一个位置：尾后迭代器
	//b的类型 std::vector<std::string>::iterator
	auto b = v.begin(), e = v.end();//如果v为空，begin和end一样都是尾后迭代器

	auto bc = v.cbegin();
	//*bc = "hiahia"; cbegin()不管集合是否是const，迭代器返回的都是const

	string a = *b; //*b是当前所指元素的引用
	*b = "d";
	std::cout << b->size() << (*b).size() << endl; //b->取当前所指元素的元素

	++b; //向前移动

	b = b + 2;
	b -= 2; //移动
	cout << e - b << endl; //相差几个元素 2， 必然支持><==!=
	for (auto b = v.begin(); b != v.end(); b++) { 
		cout << *b << endl;
	}

	vector<int> arr{ 1,2,3,4,5 };
	auto begin = arr.begin(), end = arr.end();
	auto mid = begin + (end - begin) / 2;
	int source = 50;
	while (mid < end - 1 && *mid != source) {

		if (*mid < source) {
			begin = mid;
		}
		else {
			end = mid;
		}
		mid= begin + (end - begin) / 2;
	}
	if (*mid == source) {
		cout << "found it!" << endl;
	}
	else {
		cout << "not found!" << endl;
	}

	return 0;
}
