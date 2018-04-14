#include "Quiz.h"
int main() 
{
	Quiz quiz;
	quiz.readQuestionsFromFile("questions.txt");
	system("pause");
	return 0;
}