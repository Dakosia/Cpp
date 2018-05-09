#include "Product.h"



Product::Product(String_ productName, String_ manufacturer, int year, int month, int day, double price, int quantity)
{
	this->setProductName(productName);
	this->setManufacturer(manufacturer);
	this->setShelfLife(year, month, day);
	this->setPrice(price);
	this->setQuantity(quantity);
}

Product::~Product()
{
	this->productName.~String_();
	this->manufacturer.~String_();
	this->shelfLife.~String_();
}

void Product::setProductName(String_ productName)
{
	this->productName = productName;
}

void Product::setManufacturer(String_ manufacturer)
{
	this->manufacturer = manufacturer;
}

void Product::setShelfLife(int year, int month, int day)
{
	this->setYear(year);
	this->setMonth(month);
	this->setDay(day);
}

void Product::setYear(int year)
{
	if (year < 0)
		year = 0;
	this->year += year;
}

void Product::setMonth(int month)
{
	if (month > 11)
		setYear(month / 12);
	if (month < 0)
		month = 0;
	this->month += month % 12;
}

void Product::setDay(int day)
{
	if (day > 30)
		setMonth(day / 31);
	if (day < 0)
		day = 0;
	this->day += day % 31;
}

void Product::setPrice(double price)
{
	this->price = price;
}

void Product::setQuantity(int quantity)
{
	this->quantity = quantity;
}

String_ Product::getProductName() const
{
	return this->productName;
}

String_ Product::getManufacturer() const
{
	return this->manufacturer;
}

String_ Product::getShelfLife() const
{
	return this->shelfLife;
}

int Product::getYear() const
{
	return this->year;
}

int Product::getMonth() const
{
	return this->month;
}

int Product::getDay() const
{
	return this->day;
}

double Product::getPrice() const
{
	return this->price;
}

int Product::getQuantity() const
{
	return this->quantity;
}

Product & Product::operator=(const Product & a)
{
	if (&a == this)
		return *this;
	this->~Product();
	this->productName = a.productName;
	this->manufacturer = a.manufacturer;
	this->shelfLife = a.shelfLife;
	this->price = a.price;
	this->quantity = a.quantity;
	return *this;
}

std::ostream & operator<<(std::ostream & out, const Product & a)
{
	out << a.productName << std::endl << a.manufacturer << std::endl << a.shelfLife << std::endl;
	out << a.price << std::endl << a.quantity << std::endl;
	return out;
}
