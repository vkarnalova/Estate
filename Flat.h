#ifndef ESTATE_ESTATE_FLAT_H_
#define ESTATE_ESTATE_FLAT_H_

#include <iostream>
#include <string>
#include "Estate.h"

using namespace std;

class Flat:public Estate {
private:
	int rooms_num_;
	int floors_num_;
	int flat_ID_;
	void CopyFlat(const Flat&);
public:
	Flat(string = "", string = "", double = 0.0, double = 0.0, int = 0, int = 0 );
	virtual ~Flat() {}
	Flat(const Flat&);
	Flat& operator=(const Flat&);

	double GetRooms() const;
	double GetFloors() const;

	virtual int GetID();
	virtual void Print();
};

#endif