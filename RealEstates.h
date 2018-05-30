#ifndef ESTATE_ESTATE_REALESTATES_H_
#define ESTATE_ESTATE_REALESTATES_H_

#include <iostream>
#include <cassert>
#include <algorithm>
#include <iomanip>
#include "Estate.h"
#include "Plot.h"

using namespace std;

class RealEstates {
private:
	Estate** list_estates_;
	int size_list_;
	int capacity_;
	void CopyRealEstates(const RealEstates&); //страхотна си!!! 
	void DelRealEstates();
public:
	RealEstates();
	~RealEstates();
	RealEstates(const RealEstates&);
	RealEstates& operator=(const RealEstates&);

	Estate** GetList() {
		return list_estates_;
	}
	
	int GetSize() {
		return size_list_;
	}

	void AddEstate(Estate*); //работииииии :))))
	void RemoveEstate(int); //работиииии :))))
	void SortRealEstate(); //работиииии :)))) 
	void RandomShufflePrice();
	void RandomShuffleArea();
	
	RealEstates FindEstatesWithSameType(string);
	RealEstates FindEstatesWithPriceInterval(double, double);
	RealEstates FindEstatesWithSameArea(double);
	RealEstates FindEstatesWithSameCity(string);
	RealEstates FindEstatesWithSameCommunications(Communication*, int);

	void Print();
	void PrintTable();
};


#endif;
