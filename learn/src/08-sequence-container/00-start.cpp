#include <iostream>
#include <vector>
#include <list>
#include <forward_list>
#include <array>
using namespace std;

/*
 vector:�ɱ��С����
 string:�ɱ��С����(char)
 array:Ԫ�ز��ɱ�̶���С����, ������ӻ�ɾ��Ԫ��
 list:˫������
 forward_list:��������,Ϊ�����ܿ��ǣ�û��size����
 deque:˫�˶���,���ٷ��ʣ�ͷβ����ɾ����
*/

int main_08_00() {

	vector<int> v{ 1,2,3 };

	auto ite = v.begin(); //v��const��ʱ�򷵻�const_iterator<>
	list<string> s = { "a", "b", "c" };
	forward_list<double> ch(v.begin(), v.end()); //�õ�������ʼ��ֻҪԪ�ؿ���ת����Ŀ�����;Ϳ���
	vector<int> vs(v); //����һ��������ʼ��
	array<int, 5> arr{ 0,1,2 }; //{0,1,2,0,0}
	array<int, 5> a2 = arr; //array���Ը�ֵ
	//array<int, 3> a3 = arr;�������Ͳ�ͬ

	array<int, 3> a3{0,1,2};
	// assign()Ԫ��ȫ���滻����˴��ݵĵ���������ָ������,�����������ú�ָ��ʧЧ
	v.assign(a3.begin(), a3.end()); //assign()���Բ�ͬ����
	v.assign(3, 99); //�滻Ϊ3��99

	//��string�⣬swap��Ԫ�ز��ᷢ������
	v.swap(vs); //Ԫ�ؽ���(ֻ�ǽ������ݽṹ��û�п����͸�ֵ), ������Ҫ��ͬ���ٶȱȸ�ֵ��ö�
	//��������arr��������"����"Ԫ��
	swap(arr, a2);

	//��������������֧��<,>=,==,!=����string����,��������ͬ,��Ԫ��֧�ֱȽ�
	vector<int> v1 = { 1,3,5,7,9 }, v2 = { 1,3,5 };
	cout << (v1 > v2) << endl; //true

	void operators();
	operators();

	return 0;
}

void operators() {
	//��array�⣬�������������Զ�̬��ӻ�ɾ��Ԫ��

	//��array, forward_list����֧��push_back
	vector<string> strs;
	strs.push_back("abc");

	//list, forward_list,dequeue֧��push_front
	list<int> ilist;
	ilist.push_front(1);

	//��array�� ��֧��insert, insert(0,..)�൱��push_front.ָ��λ��֮ǰ
	//�����²���ĵ�һ��Ԫ�صĵ�����
	vector<string> svec;
	list<string> slist;
	string str;
	slist.insert(slist.begin(), "Hello");
	svec.insert(svec.begin(), "Hello");
	str.insert(str.begin(), 'H');
	cout << str << endl;

	svec.insert(svec.end(), 10, "Anna"); //����10��"Anna"

	vector<string> v = { "abc", "def", "ghi" };
	slist.insert(slist.begin(), v.end() - 2, v.end());//��������Χ����ָ��insert����

	//��insert��Ӧ����emplace, ֱ���������ڴ��д�������
	vector<vector<int>> vv;
	vv.emplace_back(3, 99); //(3, 99)��vector<int>��һ�����캯��
	cout << vv.size() << vv.at(0)[2] << endl;

	string& fs1 = *slist.begin();
	//����˳�����׶���front()ָ���һ��Ԫ������
	string& fs2 = slist.front();
	//��forward_list����back()ָ�����һ��Ԫ������
	string& fs3 = slist.back();

	//�ṩ������������ʡ��Ķ�֧��[]�������at(), �����±�Խ��,at()���׳��쳣
	//cout << v[10] << endl;
	//cout << v.at(10) << endl;
	
	array<int, 5> arr{ 1,2,3,4,5 };
	forward_list<int> flst(arr.begin(), arr.end());

	//pop_back()ɾ��β��array,forward_list��֧��
	//pop_front()ɾ��ͷ, array,vector��string��֧��
	fs1.pop_back();
	flst.pop_front();

	//erase()��array�ⶼ֧��, ���غ�һ��������λ��
	v.erase(v.begin() + 1);
	v.erase(v.begin(), v.end());
	v.clear();

	flst = { 0,1,2,3,4,5 };
	auto prev = flst.before_begin();
	auto curr = flst.begin();
	while (curr != flst.end()) {
		if (*curr % 2 == 0) {
			curr = flst.erase_after(prev);
		}
		else {
			prev = curr;
			++curr;
		}
	}

	vector<int> vis{ 1,2 };
	auto ite = vis.insert(vis.begin() + 1, 3, 0);
	vis.insert(ite, 3, 9);
	for (auto v : vis) {
		cout << v << " ";
	}
	cout << endl;
}
