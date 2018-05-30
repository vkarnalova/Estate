#include <iostream>
#include <string>
#include "Flat.h"

using namespace std;

void Flat::CopyFlat(const Flat &rhs)
{
	rooms_num_ = rhs.rooms_num_;
	floors_num_ = rhs.floors_num_;
	flat_ID_ = rhs.flat_ID_;
}

Flat::Flat(string address, string name, double price, double area, int rooms, int floors) :
	Estate(address, name , price , area)
{
	rooms_num_ = rooms ;
	floors_num_ = floors;
	flat_ID_ = 1;
}

Flat::Flat(const Flat &rhs) : Estate(rhs)
{
	CopyFlat(rhs);
}

Flat & Flat::operator=(const Flat & rhs)
{
	if(this != &rhs){
		Estate::operator=(rhs);
		CopyFlat(rhs);
	}
	return *this;
}

double Flat::GetRooms() const
{
	return rooms_num_;
}

double Flat::GetFloors() const
{
	return floors_num_;
}

int Flat::GetID()
{
	return flat_ID_;
}

void Flat::Print()
{
	Estate::Print();
	cout << "Number of rooms: " << rooms_num_ << endl;
	cout << "Number of floors: " << floors_num_ << endl;
}
