#include <iostream>
#include <cstring>
#include <locale>
#include "Estate.h"
#include "Flat.h"
#include "House.h"
#include "Plot.h"
#include "RealEstates.h"
#include "Broker.h"
#include "HelpfulBroker.h"
#include "DishonestBroker.h" 
#include "SimpleBroker.h"
#include "functions.h"

using namespace std;



int main() {
	/*Estate test;
	test.print();
	Estate test1("ul. Tyrpo Gendov", "Stefan Karnalov", 15000, 200);
	test1.print();
	Estate test2 = test1;
	test2.print();
	Estate test3("ul. Roza", "Roza Karnalova", 30000, 300);
	test3.print();
	test3 = test2;
	test3.print();*/

	/*Flat test4;
	test4.print();
	Flat test5("ul. Roza", "Roza Karnalova", 30000, 300, 20, 5);
	test5.print();
	Flat test6 = test5;
	test6.print();
	Flat test7("ul. Tyrpo Gendov", "Stefan Karnalov", 15000, 200, 25, 4);
	test7.print();
	test7 = test5;
	test7.print();*/


	/*House test8;
	test8.print();
	House test9("ul. Tyrpo Gendov", "Stefan Karnalov", 15000, 200, 25, 4, 50);
	test9.print();
	House test10 = test9;
	test10.print();
	House test11("ul. Roza", "Roza Karnalova", 30000, 300, 20, 5, 25);
	test11.print();
	test11 = test10;
	test11.print();*/

	/*Communication list[1];
	list[0] = WATER;
	list[1] = ELECTRICITY;*/

	/*Plot test12;
	test12.print();
	Plot test13("ul. Tyrpo Gendov", "Stefan Karnalov", 17000, 200, list, 2);
	test13.print();
	Plot test14 = test13;
	test14.print();
	Plot test15("ul. Roza", "Roza Karnalova", 30000, 300);
	test15.print();
	test15 = test13;
	test15.print();*/

	/*Communication list[1];
	list[0] = WATER;
	list[1] = ELECTRICITY;

	House test9("ul. Tyrpo Gendov", "Stefan Karnalov", 15000, 200, 25, 4, 50);
	Plot test13("ul. Tyrpo Gendov", "Stefan Karnalov", 17000, 200, list, 2);

	Plot* ptrPlot = &test13;

	House* ptrHouse = &test9;

	/*RealEstates testArr2;*/

	/*RealEstates testArr;
	testArr.addEstate(ptrPlot);
	testArr.addEstate(ptrHouse);*/

	/*testArr.print();*/
	/*testArr.sortRealEstate();
	testArr.print();*/

	/*{
	RealEstates testArr2 = testArr;
	testArr2.print();
	}

	testArr.print();
	*/

	/*Broker test16;
	test16.print();
	Broker test17("Nadejda Ivanova", 15, testArr);
	test17.print();
	test17.changePrice();
	test17.print();

	Flat test5("ul. Roza", "Roza Karnalova", 30000, 300, 20, 5);
	Flat* ptrFlat = &test5;
	test17.addEstateToList(ptrFlat);
	test17.print();*/

	/*HelpfulBroker test18;
	test18.print();
	system("pause");*/

	/*string test;
	getline(cin, test);
	cout << test;*/

	/*createRealEstates().print();*/

	/*int num_brokers_;
	do {
		cout << "How many brokers would you like to create: ";
		cin >> num_brokers_;
	} while (num_brokers_ < 0);
	Broker** brokers_ = new Broker*[num_brokers_];
	createArrBrokers(brokers_,num_brokers_);
	for (int i = 0; i < num_brokers_; i++) {
		brokers_[i]->print();
	}*/

	/*RealEstates temp2;*/	
	
	RealEstates tempRealEstate;

	Flat* test1 = new Flat("ul. Roza", "Roza Karnalova", 30000, 300, 20, 5);
	assert(test1 != NULL);
	House* test2 = new House("ul. Tyrpo Gendov", "Stefan Karnalov", 15000, 200, 25, 4, 50);
	assert(test1 != NULL);
	Communication list[4];
	list[0] = WATER;
	list[1] = ELECTRICITY;
	list[2] = TELEPHONE;
	list[3] = ROAD;
	Plot* test3 = new Plot("ul. Tyrpo Gendov", "Stefan Karnalov", 17000, 170, list, 4);
	assert(test1 != NULL);
	Plot* test4 = new Plot("Nezabravka", "Georgi Georgiev", 15000, 150, list, 4);
	assert(test1 != NULL);
	tempRealEstate.AddEstate(test1);
	tempRealEstate.AddEstate(test2);
	tempRealEstate.AddEstate(test3);
	tempRealEstate.AddEstate(test4);
	/*temp2.AddEstate(test1);
	temp2.AddEstate(test2);
	temp2.AddEstate(test3);
	temp2.AddEstate(test4);
	tempRealEstate.PrintTable();
	temp2.PrintTable();*/
	
	/*{RealEstates temp3;
	temp3.AddEstate(test1);
	temp3.AddEstate(test2);
	temp3.PrintTable();
	}*/
	
	/*tempRealEstate.findEstatesWithSameType("plot");
	
	
	tempRealEstate.findEstatesWithPriceInterval(14000.0, 20000.0).printTable();
	
	RealEstates testRealEstates3 = tempRealEstate.findEstatesWithSameArea(200);
	testRealEstates3.printTable();
	RealEstates testRealEstates4 = tempRealEstate.findEstatesWithSameCity("ul. Tyrpo Gendov");
	testRealEstates4.printTable();*/

	/*Communication list2[2];
	list2[0] = WATER;
	list2[1] = ELECTRICITY;
	tempRealEstate.findEstatesWithSameCommunications(list2, 2).printTable();*/
	
	/*tempRealEstate.RandomShufflePrice();
	tempRealEstate.PrintTable();*/
	

	/*system("pause");*/
	return 0;
}