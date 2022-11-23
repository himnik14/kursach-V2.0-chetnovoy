#include "FileManager.h"
#include <iostream>
#include "lineSeparator.h"
vector<HairMasters> ReadFile1(ifstream &fout, string separator)
{
	vector<string> a;
	string path = "C:\\Games\\text.txt";
	fout.open(path);
	string s;
	vector<HairMasters> Masters;
	while (!fout.eof())
	{
		getline(fout, s);
		if (s.size() != 0) {
			a = lineSeparotor(s, separator);
			Masters.push_back(HairMasters(a[0], a[1], a[2], a[3], a[4]));
		}
	}
	fout.close();
	return Masters;
}

void FileOverwrite(vector<HairMasters> &Masters, ofstream& fout)
{
	string path = "C:\\Games\\text.txt";
	fout.open(path, ios::trunc);
	fout.close();
	fout.open(path, ios::app);
	for (int i = 0; i < Masters.size(); i++)
	{
		fout << Masters[i].GetName() << ";" << Masters[i].GetType() << ";" << Masters[i].GetNumberClient() << ";" << Masters[i].GetPrice() << ";" << Masters[i].GetTheData() << ";" << "\n";
	}

}
