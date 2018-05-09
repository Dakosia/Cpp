#pragma once
#include "String_.h"
class Product
{
private:
	String_ productName;
	String_ manufacturer;
	String_ shelfLife;
	int day;
	int month;
	int year;
	double price;
	int quantity;
public:
	Product(String_ productName = "Product Name", String_ manufacturer = "Manufacturer", int year = 0, int month = 0, int day = 1, double price = 1000, int quantity = 10);
	~Product();

	//setters
	void setProductName(String_ productName);
	void setManufacturer(String_ manufacturer);
	void setShelfLife(int year, int month, int day);
	void setYear(int year);
	void setMonth(int month);
	void setDay(int day);
	void setPrice(double price);
	void setQuantity(int quantity);            
	//getters
	String_ getProductName() const;
	String_ getManufacturer() const;
	String_ getShelfLife() const;
	int getYear() const;
	int getMonth() const;
	int getDay() const;
	double getPrice() const;
	int getQuantity() const;

	Product& operator=(const Product &a);

	friend std::ostream& operator<<(std::ostream &out, const Product &a);
};

std::ostream& operator<<(std::ostream &out, const Product &a);
