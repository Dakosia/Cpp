#include "Group_.h"
#include <fstream>
#include <iterator>

int main()
{
	srand(time(NULL));
	std::vector<int> m1, m2, m3, m4, m5;
	for (int i = 0; i < 5; i++)
	{
		m1.push_back(rand() % 12 + 1);
		m2.push_back(rand() % 12 + 1);
		m3.push_back(rand() % 12 + 1);
		m4.push_back(rand() % 12 + 1);
		m5.push_back(rand() % 12 + 1);
	}
	Student_ s1("Natsu", "Dragneel", 17, 1, m1);
	Student_ s2("Lucy", "Heartfilia", 18, 2, m2);
	Student_ s3("Gray", "Fullbuster", 19, 3, m3);
	Student_ s4("Erza", "Scarlet ", 20, 4, m4);
	Student_ s5("Jellal", "Fernandez", 20, 5, m5);
	std::vector<Student_> s = { s1,s2,s3,s4,s5 };
	std::ofstream file("students.txt");
	std::ostream_iterator<Student_> os(file, "\n");
	copy(s.begin(), s.end(), os);
	file.close();

	/*Group_ g;
	g.setGroupName("SMP-172.2");
	g.setGroup(s);
	g.addRandMarks();
	std::cout << g;*/

	system("pause");
	return 0;
}