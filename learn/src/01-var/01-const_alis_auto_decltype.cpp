#include <iostream>

void top_bottom_const();
void const_expr();
void type_alias();
void type_auto();
void decl_type();
int main_01() {

	//�����������ʼ���������޸�
	const int bufsize = 512;

	//const����������
	const int ci = 1024;
	const int& rl = ci; //��ȷ�����ü����õĶ����ǳ���
	// rl = 42;����, rl�ǳ�������
	//int& r2 = ci; //����, ci�ǳ���,�������ͨ��r2�޸�ֵ

	int i = 42;
	const int& r1 = i; //����
	const int& r2 = 42; //��������
	const int& r3 = i * 8; //��������
	//int& r4 = i * 5; //����
	const int& r5 = r1 * 8;//��������
	//int& r6 = r1 * 8; //����, �ǳ�������
	
	double dval = 3.14;
	const int& d = dval; //3

	//ָ������ָ�룬���ܸı���ָ�����ֵ
	const double pi = 3.14;
	//double* ptr = &pi; //����ֻ��ͨ������ָ��
	const double* ptr = &pi; //�����������ʹ��ָ������ָ��(��Ϊ������ͨ��ָ���޸�ֵ)
	//*ptr = 42; //����, ���ܸı�ֵ
	ptr = &dval; //ָ������ָ�����ָ��ǳ�������

	//constָ�룬ָ��Ҳ�Ƕ��󣬳������󣬲������޸���ָ��Ķ���
	int errNum = 0;
	int another = 0;
	int* const curErr = &errNum; //curErr��һֱָ��errNum�����ɸı�
	//curErr = &another; ���󣬲��ܸı���ָ��Ķ���
	*curErr = 100; //��ȷ,���Ըı���ָ�����ֵ
	const double pi2 = 3.14159;
	const double* const pi2_p = &pi2; //pi2_p��ָ��������ĳ���ָ�롣

	top_bottom_const();
	const_expr();
	type_alias();
	type_auto();
	decl_type();
	
	return 0;
}

void top_bottom_const() {
	//����const:����(����ָ��)�Ǹ�����,���ܸı�ֵ
	//�ײ�const:ָ����ָ������һ���������������ö��ǵײ�const
	//ָ�����ͼȿ����Ƕ���const�ֿ����ǵײ�const

	int i = 0;
	const int ci = 42;//����const�����ܸı�cr��ֵ
	int* const p1 = &i; //����const�����ܸı�p1��ֵ
	const int* p2 = &ci; //�ײ�const��p2ֵ�ɱ䣬����ͨ��ָ��ı���ָ�����ֵ
	const int* const p3 = p2; //���ǵײ�constҲ�Ƕ���const
	const int& r = ci; //�������ö��ǵײ�const

	//int* p = p3; //����, p3�����ײ�const
	p2 = p3;//��ȷ��p2,p3�������ײ�const
	p2 = &i; //��ȷ, ��const����ת��Ϊconst
	//int& r = ci; ����
	const int& r2 = i;
}

int j = 0;
constexpr int i = 42;
void const_expr() {

	//�������ʽ�ڱ�����̾��ܵõ����, �м��������Ҫ�������ʽ
	const int max_files = 20; //�ǳ������ʽ
	const int limit = max_files + 1; //��
	int staff_size = 27;//����
	int get_size();
	const int sz = get_size(); //����, get_size()����ʱ��֪��
	std::cout << sz << std::endl;

	//����Ϊconstexprһ����һ���������ұ����ó������ʽ��ʼ��
	constexpr int mf = 20; //20�ǳ������ʽ
	constexpr int lim = mf + 1; //mf+1�ǳ������ʽ
	//constexpr int limit = staff_size + 1; staff_size�Ǳ���
	//constexpr int sz = get_size(); get_size()��������Ϊconstexpr����ȷ

	//constexpr �������ʽ��ֵ��������ʱ�����֪�����, �������ͣ����ú�ָ�롣
	//����������ʹ��constexpr����(��Ϊ�޷������ʱ��֪��ֵ)���ַ���, ��
	//constexpr���ε��ֳ�Ϊ����������

	const int* p = nullptr; //ͬ��const int* p = 0, p��һ��ָ������ָ��
	constexpr int* q = nullptr; //q��һ��ָ�����ĳ���ָ��

	//constexpr����Ϊ����ָ�룬const����ָ������ָ��
	constexpr const int* p1 = &i; //i�����ں�����֮�⣬����ʱ��ȷ��ֵ
	constexpr int* p2 = &j; //ͬ��
}


void type_alias() {

	//��ͳ����
	typedef double wages; //���ͱ���typedef
	typedef wages base, * p; //p��double*ָ�����ͱ���
	base b = 3;
	p pe = &b;

	//�±�׼using
	using hourly = wages;
	using doub = double;
}

void type_auto() {

	auto ii = 0, *p = &ii;
	//auto sz = 0, pi = 3.14; ����, sz��pi���Ͳ�һ�£�һ������ֻ����һ��������������
	int i = 0, &r = i;
	auto a = r;//a��int���Ͷ���

	//autoһ�����Ե�����const�������ײ�const
	const int ci = i, & cr = ci;
	auto b = ci; //int b
	auto c = cr; //intc cr�Ǳ��������õĶ����Ƕ���const 
	auto d = &i; //int* d
	auto e = &ci; //const int* e

	//��ϣ���Ƕ���const����Ҫ�ֶ�ָ��
	const auto f = ci; //const int f;
	
	auto& g = ci; //const int& g;
	const auto& h = 42; //const int& h;
}

void decl_type() {

	//����ͨ����ָ����ı�����ֻ��decltype����
	const int ci = 0, &cj = ci;
	decltype(ci) x = 0; //const int x;
	decltype(cj) y = x; //const int& y;
	//decltype(cj) z; cj������, �����ʼ��

	int i = 42, *p = &i, &r = i;
	decltype(r + 0) b; //int b;
	//decltype(*p) c; ��ָ����������int&, ���c���뱻��ֵ
	//decltype((i)) d; int& d;�����ʼ��
	decltype(i) e; //int e;

	//decltype((var))��Զ����������
	//decltype(var)ֻ�е�var�����õ�ʱ�������������
}


int get_size() {
	int a = 0;
	return ++a;
}
