#include <iostream>
#include <map>
#include <set>
#include <unordered_map>
#include <unordered_set>
#include <utility>

using namespace std;

// 对于有序容器，必须定义关键字比较的方法

void unsort_container();

int main() {

	map<string, size_t> word_count;
	set<string> exclude = { "the", "is", "are" };
	string word;
	/*while (cin >> word) {
		if (word == "quit")
			break;
		if (exclude.find(word) != exclude.end())
			continue;
		word_count[word]++;
	}*/

	word_count["dummpy"] = 0;
	for (const auto &w : word_count) {
		cout << w.first << " occurs " << w.second << " times!" << endl;
	}

	// pair保存两个数据成员，类似容器, 数据成员是public的，直接用first,second访问, <=, >, ==, !=
	pair<string, size_t> anon; //保存string, size_t, 默认初始化保存一对空字符串和0
	pair<string, string> author{"James", "Joyce"}; //自定义初始化
	//pair<string, string> author("James", "Joyce"); //自定义初始化
	auto expPair = make_pair(string("haha"), 1); //生成pair对象
	cout << anon.first << anon.second << author.first << author.second << endl;

	set<string>::value_type v1; //string
	set<string>::key_type v2; //string
	map<string, int>::key_type v3; //string
	map<string, int>::mapped_type v4; //int
	map<string, int>::value_type v5; // pair<const string, int>

	//解引用“关联容器”的迭代器，会得到pair类型
	auto map_it = word_count.begin();
	cout << map_it->first << " " << map_it->second << endl;
	//map_it->first = "not dummy"; 错误，关键字为const
	++map_it->second; //map_it为pair类型，只改变了pair中的second, map中的value没变
	cout << map_it->second << " " << word_count["dummy"] << endl; //1 0

	//set中的iterator和const_iterator都只允许只读访问，不可修改
	set<int> iset = { 0,1,2,3,4,5 };
	set<int>::iterator set_it = iset.begin(); //遍历set, map类似(map迭代是pair<>)
	while (set_it != iset.end()) {
		//*set_it = 42; 错误, set中的关键字是只读的
		cout << *set_it << endl;
		++set_it;
	}

	//set和map insert返回pair<迭代器, bool(成功?)>, 若元素存在，则什么都不做
	vector<int> ivec = { 2,4,2,4,3 };
	set<int> set2;
	set2.insert({ 2,4,2 });
	set2.insert(ivec.begin(), ivec.end());

	//map insert的是pair
	word_count.insert({ "word", 1 }); //pair可以用列表赋值
	word_count.insert(word_count.begin(), word_count.end());

	//对于关联容器(map,set), 删除元素erase(), 类似顺序容器接收迭代器或迭代器对，额外接收关键字参数
	cout << word_count.erase("word") << endl; //返回删除的个数：1

	//map和unordered_map容器提供了[]和at, set没有，因为set元素本身就是关键字
	word_count["Anna"] = 1; //自动创建Anna--1; 首先初始化Anna--0, 然后根据右替换为1
	//map[key]:若key不存在，则自动创建并初始化；map.at(key):若key不存在，报错
	word_count["Anna"] = 2;
	cout << word_count["Anna"] << word_count.at("Anna") << endl; //只有非const元素可以使用[]运算符或at

	//访问元素
	if (iset.find(1) == iset.end())
		cout << "not found" << endl;
	else
		cout << "find it count:" << iset.count(1) << endl;

	return 0;

	// low_bound()和upper_bound()不支持无序关联容器, 一般用在可重复容器
	iset.lower_bound(5); //返回第一个不小于5的迭代器
	iset.upper_bound(5); //返回第一个大于5的迭代器
	iset.equal_range(5); //返回pair,等于5的范围


}

// 无序容器, 使用hash函数和关键字的==运算符
void unsort_container() {

	unordered_map<string, size_t> word_count;
	word_count.insert({"dummy", 0});

	//标准库为内置类型(包括指针)提供了hash模板, string和智能指针类型定义了hash

}