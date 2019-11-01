#include <iostream>
using namespace std;

class ConstRef {
public:
	//���캯����һ��ʼ����ʼ��������ˡ���˸����������ó�ʼ��ֻ������
	ConstRef() :ConstRef(0) {} //ί�й��캯��
	ConstRef(int i):ci(i),ri(i) { this->i = i; }
	string desc = "ConstRef";
	
private:

	//��Ա��ʼ��˳��ֻ�͡�����˳���йأ��빹�캯���еġ���д˳���޹ء�
	int i;
	const int ci;
	int& ri;
};

class Account {

	//��ľ�̬��Ա�������޹أ�������ͨ��������ʡ�
	//static�ؼ���ֻ�ܳ���������
public:
	void calculate() { amount += amount * interestRate; }
	static double rate() { return interestRate; }
	static void rate(double rate);

private:
	string owner;
	double amount;

	//����������ⲿ��ʼ��ÿ����̬���ݳ�Ա
	static double interestRate;
	//constexpr���������ڲ�����
	static constexpr int period = 30;
	static double initRate();
};

void Account::rate(double newrate) {
	interestRate = newrate;
}
double Account::interestRate = Account::initRate();
double Account::initRate() {
	return 0.75;
}

class Bar {
public:
	
private:
	static Bar mem1; //�������֮ǰ����̬���Ϳ���Ϊ����ȫ����
	Bar* mem2; //ָ�����Ϊ����ȫ����
	Bar& mem3; //���ÿ�����Ϊ����ȫ����
	//Bar mem4;
	Bar get() { return *this; }; //�������Ϳ���Ϊ����ȫ����
	static const char background;
};


int main_06_02() {

	ConstRef arr[2];
	cout << arr[0].desc << endl;

	double r = Account::rate();
	Account ac1, * ac2 = &ac1;
	r = ac1.rate();
	r = ac2->rate();
	cout << r << endl;

	return 0;
}
