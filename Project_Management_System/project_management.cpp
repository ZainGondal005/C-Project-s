#include "project_management.h"

void project_management::setproject_name(std::string project_name)
{
    this->project_name = project_name;
}
void project_management::setTeam_name(std::string Team_name)
{
    this->Team_name = Team_name;
}
void project_management::setbudget(float b)
{
    budget = b;
}
float project_management::getbudget()
{
    return budget;
}
std::string project_management::getproject_name()
{
    return project_name;
}
std::string project_management::getTeam_name()
{
    return Team_name;
}