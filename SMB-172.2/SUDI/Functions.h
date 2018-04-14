#pragma once
#include <fstream>
#include <string>
#include <vector>
#include <iostream>
#include <set>
#include <map>
#include <cpprest/http_client.h>
using namespace web::http;                  // Common HTTP functionality
using namespace web::http::client;          // HTTP client features
//открыть субтитры, словарь юзера и записать не одинаковые
void findDifference();
std::set<std::string> getAllWordsFromSubtitles(std::string);
std::set<std::string> getMyWordsFromDictionary(std::string);
std::map<std::string, std::string> translate(std::vector<std::string>);
std::string translateWord(std::string);
void writeResultToFile(std::string, std::map<std::string, std::string>);