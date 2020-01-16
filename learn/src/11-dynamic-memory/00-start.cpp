#include <iostream>
#include <memory>
#include <vector>
#include <string>
using namespace std;

//ÿ������ӵ��һ���ڴ�أ���Ϊ�����ɿռ䡱�򡰶ѡ������洢��̬������ڴ�
//��̬������������ɳ���������, ͨ��new��delete����
//new:����ռ䲢����ָ�룻delete:���ܶ�̬����ָ�룬���ٶ����ͷ��ڴ�
//��������ָ������������̬����
//shared_ptr:������ָ��ָ��ͬһ����unique_ptr:��ռ��ָ�����
//���ü���Ϊ0����shared_ptr, unique_ptr�뿪�����򣬾ͻ��Զ��ͷ��Լ�����Ķ���
int main() {

	shared_ptr<string> p1; //Ĭ�ϳ�ʼ����ָ�� p1 == nullptr

	shared_ptr<int> p3 = make_shared<int>(42);
	shared_ptr<string> p4 = make_shared<string>(10, '9');
	shared_ptr<int> p5 = make_shared<int>(); //p5ָ��Ĭ�ϳ�ʼ����int��Ϊ0

	auto p = make_shared<int>(42);
	auto q(p); //p��ֵ��q������,������ʱ�����ü���������
	auto r = make_shared<int>(42);
	r = q; //��r��ֵ��rԭ�������ô������٣�q���ü�������

	//shared_ptr������������ݼ���ָ���������ü���������Ϊ0�������ٶ����ͷ��ڴ�

	int* pi = new int; //piָ��һ��δ��ʼ����int
	string* ps = new string; //ָ��һ����string
	string* ps2 = new string(10, '9');
	int* pi2 = new int(1024); //pi2ָ��Ķ���ֵΪ1024
	vector<int>* pv = new vector<int>{ 0,1,2,3,4 };

	//new����const����
	const int* pic = new const int(1024);
	const string* pcs = new const string;

	int F();
	F();
	return 0;
}

int count_3(int n);

int F() {

	int count = 0;
	int n = 1;
	while (n<=9999)
	{
		count += count_3(n);
		++n;
	}
	cout << "count:" << count << endl;
	return count;

}

int count_3(int n) {

	int count = 0;
	string res = to_string(n);
	for (char ch : res) {
		if (ch == '3')
			++count;
	}
	return count;
}