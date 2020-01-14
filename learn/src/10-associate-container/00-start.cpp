#include <iostream>
#include <map>
#include <set>
#include <unordered_map>
#include <unordered_set>
#include <utility>

using namespace std;

// �����������������붨��ؼ��ֱȽϵķ���

void unsort_container();

int main() {

	map<string, size_t> word_count;
	set<string> exclude = { "the", "is", "are" };
	string word;
	/*while (cin >> word) {
		if (word == "quit")
			break;
		if (exclude.find(word) != exclude.end())
			continue;
		word_count[word]++;
	}*/

	word_count["dummpy"] = 0;
	for (const auto &w : word_count) {
		cout << w.first << " occurs " << w.second << " times!" << endl;
	}

	// pair�����������ݳ�Ա����������, ���ݳ�Ա��public�ģ�ֱ����first,second����, <=, >, ==, !=
	pair<string, size_t> anon; //����string, size_t, Ĭ�ϳ�ʼ������һ�Կ��ַ�����0
	pair<string, string> author{"James", "Joyce"}; //�Զ����ʼ��
	//pair<string, string> author("James", "Joyce"); //�Զ����ʼ��
	auto expPair = make_pair(string("haha"), 1); //����pair����
	cout << anon.first << anon.second << author.first << author.second << endl;

	set<string>::value_type v1; //string
	set<string>::key_type v2; //string
	map<string, int>::key_type v3; //string
	map<string, int>::mapped_type v4; //int
	map<string, int>::value_type v5; // pair<const string, int>

	//�����á������������ĵ���������õ�pair����
	auto map_it = word_count.begin();
	cout << map_it->first << " " << map_it->second << endl;
	//map_it->first = "not dummy"; ���󣬹ؼ���Ϊconst
	++map_it->second; //map_itΪpair���ͣ�ֻ�ı���pair�е�second, map�е�valueû��
	cout << map_it->second << " " << word_count["dummy"] << endl; //1 0

	//set�е�iterator��const_iterator��ֻ����ֻ�����ʣ������޸�
	set<int> iset = { 0,1,2,3,4,5 };
	set<int>::iterator set_it = iset.begin(); //����set, map����(map������pair<>)
	while (set_it != iset.end()) {
		//*set_it = 42; ����, set�еĹؼ�����ֻ����
		cout << *set_it << endl;
		++set_it;
	}

	//set��map insert����pair<������, bool(�ɹ�?)>, ��Ԫ�ش��ڣ���ʲô������
	vector<int> ivec = { 2,4,2,4,3 };
	set<int> set2;
	set2.insert({ 2,4,2 });
	set2.insert(ivec.begin(), ivec.end());

	//map insert����pair
	word_count.insert({ "word", 1 }); //pair�������б�ֵ
	word_count.insert(word_count.begin(), word_count.end());

	//���ڹ�������(map,set), ɾ��Ԫ��erase(), ����˳���������յ�������������ԣ�������չؼ��ֲ���
	cout << word_count.erase("word") << endl; //����ɾ���ĸ�����1

	//map��unordered_map�����ṩ��[]��at, setû�У���ΪsetԪ�ر�����ǹؼ���
	word_count["Anna"] = 1; //�Զ�����Anna--1; ���ȳ�ʼ��Anna--0, Ȼ��������滻Ϊ1
	//map[key]:��key�����ڣ����Զ���������ʼ����map.at(key):��key�����ڣ�����
	word_count["Anna"] = 2;
	cout << word_count["Anna"] << word_count.at("Anna") << endl; //ֻ�з�constԪ�ؿ���ʹ��[]�������at

	//����Ԫ��
	if (iset.find(1) == iset.end())
		cout << "not found" << endl;
	else
		cout << "find it count:" << iset.count(1) << endl;

	return 0;

	// low_bound()��upper_bound()��֧�������������, һ�����ڿ��ظ�����
	iset.lower_bound(5); //���ص�һ����С��5�ĵ�����
	iset.upper_bound(5); //���ص�һ������5�ĵ�����
	iset.equal_range(5); //����pair,����5�ķ�Χ


}

// ��������, ʹ��hash�����͹ؼ��ֵ�==�����
void unsort_container() {

	unordered_map<string, size_t> word_count;
	word_count.insert({"dummy", 0});

	//��׼��Ϊ��������(����ָ��)�ṩ��hashģ��, string������ָ�����Ͷ�����hash

}