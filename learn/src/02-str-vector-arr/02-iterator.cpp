#include <iostream>
#include <vector>
using namespace std;

int main_02_02() {

	vector<string> v{ "a", "b", "c" };
	vector<int> i{ 1,2,3 };

	//end()ָ��ĩβ��һ��λ�ã�β�������
	//b������ std::vector<std::string>::iterator
	auto b = v.begin(), e = v.end();//���vΪ�գ�begin��endһ������β�������

	auto bc = v.cbegin();
	//*bc = "hiahia"; cbegin()���ܼ����Ƿ���const�����������صĶ���const

	string a = *b; //*b�ǵ�ǰ��ָԪ�ص�����
	*b = "d";
	std::cout << b->size() << (*b).size() << endl; //b->ȡ��ǰ��ָԪ�ص�Ԫ��

	++b; //��ǰ�ƶ�

	b = b + 2;
	b -= 2; //�ƶ�
	cout << e - b << endl; //����Ԫ�� 2�� ��Ȼ֧��><==!=
	for (auto b = v.begin(); b != v.end(); b++) { 
		cout << *b << endl;
	}

	vector<int> arr{ 1,2,3,4,5 };
	auto begin = arr.begin(), end = arr.end();
	auto mid = begin + (end - begin) / 2;
	int source = 50;
	while (mid < end - 1 && *mid != source) {

		if (*mid < source) {
			begin = mid;
		}
		else {
			end = mid;
		}
		mid= begin + (end - begin) / 2;
	}
	if (*mid == source) {
		cout << "found it!" << endl;
	}
	else {
		cout << "not found!" << endl;
	}

	return 0;
}
