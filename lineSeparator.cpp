#include "lineSeparator.h"

vector<string> lineSeparotor(string line, string separator)
{
	vector<string> a;
	while (!line.empty())
	{
		a.push_back(line.substr(0, line.find(separator)));
		line.erase(0, line.find(separator)+1);
	}
	return a;
}
