#include "Functions.h"


void findDifference()
{
	std::ifstream files("files.txt");
	//s - .srt file, d - .txt file
	std::string s, d;
	files >> s >> d;
	std::set<std::string> allwords(getAllWordsFromSubtitles(s)), mywords(getMyWordsFromDictionary(s));
	std::vector<std::string> unknownwords;
	for (std::string i : allwords)
	{
		bool isInMyWords = false;
		for (std::string j : mywords)
		{
			if (i == j)
			{
				isInMyWords = true;
				break;
			}
		}
		if (!isInMyWords)
		{
			unknownwords.push_back(i);
		}
	}
	writeResultToFile("result.txt", translate(unknownwords));
}

//заполняем сет всех слов из субтитров
std::set<std::string> getAllWordsFromSubtitles(std::string s)
{
	std::ifstream subtitles(s);
	std::set<std::string> words;
	std::string temp;
	while (subtitles >> temp)
	{
		if (!isdigit(temp[0]) && temp[0] != '-')
		{
			while (!temp.empty() && !isalpha(temp[temp.length() - 1]))
			{
				temp.erase(temp.end() - 1);
			}
			words.insert(temp);
		}
	}
	return words;
}

//заполняем сет моих слов из словаря
std::set<std::string> getMyWordsFromDictionary(std::string d)
{
	std::ifstream dictionary(d);
	std::string word;
	std::set<std::string> words;
	while (dictionary >> word)
	{
		words.insert(word);
	}
	return words;
}

std::map<std::string, std::string> translate(std::vector<std::string> words)
{
	std::map<std::string, std::string> dictionary;
	for (std::string word : words) 
	{
		dictionary.insert({ word, translateWord(word) });
	}
	return dictionary;
}

std::string translateWord(std::string word)
{
	const char x[45] = "https://jsonplaceholder.typicode.com/posts/1";
	http_client client(x);

	http_response response;
	// ordinary `get` request
	response = client.request(methods::GET, "/get").get();
	std::cout << "url: " << response.extract_json().get()[U("url")] << "\n";
}

void writeResultToFile(std::string filename, std::map<std::string, std::string> words)
{
	std::ofstream out(filename);
	for (auto key : words) 
	{
		out << key.first << ' ' << key.second << std::endl;
	}
}
