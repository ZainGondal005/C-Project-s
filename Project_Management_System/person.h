#pragma once
#include "project_management.h"

class person : public project_management
{
private:
    std::string *person_name;
    int size;

public:
    void setperson_name();
    void print();
    void fun_export(char[]);
    void set_project();

    friend std::ostream &operator<<(std::ostream &os, const person &p)
    {
        os << "Name of Project is : " << p.project_name << "\n";
        os << "Involved people under " << p.Team_name << " Team are : " << p.size << "\n";
        for (int i = 0; i < p.size; i++)
        {
            os << "Name of person " << i + 1 << " is : " << p.person_name[i] << "\n";
        }
        os << "The budget of " << p.project_name << " project is : " << p.budget << " $\n";

        return os;
    }
    ~person()
    {
        delete[] person_name;
    }
};