#pragma once
#include "Student_.h"
class Group_
{
private:
	String_ groupName;
	vector_<Student_> group;
public:
	Group_(String_ groupName = "Group Name", vector_<Student_> group = vector_<Student_>());

	void setGroupName(String_ groupName);
	void setGroup(vector_<Student_> group);

	String_ getGroupName() const;
	vector_<Student_> getGroup() const;

	void addStudent(Student_ student);
	void deleteStudentById(int id);
	void deleteStudent(int ind);
	void addRandMarks();
	void addMarks();

	friend std::ostream& operator<<(std::ostream &out, const Group_ &obj);
};

std::ostream& operator<<(std::ostream &out, const Group_ &obj);