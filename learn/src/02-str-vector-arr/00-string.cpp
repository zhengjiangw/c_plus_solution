#include <iostream>
#include <string>
using std::string;
using std::cin; using std::cout; using std::endl; using std::getline;

int main_02_00() {

	string s1; //Ĭ�ϳ�ʼ�����ַ���
	string s2 = s1;//����, ������ʼ��
	string s3 = "hiya";//���� ������ʼ��
	string s4(10, 'c'); //ֱ�ӳ�ʼ��

	string s5 = "";
	cout << s5.empty() << endl;

	/*
	while (cin >> s5) {
		cout << s5 << endl;
	}
	*/

	//��cin�ж�ȡһ�и�ֵ��s1
	/*
	while (getline(cin, s1)) {
		if (!s1.empty() && s1.size() > 10) {
			cout << s1 << endl;
		}
	}
	*/
	auto len = s3.size();
	cout << len << endl;
	cout << s1 << s1.empty() << s1.size() << s1 + s3 << s1[0] << endl;

	string str = "Hello\n";
	string phase = "Hello world";
	string slang = "Hiya";
	cout << (str < phase) << (str < slang) << endl;

	//�ַ��������Ҫ��֤����һ����string����
	//��Ϊ��ʷԭ���ַ�����������string�ǲ�ͬ���ͣ�����������ֱ�����
	string a = "hello", b = "world";
	string c = a + " " + b;
	//string d = "helo" + "world"; ����, ����������ֱ�����

	cout << "isalnum" << std::isalnum(a[5]) << endl;

	str = "some string";
	for (auto c : str) {
		cout << c << endl;
	}

	for (auto& c : str) {
		c = std::toupper(c);
	}
	cout << str << str[10] << endl;

	return 0;
}
