#include <iostream>
#include <stack>
#include <queue>
#include <vector>

using namespace std;

int main_08_02() {

	//����������˳��������װ��ջ������

	vector<int> v{ 0,1,2 };
	stack<int> sk; //Ĭ��queueʵ��
	stack<int, vector<int>> sk2(v); //����Ϊvectorʵ��

	queue<int> q; //Ĭ��queueʵ��
	priority_queue<int> pq; //Ĭ��vectorʵ��

	return 0;
}
