#include <iostream>
using namespace std;

int main_06_00() {

	return 0;
}

//struct Sales_data { Ĭ��public
class Sales_data { //Ĭ��private, class��structΨһ�������Ĭ�Ϸ���Ȩ��

	//��Ԫ�������Է��ʷǹ��г�Ա�� �����������������ܷ��ʿ���Լ��, struct->class������
	friend Sales_data add(const Sales_data& lhs, const Sales_data& rhs);
	friend std::ostream& print(std::ostream& os, const Sales_data& item);
	friend std::istream& read(std::istream& is, Sales_data& item);

public:
	//��������ֵ�������Զ��ϳ�

	//���캯��
	Sales_data() = default; //��Ϊ�����������Ĺ��죬Ĭ�ϵĻᱻ���ǣ������ʽ������
	Sales_data(const std::string& s) :bookNo(s) {}
	Sales_data(const std::string& s, unsigned n, double p) :
		bookNo(s), units_sold(n), revenue(p* n) {}
	Sales_data(std::istream&);

	//const ��Ա�������������޸ĳ�Ա������ֵ
	std::string isbn() const { return bookNo; }
	Sales_data& combine(const Sales_data&);
	double avg_price() const;
private:
	std::string bookNo;
	unsigned units_sold = 0;
	double revenue = 0.0;
};

//���ⶨ���Ա����
Sales_data::Sales_data(std::istream& is) { read(is, *this); }

double Sales_data::avg_price() const {
	if (units_sold)
		return revenue / units_sold;
	else
		return 0;
}
//����this����
Sales_data& Sales_data::combine(const Sales_data& rhs) {
	
	units_sold += rhs.units_sold;
	revenue += rhs.revenue;
	return *this;
}

Sales_data add(const Sales_data& lhs, const Sales_data& rhs) {

	Sales_data sum = lhs;
	sum.combine(rhs);
	return sum;
}
std::ostream& print(std::ostream& os, const Sales_data& item) {
	os << item.isbn() << " " << item.units_sold << " " << item.revenue << " " << item.avg_price();
	return os;
}
std::istream& read(std::istream& is, Sales_data& item) {
	double price = 0;
	is >> item.bookNo >> item.units_sold >> price;
	item.revenue = price * item.units_sold;
	return is;
}
