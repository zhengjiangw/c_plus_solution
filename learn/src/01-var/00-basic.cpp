#include <iostream>

int c; //�����ں������ⲿ�ı�������ʼ��Ϊ0
int global = 1000;
int main() {
	
	//���û����������ͷ�Ϊ ���������͡��͡�������(void)��
	//�������ͷ�Ϊ�����͡��͡������͡�
	
	unsigned int a = 3;
	bool b = 10; //0Ϊfalse������Ϊtrue
	int i = true; //true:1, false:0
	bool c = false;
	std::cout << a << b << c << i << "a very very long "
		"long string\n";

	wchar_t me = '��';
	std::cout << me << std::endl;

	int units_sold = 0;
	int units_sold_2(0);
	//������Ϊ�б��ʼ������Ӧ�������������У������ڶ�ʧ��Ϣ�ķ��գ�������������
	int units_sold_0 = { 0 }; //int units_sold_0 = { 0.5 }; ����!
	int units_sold_1{ 0 };

	std::cout << c << std::endl;

	//int d; //δ����ʼ����Σ�ա������Ĭ�ϳ�ʼ����������Լ�������
	std::cout << global << std::endl;
	int global = 100; //�������global����
	std::cout << global << std::endl;

	//���ü�����������һ����ֵ���޷��޸ġ���˱����ʼ��

}
