#include <iostream>
using namespace std;

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
	//explicit关键字只能声明在类内部，不可用来做隐式转换
	explicit Sales_data(std::istream&);

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

int main_06_00() {

	Sales_data item;
	item = string("huhu"); //拷贝初始化，隐式变换
	string bookNo = "123456";
	item.combine(bookNo); //隐式转换，bookNo调用了Sales(string)构造函数默认转换为Sales_data对象
	//item.combine("123");错误, 隐式转换只能一次，这里"123"->string->Sales_data是两次。
	item.combine(string("123"));//正确，一次隐式转换
	//item.combine(cin);//调用Sales_data(std::istream)
	Sales_data data(cin); //explicit声明的只能直接初始化
	//data.combine(cin); //explicit不能隐式初始化
	data.combine(static_cast<Sales_data>(cin)); //但可以强制转换
	
	return 0;
}
