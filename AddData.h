#pragma once
#include <conio.h>

#include "HairMasters.h"
void AddData(vector<HairMasters>& Masters, ofstream& fout);
void EditPost(vector<HairMasters>& Masters, ofstream& fout);
void DeletePost(vector<HairMasters>& Masters, ofstream& fout);