#ifndef ESTATE_ESTATE_PLOT_H_
#define ESTATE_ESTATE_PLOT_H_

#include <iostream>
#include <string>
#include "Estate.h"

using namespace std;

enum  Communication {WATER,ELECTRICITY,TELEPHONE,ROAD,SEWERAGE};

class Plot : public Estate {
private:
	Communication available_communications_[4];
	int size_arr_;
	int plot_ID_;
	void CopyPlot(const Plot&);
public:
	Plot(string = "", string = "", double = 0.0, double = 0.0,Communication* = NULL, int = 0);
	virtual ~Plot() {}
	Plot(const Plot&);
	Plot& operator=(const Plot&);

	Communication* GetCommunications();
	int GetSizeArrCommunications();

	virtual int GetID();
	virtual void Print();

};



#endif