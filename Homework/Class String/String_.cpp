#include "String_.h"



String_::String_()
{
	this->len = 0;
	this->str = nullptr;
}

String_::String_(const char * st)
{
	this->len = std::strlen(st);
	this->str = new char[this->len + 1];
	strcpy_s(this->str, this->len + 1, st);
}

String_::String_(const String_ & obj)
{
	this->len = obj.len;
	if (this->len == 0)
		this->str = nullptr;
	else
	{
		this->str = new char[this->len + 1];
		strcpy_s(this->str, this->len + 1, obj.str);
	}
}


String_::~String_()
{
	if (this->str != nullptr)
		delete[] this->str;
	this->str = nullptr;
	this->len = 0;
}

void String_::setStr(char * ch)
{
	if (this->len != 0)
		delete this->str;
	this->len = strlen(ch);
	this->str = new char[this->len + 1];
	strcpy_s(this->str, this->len + 1, ch);
}

const char * String_::data() const
{
	return this->str;
}

void String_::clear()
{
	//this->~String_();
	if (this->str != nullptr)
		delete[] this->str;
	this->str = nullptr;
	this->len = 0;
}

bool String_::empty() const
{
	return this->len == 0;
}

const String_ & String_::operator+=(const String_ & obj)
{
	this->len += obj.len;
	char *new_str = new char[this->len + 1];
	strcpy_s(new_str, this->len + 1, this->str);
	strcat_s(new_str, this->len + 1, obj.str);
	delete[] this->str;
	this->str = new_str;
	return *this;
}

void String_::append()
{
}

char & String_::at(int pos)
{
	if (pos > len || pos < 0)
		throw std::exception("out of range");
	return str[pos];
}

const char & String_::at(int pos) const
{
	if (pos > len || pos < 0)
		throw std::exception("out of range");
	return str[pos];
}

char & String_::operator[](int ind)
{
	return str[ind];
}

char & String_::operator[](int ind) const
{
	return str[ind];
}

String_& String_::operator=(const String_ & s)
{
	//защита от самоприсваивания
	if (&s == this)
		return *this;
	if (this->str != nullptr)
		delete[] this->str;
	this->str = nullptr;
	this->len = s.len;
	//только если есть что копировать из s
	if (this->len > 0)
	{
		this->str = new char[this->len + 1];
		strcpy_s(this->str, this->len + 1, s.str);
	}
	return *this;
}

std::ostream & operator<<(std::ostream & out, const String_ & a)
{
	if (a.data() != nullptr)
		out << a.data();
	return out;
}

std::istream & operator >> (std::istream & in, String_ & a)
{
	char hop[1024];
	in >> hop;
	a.setStr(hop);
	return in;
}

bool operator==(const String_ & a, const String_ & b)
{
	if (a.length() != b.length())
		return false;
	for (size_t i = 0; i < a.length(); i++)
	{
		if (a[i] != b[i])
			return false;
	}
	return true;
}