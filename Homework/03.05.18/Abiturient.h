#pragma once
#include "String_.h"
#include "VectorMy.h"
class Abiturient
{
private:
	String_ fio;
	String_ address;
	VectorMy marks;
public:
	Abiturient(String_ fio = "FIO", String_ address = "Address", VectorMy marks = VectorMy());
	~Abiturient();
	//setters
	void setFio(String_ fio);
	void setAddress(String_ address);
	void setMarks(VectorMy marks);
	//getters
	String_ getFio() const;
	String_ getAddress() const;
	VectorMy getMarks() const;

	void addMark(int mark);
	bool isLoser();
	int getAvgMark();

	Abiturient& operator=(const Abiturient &a);

	friend std::ostream& operator<<(std::ostream &out, const Abiturient &a);
};


std::ostream& operator<<(std::ostream &out, const Abiturient &a);

//bool compare(Abiturient & a1, Abiturient & a2) {
//	return a1.getAvgMark() < a2.getAvgMark();
//}