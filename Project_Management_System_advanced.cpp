#include <iostream>
#include <fstream>
#include <cstring>

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
void save(char filename[], person std1[], int new_person)
{
    std::ofstream file(filename, std::ios::binary | std::ios::app);
    if (!file.is_open())
    {
        std::cout << "File is not open " << std::endl;
    }
    else
    {

        file.write((char *)&std1, sizeof(person) * new_person);

        file.close();

        // std::ifstream filt(filename, ios::binary);
        // person *std = new person[10];
        // filt.read((char *)std, sizeof(person) * new_person);

        // filt.close();
        // if (new_person == 0)
        // {
        //     cout << " There are zero projects at this time." << endl;
        // }
        // else
        // {
        //     for (int i = 0; i < new_person; i++)
        //     {
        //         std::cout << "-------  Data of Project's  " << i + 1 << "-------\n"
        //              << std::endl;

        //        std:: cout << std[i];
        //     }
        // }
    }
}
void exist(std::fstream &file)
{

    person p1;

    int newperson;

    while (file.read((char *)&p1, sizeof(person)))
    {
        std::cout << "--------  Data of Project's --------\n";
        if (file.good())
        {
            std::cout << p1;
        }
    }

    file.close();
    std::cout << "------------------------------------" << std::endl;
}
void person::fun_export(char name_file[])
{
    std::ofstream filecsv(name_file, std::ios::out | std::ios::app);

    if (!filecsv.is_open())
    {
        std::cout << "File is not open " << std::endl;
        return;
    }
    else
    {
        filecsv << getproject_name() << ",";
        filecsv << getTeam_name() << ",";
        for (int i = 0; i < size; i++)
        {
            filecsv << person_name[i] << ",";
        }
        filecsv << getbudget();
        filecsv << std::endl;
        filecsv.close();
    }
}
void fun_import(char name_file[])
{
    std::ifstream file1(name_file, std::ios::in);

    if (!file1.is_open())
    {
        std::cout << "File is not open " << std::endl;
        return;
    }
    else
    {
        std::string line;
        while (getline(file1, line))
        {
            std::cout << line << std::endl;
        }
        file1.close();
    }
}

int main(int argc, char *argv[])
{
    char filename[20] = "person_data.bin";

    std::fstream myfile(filename, std::ios::binary | std::ios::in);
    if (!myfile.is_open())
    {
        std::cout << "File does not exist\n"
                  << std::endl;
    }
    else
    {
        std::cout << "In exist part" << std::endl;
        exist(myfile);
    }

    person *obj_person = new person[10];
    char name_file[20];
    int new_person = 0;
    int choice;
    int option;
    int count;
    if (argc == 3)
    {
        strcpy(name_file, argv[2]);

        if (argv[1] == "import")
        {
            std::cout << "import function";
            fun_import(name_file);
        }
    }
    if (argc == 2)
    {
        std::string help = argv[1];
        if (argv[1] == "help")
        {
            std::cout << "This help message.\nThis program like project mangement system that perform the CRUD opertion, use binary file and .csv file to store data\n";
        }
    }

    do
    {
        std::cout << "------ Project Managent System ------" << std::endl;
        std::cout << "1. Add Project" << std::endl;
        std::cout << "2. View specific Project" << std::endl;
        std::cout << "3. update the specific record" << std::endl;
        std::cout << "4. Delete Project" << std::endl;
        std::cout << "5. Display Project's" << std::endl;
        std::cout << "6. Save to File" << std::endl;
        std::cout << "7. Exit" << std::endl;
        std::cout << "----------------------" << std::endl;
        std::cout << "Enter option   ";
        std::cin >> option;
        std::cout << "----------------------" << std::endl;
        std::cout << std::endl;

        switch (option)
        {
        case 1:
        {
            if (new_person >= 10)
            {
                std::cout << "You Reached at a maximum limit\nYou cannot add more Project's\n";
                option = 7;
            }
            else
            {
                obj_person[new_person].set_project();
                new_person++;
                std::cout << "Data stored successfully" << std::endl;
                std::cout << "------------------------------------" << std::endl;
            }
        }
        break;
        case 2:
        {
            if (new_person == 0)
            {
                std::cout << " There are zero projects at this time." << std::endl;
            }
            else
            {
                for (int i = 0; i < new_person; i++)
                {
                    std::cout << "Enter " << i + 1 << "  to view this " << obj_person[i].getproject_name() << " under the " << obj_person[i].getTeam_name() << " Team" << std::endl;
                }
                std::cout << "Enter now ";
                std::cin >> choice;
                choice = choice - 1;
                while (choice >= new_person)
                {
                    std::cout << "The index value must be etween [ 0-" << new_person - 1 << " ]" << std::endl;
                    std::cin >> choice;
                    choice = choice - 1;
                }
                std::cout << "-------  Data of Project's -------\n";
                obj_person[choice].print();
            }

            std::cout << "------------------------------------" << std::endl;
        }
        break;
        case 3:
        {
            if (new_person == 0)
            {
                std::cout << " There are zero projects at this time." << std::endl;
            }
            else
            {
                for (int i = 0; i < new_person; i++)
                {
                    std::cout << "Enter " << i + 1 << "  to update this " << obj_person[i].getproject_name() << " record under the " << obj_person[i].getTeam_name() << " Team" << std::endl;
                }
                std::cout << "Enter now ";
                std::cin >> choice;
                choice = choice - 1;
                while (choice >= new_person)
                {
                    std::cout << "The index value must be etween [ 0-" << new_person - 1 << " ]" << std::endl;
                    std::cin >> choice;
                    choice = choice - 1;
                }
                std::cout << "-------  Data of Project's -------\n";
                obj_person[choice].set_project();
                if (count != 0)
                {
                    save(filename, obj_person, new_person);
                    std::cout << "Data updated successfully" << std::endl;
                }
            }

            std::cout << "------------------------------------" << std::endl;
        }
        break;
        case 4:
        {
            if (new_person == 0)
            {
                std::cout << " There are zero projects at this time." << std::endl;
            }
            else
            {
                for (int i = 0; i < new_person; i++)
                {
                    std::cout << "Enter " << i + 1 << "  to Delete this " << obj_person[i].getproject_name() << " under the " << obj_person[i].getTeam_name() << " Team" << std::endl;
                }
                std::cout << "Enter now ";
                std::cin >> choice;
                choice = choice - 1;
                while (choice >= new_person)
                {
                    std::cout << "The index value must be etween [ 0-" << new_person - 1 << " ]" << std::endl;
                    std::cin >> choice;

                    choice = choice - 1;
                }
            }
            obj_person[choice] = obj_person[choice + 1];
            new_person--;
            std::cout << "Project's deleted successfully" << std::endl;
            std::cout << "------------------------------------" << std::endl;
        }
        break;
        case 5:
        {
            if (new_person == 0)
            {
                std::cout << " There are zero projects at this time." << std::endl;
            }
            else
            {
                for (int i = 0; i < new_person; i++)
                {
                    std::cout << "-------  Data of Project's  " << i + 1 << "-------\n"
                              << std::endl;
                    std::cout << obj_person[i];
                }
            }
            std::cout << "------------------------------------" << std::endl;
        }

        break;
        case 6:
        {
            if (new_person == 0)
            {
                std::cout << " There are zero projects at this time\nNO data is saved into binary file" << std::endl;
            }
            else
            {
                count++;
                save(filename, obj_person, new_person);
                std::cout << "Data stored in binary file successfully" << std::endl;
                std::cout << "------------------------------------" << std::endl;
            }
        }
        break;
        case 7:
        {
            std::cout << "Exiting Program..." << std::endl;
        }
        break;

        default:
        {
            std::cout << "Invalid option" << std::endl;
        }
        break;
        }
    } while (option != 7);
    if (argc == 3)
    {
        strcpy(name_file, argv[2]);

        if (argv[1] == "export")
        {
            // std::cout << "export function";
            if (new_person == 0)
            {
                std::cout << " There is zero data at this time" << std::endl;
            }
            else
            {
                for (int i = 0; i < new_person; i++)
                {
                    obj_person[i].fun_export(name_file);
                }
                std::cout << "Data export to file successfully\n";
            }
        }
        // else
        // {
        //     std::cout << "give proper command to export file\n";
        // }
    }
    delete[] obj_person;
    return 0;
}
