#include "algorithm"
#include "RealEstates.h"
#include "Flat.h"
#include "House.h"
#include "Plot.h"
#include <cstdlib>
#include <ctime>
void RealEstates::CopyRealEstates(const RealEstates & rhs)
{
	list_estates_ = new Estate*[rhs.size_list_];
	assert(list_estates_ != NULL);
	size_list_ = rhs.size_list_;
	capacity_ = rhs.capacity_;

	Estate** temp = new Estate*[size_list_];
	assert(temp != NULL);

	for (int i = 0; i < size_list_;i++) {
		switch (rhs.list_estates_[i]->GetID())
		{
		case 1: temp[i] = new Flat;
			assert(temp[i] != NULL);
			*(Flat*)temp[i] = *(Flat*)rhs.list_estates_[i];
			break;
		case 2: temp[i] = new House;
			assert(temp[i] != NULL);
			*(House*)temp[i] = *(House*)rhs.list_estates_[i];
			break;
		case 3: temp[i] = new Plot;
			assert(temp[i] != NULL);
			*(Plot*)temp[i] = *(Plot*)rhs.list_estates_[i];
			break;
		}
	}

	for (int j = 0; j < size_list_; j++) {
		list_estates_[j] = temp[j];
	}

	
}

void RealEstates::DelRealEstates()
{
	for (int i = 0; i < size_list_; i++) {
		/*list_estates_[i] = NULL;*/
		delete list_estates_[i];
	}
	delete[] list_estates_;
}

RealEstates::RealEstates()
{
	size_list_ = 0;
	capacity_= 1;
	list_estates_ = new Estate*[capacity_];

}

RealEstates::~RealEstates()
{
	DelRealEstates();
}

RealEstates::RealEstates(const RealEstates & rhs)
{
	CopyRealEstates(rhs);
}

RealEstates & RealEstates::operator=(const RealEstates & rhs)
{
	if (this != &rhs) {
		DelRealEstates();
		CopyRealEstates(rhs);
	}
	return *this;
}

void RealEstates::AddEstate(Estate* new_estate_)
{
	if (size_list_ == capacity_) {
		capacity_ = 2 * capacity_;
		Estate** temp_arr = new Estate*[capacity_];
		assert(temp_arr != NULL);
		for (int i = 0; i < size_list_; i++) {
			temp_arr[i] = list_estates_[i];
		}

		Estate** tmp = list_estates_;
		list_estates_ = temp_arr;
		delete tmp;
	}
	/*list_estates_[size_list_++] = new_estate_;*/
	Estate* temp_estate;
	if (new_estate_->GetID() == 1) {
		temp_estate = new Flat;
		assert(temp_estate != NULL);
		*(Flat*)temp_estate = *(Flat*)new_estate_;
		
	}
	else if (new_estate_->GetID() == 2) {
		temp_estate = new House;
		assert(temp_estate != NULL);
		*(House*)temp_estate = *(House*)new_estate_;
		
	}
	else {
		temp_estate = new Plot;
		assert(temp_estate != NULL);
		*(Plot*)temp_estate = *(Plot*)new_estate_;
		
	}
	list_estates_[size_list_] = new_estate_;
	size_list_++;
	
}

void RealEstates::RemoveEstate(int index)
{
	if (index >= 0 && index <= size_list_) {
		list_estates_[index] = NULL;
		for (int i = index; i < size_list_-1; i++) {
			list_estates_[index] = list_estates_[index + 1];
		}
		list_estates_[size_list_ - 1] = NULL;
		size_list_--;
	}
	else {
		cout << "Unable to romove estate!";
	}
}

void RealEstates::SortRealEstate()
{
	for (int i = 0; i < size_list_ - 1; i++) {
		for (int j = 0; j < size_list_ - i - 1; j++) {
			if (list_estates_[j]->GetPrice() > list_estates_[j + 1]->GetPrice()) {
				Estate* temp = list_estates_[j];
				list_estates_[j] = list_estates_[j+1];
				list_estates_[j + 1] = temp;
			}
		}
	}
}

void RealEstates::RandomShufflePrice()
{
	int* bool_arr = new int[size_list_];
	for (int i = 0; i < size_list_; i++) {
		bool_arr[i] = 0;
	}
	srand(time(NULL));
	int random_index = 0;
	double temp=0.0;
	for (int i = 0; i < size_list_; i++)
	{
		if (bool_arr[i] == 0) {
			bool_arr[i] = -1;
			do { 
				random_index = rand() % size_list_; 
			} while (bool_arr[random_index] == -1);
			bool_arr[random_index] = -1;
			temp = list_estates_[i]->GetPrice();
			list_estates_[i]->SetPrice(list_estates_[random_index]->GetPrice());
			list_estates_[random_index]->SetPrice(temp);
		}
	}
	
	delete[] bool_arr;
}

void RealEstates::RandomShuffleArea()
{
	int* bool_arr = new int[size_list_];
	for (int i = 0; i < size_list_; i++) {
		bool_arr[i] = 0;
	}
	srand(time(NULL));
	int random_index = 0;
	double temp = 0.0;
	for (int i = 0; i < size_list_; i++)
	{
		if (bool_arr[i] == 0) {
			bool_arr[i] = -1;
			do {
				random_index = rand() % size_list_;
			} while (bool_arr[random_index] == -1);
			bool_arr[random_index] = -1;
			temp = list_estates_[i]->GetArea();
			list_estates_[i]->SetArea(list_estates_[random_index]->GetArea());
			list_estates_[random_index]->SetArea(temp);
		}
	}

	delete[] bool_arr;
}

RealEstates RealEstates::FindEstatesWithSameType(string type)
{
	RealEstates temp;
	if (type == "flat") {
		for (int i = 0; i < size_list_; i++) {
			if ((list_estates_[i]->GetID()) == 1) {
				temp.AddEstate(list_estates_[i]);
			}
		}
	}
	else if (type == "house") {
		for (int i = 0; i < size_list_; i++) {
			if ((list_estates_[i]->GetID()) == 2) {
				temp.AddEstate(list_estates_[i]);
			}
		}
	}
	else if (type == "plot") {
		for (int i = 0; i < size_list_; i++) {
			if ((list_estates_[i]->GetID()) == 3) {
				temp.AddEstate(list_estates_[i]);
			}
		}
	}
	temp.SortRealEstate();
	temp.PrintTable();
	return temp;
}

RealEstates RealEstates::FindEstatesWithPriceInterval(double min_price, double max_price)
{
	RealEstates temp;
	for (int i = 0; i < size_list_; i++) {
		if ((list_estates_[i]->GetPrice()) >= min_price && (list_estates_[i]->GetPrice()) <= max_price) {
			temp.AddEstate(list_estates_[i]);
		}
	}
	return temp;
}

RealEstates RealEstates::FindEstatesWithSameArea(double search_area)
{
	RealEstates temp;
	for (int i = 0; i < size_list_; i++) {
		if ((list_estates_[i]->GetArea())==search_area) {
			temp.AddEstate(list_estates_[i]);
		}
	}
	return temp;
}

RealEstates RealEstates::FindEstatesWithSameCity(string city)
{
	RealEstates temp;
	for (int i = 0; i < size_list_; i++) {
		if ((list_estates_[i]->GetAddress()) == city) {
			temp.AddEstate(list_estates_[i]);
		}
	}
	return temp;
}

RealEstates RealEstates::FindEstatesWithSameCommunications(Communication* search_communications, int size_arr)
{
	RealEstates temp;
	bool* flag = new bool[size_arr];
	for (int i = 0; i < size_arr; i++) {
		flag[i] = false;
	}
	bool flag_add_estate_ = true;
	for (int i = 0; i < size_list_; i++) {
		if (list_estates_[i]->GetID() == 3) {
			for (int j = 0; j < size_arr; j++) {
				for (int k = 0; k < ((Plot*)list_estates_[i])->GetSizeArrCommunications(); k++) {
					if (search_communications[i] == (((Plot*)list_estates_[i])->GetCommunications())[k]) {
						flag[j] = true;
					}
				}
				if (flag[j] == false) {
					break;
				}
			}
			for (int l = 0; l < size_arr; l++) {
				if (flag[l] == false) {
					flag_add_estate_ = false;
				}
			}
			if (flag_add_estate_) {
				temp.AddEstate(list_estates_[i]);
			}
		}
	}
	delete[] flag;
	return temp;
}


void RealEstates::Print()
{
	cout << "Real Estates:" << endl;
	for (int i = 0; i < size_list_; i++) {
		list_estates_[i]->Print();
	}
}

void RealEstates::PrintTable()
{
	int max_len_name = 0;
	int max_len_address = 0;
	int max_len = 0;
	for (int i = 0; i < size_list_; i++) {
		if ((list_estates_[i]->GetName()).length() > max_len_name) {
			max_len_name = (list_estates_[i]->GetName()).length();
		};
		if ((list_estates_[i]->GetAddress()).length() > max_len_address) {
			max_len_address = (list_estates_[i]->GetAddress()).length();
		};
	}
	if (max_len_name > max_len_address) {
		max_len = max_len_name +1;
	}
	else {
		max_len = max_len_address +1;
	}
	for (int i = 0; i < 9 * max_len + 10; i++) {
		cout << "-";
	}
	cout << endl;
	cout << "|" << setw(max_len) << "Type";
	cout << "|" << setw(max_len) << "Address";
	cout << "|" << setw(max_len) << "Owner"; 
	cout << "|" << setw(max_len) << "Price";
	cout << "|" << setw(max_len) << "Area"; 
	cout << "|" << setw(max_len) << "Number rooms"; 
	cout << "|" << setw(max_len) << "Number floors";
	cout << "|" << setw(max_len) << "Area yard";
	cout << "|" << setw(max_len) << "Communications" << "|" << endl;
	for (int i = 0; i < 9 * max_len + 10; i++) {
		cout << "-";
	}
	cout << endl;
	for (int k = 0; k < size_list_; k++) {
		if ((list_estates_[k]->GetID()) == 1) {
			cout << "|" << setw(max_len) << "Flat";
			cout << "|" << setw(max_len) << list_estates_[k]->GetAddress();
			cout << "|" << setw(max_len) << list_estates_[k]->GetName();
			cout << "|" << setw(max_len) << list_estates_[k]->GetPrice();
			cout << "|" << setw(max_len) << list_estates_[k]->GetArea();
			cout << "|" << setw(max_len) << ((Flat*)list_estates_[k])->GetRooms();
			cout << "|" << setw(max_len) << ((Flat*)list_estates_[k])->GetFloors();
			cout << "|" << setw(max_len) << "No";
			cout << "|" << setw(max_len) << "No" << "|" << endl;
		}
		else if ((list_estates_[k]->GetID()) == 2) {
			cout << "|" << setw(max_len) << "House";
			cout << "|" << setw(max_len) << list_estates_[k]->GetAddress();
			cout << "|" << setw(max_len) << list_estates_[k]->GetName();
			cout << "|" << setw(max_len) << list_estates_[k]->GetPrice();
			cout << "|" << setw(max_len) << list_estates_[k]->GetArea();
			cout << "|" << setw(max_len) << ((House*)list_estates_[k])->GetRooms();
			cout << "|" << setw(max_len) << ((House*)list_estates_[k])->GetFloors();
			cout << "|" << setw(max_len) << ((House*)list_estates_[k])->GetAreaYard();
			cout << "|" << setw(max_len) << "No" << "|" << endl;
		}
		else if ((list_estates_[k]->GetID()) == 3) {
			cout << "|" << setw(max_len) << "Plot";
			cout << "|" << setw(max_len) << list_estates_[k]->GetAddress();
			cout << "|" << setw(max_len) << list_estates_[k]->GetName();
			cout << "|" << setw(max_len) << list_estates_[k]->GetPrice();
			cout << "|" << setw(max_len) << list_estates_[k]->GetArea();
			cout << "|" << setw(max_len) << "No";
			cout << "|" << setw(max_len) << "No";
			cout << "|" << setw(max_len) << "No";
			if (((Plot*)list_estates_[k])->GetSizeArrCommunications() > 0) {
				
				switch ((((Plot*)list_estates_[k])->GetCommunications())[0]) {
				case 0: cout << "|" << setw(max_len) << "water" << "|" << endl; break;
				case 1: cout << "|" << setw(max_len) << "electricity" << "|" << endl; break;
				case 2: cout << "|" << setw(max_len) << "telephone" << "|" << endl; break;
				case 3: cout << "|" << setw(max_len) << "road" << "|" << endl; break;
				case 4: cout << "|" << setw(max_len) << "sewerage" << "|" << endl; break;
				}
				for (int i = 1; i < ((Plot*)list_estates_[k])->GetSizeArrCommunications();i++) {
					cout << "|" << setw(max_len + 1);
					cout << "|" << setw(max_len + 1);
					cout << "|" << setw(max_len + 1);
					cout << "|" << setw(max_len + 1);
					cout << "|" << setw(max_len + 1);
					cout << "|" << setw(max_len + 1);
					cout << "|" << setw(max_len + 1);
					cout << "|" << setw(max_len + 1); //WATER,ELECTRICITY,TELEPHONE,ROAD,SEWERAGE
					switch ((((Plot*)list_estates_[k])->GetCommunications())[i]) {
					case 0: cout << "|" << setw(max_len) << "water" << "|" << endl; break;
					case 1: cout << "|" << setw(max_len) << "electricity" << "|" << endl; break;
					case 2: cout << "|" << setw(max_len) << "telephone" << "|" << endl; break;
					case 3: cout << "|" << setw(max_len) << "road" << "|" << endl; break;
					case 4: cout << "|" << setw(max_len) << "sewerage" << "|" << endl; break;
					}
				}
			}
			else {
				cout << "|" << setw(max_len) << "No" << "|" << endl;
			}
		}
		for (int i = 0; i < 9 * max_len + 10; i++) {
			cout << "-";
		}
		cout << endl;
	}
	
}
