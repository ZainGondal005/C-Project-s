#include <iostream>
#include <fstream>
#include <stdexcept>
using namespace std;
class project_management
{
protected:
    float budget;
    string project_name;
    string Team_name;

public:
    project_management() {}
    void setbudget(float);
    void setproject_name(string);
    void setTeam_name(string);
    float getbudget();
    string getproject_name();
    string getTeam_name();
};
void project_management::setproject_name(string project_name)
{
    this->project_name = project_name;
}
void project_management::setTeam_name(string Team_name)
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
string project_management::getproject_name()
{
    return project_name;
}
string project_management::getTeam_name()
{
    return Team_name;
}
class Date : public project_management
{
private:
    int day, month, year;

protected:
    int Time;

public:
    Date()
    {
        day = 0;
        month = 0;
        year = 0;
    }
    void setdates();
    void setdates_data();
    void setday(int);
    void setmonth(int);
    void setyear(int);
    int getday();
    int getmonth();
    int getyear();
    int Time_period(Date);
    void display();
};

void Date::setday(int d)
{
    day = d;
}
void Date::setmonth(int m)
{
    month = m;
}
void Date::setyear(int y)
{
    year = y;
}
int Date::getday()
{
    return day;
}
int Date::getmonth()
{
    return month;
}
int Date::getyear()
{
    return year;
}
int Date::Time_period(Date D)
{
    int difference;
    difference = year - D.year;
    if (difference <= 0)
    {
        difference = difference * (-1);
    }
    difference = difference * 365;
    int FinalY = difference;
    difference = month - D.month;
    if (difference <= 0)
    {
        difference = difference * (-1);
    }

    difference = difference * 30 + difference / 2;

    int FinalM = difference;

    int FINDALDATE = FinalM + FinalY;

    return FINDALDATE;
}
void Date::display()
{
    cout << "Your date is : " << day << "/" << month << "/" << year << endl;
}
void Date::setdates_data()
{
    int d, m, y;
    cout << "Enter month : ";
    cin >> m;

    while (m > 12 || m < 1)
    {
        cout << "Invalid month \nMOnth must be between 1-12" << endl;
        cout << "Enter Month again" << endl;
        cin >> m;
    }
    setmonth(m);

    switch (m)
    {
    case 1:
    case 3:
    case 5:
    case 7:
    case 8:
    case 10:
    case 12:
    {
        d = 31;
        setday(d);

        break;
    }
    case 2:
    {
        d = 28;
        setday(d);

        break;
    }
    case 4:
    case 6:
    case 9:
    case 11:
    {

        d = 30;

        setday(d);

        break;
    }
    }

    cout << "Enter year : ";
    cin >> y;
    cout << endl;
    while (y < 1900 || y > 2100)
    {
        cout << "Invalid year \nYears must be between 1900-2100" << endl;
        cout << "Enter year again" << endl;
        cin >> y;
    }
    setyear(y);
    cout << "--------------------------" << endl;
}
void Date::setdates()
{
    Date date1, date2;
    cout << "Project starting date is " << endl;
    cout << "---------------------------" << endl;
    date1.setdates_data();
    cout << "Project end's on " << endl;
    cout << "---------------------------" << endl;
    date2.setdates_data();
    date1.display();
    date2.display();
    cout << "\n";
    Time = date1.Time_period(date2);
    cout << "Total time period taken by " << getproject_name() << " Project is : " << Time << " days under " << getTeam_name() << " Team" << endl;
}

class person : public Date
{
private:
    string *person_name;
    int size;

public:
    void setperson_name();
    void print();
    void set_project();
    void save(char[]);
    friend ostream &operator<<(ostream &os, const person &p)
    {
        os << "Name of Project is : " << p.project_name << "\n";
        os << "Involved people under " << p.Team_name << " Team are : " << p.size << "\n";
        for (int i = 0; i < p.size; i++)
        {
            os << "Name of person " << i + 1 << " is : " << p.person_name[i] << "\n";
        }
        os << "The budget of " << p.project_name << " project is : " << p.budget << " $\n";
        os << "Time period taken by " << p.Team_name << " Team is : " << p.Time << " Days\n";
        return os;
    }
};
void person::setperson_name()
{
    cout << "Enter number of people involved in " << getTeam_name() << " Team ";
    cin >> size;
    person_name = new string[size];
    cout << "\nEnter names of people's " << endl;
    for (int i = 0; i < size; i++)
    {
        cout << "Enter name of person " << i + 1 << " is : ";
        cin >> person_name[i];
        cout << endl;
    }
}

void person::print()
{
    cout << "Name of Project is : " << getproject_name() << endl;
    cout << "Involved people under " << getTeam_name() << " Team are : " << size << endl;
    for (int i = 0; i < size; i++)
    {
        cout << "Name of person " << i + 1 << " is : ";
        cout << person_name[i] << endl;
    }
    cout << "The budget of " << getproject_name() << " project is : " << getbudget() << " $" << endl;
    cout << "Time period taken by " << getTeam_name() << " Team is : " << Time << " Days" << endl;
}
void person::set_project()
{
    string project;
    string team;
    cout << "Enter project name   ";
    cin >> project;
    cout << endl;
    setproject_name(project);

    cout << "Enter Team name   ";
    cin >> team;
    cout << endl;
    setTeam_name(team);

    setperson_name();
    float budget_project;
    cout << "Enter budget of " << getproject_name() << " project ";
    cin >> budget_project;
    cout << endl;
    setbudget(budget_project);

    setdates();
    cout << "\n------------------------------------" << endl;
    print();
}

void person::save(char filename[])
{
    ofstream file(filename, ios::out | ios::app);
    try
    {

        if (!file.is_open())
        {
            cout << "The file cannot be opened due to an error." << endl;
            throw "Error";
            file.close();
        }
    }
    catch (string)
    {
        cout << "Error: Unable to open the file for writing." << endl;
    }

    file << "Project Name: " << getproject_name() << endl;
    file << "Team Name: " << getTeam_name() << endl;
    for (int i = 0; i < size; i++)
    {
        file << "Person Name " << i + 1 << " is : " << person_name[i] << endl;
    }
    file << "Budget: " << getbudget() << " $" << endl;
    file << "Time Period: " << Time << " Days" << endl;
    file << "------------------------------------" << endl;

    file.close();
}

int main()
{
    static int new_person = 0;
    person *obj_person = new person[10];
    char filename[20] = "person_data.txt";
    int choice;
    int option;
    do
    {
        cout << "------ Project Managent System ------" << endl;
        cout << "1. Add Project" << endl;
        cout << "2. Display Project's" << endl;
        cout << "3. Delete Project" << endl;
        cout << "4. View specific Project" << endl;
        cout << "5. Save to File" << endl;
        cout << "6. Exit" << endl;
        cout << "----------------------" << endl;
        cout << "Enter option   ";
        cin >> option;
        cout << "----------------------" << endl;
        cout << endl;

        switch (option)
        {
        case 1:
        {
            obj_person[new_person].set_project();
            new_person++;
            cout << "------------------------------------" << endl;
        }
        break;
        case 2:
        {
            if (new_person == 0)
            {
                cout << " There are zero projects at this time." << endl;
            }
            else
            {
                for (int i = 0; i < new_person; i++)
                {
                    cout << "-------  Data of Project's  " << i + 1 << "-------\n"
                         << endl;

                    cout << obj_person[i];
                }
            }
            cout << "------------------------------------" << endl;
        }
        break;
        case 3:
        {
            if (new_person == 0)
            {
                cout << " There are zero projects at this time." << endl;
            }
            else
            {
                for (int i = 0; i < new_person; i++)
                {
                    cout << "Enter " << i << "  to Delete this " << obj_person[i].getproject_name() << " under the " << obj_person[i].getTeam_name() << " Team" << endl;
                }
                cout << "Enter now ";
                cin >> choice;
                while (choice >= new_person)
                {
                    cout << "The index value must be etween [ 0-" << new_person - 1 << " ]" << endl;
                    cin >> choice;
                }
            }
            obj_person[choice] = obj_person[choice + 1];
            new_person--;
            cout << "------------------------------------" << endl;
        }
        break;
        case 4:
        {
            if (new_person == 0)
            {
                cout << " There are zero projects at this time." << endl;
            }
            else
            {
                for (int i = 0; i < new_person; i++)
                {
                    cout << "Enter " << i << "  to view this " << obj_person[i].getproject_name() << " under the " << obj_person[i].getTeam_name() << " Team" << endl;
                }
                cout << "Enter now ";
                cin >> choice;
                while (choice >= new_person)
                {
                    cout << "The index value must be etween [ 0-" << new_person - 1 << " ]" << endl;
                    cin >> choice;
                }
                cout << "-------  Data of Project's -------\n";
                obj_person[choice].print();
            }

            cout << "------------------------------------" << endl;
        }

        break;
        case 5:
        {
            for (int i = 0; i < new_person; i++)
            {
                obj_person[i].save(filename);
                cout << "Data saved to " << filename << endl;
            }
        }
        break;
        case 6:
        {
            cout << "Exiting Program..." << endl;
        }
        break;

        default:
        {
            cout << "Invalid option" << endl;
        }
        break;
        }
    } while (option != 6);

    delete[] obj_person;
    return 0;
}
