#pragma once
#include <iostream>
	class String_
{
private:
	char *str;
	int len;
public:
	String_();
	String_(const char* st);
	String_(const String_ &obj);
	String_& operator=(const String_ &s);

	void setStr(char* st);
	const char* data() const;
	int length() { return this->len; }
	void clear();
	bool empty() const;
	const String_& operator+=(const String_ &str);
	void append();

	~String_();
};

std::ostream & operator<<(std::ostream &out, const String_ &a);
std::istream & operator >> (std::istream &in, String_ &a);