#include <iostream>
#include <vector>
#include <list>
#include <forward_list>
#include <array>
using namespace std;

/*
 vector:可变大小数组
 string:可变大小数组(char)
 array:元素不可变固定大小数组, 不能添加或删除元素
 list:双向链表
 forward_list:单向链表,为了性能考虑，没有size操作
 deque:双端队列,快速访问，头尾插入删除快
*/

int main_08_00() {

	vector<int> v{ 1,2,3 };

	auto ite = v.begin(); //v是const的时候返回const_iterator<>
	list<string> s = { "a", "b", "c" };
	forward_list<double> ch(v.begin(), v.end()); //用迭代器初始化只要元素可以转换成目标类型就可以
	vector<int> vs(v); //用另一个容器初始化
	array<int, 5> arr{ 0,1,2 }; //{0,1,2,0,0}
	array<int, 5> a2 = arr; //array可以赋值
	//array<int, 3> a3 = arr;错误，类型不同

	array<int, 3> a3{0,1,2};
	// assign()元素全部替换，因此传递的迭代器不能指向自身,迭代器、引用和指针失效
	v.assign(a3.begin(), a3.end()); //assign()可以不同类型
	v.assign(3, 99); //替换为3个99

	//除string外，swap后元素不会发生交换
	v.swap(vs); //元素交换(只是交换数据结构，没有拷贝和赋值), 类型需要相同，速度比赋值快得多
	//交换两个arr，会真正"交换"元素
	swap(arr, a2);

	//所有有序容器都支持<,>=,==,!=。和string类似,类型需相同,且元素支持比较
	vector<int> v1 = { 1,3,5,7,9 }, v2 = { 1,3,5 };
	cout << (v1 > v2) << endl; //true

	void operators();
	operators();

	return 0;
}

void operators() {
	//除array外，其他容器都可以动态添加或删除元素

	//除array, forward_list，都支持push_back
	vector<string> strs;
	strs.push_back("abc");

	//list, forward_list,dequeue支持push_front
	list<int> ilist;
	ilist.push_front(1);

	//除array， 都支持insert, insert(0,..)相当于push_front.指定位置之前
	//返回新插入的第一个元素的迭代器
	vector<string> svec;
	list<string> slist;
	string str;
	slist.insert(slist.begin(), "Hello");
	svec.insert(svec.begin(), "Hello");
	str.insert(str.begin(), 'H');
	cout << str << endl;

	svec.insert(svec.end(), 10, "Anna"); //插入10个"Anna"

	vector<string> v = { "abc", "def", "ghi" };
	slist.insert(slist.begin(), v.end() - 2, v.end());//迭代器范围不能指向被insert对象

	//和insert对应，有emplace, 直接在容器内存中创建对象
	vector<vector<int>> vv;
	vv.emplace_back(3, 99); //(3, 99)是vector<int>的一个构造函数
	cout << vv.size() << vv.at(0)[2] << endl;

	string& fs1 = *slist.begin();
	//所有顺序容易都有front()指向第一个元素引用
	string& fs2 = slist.front();
	//除forward_list都有back()指向最后一个元素引用
	string& fs3 = slist.back();

	//提供“快速随机访问”的都支持[]运算符和at(), 对于下标越界,at()会抛出异常
	//cout << v[10] << endl;
	//cout << v.at(10) << endl;
	
	array<int, 5> arr{ 1,2,3,4,5 };
	forward_list<int> flst(arr.begin(), arr.end());

	//pop_back()删除尾，array,forward_list不支持
	//pop_front()删除头, array,vector和string不支持
	fs1.pop_back();
	flst.pop_front();

	//erase()除array外都支持, 返回后一个迭代器位置
	v.erase(v.begin() + 1);
	v.erase(v.begin(), v.end());
	v.clear();

	flst = { 0,1,2,3,4,5 };
	auto prev = flst.before_begin();
	auto curr = flst.begin();
	while (curr != flst.end()) {
		if (*curr % 2 == 0) {
			curr = flst.erase_after(prev);
		}
		else {
			prev = curr;
			++curr;
		}
	}

	vector<int> vis{ 1,2 };
	auto ite = vis.insert(vis.begin() + 1, 3, 0);
	vis.insert(ite, 3, 9);
	for (auto v : vis) {
		cout << v << " ";
	}
	cout << endl;
}
