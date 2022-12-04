#pragma once

#include "HairMasters.h"
#include "lineSeparator.h"
#include <windows.h>
#include <fstream>
#include "ConsoleOutput.h"
#include "FileManager.h"
#include "AddData.h"
#include <iomanip>

class AdminMode 
{
	void AddData();
	void EditPost();
	void DeletePost();
protected:
	vector<HairMasters> Masters;
	string path;
	ifstream f;
	ofstream fout;

public:
	AdminMode(string path);
	virtual void ConsoleOutput(vector<HairMasters> Master);
	virtual void Main();

};
