#include <iostream>
#include "Plot.h"

using namespace std;

void Plot::CopyPlot(const Plot & rhs)
{
	size_arr_ = rhs.size_arr_;
	for (int i = 0; i < size_arr_; i++) {
		available_communications_[i] = rhs.available_communications_[i];
	}
	plot_ID_ = rhs.plot_ID_;
}

Plot::Plot(string address, string name, double price, double area, Communication* avalable_com, int size) :
	Estate(address, name, price, area)
{
	size_arr_ = size;
	for (int i = 0; i < size; i++) {
		available_communications_[i] = avalable_com[i];
	}
	plot_ID_ = 3;
}

Plot::Plot(const Plot & rhs)
{
	CopyPlot(rhs);
}

Plot & Plot::operator=(const Plot & rhs)
{
	if (this != &rhs) {
		Estate::operator=(rhs);
		CopyPlot(rhs);
	}
	return *this;
}

Communication* Plot::GetCommunications() 
{
	return available_communications_;
}

int Plot::GetSizeArrCommunications()
{
	return size_arr_;
}

int Plot::GetID()
{
	return plot_ID_;
}

void Plot::Print()
{
	Estate::Print();
	cout << "Available communications: "; 
	if (size_arr_ != 0) {
		for (int i = 0; i < size_arr_; i++) {
			switch (available_communications_[i]) {
			case 0: cout << "water"; 
				break;
			case 1: cout << "electricity"; 
				break;
			case 2: cout << "phone"; 
				break;
			case 3: cout << "road"; 
				break;
			case 4: cout << "sewerage";
				break;
			}
			cout << " ";
		}
		cout << endl;
	}
	else {
		cout << "none." << endl;
	}
}
