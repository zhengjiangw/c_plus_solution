#include <iostream>

using namespace std;

void arr_and_pointer();
int main() {

	//�������Ҳ���������͵�һ���֣������֪�� arr����Ϊ��int arr[10]
	unsigned cnt = 42;
	constexpr unsigned sz = 3;
	int arr[10]; //����Ĭ�ϳ�ʼ���� int[]��ʼ��Ϊ0
	//string bad[cnt];//����, cnt���ǳ������ʽ
	int* parr[sz]; //����3��int*������ �������Ƕ������������

	//���������ʱ������ƶ����ͣ���������auto�ؼ���

	int ial[sz] = { 0,1,2 }; //�������ܳ����ܳ���
	int a2[] = { 0,1,2 }; //���Ƴ�a2����Ϊ��int a2[3];
	int a3[5] = { 0,1,2 }; //�൱�� {0,1,2,0,0}

	char c1[] = { 'c','+','+' ,'!' };
	char c2[] = "c++"; //char c2[4], �ַ����н�����

	//c1 = c2;//���󣡣��������ֹ�����͸�ֵ
	int* ptrs[10]; //10��int*���͵�����
	int(*Parry)[10]; //Parry��ָ�룬ָ���������͡����麬��10��int
	int(&arrRef)[5] = a3; //arrRef��һ����������ã����麬��5��int
	//int* (&ref)[5] = ..; ref��һ����������ã����麬��5��int*

	arr_and_pointer();
	return 0;
}

//�����ָ��
void arr_and_pointer() {

	//ʹ�������ʱ�򣬱�������һ�㡱�����ת����ָ��
	string nums[3] = { "one", "two", "three" };
	string* p = &nums[0]; //pָ���һ��Ԫ��
	string* p2 = nums; //���ϵȼ�, �ںܶ��õ���������ʱ�򣬱������Զ��滻Ϊָ���һ��Ԫ�ص�ָ��
	cout << (p == p2) << endl; //true

	auto ia2 = nums; //
}
