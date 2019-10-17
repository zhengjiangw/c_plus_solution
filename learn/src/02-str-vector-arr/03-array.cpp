#include <iostream>
#include <vector>

using namespace std;

void arr_and_pointer();
void multi_arr();
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

	int int_arr[] = { 0,1,2,3,4,5 };
	vector<int> ivec(begin(int_arr), end(int_arr));

	arr_and_pointer();
	multi_arr();
	return 0;
}

//�����ָ��
void arr_and_pointer() {

	//ʹ�������ʱ�򣬱�������һ�㡱�����ת����ָ��
	string nums[3] = { "one", "two", "three" };
	string* p = &nums[0]; //pָ���һ��Ԫ��
	string* p2 = nums; //���ϵȼ�
	cout << (p == p2) << endl;

	auto ia2(nums); //string* ia2;
	//decltype���᲻�ᷢ��ת��
	decltype(nums) ia3; //string ia3[3];

	//ָ��Ҳ�ǵ�������֧�����е���������!!!
	int ia[5] = { 0,1,2,3,4 };
	int* beg = begin(ia), * e = end(ia);
	while (beg < e) {
		cout << *beg << " ";
		beg++;
	}

	int i = ia[2]; //2
	int* pa = ia; //pָ��ia��Ԫ��
	i = *(pa + 2); //�ȼ���ia[2]

	int* pp = &ia[2];//ppָ������� 2
	int j = pp[1]; //�����ƶ�һ�� 3
	int k = pp[-2]; //�������� 0
	cout << "right" << j << "left" << k << endl; //3, 0


	int i1 = 1, i2 = 2, *p1 = &i1, *p3 = &i2;
	cout << (p1 == p3) << endl;
}

void multi_arr() {

	//��ά���飬��Ϊ���������
	int ia[3][4]; //��СΪ3�����飬ÿ��Ԫ����4��Ԫ�ص�����

	//ia = { {0,1,2,3},{4,5,6,7},{8,9,10,11} };���鲻����ֵ
	int ia1[3][4] = { {0,1,2,3},{4,5,6,7},{8,9,10,11} };
	int ia2[3][4] = { {0,1,2,3},{4,5,6,7},{8,9,10,11} };
	int ia3[3][4] = { 0,1,2,3,4,5,6,7,8,9,10,11 }; //���ϵȼ�
	int ia4[3][4] = { {0},{1},{2} }; //��ʼ��ÿһ�е�һ��Ԫ��
	int ia5[3][4] = { 0,1,2,3 }; //��ʼ����һ��

	int(&row)[4] = ia1[0]; //row����ia1��һ��
	size(ia);

	const size_t rowcnt = 3, colcnt = 4;
	int ia6[rowcnt][colcnt];
	for (size_t i = 0; i < rowcnt; i++) {
		for (size_t j = 0; j < colcnt; j++) {
			ia6[i][j] = i * colcnt + j;
		}
	}

	for (auto& row : ia6) { //��㲻��auto&�Ļ���row�ᱻתΪָ��
		for (auto col : row) {
			cout << col << "\t";
		}
		cout << endl;
	}

	//int ia[3][4] ��Ϊ�Ƕ�ά���飬iaָ���˵�һ��(Ԫ��)����һ������
	int(*p)[4] = ia;
	p = &ia[2]; //pָ�������һ������
	int* pa = ia[2]; //paָ�������һ�е�һ��Ԫ��
}
