#pragma once
#include "AdminMode.h"
class UserMode :
    public AdminMode
{
public:
    UserMode(string path) :AdminMode(path) {};
    void Search();
    void BestJob();
    vector<HairMasters> SortAlf(vector<HairMasters> M);
    void Main() override;
};

