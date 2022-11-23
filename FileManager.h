#include "HairMasters.h"
#include <fstream>
#pragma once
vector<HairMasters> ReadFile1(ifstream &fout, string separator);
void FileOverwrite(vector<HairMasters> &Masters, ofstream &fout);