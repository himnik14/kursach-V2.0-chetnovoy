#pragma once
#include <string>
#include <iostream>
#include <vector>
using namespace std;

class HairMasters
{
	string name, type, numberClient, price, theData;
public:
	HairMasters(string name, string type, string numberClient, string price, string theData);
	HairMasters();
	string GetName();
	string GetType();
	string GetNumberClient();
	string GetPrice();
	string GetTheData();
	void SetName(string name);
	void SetType(string type);
	void SetNumberClient(string numberClient);
	void SetPrice(string price);
	void SetTheData(string theData);


};

