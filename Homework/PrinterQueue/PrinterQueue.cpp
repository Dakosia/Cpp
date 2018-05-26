#include "PrinterQueue.h"

int PrinterQueue::getSize() const
{
	return q.size();
}

void PrinterQueue::addToPrinterQueue(std::string name, int prior)
{
	q.push(name, prior);
}

void PrinterQueue::delFromPrinterQueue()
{
	q.pop();
}

void PrinterQueue::showPrinterQueue()
{
	q.showQueue();
}
