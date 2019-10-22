#include <iostream>
using namespace std;

size_t count_calls() {
	static size_t count = 0; //�ֲ���̬����,��һ���õ�����û�г�ʼ����Ĭ�ϳ�ʼ�������ܺ�������Ӱ��
	return ++count;
}

void resnet(int& i) { //��������, ���Ա��⿽��
	i = 0;
}

void fcn(const int i) {} //����const�����ԣ�����const int i��int i������
//void fcn(int i) {} ��Ϊ��ͬʱ���Դ�int i�����Զ����ظ���

void sum(initializer_list<int> eles);

int main() {

	string str = "hello";
	const char* ch = "helo";
	cout << *ch << endl;
	size_t count = 0;
	for (int i = 0; i < 5; i++) {
		count = count_calls();
	}
	cout << count << endl;

	int j = 42;
	resnet(j);
	cout << j << endl;

	initializer_list<int> eles{ 1,2,3 };
	initializer_list<int> aug = eles; //����
	sum(aug);
	sum({ 1,2,3,4,5 });

	return 0;
}

int a = 3;
int fact(int a) {
	return a++;
}

//�ȼۣ��������֣�ֻ����ǲ���const int*
void print(const int*);
void print(const int[]);//���鲻����ֵ�������Int*
void print(const int[5]); //[5]ʵ���в��ϸ�У�飬ֻ��������ֵ
void print(const int(&)[5]); //��������ã����봫��int[5]���͡�

void print(const int* a) {}

//initializer_list<>�ʺϴ���������ͬ������δ֪�Ķ���
void sum(initializer_list<int> eles) {
	
	int sum = 0;
	for (auto beg = eles.begin(); beg != eles.end(); ++beg) {
		sum += *beg;
		//(*beg)++; Ԫ�ض���ֻ���ģ������޸ġ�
	}
	cout << "size:" << eles.size() << ", sum:" << sum << endl;
}
