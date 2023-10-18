#include "person.h"

void person::setperson_name()
{
    std::cout << "Enter number of people involved in " << getTeam_name() << " Team ";
    std::cin >> size;
    person_name = new std::string[size];
    std::cout << "\nEnter names of people's " << std::endl;
    for (int i = 0; i < size; i++)
    {
        std::cout << "Enter name of person " << i + 1 << " is : ";
        std::cin >> person_name[i];
        std::cout << std::endl;
    }
}

void person::print()
{
    std::cout << "Name of Project is : " << getproject_name() << std::endl;
    std::cout << "Involved people under " << getTeam_name() << " Team are : " << size << std::endl;
    for (int i = 0; i < size; i++)
    {
        std::cout << "Name of person " << i + 1 << " is : ";
        std::cout << person_name[i] << std::endl;
    }
    std::cout << "The budget of " << getproject_name() << " project is : " << getbudget() << " $" << std::endl;
}
void person::set_project()
{
    std::string project;
    std::string team;
    std::cout << "Enter project name   ";
    std::cin >> project;
    std::cout << std::endl;
    setproject_name(project);

    std::cout << "Enter Team name   ";
    std::cin >> team;
    std::cout << std::endl;
    setTeam_name(team);

    setperson_name();
    float budget_project;
    std::cout << "Enter budget of " << getproject_name() << " project ";
    std::cin >> budget_project;
    std::cout << std::endl;
    setbudget(budget_project);

    std::cout << "\n------------------------------------" << std::endl;
    print();
}