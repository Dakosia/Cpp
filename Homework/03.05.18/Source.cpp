#include "Abiturient.h"
#include "AirAstana.h"
#include "Book.h"
#include "Worker.h"
#include "Train.h"
#include "Product.h"
#include <ctime>
#include <algorithm>

void abiturient()
{
	//Массивы оценок
	VectorMy m1, m2, m3, m4, m5, m6, m7, m8, m9, m10;
	//Заполнение массивов из 5 рандомных оценок
	for (int i = 0; i < 5; i++)
	{
		m1.push_back(rand() % 12 + 1);
		m2.push_back(rand() % 12 + 1);
		m3.push_back(rand() % 12 + 1);
		m4.push_back(rand() % 12 + 1);
		m5.push_back(rand() % 12 + 1);
		m6.push_back(rand() % 12 + 1);
		m7.push_back(rand() % 12 + 1);
		m8.push_back(rand() % 12 + 1);
		m9.push_back(rand() % 12 + 1);
		m10.push_back(rand() % 12 + 1);
	}
	//Объекты класса Abiturient
	Abiturient a1("Sergeyev Sergey Sergeyevich", "Almaty", m1);
	Abiturient a2("Pavlov Pavel Pavlovich", "Aktau", m2);
	Abiturient a3("Isaeva Sabina Serikovna", "Astana", m3);
	Abiturient a4("Filatova Elena Andreevna", "Almaty", m4);
	Abiturient a5("Zhuk Ivan Myroslavovych", "Astana", m5);
	Abiturient a6("Kenesova Saule Kairatovna", "Almaty", m6);
	Abiturient a7("Olzhasov Marlen Bekbolatovich", "Almaty", m7);
	Abiturient a8("Kirillov Kirill Kirillovich", "Taraz", m8);
	Abiturient a9("Amirov Madi Muratovich", "Almaty", m9);
	Abiturient a10("Belova Aleksandra Nikolayevna", "Astana", m10);
	//Массив объектов класса Abiturient
	Abiturient a[10];
	a[0] = a1;
	a[1] = a2;
	a[2] = a3;
	a[3] = a4;
	a[4] = a5;
	a[5] = a6;
	a[6] = a7;
	a[7] = a8;
	a[8] = a9;
	a[9] = a10;

	//Список абитуриентов, имеющих неудовлетворительные оценки
	std::cout << "Losers: " << std::endl;
	for (size_t i = 0; i < 10; i++)
	{
		if (a[i].isLoser())
			std::cout << a[i].getFio() << std::endl;
	}
	std::cout << std::endl;

	//Заданный средний балл
	int avg = 7;
	//std::cin >> avgM;
	//Cписок абитуриентов, средний балл у которых выше заданного
	std::cout << "Abiturients whose average mark higher than " << avg << ": " << std::endl;
	for (size_t i = 0; i < 10; i++)
	{
		if (a[i].getAvgMark() > avg)
			std::cout << a[i].getFio() << std::endl;
	}

	//не знаю как отсортировать с нашем классом

	/*//Заданное количество абитуриентов
	int n = 5;
	//std::cin >> n;
	int cnt = 0;
	//bool(*func)(Abiturient &, Abiturient &) = compare;
	//std::sort(a[0], a[9], func);
	
	for (size_t i = 0; i < 10; i++)
	{
		if (cnt != n)
		{
			std::cout << a[i].getFio() << std::endl;
		}
	}
	int semi_pass = 6; //полупроходной балл
	//std::cin >> semi_pass;
	for (size_t i = 0; i < 10; i++)
	{
		if(a[i].getAvgMark() > semi_pass)
			std::cout << a[i].getFio() << std::endl;
	}*/
	
}

void airAstana()
{
	Time_ t1(18, 15);
	Time_ t2(5, 10);
	Time_ t3(1, 10);
	Time_ t4(18, 15);
	Time_ t5(23, 55);
	Time_ t6(5, 10);
	Time_ t7(4);
	Time_ t8(23, 10);
	Time_ t9(23, 10);
	Time_ t10(8, 25);
	//Объекты класса AirAstana
	AirAstana a1("St.Petersburg", "KC135", "Airbus A321", t1, "Friday");
	AirAstana a2("Minsk", "B2768", "Boeing 738", t2, "Thursday");
	AirAstana a3("Seoul", "KC909", "Boeing 763", t3, "Monday");
	AirAstana a4("St.Petersburg", "KC135", "Airbus A321", t4, "Tuesday");
	AirAstana a5("Seoul", "KC959", "Boeing 763", t5, "Saturday");
	AirAstana a6("Minsk", "B2768", "Boeing 738", t6, "Saturday");
	AirAstana a7("Frankfurt", "LH647", "Airbus A330", t7, "Thursday");
	AirAstana a8("Seoul", "OZ578", "Boeing 763", t8, "Friday");
	AirAstana a9("Seoul", "OZ578", "Boeing 763", t9, "Thursday");
	AirAstana a10("St.Petersburg", "KC153", "Airbus A321", t10, "Monday");
	//Массив объектов класса AirAstana
	AirAstana a[10];
	a[0] = a1;
	a[1] = a2;
	a[2] = a3;
	a[3] = a4;
	a[4] = a5;
	a[5] = a6;
	a[6] = a7;
	a[7] = a8;
	a[8] = a9;
	a[9] = a10;
	//Заданный пункт назначения
	String_ dest = "Seoul";
	//std::cin >> dest;
	//Список рейсов для заданного пункта назначения
	std::cout << "Flights with destination " << dest << ": " << std::endl;
	for (size_t i = 0; i < 10; i++)
	{
		if (a[i].getDestination() == dest)
			std::cout << a[i].getFlightNumber() << std::endl;
	}
	std::cout << std::endl;

	//Заданный день недели
	String_ day = "Friday";
	//std::cin >> day;
	//Список рейсов для заданного дня недели
	std::cout << "Flights with departure day " << day << ": " << std::endl;
	for (size_t i = 0; i < 10; i++)
	{
		if (a[i].getDay() == day)
			std::cout << a[i].getFlightNumber() << std::endl;
	}
	std::cout << std::endl;

	//Заданный день недели
	String_ day1 = "Monday";
	//std::cin >> day1;
	//Заданное время вылета
	Time_ depTime(4,30);
	//std::cin >> depTime;
	//Список рейсов для заданного дня недели, время вылета для которых больше заданного
	std::cout << "Flights with departure day " << day1 << " and departure time later than " << depTime;
	for (size_t i = 0; i < 10; i++)
	{
		if (a[i].getDay() == day1)
		{
			if(a[i].getDepartureTime() > depTime)
				std::cout << a[i].getFlightNumber() << ' ' << a[i].getDepartureTime();
		}
	}
}

void book()
{
	//Объекты класса Book
	Book b1("J.K. Rowling", "The Tales of Beedle the Bard", "Bloomsbury", 2008, 180);
	Book b2("J.R. Tolkien", "The Hobbit", "George Allen & Unwin Ltd.", 1937, 304);
	Book b3("J.R. Tolkien", "The Fellowship of the Ring", "George Allen & Unwin Ltd.", 1954, 479);
	Book b4("Brandon Sanderson", "The Way of Kings", "Tor Books", 2010, 1007);
	Book b5("J.K. Rowling", "Hogwarts: An Incomplete and Unreliable Guide", "Scholastic", 2016, 84);
	Book b6("Brandon Sanderson", "Words of Radiance", "Tor Books", 2014, 1087);
	Book b7("J.R. Tolkien", " 	The Two Towers", "George Allen & Unwin Ltd.", 1954, 352);
	Book b8("J.K. Rowling", "Quidditch Through the Ages ", "Bloomsbury", 2001, 56);
	Book b9("J.K. Rowling", "Fantastic Beasts and Where to Find Them", "Scholastic", 2001, 128);
	Book b10("Brandon Sanderson", "Oathbringer", "Tor Books", 2017, 1248);
	//Массив объектов класса Book
	Book b[10];
	b[0] = b1;
	b[1] = b2;
	b[2] = b3;
	b[3] = b4;
	b[4] = b5;
	b[5] = b6;
	b[6] = b7;
	b[7] = b8;
	b[8] = b9;
	b[9] = b10;

	//Заданный автор
	String_ auth = "J.R. Tolkien";
	//std::cin >> auth;
	//Cписок книг заданного автора
	std::cout << "Books written by " << auth << ": "<< std::endl;
	for (size_t i = 0; i < 10; i++)
	{
		if (b[i].getAuthor() == auth)
			std::cout << b[i].getTitle() << std::endl;
	}

	//Заданное издательство
	String_ publ = "Tor Books";
	//std::cin >> publ;
	//Список книг, выпущенных заданным издательством;
	std::cout << "Books published by " << publ << ": " << std::endl;
	for (size_t i = 0; i < 10; i++)
	{
		if (b[i].getPublishingHouse() == publ)
			std::cout << b[i].getTitle() << std::endl;
	}

	//Заданный год
	int y = 2001;
	//std::cin >> y;
	//Список книг, выпущенных после заданного года
	std::cout << "Books published after " << y << ": " << std::endl;
	for (size_t i = 0; i < 10; i++)
	{
		if (b[i].getYear() > y)
			std::cout << b[i].getTitle() << std::endl;
	}
}

void worker()
{
	//Объекты класса Worker
	Worker w1("Yuki Minako", "Senior Leader", 2005, 900000);
	Worker w2("Amai Shohei", "Architect", 2010, 600000);
	Worker w3("Hada Shino", "Junior Developer", 2018, 100000);
	Worker w4("Hada Ryuichi", "Senior Developer", 2015, 300000);
	Worker w5("Fukase Erika", "Mid-Level Manager", 2007, 800000);
	Worker w6("Ishikura Kei", "Architect", 2008, 700000);
	Worker w7("Higashi Sadaharu", "Junior Developer", 2018, 100000);
	Worker w8("Fujita Shuichi", "Architect", 2010, 600000);
	Worker w9("Nakajima Eishi", "Senior Developer", 2014, 400000);
	Worker w10("Inouye Kazuhiro", "Junior Developer", 2017, 200000);
	//Массив объектов класса Worker
	Worker w[10];
	w[0] = w1;
	w[1] = w2;
	w[2] = w3;
	w[3] = w4;
	w[4] = w5;
	w[5] = w6;
	w[6] = w7;
	w[7] = w8;
	w[8] = w9;
	w[9] = w10;

	//Заданное число лет работы
	int y = 7;
	//std::cin >> y;
	//Список работников, стаж работы которых на данном предприятии превосходит заданное число лет
	std::cout << "Workers with more than " << y << " years of experience at the enterprise:" << std::endl;
	for (size_t i = 0; i < 10; i++)
	{
		if (2018 - w[i].getYear() > y)
			std::cout << w[i].getFio() << std::endl;
	}
	std::cout << std::endl;

	//Заданная зарплата
	int sal = 300000;
	//std::cin >> sal;
	//Список работников, зарплата которых превосходит заданную
	std::cout << "Workers with a salary more than " << sal << ": " << std::endl;
	for (size_t i = 0; i < 10; i++)
	{
		if (w[i].getSalary() > sal)
			std::cout << w[i].getFio() << std::endl;
	}
	std::cout << std::endl;

	//Заданная должность
	String_ pos = "Architect";
	//std::cin >> pos;
	//Список работников, занимающих заданную должность
	std::cout << "Workers holding the position of " << pos << ": " << std::endl;
	for (size_t i = 0; i < 10; i++)
	{
		if (w[i].getPosition() == pos)
			std::cout << w[i].getFio() << std::endl;
	}
}

void train()
{
	Time_ time1(19, 37);
	Time_ time2(21, 8);
	Time_ time3(1, 22);
	Time_ time4(15, 24);
	Time_ time5(23, 55);
	Time_ time6(23, 36);
	Time_ time7(23, 5);
	Time_ time8(16, 33);
	Time_ time9(8, 36);
	Time_ time10(17, 10);
	//Объекты класса Train
	Train t1("Tashkent", "001X", time1, 18, 34, 51);
	Train t2("Uralsk", "379T", time2, 21, 53, 42);
	Train t3("Urumqi", "013X", time3, 0, 50, 50);
	Train t4("Astana", "003T", time4, 17, 50, 50);
	Train t5("Astana", "031X", time5, 0, 41, 64);
	Train t6("Uralsk", "380T", time6, 0, 59, 42);
	Train t7("Uralsk", "049T", time7, 30, 37, 53);
	Train t8("Astana", "151C", time8, 15, 45, 50);
	Train t9("Urumqi", "103C", time9, 25, 32, 49);
	Train t10("Novosibirsk", "301С", time10, 15, 29, 65);
	//Массив объектов класса Train
	Train t[10];
	t[0] = t1;
	t[1] = t2;
	t[2] = t3;
	t[3] = t4;
	t[4] = t5;
	t[5] = t6;
	t[6] = t7;
	t[7] = t8;
	t[8] = t9;
	t[9] = t10;
	//Заданный пункт назначения
	String_ des = "Astana";
	//std::cin >> des;
	//Список поездов, следующих до заданного пункта назначения
	std::cout << "Trains with destination " << des << ": " << std::endl;
	for (size_t i = 0; i < 10; i++)
	{
		if (t[i].getDestination() == des)
			std::cout << t[i].getTrainNumber() << std::endl;
	}
	std::cout << std::endl;

	//Заданный пункт назначения
	String_ des1 = "Urumqi";
	//std::cin >> des1;
	//Заданное время отправления
	Time_ depT(1, 30);
	//std::cin >> depTime;
	//Список поездов, следующих до заданного пункта назначения и отправляющихся после заданного часа
	std::cout << "Trains with destination " << des1 << " and departure time later than " << depT;
	for (size_t i = 0; i < 10; i++)
	{
		if (t[i].getDestination() == des1)
		{
			if (t[i].getDepartureTime() > depT)
				std::cout << t[i].getTrainNumber() << ' ' << t[i].getDepartureTime();
		}
	}
	std::cout << std::endl;

	//Заданный пункт назначения
	String_ des2 = "Uralsk";
	//std::cin >> des2;
	//Список поездов, отправляющихся до заданного пункта назначения и имеющих общие места
	std::cout << "Trains with destination " << des2 << " and with common seats: " << std::endl;
	for (size_t i = 0; i < 10; i++)
	{
		if (t[i].getDestination() == des2)
		{
			if (t[i].getNumberOfSeats() > 0)
				std::cout << t[i].getTrainNumber() << std::endl;
		}
	}
}

void product()
{
	//Объекты класса Product
	Product p1("Laptop", "Acer", rand() % 10, rand() % 12, rand() % 31, 249999, 6);
	Product p2("Headphones", "JBL", rand() % 10, rand() % 12, rand() % 31, 12099, 8);
	Product p3("Phone", "Apple", rand() % 10, rand() % 12, rand() % 31, 300000, 3);
	Product p4("Laptop", "Dell", rand() % 10, rand() % 12, rand() % 31, 350000, 4);
	Product p5("Phone", "Samsung", rand() % 10, rand() % 12, rand() % 31, 239000, 5);
	Product p6("Headphones", "Razer", rand() % 10, rand() % 12, rand() % 31, 19590, 10);
	Product p7("Phone", "LG", rand() % 10, rand() % 12, rand() % 31, 75500, 5);
	Product p8("Laptop", "Asus", rand() % 10, rand() % 12, rand() % 31, 459374, 1);
	Product p9("Headphones", "Sony", rand() % 10, rand() % 12, rand() % 31, 9720, 20);
	Product p10("Laptop", "HP", rand() % 10, rand() % 12, rand() % 31, 385320, 2);
	//Массив объектов класса Product
	Product p[10];
	p[0] = p1;
	p[1] = p2;
	p[2] = p3;
	p[3] = p4;
	p[4] = p5;
	p[5] = p6;
	p[6] = p7;
	p[7] = p8;
	p[8] = p9;
	p[9] = p10;

	//Заданное наименование
	String_ name = "Laptop";
	//std::cin >> name;
	//Список товаров для заданного наименования
	std::cout << "List of products for " << name << ":" << std::endl;
	for (size_t i = 0; i < 10; i++)
	{
		if (p[i].getProductName() == name)
			std::cout << p[i].getManufacturer() << std::endl;
	}
	std::cout << std::endl;

	//Заданное наименование
	String_ name1 = "Phone";
	//std::cin >> name1;
	//Заданная цена
	int pr = 250000;
	//std::cin >> pr;
	//Список товаров для заданного наименования, цена которых не превосходит заданную
	std::cout << "List of products for " << name1 << " with a price not exceeding " << pr << ":" << std::endl;
	for (size_t i = 0; i < 10; i++)
	{
		if (p[i].getProductName() == name1)
		{
			if(p[i].getPrice() < pr)
				std::cout << p[i].getManufacturer() << std::endl;
		}
	}
	std::cout << std::endl;

	//не совсем поняла как последнее задание со сроком хранения сделать через наш класс
}

int main()
{
	srand(time(NULL));
	//abiturient();
	//airAstana();
	//book();
	worker();
	//train();
	//product();

	return 0;
}