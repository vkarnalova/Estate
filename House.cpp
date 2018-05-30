#include <iostream>
#include "House.h"

using namespace std;

House::House(string address, string name, double price, double area, int rooms, int floors, double yard) :
	Estate(address, name, price, area)
{
	rooms_num_ = rooms;
	floors_num_ = floors;
	area_yard_ = yard;
	house_ID_ = 2;
}

void House::CopyHouse(const House& rhs)
{
	area_yard_ = rhs.area_yard_;
	rooms_num_ = rhs.rooms_num_;
	floors_num_ = rhs.rooms_num_;
	house_ID_ = rhs.house_ID_;
}

House::House(const House &rhs) : Estate(rhs)
{
	CopyHouse(rhs);
}

House & House::operator=(const House &rhs)
{
	if (this != &rhs) {
		Estate::operator=(rhs);
		CopyHouse(rhs);
	}
	return *this;
}

double House::GetAreaYard() const
{
	return area_yard_;
}

int House::GetRooms() const
{
	return rooms_num_;
}

int House::GetFloors() const
{
	return floors_num_;
}

int House::GetID()
{
	return house_ID_;
}

void House::Print()
{
	Estate::Print();
	cout << "Number of rooms: " << rooms_num_ << endl;
	cout << "Number of floors: " << floors_num_ << endl;
	cout << "Area of the yard: " << area_yard_ << endl;
}
