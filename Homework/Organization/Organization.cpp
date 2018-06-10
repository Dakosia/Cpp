#include "Organization.h"



Organization::Organization(std::string name, double salary)
{
	this->setName(name);
	this->setSalary(salary);
}

void Organization::setName(std::string name)
{
	this->name = name;
}

void Organization::setSalary(double salary)
{
	this->salary = salary;
}

std::string Organization::getName() const
{
	return this->name;
}

double Organization::getSalary() const
{
	return this->salary;
}

void Organization::addEmployee(Employee * emp)
{
	emps.push_back(std::auto_ptr<Employee>(emp));
}

void Organization::deleteEmployee(int pos)
{
	if (pos < emps.size())
		emps.erase(emps.begin() + pos);
}

void Organization::changeEmployeeName(int pos, std::string name)
{
	if (pos < emps.size())
		emps[pos]->setName(name);
}

void Organization::changeEmployeeBirthdate(int pos, int day, int month, int year)
{
	if (pos < emps.size())
		emps[pos]->setDate(day, month, year);
}

void Organization::changeEmployeeGender(int pos, bool gender)
{
	if (pos < emps.size())
		emps[pos]->setGender(gender);
}

void Organization::changeEmployeeExperience(int pos, int experience)
{
	if (pos < emps.size())
		emps[pos]->setExperience(experience);
}

void Organization::needForSalary()
{
	double sum = 0.0;
	for (size_t i = 0; i < emps.size(); i++)
	{
		sum += emps[i]->getCoef() * salary;
	}
	std::cout << "Need for salary: " << sum << std::endl << "----------\n";
}

void Organization::getInfo() const
{
	std::cout << "Oraganization name: " << name << std::endl << "----------\n";
	for (size_t i = 0; i < emps.size(); i++)
	{
		//std::cout << std::string(typeid(*emps[i]).name()).substr(6) << ":\n";
		std::string res = typeid(*emps[i]).name();
		res = res.substr(6);
		std::cout << res << ":\n";
		emps[i].get()->getInfo();
		std::cout << std::endl;
		std::cout << "Salary: " << emps[i]->getCoef() * salary << std::endl << "----------\n";
	}
}

void Organization::saveToFile() const
{
	std::fstream f("organization.csv", std::ios::out);
	f << this->name << ';';
	f << this->salary << ';' << std::endl;
	for (size_t i = 0; i < emps.size(); i++)
	{
		f << emps[i]->codeInfo();
		if (i != emps.size() - 1)
			f << std::endl;
	}
}

void Organization::readFromFile()
{
	std::fstream lol("organization.csv", std::ios::in);
	std::string kek;
	char cheburek = ';';
	getline(lol, kek, cheburek);
	this->name = kek;
	getline(lol, kek, cheburek);
	this->salary = stod(kek);
	std::vector<std::string> s;
	while (!lol.eof())
	{
		s.clear();
		for (int i = 0; i < 8; i++)
		{
			std::string s1;
			getline(lol, s1, ';');
			s.push_back(s1);
		}
		//Developer;Vasya;10;10;1997;1;0;1;
		if (s[0] == "\nDeveloper")
			addEmployee(new Developer(s[1], Date_(stoi(s[2]), stoi(s[3]), stoi(s[4])), stoi(s[5]), stoi(s[6]), stoi(s[7])));
		else if (s[0] == "\nAdmin")
			addEmployee(new Admin(s[1], Date_(stoi(s[2]), stoi(s[3]), stoi(s[4])), stoi(s[5]), stoi(s[6]), stoi(s[7])));
		else if (s[0] == "\nManager")
			addEmployee(new Manager(s[1], Date_(stoi(s[2]), stoi(s[3]), stoi(s[4])), stoi(s[5]), stoi(s[6]), stoi(s[7])));
		else if (s[0] == "\nAnykey")
			addEmployee(new Anykey(s[1], Date_(stoi(s[2]), stoi(s[3]), stoi(s[4]))));

	}
}
