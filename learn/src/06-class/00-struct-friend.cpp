#include <iostream>
using namespace std;

int main_06_00() {

	return 0;
}

//struct Sales_data { 默认public
class Sales_data { //默认private, class和struct唯一区别就是默认访问权限

	//友元函数可以访问非公有成员， 必须类内声明，不受访问控制约束, struct->class后新增
	friend Sales_data add(const Sales_data& lhs, const Sales_data& rhs);
	friend std::ostream& print(std::ostream& os, const Sales_data& item);
	friend std::istream& read(std::istream& is, Sales_data& item);

public:
	//拷贝，赋值，析构自动合成

	//构造函数
	Sales_data() = default; //因为定义了其他的构造，默认的会被覆盖，因此显式定义下
	Sales_data(const std::string& s) :bookNo(s) {}
	Sales_data(const std::string& s, unsigned n, double p) :
		bookNo(s), units_sold(n), revenue(p* n) {}
	Sales_data(std::istream&);

	//const 成员函数表明不能修改成员变量的值
	std::string isbn() const { return bookNo; }
	Sales_data& combine(const Sales_data&);
	double avg_price() const;
private:
	std::string bookNo;
	unsigned units_sold = 0;
	double revenue = 0.0;
};

//类外定义成员函数
Sales_data::Sales_data(std::istream& is) { read(is, *this); }

double Sales_data::avg_price() const {
	if (units_sold)
		return revenue / units_sold;
	else
		return 0;
}
//返回this对象
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
