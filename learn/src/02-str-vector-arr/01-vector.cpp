#include <iostream>
#include <vector>
using std::vector;
using std::string; using std::cout; using std::endl;

int main_02_01() {

	//vector<>����ģ�壬������(���ò��Ƕ���)��
	vector<string> svec; //Ĭ�ϳ�ʼ���������κ�Ԫ��
	vector<int> ivec{ 1,3,5 };
	ivec = { 2,4,6 };
	vector<int> ivec2(ivec); //Ԫ�ؿ���
	vector<int> ivec3 = ivec;//����

	vector<int> v1(10, -1); //10��-1
	vector<int> v2(10); //10��0
	vector<string> v7{ 10 };//10��Ԫ�أ�10�޷���ʼ����תΪԪ�ظ���
	vector<string> v8{ 10, "hi" }; //10��hi�� ����ͬ��

	vector<int> v3;
	for (int i = 0; i < 100; i++) {
		v3.push_back(i);
	}

	//ͬ�ַ�����֧��[], ><, == !=, ǰ����Ԫ��֧�ֱȽ������
	vector<int> v{ 1,2,3,4,5 };
	for (auto& c : v) {
		c++;
	}
	for (auto c : v) {
		cout << c << " ";
	}
	cout << endl;

}
