#include "FileManager.h"
#include <iostream>
#include "lineSeparator.h"
vector<HairMasters> ReadFile1(ifstream &f, string separator, string path)
{	
	f.open(path);
	if (!f.is_open()) {
		cout << "Ошибка открытия файла!\n";
	}
	string s;
	vector<string> a;
	vector<HairMasters> Masters;
	while (!f.eof())
	{
		getline(f, s);
		if (s.size() != 0) {
			a = lineSeparotor(s, separator);
			try
			{
				Masters.push_back(HairMasters(a[0], a[1], a[2], a[3], a[4]));

			}
			catch (const std::exception&ex)
			{
				cout << ex.what();

			}
		}
	}
	f.close();
	return Masters;
}

void FileOverwrite(vector<HairMasters> &Masters, ofstream& fout, string path)
{
	fout.open(path, ios::trunc);
	fout.close();
	fout.open(path, ios::app);
	for (int i = 0; i < Masters.size(); i++)
	{
		fout << Masters[i].GetName() << ";" << Masters[i].GetType() << ";" << Masters[i].GetNumberClient() << ";" << Masters[i].GetPrice() << ";" << Masters[i].GetTheData() << ";" << "\n";
	}
	fout.close();

}
