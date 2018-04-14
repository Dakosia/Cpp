#include "Tests.h"

void test() 
{
	std::set<std::string> result = getAllWordsFromSubtitles("Sherlock.The.Abominable.Bride.2016.1080p.WEB-DL.DD5.1.H.264-Coo7.srt");
	assert(0 < result.size());
	result = getAllWordsFromSubtitles("Sherlock.The.Abominable.Bride.2016.1080p.WEB-DL.DD5.1.H.264-Coo709.srt");
	assert(0 == result.size());
}