#include <iostream>

int c; //�����ں������ⲿ�ı�������ʼ��Ϊ0
int global = 1000;
int main_00() {
	
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

	//int d; //δ����ʼ����Σ�գ������Ĭ�ϳ�ʼ����������Լ�������
	std::cout << global << std::endl;
	int global = 100; //�������global����
	std::cout << global << std::endl;

	//���ü�����(���Ƕ���)������һ����ֵ���޷��޸ġ���˱����ʼ��
	// refg, pΪ���ã�gΪint����
	int& refg = global, & pp = units_sold, g = global;
	refg = 200;
	std::cout << refg << global << std::endl;

	//ָ�뱾�����һ������/����
	int val = 42;
	int* null = nullptr; //��ָ�룬��ָ���κζ���, ��Ч�ڣ�int* p1 = 0;
	//��ָ��Ϊ0�����������flase
	if (!null) {
		std::cout << "null pointer" << std::endl;
	}
	int* p; //δ��ʼ��
	int* q = &val;

	// ָ�븳ֵ, p,q��ָ��val
	p = &val;
	p = q;

	p == q; //ָ��Ƚϣ���������ͬ�ſɱȽ�(==, !=)

	*p = 0; //�ı�p��ָ�����ֵ

	//void* ָ�룬�ɴ���������ĵ�ַ
	double pi = 3.14, *pd = &pi;
	void* pi_p = &pi; //���double*
	pi_p = q; //���int*
	// std::cout << *pi_p << std::endl; void*���Ͳ��ɷ��ʶ���
	pi_p == q; //���ԱȽϺ͸�ֵ

	// i:int��i_p:int*��i_r:int����
	int ii = 1024, *i_p = &i, &i_r = i;

	//����ָ��
	int m = 42;
	int* m_p;
	int*& r = m_p; //r��һ��ָ��(m_p)������, �����������
	r = &m; //r��m_p��ָ����m, r��һ��ָ�������
	*r = 0;
	std::cout << m << *m_p << std::endl;

	return 0;

}

