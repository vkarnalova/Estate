#ifdef _MSC_VER
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cassert>
#include <string>
#include "Estate.h"

using namespace std;

void Estate::CopyEstate(const Estate &rhs)
{
	address_estate_ = rhs.address_estate_;
	name_owner_ = rhs.name_owner_;
	price_estate_ = rhs.price_estate_;
	area_estate_ = rhs.area_estate_;
}

Estate::Estate(string address, string name, double price, double area)
{
	address_estate_ = address;
	name_owner_ = name;
	price_estate_ = price;
	area_estate_ = area;
}

Estate::Estate(const Estate &rhs)
{
	CopyEstate(rhs);
}

Estate & Estate::operator=(const Estate & rhs)
{
	if (this != &rhs) {
		CopyEstate(rhs);
	}
	return *this;
}

double Estate::GetPrice() const
{
	return price_estate_;
}

double Estate::GetArea() const
{
	return area_estate_;
}

string Estate::GetName() const
{
	return name_owner_;
}

string Estate::GetAddress() const
{
	return address_estate_;
}

void Estate::SetPrice(double price)
{
	price_estate_ = price;
}

void Estate::SetArea(double area)
{
	area_estate_ = area;
}

void Estate::ChangePriceEstate(double per)
{
	price_estate_ += price_estate_*(per / 100);
}
void Estate::Print()
{
	cout << "Address: " << address_estate_ << endl;
	cout << "Name of owner: " << name_owner_ << endl;
	cout << "Price: " << price_estate_ << endl;
	cout << "Area: " << area_estate_ << endl;
}

#endif