#pragma once
#include <iostream>
#include <fstream>
#include <cstring>
#include <string>

class project_management
{
protected:
    std::string project_name;
    std::string Team_name;
    float budget;

public:
    project_management() {}
    void setbudget(float);
    void setproject_name(std::string);
    void setTeam_name(std::string);
    float getbudget();
    std::string getproject_name();
    std::string getTeam_name();
};