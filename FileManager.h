#include "HairMasters.h"
#include <fstream>
#pragma once
vector<HairMasters> ReadFile1(ifstream &f, string separator, string path);
void FileOverwrite(vector<HairMasters> &Masters, ofstream &fout, string path);