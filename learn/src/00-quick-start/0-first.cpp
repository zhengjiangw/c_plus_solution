#include <iostream>

int main_first() {
	
	std::cout << "please input two nums" << std::endl;
	int v1, v2;
	std::cin >> v1 >> v2;
	int v3 = v1 + v2;

	// "<<"�������ֵ����Ϊostream����,���ض������ʿ�������ʹ��<<�������
	// ">>"��������ƣ� ���岻ͬ������������������ʵ��֧�ֶ�����
	std::cout << "v1+v2=" << v3 << std::endl;

	int sum = 0, i = 0;
	while (i <= 10) {
		sum += i;
		i++;
	}
	std::cout << "1+2+3...+10=" << sum << std::endl;

	sum = 0;
	//i��������ֻ������for�����
	for (int j = 0; j <= 10; j++) {
		sum += j;
	}
	std::cout << "1+2+3...+10=" << sum << std::endl;

	sum = 0;
	int value = 0;
	// cin>>value�������ļ�������������Ч�ַ�, istream������Ч, ����Ϊ��
	while (std::cin >> value) {
		sum += value;
	}
	std::cout << "Sum is :" << sum << std::endl;

	return 0;
}
