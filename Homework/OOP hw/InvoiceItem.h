#pragma once
#include <string>
#include <iostream>
class InvoiceItem
{
private:
	std::string id;
	std::string desc;
	int qty;
	double unitPrice;
public:
	InvoiceItem();
	InvoiceItem(std::string, std::string, int, double);
	~InvoiceItem();

	std::string getID();
	std::string getDesc();
	int getQty();
	void setQty(int);
	double getUnitPrice();
	void setUnitPrice(double);
	double getTotal();
	std::string toString();
};

