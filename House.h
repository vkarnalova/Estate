#ifndef ESTATE_ESTATE_HOUSE_H_
#define ESTATE_ESTATE_HOUSE_H_

#include <iostream>
#include <string>
#include "Estate.h"

class House: public Estate {
private:
	double area_yard_;
	int rooms_num_;
	int floors_num_;
	int house_ID_;
	void CopyHouse(const House&);
public:
	House(string = "", string = "", double = 0.0, double = 0.0, int = 0, int = 0, double = 0.0);
	virtual ~House() {};
	House(const House&);
	House& operator=(const House&);

	double GetAreaYard() const;
	int GetRooms() const;
	int GetFloors() const;

	virtual int GetID();
	virtual void Print();
};


#endif