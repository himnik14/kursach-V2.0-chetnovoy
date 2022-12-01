#include "ConsoleOutput.h"
#include<iomanip>
void ConsoleOutput(vector<HairMasters> Masters) 
{

	std::cout
		<< "\t\t" << "ÔÈÎ"
		<< "\t\t   " << "ÒÈÏ ÐÀÁÎÒÛ"
		<< "\t  " << "#"
		<< "    ÖÅÍÀ"
		<< "     ÄÀÒÀ"
		<< std::endl;
	cout << "------------------------------------------------------------------------\n";
	for (int i = 0; i < Masters.size(); i++)
	{

		cout << setw(29) << left
			<< Masters[i].GetName()
			<< " | " << setw(14) << left << Masters[i].GetType()
			<< " | " << setw(3) << left << Masters[i].GetNumberClient()
			<< " | " << setw(6) << left << Masters[i].GetPrice() << " | "
			<< Masters[i].GetTheData();
		cout << endl;
	}
	cout << "------------------------------------------------------------------------\n";
}