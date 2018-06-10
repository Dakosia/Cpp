#include "Developer.h"
#include "Admin.h"
#include "Manager.h"
#include "Anykey.h"
#include "Organization.h"

void interface(Organization &o);
void addDeveloper(Organization &o);
void addAdmin(Organization &o);
void addManager(Organization &o);
void addAnykey(Organization &o);
void deleteEmployee(Organization &o);
void changeEmployeeName(Organization &o);
void changeEmployeeBirthdate(Organization &o);
void changeEmployeeGender(Organization &o);
void changeEmployeeExperience(Organization &o);
void needForSalary(Organization &o);
void information(Organization &o);

//void developer()
//{
//	Developer d;
//	d.getInfo();
//}
//
//void manager()
//{
//	Manager m("Vasya", Date_(29, 5, 1997), 1, 0, 100);
//	m.getInfo();
//	Employee *e = new Manager;
//	//std::cout << std::string(typeid(*e).name()).substr(6) << ":\n";
//	std::string res = typeid(*e).name();
//	res = res.substr(6);
//	std::cout << res << ":\n";
//
//	//std::auto_ptr<Employee> e(new Developer);
//}

void organization()
{
	Organization o("STEP Computer Academy", 100000);
	interface(o);


	/*o.addEmployee(new Developer("Petya", Date_(1, 1, 1990), 1, 5, 5));
	o.addEmployee(new Manager("Katya", Date_(5, 3, 1998), 0, 3, 300));
	o.getInfo();
	o.needForSalary();
	o.getInfo();
	o.saveToFile();*/

	/*o.readFromFile();
	o.getInfo();*/

	/*o.deleteEmployee(1);
	o.getInfo();*/
}

void interface(Organization &o)
{
	std::cout << "Choose an option: " << std::endl;
	std::cout << "0. Exit" << std::endl;
	std::cout << "1. Add developer" << std::endl;
	std::cout << "2. Add admin" << std::endl;
	std::cout << "3. Add manager" << std::endl;
	std::cout << "4. Add anykey" << std::endl;
	std::cout << "5. Delete employee" << std::endl;
	std::cout << "6. Change employee name" << std::endl;
	std::cout << "7. Change employee birthdate" << std::endl;
	std::cout << "8. Change employee gender" << std::endl;
	std::cout << "9. Change employee work experience" << std::endl;
	std::cout << "10. Get need for salary" << std::endl;
	std::cout << "11. Get organization information" << std::endl;
	int choose = 0;
	std::cin >> choose;
	switch (choose)
	{
	case 1:
		addDeveloper(o);
		break;
	case 2:
		addAdmin(o);
		break;
	case 3:
		addManager(o);
		break;
	case 4:
		addAnykey(o);
		break;
	case 5:
		deleteEmployee(o);
		break;
	case 6:
		changeEmployeeName(o);
		break;
	case 7:
		changeEmployeeBirthdate(o);
		break;
	case 8:
		changeEmployeeGender(o);
		break;
	case 9:
		changeEmployeeExperience(o);
		break;
	case 10:
		needForSalary(o);
		break;
	case 11:
		information(o);
		break;
	default:
		break;
	}
}

void addDeveloper(Organization &o)
{
	system("cls");
	std::string name;
	std::cout << "Enter developer name" << std::endl;
	std::cin >> name;
	int day, month, year;
	std::cout << "Enter developer birthdate using space(day month year)" << std::endl;
	std::cin >> day >> month >> year;
	bool gender;
	std::cout << "Enter developer gender(0 - female, 1 - male)" << std::endl;
	std::cin >> gender;
	int experience;
	std::cout << "Enter developer work experience" << std::endl;
	std::cin >> experience;
	int nmbProgLangs;
	std::cout << "Enter developer number of programming languages" << std::endl;
	std::cin >> nmbProgLangs;
	
	o.addEmployee(new Developer(name, Date_(day, month, year), gender, experience, nmbProgLangs));

	system("cls");
	interface(o);
}

void addAdmin(Organization &o)
{
	system("cls");
	std::string name;
	std::cout << "Enter admin name" << std::endl;
	std::cin >> name;
	int day, month, year;
	std::cout << "Enter admin birthdate using space(day month year)" << std::endl;
	std::cin >> day >> month >> year;
	bool gender;
	std::cout << "Enter admin gender(0 - female, 1 - male)" << std::endl;
	std::cin >> gender;
	int experience;
	std::cout << "Enter admin work experience" << std::endl;
	std::cin >> experience;
	int nmbOfComps;
	std::cout << "Enter admin number of serviceable computers" << std::endl;
	std::cin >> nmbOfComps;

	o.addEmployee(new Admin(name, Date_(day, month, year), gender, experience, nmbOfComps));

	system("cls");
	interface(o);
}

void addManager(Organization &o)
{
	system("cls");
	std::string name;
	std::cout << "Enter manager name" << std::endl;
	std::cin >> name;
	int day, month, year;
	std::cout << "Enter manager birthdate using space(day month year)" << std::endl;
	std::cin >> day >> month >> year;
	bool gender;
	std::cout << "Enter manager gender(0 - female, 1 - male)" << std::endl;
	std::cin >> gender;
	int experience;
	std::cout << "Enter manager work experience" << std::endl;
	std::cin >> experience;
	int nmbOfSales;
	std::cout << "Enter manager number of sales" << std::endl;
	std::cin >> nmbOfSales;

	o.addEmployee(new Manager(name, Date_(day, month, year), gender, experience, nmbOfSales));

	system("cls");
	interface(o);
}

void addAnykey(Organization &o)
{
	system("cls");
	std::string name;
	std::cout << "Enter anykey name" << std::endl;
	std::cin >> name;
	int day, month, year;
	std::cout << "Enter anykey birthdate using space(day month year)" << std::endl;
	std::cin >> day >> month >> year;
	bool gender;
	std::cout << "Enter anykey gender(0 - female, 1 - male)" << std::endl;
	std::cin >> gender;

	o.addEmployee(new Anykey(name, Date_(day, month, year), gender));

	system("cls");
	interface(o);
}

void deleteEmployee(Organization &o)
{
	system("cls");
	int pos;
	std::cout << "Enter position" << std::endl;
	std::cin >> pos;
	o.deleteEmployee(pos);
	system("cls");
	interface(o);
}

void changeEmployeeName(Organization &o)
{
	system("cls");
	int pos;
	std::cout << "Enter position" << std::endl;
	std::cin >> pos;
	std::string name;
	std::cout << "Enter name" << std::endl;
	std::cin >> name;
	o.changeEmployeeName(pos, name);
	system("cls");
	interface(o);
}

void changeEmployeeBirthdate(Organization &o)
{
	system("cls");
	int pos;
	std::cout << "Enter position" << std::endl;
	std::cin >> pos;
	int day, month, year;
	std::cout << "Enter birthdate using space(day month year)" << std::endl;
	std::cin >> day >> month >> year;
	o.changeEmployeeBirthdate(pos, day, month, year);
	system("cls");
	interface(o);
}

void changeEmployeeGender(Organization &o)
{
	system("cls");
	int pos;
	std::cout << "Enter position" << std::endl;
	std::cin >> pos;
	bool gender;
	std::cout << "Enter gender(0 - female, 1 - male)" << std::endl;
	std::cin >> gender;
	o.changeEmployeeGender(pos, gender);
	system("cls");
	interface(o);
}

void changeEmployeeExperience(Organization &o)
{
	system("cls");
	int pos;
	std::cout << "Enter position" << std::endl;
	std::cin >> pos;
	int experience;
	std::cout << "Enter work experience" << std::endl;
	std::cin >> experience;
	o.changeEmployeeExperience(pos, experience);
	system("cls");
	interface(o);
}

void needForSalary(Organization &o)
{
	system("cls");
	o.needForSalary();
	interface(o);
}

void information(Organization &o)
{
	system("cls");
	o.getInfo();
	interface(o);
}

int main()
{
	//developer();
	//manager();
	organization();

	system("pause");
	return 0;
}