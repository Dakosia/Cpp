#include "PrinterQueue.h"

int main()
{
	PrinterQueue q1;
	q1.addToPrinterQueue("Client1", 1);
	q1.addToPrinterQueue("Client2", 1);
	q1.addToPrinterQueue("Client3", 0);
	q1.addToPrinterQueue("Client4", 3);
	q1.addToPrinterQueue("Client5", 2);
	q1.addToPrinterQueue("Client6", 2);
	q1.addToPrinterQueue("Client7", 0);
	q1.showPrinterQueue();
	std::cout << std::endl;

	q1.delFromPrinterQueue();
	q1.showPrinterQueue();
	std::cout << std::endl;

	q1.delFromPrinterQueue();
	q1.showPrinterQueue();
	std::cout << std::endl;

	system("pause");
	return 0;
}