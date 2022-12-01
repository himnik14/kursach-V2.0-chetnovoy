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
	vector<HairMasters> Masters;
	string path;
	ifstream f;
	ofstream fout;
public:
	AdminMode(string path);
	void ConsoleOutput();
	void AddData();
	void EditPost();
	void DeletePost();
	void Main();
};
