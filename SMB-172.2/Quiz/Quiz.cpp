#include "Quiz.h"



Quiz::Quiz()
{
}


Quiz::~Quiz()
{
}

void Quiz::readQuestionsFromFile(std::string filename)
{
	std::ifstream in(filename);

	while (!in.eof()) {
		std::string line;
		Question temp;
		std::getline(in, line);
		if (line.substr(0, 9) == "question:") 
		{
			temp.question = line;
			std::cout << temp.question << std::endl;
		}
		else if (line.substr(0, 7) == "answer:")
		{
			temp.answers.push_back(line);
			std::cout << line << std::endl;
		}
		else if (line.substr(0, 6) == "right:")
		{
			int it = 0;
			while (!isdigit(line[it])) 
			{
				++it;
			}
			temp.right = (int)(line[it] - 48);
			std::cout << "right: " << temp.right << std::endl;
			questions.push_back(temp);
		}
	}
}
