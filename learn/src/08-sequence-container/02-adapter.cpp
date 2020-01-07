#include <iostream>
#include <stack>
#include <queue>
#include <vector>

using namespace std;

int main_08_02() {

	//适配器，把顺序容器包装成栈，队列

	vector<int> v{ 0,1,2 };
	stack<int> sk; //默认queue实现
	stack<int, vector<int>> sk2(v); //定制为vector实现

	queue<int> q; //默认queue实现
	priority_queue<int> pq; //默认vector实现

	return 0;
}
