#pragma once
#include "PriorityQueue.h"
#include <string>
class PrinterQueue
{
private:
	PriorityQueue<std::string> q;
public:
	int getSize() const;
	void addToPrinterQueue(std::string name, int prior);
	void delFromPrinterQueue();
	void showPrinterQueue();
};

