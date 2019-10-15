#pragma once //保证同一个头文件不会定义两次
#ifndef SALES_DATA_H //如果"SALES_DATA_H"不存在
#define SALES_DATA_H //定义"SALES_DATA_H"
#include <iostream>
struct Sales_data {

	std::string bookNo;
	unsigned units_sold = 0;
	double revenue = 0.0;
};

#endif


