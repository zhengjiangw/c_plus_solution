#include <iostream>
#include <algorithm>
#include <numeric>
#include <vector>
#include <iterator>
using namespace std;

// �����㷨������������׺������������͡�ʹ�õ�������������������
// ���㷨������Ԫ�����͵Ĳ�������֧��==, < �Ȳ�����
// ���ܸı�ֵ���ƶ�Ԫ�أ�����Զ������ӻ�ɾ��Ԫ�ء�
int main_09_00() {

	vector<int> vec{ 0,1,2,3 };
	
	int var = 31;
	auto ite = find(vec.begin(), vec.end(), var);
	if (ite == vec.end()) {
		cout << "not found" << endl;
	}
	else {
		cout << *ite << endl;
	}

	int sum = accumulate(vec.begin(), vec.end(), 0);
	cout << "sum=" << sum << endl;

	//string sumStr = accumulate(vec.cbegin(), vec.cend(), string("")); ����, �ַ������ܺ��������
	vector<string> strs{ "a","b","c","d" };
	// string sumStr = accumulate(strs.begin(), strs.end(), ""); ""��const char*���ͣ�û�мӲ���
	string sumStr = accumulate(strs.begin(), strs.end(), string(""));

	//�ڶ�����������Ӧ��ǰ�淶Χһ���ࡣԪ��֧��==
	vector<string> ano{ "1","2" };
	equal(strs.cbegin(), strs.cbegin() + 2, ano.cbegin());

	//���Ϊ0.д��������ı������Ĵ�С��ԭ���д�С���ٲ�С��д�����ݸ���
	fill(vec.begin(), vec.end(), 9);

	vector<int> vw{ 0,1,2 };
	fill_n(vw.begin(), vw.size(), 9);
	//fill_n(vw.begin(), 99, 9); ����99������������

	auto endIterator = back_inserter(vw);
	*endIterator = 100; //��ֵ����������push_back()
	//fill_n�ǵ�������ֵ��back_inserter�պû����push_back()����˲�����������
	fill_n(back_inserter(vw), 10, 9);

	int a1[] = { 0,1,2,3,4,2,4,3 };
	int a2[sizeof(a1) / sizeof(*a1)];
	// a2��Ԫ�����ٺͿ�������һ���ࡣ retָ������Ԫ��
	int* ret = copy(cbegin(a1), cend(a1), a2); 

	replace(begin(a1), end(a1), 2, 6); //��2�滻Ϊ6, a1���ݸı�

	vector<int> result; //result��a1�Ŀ���������2���滻Ϊ6��a1���ݲ���
	replace_copy(begin(a1), end(a1), back_inserter(result), 2, 6);
	cout << result.size() << endl;

	vector<string> words{ "the","quick","red","fox","jumps","over","the","slow","the","turtle" };
	sort(words.begin(), words.end());
	// unique����ɾ��Ԫ�أ����ظ�Ԫ���Ƶ���󣬷���ָ���һ��Ԫ�أ���û���ظ�������end()
	auto repeatIte = unique(words.begin(), words.end());
	words.erase(repeatIte, words.end());
	cout << words.size() << endl;
	
	void test_predicate();
	test_predicate();

	return 0;
}

bool isShorter(const string& str1, const string& str2) {

	return str1.size() < str2.size();
}

void test_predicate() {

	vector<string> words{ "the","quick","red","fox","jumps","over","the","slow","the","turtle" };
	sort(words.begin(), words.end(), isShorter);

	//lambda ��ʽ��[capture list] (parameter list) -> return type {function body}
	// capture list�����б�ֵlambda�ڶ���ľֲ������б�;
	auto f = [] {return 42; };
	cout << f() << endl;
}