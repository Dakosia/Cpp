#include "Circle.h"
#include "Rectangle.h"
#include "Employee.h"
#include "InvoiceItem.h"
#include "Account.h"
#include "Date.h"
#include "Time.h"

void circle()
{
	Circle c1 = Circle();
	std::cout << "Radius: " << c1.getRadius() << std::endl;
	std::cout << "Color: " << c1.getColor() << std::endl;
	std::cout << "Area: " << c1.getArea() << std::endl;
	std::cout << std::endl;

	Circle c2(6.2);
	std::cout << "Radius: " << c2.getRadius() << std::endl;
	std::cout << "Color: " << c2.getColor() << std::endl;
	std::cout << "Area: " << c2.getArea() << std::endl;
	std::cout << std::endl;

	Circle c3(5, "yellow");
	std::cout << "Radius: " << c3.getRadius() << std::endl;
	std::cout << "Color: " << c3.getColor() << std::endl;
	std::cout << "Area: " << c3.getArea() << std::endl;
	std::cout << std::endl;

	Circle c4;
	c4.setRadius(3.5);
	c4.setColor("orange");
	std::cout << c4.toString() << std::endl;
	std::cout << "Area: " << c4.getArea() << std::endl;
	std::cout << std::endl;
}

void rectangle()
{
	Rectangle r1 = Rectangle();
	std::cout << "Length: " << r1.getLength() << std::endl;
	std::cout << "Width: " << r1.getWidth() << std::endl;
	std::cout << "Area: " << r1.getArea() << std::endl;
	std::cout << "Perimeter: " << r1.getPerimeter() << std::endl;
	std::cout << std::endl;

	Rectangle r2(4.5, 7);
	std::cout << "Length: " << r2.getLength() << std::endl;
	std::cout << "Width: " << r2.getWidth() << std::endl;
	std::cout << "Area: " << r2.getArea() << std::endl;
	std::cout << "Perimeter: " << r2.getPerimeter() << std::endl;
	std::cout << std::endl;

	Rectangle r3;
	r3.setLength(3.26);
	r3.setWidth(6.178);
	std::cout << r3.toString() << std::endl;
	std::cout << "Area: " << r3.getArea() << std::endl;
	std::cout << "Perimeter: " << r3.getPerimeter() << std::endl;
	std::cout << std::endl;

}

void employee()
{
	Employee e1(1, "Qwe", "Rty", 2000);
	std::cout << "ID: " << e1.getID() << std::endl;
	std::cout << "First Name: " << e1.getFirstName() << std::endl;
	std::cout << "Last Name: " << e1.getLastName() << std::endl;
	std::cout << "Name: " << e1.getName() << std::endl;
	std::cout << "Salary: " << e1.getSalary() << std::endl;
	std::cout << "Annual salary: " << e1.getAnnualSalary() << std::endl;
	std::cout << "Raised salary: " << e1.raiseSalary(20) << std::endl;
	e1.setSalary(3500);
	std::cout << e1.toString() << std::endl;
	std::cout << std::endl;
}

void invoiceItem()
{
	InvoiceItem ii("Qwerty", "Ytrewq", 5, 2135);
	std::cout << "ID: " << ii.getID() << std::endl;
	std::cout << "Description: " << ii.getDesc() << std::endl;
	std::cout << "Quantity: " << ii.getQty() << std::endl;
	std::cout << "Unit price: " << ii.getUnitPrice() << std::endl;
	std::cout << "Total: " << ii.getTotal() << std::endl;
	ii.setQty(15);
	ii.setUnitPrice(3500);
	std::cout << ii.toString() << std::endl;
	std::cout << std::endl;
}

void account()
{
	Account acc1("123", "Qwerty");
	std::cout << "ID: " << acc1.getID() << std::endl;
	std::cout << "Name: " << acc1.getName() << std::endl;
	std::cout << "Balance: " << acc1.getBalance() << std::endl;
	std::cout << "Credit: " << acc1.credit(456) << std::endl;
	std::cout << "Debit: " << acc1.debit(654) << std::endl;
	std::cout << std::endl;

	Account acc2("321", "Ytrewq", 9876);
	std::cout << acc2.toString() << std::endl;
	std::cout << "Credit: " << acc2.credit(369) << std::endl;
	std::cout << "Debit: " << acc2.debit(963) << std::endl;
	std::cout << acc2.transferTo(acc1, 147) << std::endl;
	std::cout << std::endl;
}

void date()
{
	Date date;
	std::cout << date.toString() << std::endl;
}

void time()
{
	Time time;
	std::cout << time.toString() << std::endl;
}

int main()
{
	circle();
	//rectangle();
	//employee();
	//invoiceItem();
	//account();
	//date();
	//time();

	system("pause");
	return 0;
}