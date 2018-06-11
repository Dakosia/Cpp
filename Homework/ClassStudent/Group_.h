#pragma once
#include "Student_.h"
class Group_
{
private:
	std::string groupName;
	std::vector<Student_> group;
public:
	Group_(std::string groupName = "Group Name", std::vector<Student_> group = std::vector<Student_>());

	void setGroupName(std::string groupName);
	void setGroup(std::vector<Student_> group);

	std::string getGroupName() const;
	std::vector<Student_> getGroup() const;

	void addStudent(Student_ student);
	void deleteStudentById(int id);
	void deleteStudent(int ind);
	void addRandMarks();
	void addMarks();

	friend std::ostream& operator<<(std::ostream &out, const Group_ &obj);
};

std::ostream& operator<<(std::ostream &out, const Group_ &obj);