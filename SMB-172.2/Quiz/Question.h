#include <string>
#include <vector>
#pragma once
class Question
{
public:
	std::string question;
	std::vector<std::string> answers;
	int right;
	Question();
	~Question();
};
