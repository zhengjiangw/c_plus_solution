#include <iostream>
#include <vector>
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

char& get_val(const string&, string::size_type);
void test();
int main_05_00() {

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

	const string strs = "hello";
	//���ص������ã�������Ϊ��ֵʹ��
	get_val(strs, 0) = 'b';
	cout << strs << endl;

	test();

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

//�������õĺ���������Ϊ��ֵʹ��
char& get_val(const string& str, string::size_type ix) {
	
	//�˴�û�б�Ҫ���ɰ�str�����string&���ɣ�������Ҫ�Ǹ�ϰ��const_cast<>
	return const_cast<char&>(str[ix]);
}

vector<string> process() {

	//vector<string> temp = { "a", "b", "c" };

	//���Է����б�����ʼ��vector
	//return {};
	return { "ab", "cd", "ef" };
}

//���鲻����������˲��ܷ������飬�����Է������ú�ָ��
//����ָ��int[5]��ָ��, ��������
int(*func1(int idx))[5];

//Ч��ͬ�ϣ���������
auto func2(int idx) -> int(*)[5];

int arr[5] = {};
//Ч��ͬ�ϣ���Ϊdecltype�����Զ�תָ�룬����ټ�һ��*
decltype(arr) *func3(int idx);

void lookup(string str);
void lookup(const string str); //����const�����ԣ�������ظ�����

void lookup(string* str);
//���ǵײ�const, ��˲������ظ�����, ���ݴ�����������;��������ĸ�������Ҳ����
void lookup(const string* str);

void print(const string& str);
void print(double);
void fooBar(int ival) {

	void print(int);
	//print("value");
	//c++����ֲ��ҷ��������ͼ��֮ǰ��"print", �����ҵ���print(int)��
	//Ȼ���ټ���ܷ���á�ע:�����������ڵ�ǰ��������ң��Ҳ�����ȥ�����ҡ�
	//print(ival);��ȷ������print(double)
	//print(3.14);����print(double)
}

typedef string::size_type st;

string screen(st ht = 24, st wid = 80, char backgrnd = ' ');

//Ĭ�ϲ���
string screen(st ht, st wid, char backgrnd) { return ""; }

void default_param(int a, string b);
void default_param(int a, string ="hello"); //��ȷ�����Ĭ�ϲ���
//void default_param(int a, string = "2"); �����ظ�����Ĭ�ϲ��������õ�ʱ��֪�����ĸ� ��
void default_param(int a, string b) { cout << a << b << endl; }

string str_test = "hello---";
void test() {

	string str = "hello";
	//void default_param(int a, string b = str);���󣬾ֲ�����������Ĭ��ʵ�Σ���Ϊ�����ʱ��ֵ������
	void default_param(int a, string b = str_test); //��ȷ��str_test����ʱֵ�Ѿ�����.

	default_param(4);
}

//��������������ʱֱ�Ӳ������λ�á�ʡȥ�˺������ÿ���
inline const string& shortter(const string& s1, const string& s2) {

	return s1.size() < s2.size() ? s1 : s2;
}

//constexpr������������
constexpr size_t scale() {
	return 42;
}

constexpr size_t scale(size_t cnt) {
	return cnt * 10;
}

int arr1[scale()];
int arr2[scale(1)];
int ii = 1;
//int arr3[scale(ii)];����ii�Ǳ�����scale(ii)���ǳ������ʽ
