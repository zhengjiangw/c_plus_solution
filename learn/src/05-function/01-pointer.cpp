#include <iostream>
using namespace std;

// ����ָ��ָ��ĳ�����ͣ����������ɷ���ֵ���β����͹�ͬ�������ͺ������޹�
bool lengthCompare(const string s1, const string& s2);
bool lengthCompare(const string s1, const string& s2) {
	return s1.size() > s2.size();
}

void ff(int*) {};
void ff(unsigned int) {};
void (*pf1)(unsigned int) = ff; //���뾫ȷƥ��
//void(&pf2)(int) = ff;���󣬱��뾫ȷƥ��

//����ָ���βΣ��βο������Ǻ������ͣ�ʵ���ϵ�������ָ��ʹ��, �ȼ�����
void useBigger(const string& s1, const string& s2, bool pf(const string&, const string&));
void useBigger(const string& s1, const string& s2, bool (*pf)(const string&, const string&)) {
	cout << pf(s1, s2) << endl;
}

typedef decltype(lengthCompare) Func; //Func�Ǻ�������
typedef decltype(lengthCompare)* FuncP; //FuncP�Ǻ���ָ��
//�ȼ�����, �򻯺��
void useBigger(const string&, const string&, Func);
void useBigger(const string&, const string&, FuncP);

//���غ���ָ��, �������Ͳ����Զ��Ѻ�����ת��Ϊָ�룬�����Ҫ��ʽ����
using F=int(int*, int);//F�Ǻ�������
using PF = int(*)(int*, int);//PF�Ǻ���ָ��
//F f1(int); ���󣬲������غ���
PF f1(int);
F* f1(int); //��ȷ������F*������ָ�롣
int (*f1(int))(int*, int);//ֱ������
auto f1(int)->int(*)(int*, int); //��������

int main_05_01() {

	//�Ѻ������滻��
	bool (*pf)(const string, const string&); //û�г�ʼ��
	pf = lengthCompare;
	pf = &lengthCompare;// ���ϵȼۣ��Ѻ�������Ϊֵʹ��ʱ���Զ�ת��Ϊָ��

	bool b1 = pf("helo", "hello");
	bool b2 = (*pf)("helo", "hello");
	bool b3 = lengthCompare("helo", "hello"); //�ȼ۵���

	return 0;
}
