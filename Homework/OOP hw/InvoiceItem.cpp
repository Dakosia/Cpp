#include "InvoiceItem.h"



InvoiceItem::InvoiceItem()
{
}

InvoiceItem::InvoiceItem(std::string _id, std::string _desc, int _qty, double _unitPrice)
{
	id = _id;
	desc = _desc;
	qty = _qty;
	unitPrice = _unitPrice;
}


InvoiceItem::~InvoiceItem()
{
}

std::string InvoiceItem::getID()
{
	return id;
}

std::string InvoiceItem::getDesc()
{
	return desc;
}

int InvoiceItem::getQty()
{
	return qty;
}

void InvoiceItem::setQty(int _qty)
{
	qty = _qty;
}

double InvoiceItem::getUnitPrice()
{
	return unitPrice;
}

void InvoiceItem::setUnitPrice(double _unitPrice)
{
	unitPrice = _unitPrice;
}

double InvoiceItem::getTotal()
{
	return unitPrice * qty;
}

std::string InvoiceItem::toString()
{
	return "InvoiceItem[id=" + id + ", desc=" + desc + ", qty=" + std::to_string(qty) + ", unitPrice=" + std::to_string(unitPrice) + "]";
}
