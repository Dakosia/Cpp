#include "Group_.h"



Group_::Group_(std::string groupName, std::vector<Student_> group)
{
	this->setGroupName(groupName);
	this->setGroup(group);
}

void Group_::setGroupName(std::string groupName)
{
	this->groupName = groupName;
}

void Group_::setGroup(std::vector<Student_> group)
{
	this->group = group;
}

std::string Group_::getGroupName() const
{
	return this->groupName;
}

std::vector<Student_> Group_::getGroup() const
{
	return this->group;
}

void Group_::addStudent(Student_ student)
{
	this->group.push_back(student);
}

void Group_::deleteStudentById(int id)
{
	for (size_t i = 0; i < group.size(); i++)
	{
		if (group[i].getId() == id)
		{
			group.erase(group.begin() + i);
		}
	}
}

void Group_::deleteStudent(int ind)
{
	group.erase(group.begin() + ind - 1);
}

void Group_::addRandMarks()
{
	srand(time(NULL));
	for (size_t i = 0; i < group.size(); i++)
	{
		group[i].addMark(rand() % 12 + 1);
	}
}

void Group_::addMarks()
{
	for (size_t i = 0; i < group.size(); i++)
	{
		int mark;
		std::cin >> mark;
		group[i].addMark(mark);
	}
}

std::ostream & operator<<(std::ostream & out, const Group_ & obj)
{
	out << "Group name: " << obj.groupName << std::endl;
	out << "Group: ";
	for (size_t i = 0; i < obj.group.size(); i++)
	{
		out << obj.group[i] << ' ';
	}
	out << std::endl;
	return out;
}