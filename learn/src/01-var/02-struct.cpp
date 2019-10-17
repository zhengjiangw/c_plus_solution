#include <iostream>
#include "Sales_data.h"

int main_02() {

	Sales_data data1, data2;
	
	double price = 0;
	std::cin >> data1.bookNo >> data1.units_sold >> price;
	data1.revenue = price * data1.units_sold;

	std::cin >> data2.bookNo >> data2.units_sold >> price;
	data2.revenue = price * data2.units_sold;

	if (data1.bookNo == data2.bookNo) {

		auto total = data1.revenue + data2.revenue;
		std::cout << "total price:" << total << std::endl;
	}
	return 0;
}
