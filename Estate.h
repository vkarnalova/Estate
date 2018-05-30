#ifndef ESTATE_ESTATE_ESTATE_H_
#define ESTATE_ESTATE_ESTATE_H_

#include <iostream>
#include <string>

using namespace std;

class Estate{
private:
	string address_estate_;
	string name_owner_;
	double price_estate_;
	double area_estate_;
	void CopyEstate(const Estate&);
public:
	Estate(string = "", string = "", double=0.0, double=0.0);
	virtual ~Estate() {}
	Estate(const Estate&);
	Estate& operator=(const Estate&);

	double GetPrice() const;
	double GetArea() const;
	string GetName() const;
	string GetAddress() const;
	void SetPrice(double);
	void SetArea(double);
	
	void ChangePriceEstate(double);
	virtual int GetID() = 0;
	virtual void Print();
};

#endif