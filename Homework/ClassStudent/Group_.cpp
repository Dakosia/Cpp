#include "Group_.h"



Group_::Group_(String_ groupName, vector_<Student_> group)
{
	this->setGroupName(groupName);
	this->setGroup(group);
}

void Group_::setGroupName(String_ groupName)
{
	this->groupName = groupName;
}

void Group_::setGroup(vector_<Student_> group)
{
	this->group = group;
}

String_ Group_::getGroupName() const
{
	return this->groupName;
}

vector_<Student_> Group_::getGroup() const
{
	return this->group;
}

void Group_::addStudent(Student_ student)
{
	this->group.push_back(student);
}

void Group_::deleteStudentById(int id)
{
	for (size_t i = 0; i < group.getSize(); i++)
	{
		if (group[i].getId() == id)
		{
			group.erase(i);
		}
	}
}

void Group_::deleteStudent(int ind)
{
	group.erase(ind - 1);
}

void Group_::addRandMarks()
{
	srand(time(NULL));
	for (size_t i = 0; i < group.getSize(); i++)
	{
		group[i].addMark(rand() % 12 + 1);
	}
}

void Group_::addMarks()
{
	for (size_t i = 0; i < group.getSize(); i++)
	{
		int mark;
		std::cin >> mark;
		group[i].addMark(mark);
	}
}

std::ostream & operator<<(std::ostream & out, const Group_ & obj)
{
	out << obj.groupName << std::endl << obj.group;
	return out;
}