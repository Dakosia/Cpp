#include "Question.h"
#include <vector>
#include <string>
#include <fstream>
#include <iostream>
#pragma once
class Quiz
{
	std::vector<Question> questions;
public:
	Quiz();
	~Quiz();
	void readQuestionsFromFile(std::string filename);
};
